#include "opcode.h"
#include <stdio.h>

void printOpcode(uint8_t op){

    switch(op){
        case NOP: printf("NOP"); break;
        case ACONST_NULL: printf("ACONST_NULL"); break;
        case ICONST_M1: printf("ICONST_M1"); break;
        case ICONST_0: printf("ICONST_0"); break;
        case ICONST_1: printf("ICONST_1"); break;
        case ICONST_2: printf("ICONST_2"); break;
        case ICONST_3: printf("ICONST_3"); break;
        case ICONST_4: printf("ICONST_4"); break;
        case ICONST_5: printf("ICONST_5"); break;
        case LCONST_0: printf("LCONST_0"); break;
        case LCONST_1: printf("LCONST_1"); break;
        case FCONST_0: printf("FCONST_0"); break;
        case FCONST_1: printf("FCONST_1"); break;
        case FCONST_2: printf("FCONST_2"); break;
        case DCONST_0: printf("DCONST_0"); break;
        case DCONST_1: printf("DCONST_1"); break;
        case BIPUSH: printf("BIPUSH"); break;
        case SIPUSH: printf("SIPUSH"); break;
        case LDC: printf("LDC"); break;
        case LDC_W: printf("LDC_W"); break;
        case LDC2_W: printf("LDC2_W"); break;
        case ILOAD: printf("ILOAD"); break;
        case LLOAD: printf("LLOAD"); break;
        case FLOAD: printf("FLOAD"); break;
        case DLOAD: printf("DLOAD"); break;
        case ALOAD: printf("ALOAD"); break;
        case ILOAD_0: printf("ILOAD_0"); break;
        case ILOAD_1: printf("ILOAD_1"); break;
        case ILOAD_2: printf("ILOAD_2"); break;
        case ILOAD_3: printf("ILOAD_3"); break;
        case LLOAD_0: printf("LLOAD_0"); break;
        case LLOAD_1: printf("LLOAD_1"); break;
        case LLOAD_2: printf("LLOAD_2"); break;
        case LLOAD_3: printf("LLOAD_3"); break;
        case FLOAD_0: printf("FLOAD_0"); break;
        case FLOAD_1: printf("FLOAD_1"); break;
        case FLOAD_2: printf("FLOAD_2"); break;
        case FLOAD_3: printf("FLOAD_3"); break;
        case DLOAD_0: printf("DLOAD_0"); break;
        case DLOAD_1: printf("DLOAD_1"); break;
        case DLOAD_2: printf("DLOAD_2"); break;
        case DLOAD_3: printf("DLOAD_3"); break;
        case ALOAD_0: printf("ALOAD_0"); break;
        case ALOAD_1: printf("ALOAD_1"); break;
        case ALOAD_2: printf("ALOAD_2"); break;
        case ALOAD_3: printf("ALOAD_3"); break;
        case IALOAD: printf("IALOAD"); break;
        case LALOAD: printf("LALOAD"); break;
        case FALOAD: printf("FALOAD"); break;
        case DALOAD: printf("DALOAD"); break;
        case AALOAD: printf("AALOAD"); break;
        case BALOAD: printf("BALOAD"); break;
        case CALOAD: printf("CALOAD"); break;
        case SALOAD: printf("SALOAD"); break;
        case ISTORE: printf("ISTORE"); break;
        case LSTORE: printf("LSTORE"); break;
        case FSTORE: printf("FSTORE"); break;
        case DSTORE: printf("DSTORE"); break;
        case ASTORE: printf("ASTORE"); break;
        case ISTORE_0: printf("ISTORE_0"); break;
        case ISTORE_1: printf("ISTORE_1"); break;
        case ISTORE_2: printf("ISTORE_2"); break;
        case ISTORE_3: printf("ISTORE_3"); break;
        case LSTORE_0: printf("LSTORE_0"); break;
        case LSTORE_1: printf("LSTORE_1"); break;
        case LSTORE_2: printf("LSTORE_2"); break;
        case LSTORE_3: printf("LSTORE_3"); break;
        case FSTORE_0: printf("FSTORE_0"); break;
        case FSTORE_1: printf("FSTORE_1"); break;
        case FSTORE_2: printf("FSTORE_2"); break;
        case FSTORE_3: printf("FSTORE_3"); break;
        case DSTORE_0: printf("DSTORE_0"); break;
        case DSTORE_1: printf("DSTORE_1"); break;
        case DSTORE_2: printf("DSTORE_2"); break;
        case DSTORE_3: printf("DSTORE_3"); break;
        case ASTORE_0: printf("ASTORE_0"); break;
        case ASTORE_1: printf("ASTORE_1"); break;
        case ASTORE_2: printf("ASTORE_2"); break;
        case ASTORE_3: printf("ASTORE_3"); break;
        case IASTORE: printf("IASTORE"); break;
        case LASTORE: printf("LASTORE"); break;
        case FASTORE: printf("FASTORE"); break;
        case DASTORE: printf("DASTORE"); break;
        case AASTORE: printf("AASTORE"); break;
        case BASTORE: printf("BASTORE"); break;
        case CASTORE: printf("CASTORE"); break;
        case SASTORE: printf("SASTORE"); break;
        case POP: printf("POP"); break;
        case POP2: printf("POP2"); break;
        case DUP: printf("DUP"); break;
        case DUP_X1: printf("DUP_X1"); break;
        case DUP_X2: printf("DUP_X2"); break;
        case DUP2: printf("DUP2"); break;
        case DUP2_X1: printf("DUP2_X1"); break;
        case DUP2_X2: printf("DUP2_X2"); break;
        case SWAP: printf("SWAP"); break;
        case IADD: printf("IADD"); break;
        case LADD: printf("LADD"); break;
        case FADD: printf("FADD"); break;
        case DADD: printf("DADD"); break;
        case ISUB: printf("ISUB"); break;
        case LSUB: printf("LSUB"); break;
        case FSUB: printf("FSUB"); break;
        case DSUB: printf("DSUB"); break;
        case IMUL: printf("IMUL"); break;
        case LMUL: printf("LMUL"); break;
        case FMUL: printf("FMUL"); break;
        case DMUL: printf("DMUL"); break;
        case IDIV: printf("IDIV"); break;
        case LDIV: printf("LDIV"); break;
        case FDIV: printf("FDIV"); break;
        case DDIV: printf("DDIV"); break;
        case IREM: printf("IREM"); break;
        case LREM: printf("LREM"); break;
        case FREM: printf("FREM"); break;
        case DREM: printf("DREM"); break;
        case INEG: printf("INEG"); break;
        case LNEG: printf("LNEG"); break;
        case FNEG: printf("FNEG"); break;
        case DNEG: printf("DNEG"); break;
        case ISHL: printf("ISHL"); break;
        case LSHL: printf("LSHL"); break;
        case ISHR: printf("ISHR"); break;
        case LSHR: printf("LSHR"); break;
        case IUSHR: printf("IUSHR"); break;
        case LUSHR: printf("LUSHR"); break;
        case IAND: printf("IAND"); break;
        case LAND: printf("LAND"); break;
        case IOR: printf("IOR"); break;
        case LOR: printf("LOR"); break;
        case IXOR: printf("IXOR"); break;
        case LXOR: printf("LXOR"); break;
        case IINC: printf("IINC"); break;
        case I2L: printf("I2L"); break;
        case I2F: printf("I2F"); break;
        case I2D: printf("I2D"); break;
        case L2I: printf("L2I"); break;
        case L2F: printf("L2F"); break;
        case L2D: printf("L2D"); break;
        case F2I: printf("F2I"); break;
        case F2L: printf("F2L"); break;
        case F2D: printf("F2D"); break;
        case D2I: printf("D2I"); break;
        case D2L: printf("D2L"); break;
        case D2F: printf("D2F"); break;
        case I2B: printf("I2B"); break;
        case I2C: printf("I2C"); break;
        case I2S: printf("I2S"); break;
        case LCMP: printf("LCMP"); break;
        case FCMPL: printf("FCMPL"); break;
        case FCMPG: printf("FCMPG"); break;
        case DCMPL: printf("DCMPL"); break;
        case DCMPG: printf("DCMPG"); break;
        case IFEQ: printf("IFEQ"); break;
        case IFNE: printf("IFNE"); break;
        case IFLT: printf("IFLT"); break;
        case IFGE: printf("IFGE"); break;
        case IFGT: printf("IFGT"); break;
        case IFLE: printf("IFLE"); break;
        case IF_ICMPEQ: printf("IF_ICMPEQ"); break;
        case IF_ICMPNE: printf("IF_ICMPNE"); break;
        case IF_ICMPLT: printf("IF_ICMPLT"); break;
        case IF_ICMPGE: printf("IF_ICMPGE"); break;
        case IF_ICMPGT: printf("IF_ICMPGT"); break;
        case IF_ICMPLE: printf("IF_ICMPLE"); break;
        case IF_ACMPEQ: printf("IF_ACMPEQ"); break;
        case IF_ACMPNE: printf("IF_ACMPNE"); break;
        case GOTO: printf("GOTO"); break;
        case JSR: printf("JSR"); break;
        case RET: printf("RET"); break;
        case TABLESWITCH: printf("TABLESWITCH"); break;
        case LOOKUPSWITCH: printf("LOOKUPSWITCH"); break;
        case IRETURN: printf("IRETURN"); break;
        case LRETURN: printf("LRETURN"); break;
        case FRETURN: printf("FRETURN"); break;
        case DRETURN: printf("DRETURN"); break;
        case ARETURN: printf("ARETURN"); break;
        case RETURN: printf("RETURN"); break;
        case GETSTATIC: printf("GETSTATIC"); break;
        case PUTSTATIC: printf("PUTSTATIC"); break;
        case GETFIELD: printf("GETFIELD"); break;
        case PUTFIELD: printf("PUTFIELD"); break;
        case INVOKEVIRTUAL: printf("INVOKEVIRTUAL"); break;
        case INVOKESPECIAL: printf("INVOKESPECIAL"); break;
        case INVOKESTATIC: printf("INVOKESTATIC"); break;
        case INVOKEINTERFACE: printf("INVOKEINTERFACE"); break;
        case INVOKEDYNAMIC: printf("INVOKEDYNAMIC"); break;
        case NEW: printf("NEW"); break;
        case NEWARRAY: printf("NEWARRAY"); break;
        case ANEWARRAY: printf("ANEWARRAY"); break;
        case ARRAYLENGTH: printf("ARRAYLENGTH"); break;
        case ATHROW: printf("ATHROW"); break;
        case CHECKCAST: printf("CHECKCAST"); break;
        case INSTANCEOF: printf("INSTANCEOF"); break;
        case MONITORENTER: printf("MONITORENTER"); break;
        case MONITOREXIT: printf("MONITOREXIT"); break;
        case WIDE: printf("WIDE"); break;
        case MULTIANEWARRAY: printf("MULTIANEWARRAY"); break;
        case IFNULL: printf("IFNULL"); break;
        case IFNONNULL: printf("IFNONNULL"); break;
        case GOTO_W: printf("GOTO_W"); break;
        case JSR_W: printf("JSR_W"); break;
        case BREAKPOINT: printf("BREAKPOINT"); break;
        case IMPDEP1: printf("IMPDEP1"); break;
        case IMPDEP2: printf("IMPDEP2"); break;
        default: printf("OPCODE não encontrado");
    }
}
