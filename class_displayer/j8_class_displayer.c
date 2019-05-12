//j8_class_displayer.c 
#include "j8_class_displayer.h"
#include <string.h>

//de acordo com a tag do constant pool, altera a string tagType para o significado
void cpTagToString(uint8_t tag, char *tagType){
    switch(tag){
        case 7:
            strcpy(tagType,"Class");
            break;
        case 9:
            strcpy(tagType,"Fieldref");
            break;
        case 10:
            strcpy(tagType,"Methodref");
            break;
        case 11:
            strcpy(tagType,"InterfaceMethdref");
            break;
        case 8:
            strcpy(tagType,"String");
            break;
        case 3:
            strcpy(tagType,"Integer");
            break;
        case 4:
            strcpy(tagType,"Float");
            break;
        case 5:
            strcpy(tagType,"Long");
            break;
        case 6:
            strcpy(tagType,"Double");
            break;
        case 12:
            strcpy(tagType,"NameAndType");
            break;
        case 1:
            strcpy(tagType,"Utf8");
            break;
        case 15:
            strcpy(tagType,"MethodHandle");
            break;
        case 16:
            strcpy(tagType,"MethodType");
            break;
        case 18:
            strcpy(tagType,"InvokeDynamic");
    }
}

//percorre a struct da classe e imprime todos os dados
void printConstantPool(FILE* class_file, class_structure* jclass){

    char tagType[18];
    printf("Mostrando o conteúdo do constant pool:\n");
    for(int i = 0; i < jclass->constant_pool_count-1 ; i++){

        cpTagToString(jclass->constant_pool[i].tag, tagType);
        printf("\t#%d: %-18s\t",(i+1),tagType); 

        switch(jclass->constant_pool[i].tag){
            case CONSTANT_Class:
                printf("name Index: #%d\n",jclass->constant_pool[i].info.classInfo.name_index);
                break;
            case CONSTANT_Fieldref:
            case CONSTANT_Methodref:
            case CONSTANT_InterfaceMethodref:
                printf("class index: #%d, ",jclass->constant_pool[i].info.refInfo.class_index);
                printf("name and type index: #%d\n",jclass->constant_pool[i].info.refInfo.name_and_type_index);
                break;
            case CONSTANT_String:
                printf("string index: #%d\n",jclass->constant_pool[i].info.stringInfo.string_index);
                break;
            case CONSTANT_Integer:
            case CONSTANT_Float:
                printf("bytes: #%x\n",jclass->constant_pool[i].info.number32Info.bytes);
                break;
            case CONSTANT_Long:
            case CONSTANT_Double:
                printf("high bytes: 0x%x, low bytes: 0x%x\n",
                    jclass->constant_pool[i].info.number64Info.high_bytes,
                    jclass->constant_pool[i].info.number64Info.low_bytes
                );
                break;
            case CONSTANT_NameAndType:
                printf("name index: #%d, descriptor_index: #%d\n",
                        jclass->constant_pool[i].info.nameAndTypeInfo.name_index,
                        jclass->constant_pool[i].info.nameAndTypeInfo.descriptor_index
                      );
                 break;
            case CONSTANT_Utf8:
                printf("length: #%d, bytes: \"%s\"\n",
                    jclass->constant_pool[i].info.utf8Info.length,
                    jclass->constant_pool[i].info.utf8Info.bytes 
                ); 
                break;
                
            case CONSTANT_MethodHandle:
                printf("reference kind: #%d, reference index: #%d\n",
                    jclass->constant_pool[i].info.methodHandleInfo.reference_kind,
                    jclass->constant_pool[i].info.methodHandleInfo.reference_index
                ); 
                break;
            case CONSTANT_MethodType:
                printf("descriptor index: #%d\n",
                    jclass->constant_pool[i].info.methodTypeInfo.descriptor_index
                ); 
                break;
            case CONSTANT_InvokeDynamic:
                printf("bootstrap method attr index: #%d, name and type index: #%d\n",
                    jclass->constant_pool[i].info.invokeDynamicInfo.bootstrap_method_attr_index,
                    jclass->constant_pool[i].info.invokeDynamicInfo.name_and_type_index 
                ); 
                break;
        } 
    } 
}
