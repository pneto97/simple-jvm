//j8_class_displayer.c
#include "j8_class_displayer.h"
#include "j8_primitive_types.h"
#include "opcode.h"
#include "read_utils.h"
#include <math.h>
#include <string.h>

//de acordo com a tag do constant pool, altera a string tagType para o significado
void cpTagToString(uint8_t tag, char *tagType) {
    switch (tag) {
    case 7:
        strcpy(tagType, "Class");
        break;
    case 9:
        strcpy(tagType, "Fieldref");
        break;
    case 10:
        strcpy(tagType, "Methodref");
        break;
    case 11:
        strcpy(tagType, "InterfaceMethdref");
        break;
    case 8:
        strcpy(tagType, "String");
        break;
    case 3:
        strcpy(tagType, "Integer");
        break;
    case 4:
        strcpy(tagType, "Float");
        break;
    case 5:
        strcpy(tagType, "Long");
        break;
    case 6:
        strcpy(tagType, "Double");
        break;
    case 12:
        strcpy(tagType, "NameAndType");
        break;
    case 1:
        strcpy(tagType, "Utf8");
        break;
    case 15:
        strcpy(tagType, "MethodHandle");
        break;
    case 16:
        strcpy(tagType, "MethodType");
        break;
    case 18:
        strcpy(tagType, "InvokeDynamic");
    }
}
// Função que chama todas as outras que printam
void printClassFile(class_structure *jclass) {
    printInitialParams(jclass); //magic, minor e major version
    printConstantPool(jclass); // Constant pool
    printInterfaces(jclass); // Interfaces
    printFields(jclass); // Fields
    printMethods(jclass); // Methods
    printClassAttributes(jclass); // Class Attributes
}

// print do magic number, minor e major version
void printInitialParams(class_structure *jclass) {
    printf("Magic Number: %x\n", jclass->magic);
    printf("Minor Version: %x\n", jclass->minor_version);
    printf("Major Version: %d\n", jclass->major_version);
    printf("Version: ");
    printVersion(jclass->major_version, jclass->minor_version);
    printf("\n");
    printf("Constant Pool Count: %d\n", jclass->constant_pool_count);
    printAccessFlags(jclass->access_flags, CLASS); // access flag
    printf("This Class: "); // This Class
    printClassName(jclass->this_class, jclass);
    printf("\n");
    printf("Super Class: "); // Super class
    if (jclass->super_class != 0)
        printClassName(jclass->super_class, jclass);
    else
        printf("Object");
    printf("\n");
    printf("Interfaces Count: %d\n", jclass->interfaces_count);
    printf("Fields Count: %d\n", jclass->fields_count);
    printf("Methods Count: %d\n", jclass->methods_count);
}

//percorre a struct da classe e imprime todos os dados
void printConstantPool(class_structure *jclass) {
    printf("\n------------------------------\n");
    printf("          CONSTANT POOL          \n");

    printf("Constant Pool Count: %d\n", jclass->constant_pool_count);
    char tagType[18];
    printf("Mostrando o conteúdo do constant pool:\n");
    for (int i = 0; i < jclass->constant_pool_count - 1; i++) {

        cpTagToString(jclass->constant_pool[i].tag, tagType);
        printf("\t#%d: %-18s\t", (i + 1), tagType);

        switch (jclass->constant_pool[i].tag) {
        case CONSTANT_Class:
            printf("name Index: #%d\t\t\t\t\t //  ", jclass->constant_pool[i].info.classInfo.name_index);
            printUtf8(jclass->constant_pool[i].info.classInfo.name_index, jclass);
            printf("\n");
            break;
        case CONSTANT_Fieldref:
        case CONSTANT_Methodref:
        case CONSTANT_InterfaceMethodref:
            printf("class index: #%d, ", jclass->constant_pool[i].info.refInfo.class_index);
            printf("name and type index: #%d\t // ", jclass->constant_pool[i].info.refInfo.name_and_type_index);
            printClassName(jclass->constant_pool[i].info.refInfo.class_index, jclass);
            printf(".");
            printNameAndType(jclass->constant_pool[i].info.refInfo.name_and_type_index, jclass);
            printf("\n");
            break;
        case CONSTANT_String:
            printf("string index: #%d\t\t\t\t // ", jclass->constant_pool[i].info.stringInfo.string_index);
            printUtf8(jclass->constant_pool[i].info.stringInfo.string_index, jclass);
            printf("\n");
            break;
        case CONSTANT_Integer:
            printf("bytes: #%x \t\t\t\t\t // ", jclass->constant_pool[i].info.number32Info.bytes);
            printf("%d", (int32_t)jclass->constant_pool[i].info.number32Info.bytes);
            printf("\n");
            break;
        case CONSTANT_Float:
            printf("bytes: 0x%x\t\t\t\t // ", jclass->constant_pool[i].info.number32Info.bytes);
            printFloat(jclass->constant_pool[i].info.number32Info.bytes);
            printf("\n");
            break;
        case CONSTANT_Long:
            printf("high bytes: 0x%08x, low bytes: 0x%08x\t // ",
                jclass->constant_pool[i].info.number64Info.high_bytes,
                jclass->constant_pool[i].info.number64Info.low_bytes);
            printLong(jclass->constant_pool[i].info.number64Info.high_bytes, jclass->constant_pool[i].info.number64Info.low_bytes);
            printf("\n");
            i++;
            break;
        case CONSTANT_Double:
            printf("high bytes: 0x%08x, low bytes: 0x%08x  \t // ",
                jclass->constant_pool[i].info.number64Info.high_bytes,
                jclass->constant_pool[i].info.number64Info.low_bytes);
            printDouble(jclass->constant_pool[i].info.number64Info.high_bytes, jclass->constant_pool[i].info.number64Info.low_bytes);
            printf("\n");
            i++;
            break;
        case CONSTANT_NameAndType:
            printf("name index: #%d, descriptor_index: #%d\t\t // ",
                jclass->constant_pool[i].info.nameAndTypeInfo.name_index,
                jclass->constant_pool[i].info.nameAndTypeInfo.descriptor_index);
            printNameAndType(i + 1, jclass);
            printf("\n");
            break;
        case CONSTANT_Utf8:
            printf("length: #%d, bytes: \"%s\"\n",
                jclass->constant_pool[i].info.utf8Info.length,
                jclass->constant_pool[i].info.utf8Info.bytes);
            break;

        case CONSTANT_MethodHandle:
            printf("reference kind: #%d, reference index: #%d\n",
                jclass->constant_pool[i].info.methodHandleInfo.reference_kind,
                jclass->constant_pool[i].info.methodHandleInfo.reference_index);
            break;
        case CONSTANT_MethodType:
            printf("descriptor index: #%d\n",
                jclass->constant_pool[i].info.methodTypeInfo.descriptor_index);
            break;
        case CONSTANT_InvokeDynamic:
            printf("bootstrap method attr index: #%d, name and type index: #%d\n",
                jclass->constant_pool[i].info.invokeDynamicInfo.bootstrap_method_attr_index,
                jclass->constant_pool[i].info.invokeDynamicInfo.name_and_type_index);
            break;
        }
    }
}

// Imprime o nome das flags presentes classe
void printAccessFlags(uint16_t access_flags, infotype type) {
    printf("Access Flags: (0x%04x)\n\t", access_flags);

    if (access_flags & ACC_PUBLIC)
        printf("Public ");
    if (access_flags & ACC_PRIVATE)
        printf("Private ");
    if (access_flags & ACC_PROTECTED)
        printf("Protected ");
    if (access_flags & ACC_STATIC)
        printf("Static ");
    if (access_flags & ACC_FINAL)
        printf("Final ");
    if (access_flags & ACC_SUPER)
        type == CLASS ? printf("Super ") : printf("Synchronized ");
    if (access_flags & ACC_BRIDGE)
        type == METHOD ? printf("Bridge ") : printf("Volatile ");
    if (access_flags & ACC_VARARGS)
        printf("Varargs ");
    if (access_flags & ACC_NATIVE)
        printf("Native ");
    if (access_flags & ACC_INTERFACE)
        printf("Interface ");
    if (access_flags & ACC_ABSTRACT)
        printf("Abstract ");
    if (access_flags & ACC_STRICT)
        printf("Strict ");
    if (access_flags & ACC_SYNTHETIC)
        printf("Synthetic ");
    if (access_flags & ACC_ANNOTATION)
        printf("Annotation ");
    if (access_flags & ACC_ENUM)
        printf("Enum ");
    printf("\n");
}

// Imprime o nome das interfaces
void printInterfaces(class_structure *jclass) {
    printf("\n------------------------------\n");
    printf("             INTERFACES         \n");
    printf("Interfaces Count: %d\n", jclass->interfaces_count);

    uint16_t interfaces_count = jclass->interfaces_count;

    if (interfaces_count > 0) {
        printf("Interfaces: \n");
        for (int i = 0; i < interfaces_count; i++) {
            printf("\t");
            printClassName(jclass->interfaces[i], jclass);
            printf("\n");
        }
    }
}

void printFields(class_structure *jclass) {
    printf("\n------------------------------\n");
    printf("             FIELDS             \n");
    printf("Fields Count: %d\n", jclass->fields_count);

    uint8_t fields_count = jclass->fields_count;

    for (int i = 0; i < fields_count; i++) {
        printf("\n------------------------------\n");
        printf("FIELD: %d\n", i + 1);
        // printf("Access Flag: %u\n", jclass->fields[i].access_flags);
        printAccessFlags(jclass->fields[i].access_flags, FIELD);
        printf("Name Index: #%u ", jclass->fields[i].name_index);
        printUtf8(jclass->fields[i].name_index, jclass);
        printf("\n");
        printf("Descriptor Index: %u\n", jclass->fields[i].descriptor_index);
        printf("Attribute Count: %u\n", jclass->fields[i].attributes_count);

        uint16_t attribute_count = jclass->fields[i].attributes_count;

        printAttributes(jclass->fields[i].attributes, attribute_count, jclass);
    }
}

void printMethods(class_structure *jclass) {
    printf("\n------------------------------\n");
    printf("             METHODS            \n");
    printf("Methods Count: %d\n", jclass->methods_count);
    uint8_t methods_count = jclass->methods_count;

    for (int i = 0; i < methods_count; i++) {
        printf("\n------------------------------\n");
        printf("METHOD: %d\n", i);
        // printf("Access Flag: %u\n", jclass->methods[i].access_flags);
        printAccessFlags(jclass->methods[i].access_flags, METHOD);
        printf("Name Index: #%u ", jclass->methods[i].name_index);
        printUtf8(jclass->methods[i].name_index, jclass);
        printf("\n");
        printf("Descriptor Index: %u\n", jclass->methods[i].descriptor_index);
        printf("Attribute Count: %u\n", jclass->methods[i].attributes_count);

        uint16_t attribute_count = jclass->methods[i].attributes_count;

        printAttributes(jclass->methods[i].attributes, attribute_count, jclass);
    }
}

// Imprime o nome de uma class a partir de seu índice
void printClassName(uint16_t index, class_structure *jclass) {
    uint16_t name_index = jclass->constant_pool[index - 1].info.classInfo.name_index;
    printf("%s", jclass->constant_pool[name_index - 1].info.utf8Info.bytes);
}

void printClassAttributes(class_structure *jclass) {
    printf("\n------------------------------\n");
    printf("        CLASS ATTRIBUTES        \n");
    printf("Class Attributes Count: %d\n", jclass->attributes_count);
    printAttributes(jclass->attribute, jclass->attributes_count, jclass);
}

void printUtf8(uint16_t index, class_structure *jclass) {
    printf("%s", jclass->constant_pool[index - 1].info.utf8Info.bytes);
}

void printAttributes(attribute_info *attr_info, uint16_t attribute_count, class_structure *jclass) {
    for (int i = 0; i < attribute_count; i++) {

        uint16_t name_index = attr_info[i].attribute_name_index;

        printf("Attribute: %d\n", i + 1);

        printf("\tname_index: #%u\t", attr_info[i].attribute_name_index);
        printf("//  ");
        printUtf8(attr_info[i].attribute_name_index, jclass);
        printf("\n");
        printf("\tattribute_length: %u\n", attr_info[i].attribute_length);

        char *attribute_type = (char *)malloc(
            (jclass->constant_pool[name_index - 1].info.utf8Info.length + 1) * sizeof(char *));

        if (attribute_type == NULL) {
            printf("Erro na alocacao!\n");
            exit(2);
        }

        strcpy(attribute_type, (char *)jclass->constant_pool[name_index - 1].info.utf8Info.bytes);

        printf("\tType: %s\n", (char *)jclass->constant_pool[name_index - 1].info.utf8Info.bytes);

        if (!strcmp(attribute_type, "Code")) {

            printCodes(attr_info[i].info.code_attribute, jclass);

        } else if (!strcmp(attribute_type, "ConstantValue")) {

            printf("\tConstant Value Index: %d\n", attr_info[i].info.constant_value_attribute.constantvalue_index);
        } else if (!strcmp(attribute_type, "Synthetic")) {
            // O synthetic não printa nada!
            continue;
        } else if (!strcmp(attribute_type, "Deprecated")) {
            // O deprecated não printa nada!
            continue;
        } else if (!strcmp(attribute_type, "LocalVariableTable")) {
            uint16_t local_variable_table_length = attr_info[i].info.localVariableTable_attribute.local_variable_table_length;
            printf("local_variable_table_length: %d\n", local_variable_table_length);
            for (int j = 0; j < local_variable_table_length; j++) {
                printf("Start PC: %d\n", attr_info[i].info.localVariableTable_attribute.local_variable_table[j].start_pc);
                printf("Length: %d\n", attr_info[i].info.localVariableTable_attribute.local_variable_table[j].length);
                printf("Descriptor Index: %d\n", attr_info[i].info.localVariableTable_attribute.local_variable_table[j].descriptor_index);
                printf("index: %d\n", attr_info[i].info.localVariableTable_attribute.local_variable_table[j].index);
            }

        }

        else if (!strcmp(attribute_type, "Exceptions")) {

            printf("number_of_oxceptions: %d\n", attr_info[i].info.exceptions_attribute.number_of_exceptions);

            for (int j = 0; i < attr_info[i].info.exceptions_attribute.number_of_exceptions; j++) {
                printf("excepetions_table[%d]: %d\n", j + 1, attr_info[i].info.exceptions_attribute.excepetions_table[j]);
            }

        } else if (!strcmp(attribute_type, "StackMapTable")) {
            printf("\tSem implementação\n");
        } else if (!strcmp(attribute_type, "BootstrapMethods")) {

            printf("Bootstrap Methods\n");
            printf("Num Bootstrap methods: %d\n", attr_info[i].info.bootstrapMethods_attributes.num_bootstrap_methods);

            for (int j = 0; j < attr_info[i].info.bootstrapMethods_attributes.num_bootstrap_methods; j++) {

                printf("\tMethod Ref: #%d\n", attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].bootstrap_method_ref);
                printf("\tNum bootstrap arguments: %d\n", attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].num_bootstrap_arguments);

                for (int k = 0; k < attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].num_bootstrap_arguments; k++) {

                    printf("\t\tBootstrap arguments: #%d", attr_info[i].info.bootstrapMethods_attributes.bootstrap_methods[j].bootstrap_arguments[k]);
                }
            }

        } else if (!strcmp(attribute_type, "Signature")) {

            printf("\tSignature Index: %d\n", attr_info[i].info.signature_attribute.signature_index);

        } else if (!strcmp(attribute_type, "LineNumberTable")) {
            int length             = attr_info[i].info.lineNumberTable_attribute.line_number_table_length;
            line_number_table *lnt = attr_info[i].info.lineNumberTable_attribute.line_number_table;

            printf("line_number_table_length: %d\n", length);
            printf("Nr\tStart\tLine Number\n");

            for (int j = 0; j < length; j++) {
                printf("%d\t%d\t%d\n", j, lnt[j].start_pc, lnt[j].line_number);
            }

        } else if (!strcmp(attribute_type, "SourceFile")) {

            uint16_t sourcefile_index = attr_info[i].info.sourceFile_attribute.sourcefile_index;
            printf("\tSourceFile Index: %s\n", jclass->constant_pool[sourcefile_index - 1].info.utf8Info.bytes);

        } else if (!strcmp(attribute_type, "InnerClasses")) {

            printf("number_of_classes: %d\n", attr_info[i].info.innerClasses_attribute.number_of_classes);

            for (int j = 0; j < attr_info[i].info.innerClasses_attribute.number_of_classes; j++) {
                printf("InnerClasses:\n");
                printf("#%d = ", attr_info[i].info.innerClasses_attribute.classes[j].inner_name_index);
                printf("#%d", attr_info[i].info.innerClasses_attribute.classes[j].inner_class_info_index);
                printf(" of #%d;", attr_info[i].info.innerClasses_attribute.classes[j].outer_class_info_index);
                printf(" //  ");
                printUtf8(attr_info[i].info.innerClasses_attribute.classes[j].inner_name_index, jclass);
                printf(" = ");
                printClassName(attr_info[i].info.innerClasses_attribute.classes[j].inner_class_info_index, jclass);
                printf(" of ");
                printClassName(attr_info[i].info.innerClasses_attribute.classes[j].outer_class_info_index, jclass);
                printf(";\n");
                printAccessFlags(attr_info[i].info.innerClasses_attribute.classes[j].inner_class_access_flags, CLASS);
            }
        } else {
            printf("\tDesconhecido!\n");
        }

        //Free na string auxiliar (serve apenas para realizar a comparacao dos tipos de atributo)
        free(attribute_type);
    }
}

void printCodes(code_attribute code_attribute, class_structure *jclass) {
    printf("Code:\n");
    printf("   stack=%d, locals=%d, args_size=\n", code_attribute.max_stack, code_attribute.max_locals);
    //printf("Max locals: %d\n", code_attribute.max_locals);
    //printf("Code Length: %d\n", code_attribute.code_length);

    for (int j = 0; j < code_attribute.code_length; j++) {
        printf("\t%d: ", j);
        j += printCode(code_attribute.code, j, jclass); //printOpcode retorna quantidade de Bytes lidos depois do opcode
        printf("\n");
    }

    printf("exception_table_length: %d \n", code_attribute.exception_table_length);

    for (int j = 0; j < code_attribute.exception_table_length; j++) {
        printf("EXCEPTION %d", j + 1);
        printf("\tstart_pc[%d]: %d\n", j + 1, code_attribute.exception_table[j].start_pc);
        printf("\tend_pc[%d]: %d\n", j + 1, code_attribute.exception_table[j].end_pc);
        printf("\thandler_pc[%d]: %d\n", j + 1, code_attribute.exception_table[j].handler_pc);
        printf("\tCatch Type: ");
        printClassName(code_attribute.exception_table[j].catch_type, jclass);
        printf("\n");
    }

    // Leitura dos atributos de cada atributo code (Sim, a parada é recursiva :o )
    printAttributes(code_attribute.attributes, code_attribute.attributes_count, jclass);
}

void printFloat(uint32_t bytes) {

    float number;
    if (bytes == 0x7f800000)
        printf("Inf\n");
    else if (bytes == 0xff800000)
        printf("-Inf\n");
    else if ((bytes >= 0x7f800001 && bytes <= 0x7fffffff) || (bytes > 0xff800001 && bytes <= 0xffffffff))
        printf("NaN\n");
    else {
        int s  = ((bytes >> 31) == 0) ? 1 : -1;
        int e  = ((bytes >> 23) & 0xff);
        int m  = (e == 0) ? (bytes & 0x7fffff) << 1 : (bytes & 0x7fffff) | 0x800000;
        number = s * m * pow(2, e - 150);
        printf("%f", number);
    }
}

void printDouble(uint32_t high, uint32_t low) {

    uint64_t bytes;
    double double_number;

    bytes = ((uint64_t)high << 32) + low;
    if (bytes == 0x7ff0000000000000L)
        printf("Inf\n");
    else if (bytes == 0xfff0000000000000L)
        printf("-Inf\n");
    else if ((bytes >= 0x7ff0000000000001L && bytes <= 0x7ffffffffffffL) || (bytes > 0xfff0000000000001L && bytes <= 0xffffffffffffffffL))
        printf("NaN\n");
    else {
        int s  = ((bytes >> 63) == 0) ? 1 : -1;
        int e  = ((bytes >> 52) & 0x7ffL);
        long m = (e == 0) ? (bytes & 0xfffffffffffffL) << 1 : (bytes & 0xfffffffffffffL) | 0x10000000000000L;

        double_number = s * m * pow(2, e - 1075);
        printf("%lf", double_number);
    }
}

void printLong(uint32_t high, uint32_t low) {
    uint64_t long_number = ((uint64_t)high << 32) + low;
    printf("%llu", (long long)long_number);
}

void printNameAndType(uint16_t name_type_index, class_structure *jclass) {
    uint16_t name_index = jclass->constant_pool[name_type_index - 1].info.nameAndTypeInfo.name_index;
    uint16_t type_index = jclass->constant_pool[name_type_index - 1].info.nameAndTypeInfo.descriptor_index;
    printf("%s", jclass->constant_pool[name_index - 1].info.utf8Info.bytes);
    printf(":");
    printf("%s", jclass->constant_pool[type_index - 1].info.utf8Info.bytes);
}

void printName(uint16_t name_type_index, class_structure *jclass) {
    uint16_t name_index = jclass->constant_pool[name_type_index - 1].info.nameAndTypeInfo.name_index;
    printf("%s", jclass->constant_pool[name_index - 1].info.utf8Info.bytes);
}

void printClassAndName(uint16_t method_index, class_structure *jclass) {
    printClassName(jclass->constant_pool[method_index - 1].info.refInfo.class_index, jclass);
    printf(".");
    uint16_t name_and_type_index = jclass->constant_pool[method_index - 1].info.refInfo.name_and_type_index;
    printName(name_and_type_index, jclass);
}

void printClassAndNameType(uint16_t method_index, class_structure *jclass) {
    printClassName(jclass->constant_pool[method_index - 1].info.refInfo.class_index, jclass);
    printf(".");
    uint16_t name_and_type_index = jclass->constant_pool[method_index - 1].info.refInfo.name_and_type_index;
    printNameAndType(name_and_type_index, jclass);
}

int printCode(uint8_t *code, int pc, class_structure *jclass) {
    uint8_t op = code[pc];

    printOpcode(op);

    if (op == BIPUSH) {
        printf(" %d", (int8_t)code[pc + 1]);
        return 1;
    } else if (op == SIPUSH) {
        uint16_t value = build16(code[pc + 1], code[pc + 2]);
        printf(" %d", value);
        return 2;
    } else if (op == LDC) {
        uint16_t ref = build16(0, code[pc + 1]);
        printf(" #%d // ", ref);
        printConstantPoolValue(ref - 1, jclass);
        return 1;
    } else if (op == LDC_W || op == LDC2_W) {
        uint16_t ref = build16(code[pc + 1], code[pc + 2]);
        printf(" #%d // ", ref);
        printConstantPoolValue(ref - 1, jclass);
        return 2;
    } else if (op >= ILOAD && op <= ALOAD) {
        printf(" %d ", code[pc + 1]);
        return 1;
    } else if (op >= ISTORE && op <= ASTORE) {
        printf(" %d ", code[pc + 1]);
        return 1;
    } else if (op == IINC) {
        printf(" %d, %d", code[pc + 1], code[pc + 2]);
        return 2;
    } else if (op >= IFEQ && op <= JSR) {
        uint16_t offset = build16(code[pc + 1], code[pc + 2]);
        printf(" %d (%d)", (int16_t)(pc + offset), (int16_t)offset);
        return 2;
    } else if (op == RET) {
        printf(" %d ", code[pc + 1]);
        return 1;
    } else if (op == TABLESWITCH) {
        int resto     = 3 - (pc % 4);
        int pc_offset = resto + pc;

        uint32_t default_variable = build32(code[pc_offset + 1], code[pc_offset + 2], code[pc_offset + 3], code[pc_offset + 4]);
        uint32_t low_variable     = build32(code[pc_offset + 5], code[pc_offset + 6], code[pc_offset + 7], code[pc_offset + 8]);
        uint32_t high_variable    = build32(code[pc_offset + 9], code[pc_offset + 10], code[pc_offset + 11], code[pc_offset + 12]);

        uint32_t return_amount = 0xFFFF;

        printf(" %d to %d\n", low_variable, high_variable);
        for (int j = 0; j < high_variable - low_variable + 1; j++) {
            int aux_off     = resto + pc + j * 4;
            int jump_amount = build32(code[aux_off + 13], code[aux_off + 14], code[aux_off + 15], code[aux_off + 16]);
            printf("\t\t%d: %d (+%d)\n", j + low_variable, jump_amount + pc, jump_amount);

            if (return_amount > jump_amount) return_amount = jump_amount;
        }
        printf("\t\tdefault: %d (+%d)", pc + default_variable, default_variable);
        return (return_amount - 1);
    } else if (op == LOOKUPSWITCH) {
        int resto     = 3 - (pc % 4);
        int pc_offset = resto + pc;

        uint32_t default_variable = build32(code[pc_offset + 1], code[pc_offset + 2], code[pc_offset + 3], code[pc_offset + 4]);
        uint32_t n_pairs          = build32(code[pc_offset + 5], code[pc_offset + 6], code[pc_offset + 7], code[pc_offset + 8]);

        uint32_t return_amount = 0xFFFF;

        printf(" // %d\n", n_pairs);
        for (int j = 0; j < n_pairs * 2; j += 2) {
            int aux_off     = resto + pc + j * 4;
            int index       = build32(code[aux_off + 9], code[aux_off + 10], code[aux_off + 11], code[aux_off + 12]);
            int jump_amount = build32(code[aux_off + 13], code[aux_off + 14], code[aux_off + 15], code[aux_off + 16]);
            printf("\t\t%d: %d (+%d)\n", index, jump_amount + pc, jump_amount);

            if (return_amount > jump_amount) return_amount = jump_amount;
        }
        printf("\t\tdefault: %d (+%d)\n", pc + default_variable, default_variable);
        return (return_amount - 1);
    } else if (op >= GETSTATIC && op <= INVOKESTATIC) {
        uint16_t ref = build16(code[pc + 1], code[pc + 2]);
        printf(" #%d ", ref);
        printClassAndName(ref, jclass);
        return 2;
    } else if (op == INVOKEINTERFACE) {
        uint16_t ref = build16(code[pc + 1], code[pc + 2]);
        printf(" #%d ", ref);
        printConstantPoolValue(ref - 1, jclass);
        printf(" count %d ", code[pc + 3]);
        return 4;
    } else if (op == INVOKEDYNAMIC) {
        uint16_t ref = build16(code[pc + 1], code[pc + 2]);
        printf(" #%d ", ref);
        printConstantPoolValue(ref - 1, jclass);
        return 4;
    } else if (op == NEW || op == ANEWARRAY || op == CHECKCAST || op == INSTANCEOF) {
        uint16_t ref = build16(code[pc + 1], code[pc + 2]);
        printf(" #%d // ", ref);
        printConstantPoolValue(ref - 1, jclass);
        return 2;
    } else if (op == NEWARRAY) {
        uint8_t ref = code[pc + 1];
        printf(" #%d ", ref);
        printPrimitiveType(ref);
        return 1;
    } else if (op == WIDE) {
        uint8_t opcode = code[pc + 1];
        //Falta saber se é isso que printa mesmo
        if (opcode == IINC) {
            printOpcode(opcode);
            uint16_t index = build16(code[pc + 2], code[pc + 3]);
            printf("index: #%d ", index);
            uint16_t constbyte = build16(code[pc + 4], code[pc + 5]);
            printf("constbyte: #%d ", constbyte);
            return 5;
        } else {
            printOpcode(opcode);
            uint16_t index = build16(code[pc + 2], code[pc + 3]);
            printf("index: #%d ", index);
            return 3;
        }
    } else if (op == MULTIANEWARRAY) {
        uint16_t ref = build16(code[pc + 1], code[pc + 2]);
        printf(" #%d ", ref);
        printConstantPoolValue(ref - 1, jclass);
        printf(" dim %d", code[pc + 3]);
        return 3;
    } else if (op == IFNULL || op == IFNONNULL) {
        uint16_t offset = build16(code[pc + 1], code[pc + 2]);
        printf(" %d (%d)", (int16_t)(pc + offset), (int16_t)offset);
        return 2;
    } else if (op == GOTO_W || op == JSR_W) {
        uint32_t offset = build32(code[pc + 1], code[pc + 2], code[pc + 3], code[pc + 4]);
        printf(" %d (%d)", (int32_t)(pc + offset), (int32_t)offset);
        return 4;
    } else {
        return 0;
    }

    return 0;
}

void printConstantPoolValue(int i, class_structure *jclass) {
    switch (jclass->constant_pool[i].tag) {
    case CONSTANT_String:
        // printf("String ");
        printUtf8(jclass->constant_pool[i].info.stringInfo.string_index, jclass);
        break;
    case CONSTANT_Integer:
        // printf("Integer ");
        printf("%d", (int32_t)jclass->constant_pool[i].info.number32Info.bytes);
        break;
    case CONSTANT_Float:
        // printf("Float ");
        printFloat(jclass->constant_pool[i].info.number32Info.bytes);
        break;
    case CONSTANT_Class:
        // printf("Class ");
        printUtf8(jclass->constant_pool[i].info.classInfo.name_index, jclass);
        break;
    case CONSTANT_MethodType:
        printf("descriptor index: #%d\n",
            jclass->constant_pool[i].info.methodTypeInfo.descriptor_index);
        break;
    case CONSTANT_MethodHandle:
        printf("reference kind: #%d, reference index: #%d\n",
            jclass->constant_pool[i].info.methodHandleInfo.reference_kind,
            jclass->constant_pool[i].info.methodHandleInfo.reference_index);
        break;
    case CONSTANT_Long:
        // printf("Long ");
        printLong(jclass->constant_pool[i].info.number64Info.high_bytes, jclass->constant_pool[i].info.number64Info.low_bytes);
        break;
    case CONSTANT_Double:
        // printf("Double ");
        printDouble(jclass->constant_pool[i].info.number64Info.high_bytes, jclass->constant_pool[i].info.number64Info.low_bytes);
        break;
    case CONSTANT_Fieldref:
    case CONSTANT_Methodref:
    case CONSTANT_InterfaceMethodref:
        printClassName(jclass->constant_pool[i].info.refInfo.class_index, jclass);
        printf(".");
        printNameAndType(jclass->constant_pool[i].info.refInfo.name_and_type_index, jclass);
        break;
    }
}

void printConstantDouble(uint16_t ref, class_structure *jclass) {
    uint32_t hi  = jclass->constant_pool[ref - 1].info.number64Info.high_bytes;
    uint32_t low = jclass->constant_pool[ref - 1].info.number64Info.low_bytes;
    printDouble(hi, low);
}

void printVersion(uint16_t major, uint16_t minor) {
    if (major == 45 && minor == 3)
        printf("Java 1(.0.2)");
    else if (major == 45 && minor == 3)
        printf("Java 1.1");
    else {
        switch (major) {
        case 46:
            printf("Java 1.2");
            break;
        case 47:
            printf("Java 1.3");
            break;
        case 48:
            printf("Java 1.4");
            break;
        case 49:
            printf("Java 5");
            break;
        case 50:
            printf("Java 6");
            break;
        case 51:
            printf("Java 7");
            break;
        case 52:
            printf("Java 8");
            break;
        default:
            printf("Versão desconhecida");
        }
    }
}
