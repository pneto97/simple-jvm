#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include <stdio.h>

void Nop         ();
void Aconst_null ();
void Iconst_m1   ();
void Iconst_0    ();
void Iconst_1    ();
void Iconst_2    ();
void Iconst_3    ();
void Iconst_4    ();
void Iconst_5    ();
void Lconst_0    ();
void Lconst_1    ();
void Fconst_0    ();
void Fconst_1    ();
void Fconst_2    ();
void Dconst_0    ();
void Dconst_1    ();
void Bipush      ();
void Sipush      ();
void Ldc         ();
void Ldc_w       ();
void Ldc2_w      ();
void Iload  ();
void Lload  ();
void Fload  ();
void Dload  ();
void Aload  ();
void Iload_0();
void Iload_1();
void Iload_2();
void Iload_3();
void Lload_0();
void Lload_1();
void Lload_2();
void Lload_3();
void Fload_0();
void Fload_1();
void Fload_2();
void Fload_3();
void Dload_0();
void Dload_1();
void Dload_2();
void Dload_3();
void Aload_0();
void Aload_1();
void Aload_2();
void Aload_3();
void Iaload ();
void Laload ();
void Faload ();
void Daload ();
void Aaload ();
void Baload ();
void Caload ();
void Saload ();
void Istore   ();
void Lstore   ();
void Fstore   ();
void Dstore   ();
void Astore   ();
void Istore_0 ();
void Istore_1 ();
void Istore_2 ();
void Istore_3 ();
void Lstore_0 ();
void Lstore_1 ();
void Lstore_2 ();
void Lstore_3 ();
void Fstore_0 ();
void Fstore_1 ();
void Fstore_2 ();
void Fstore_3 ();
void Dstore_0 ();
void Dstore_1 ();
void Dstore_2 ();
void Dstore_3 ();
void Astore_0 ();
void Astore_1 ();
void Astore_2 ();
void Astore_3 ();
void Iastore  ();
void Lastore  ();
void Fastore  ();
void Dastore  ();
void Aastore  ();
void Bastore  ();
void Castore  ();
void Sastore  ();
void Pop      ();
void Pop2     ();
void Dup      ();
void Dup_x1   ();
void Dup_x2   ();
void Dup2     ();
void Dup2_x1  ();
void Dup2_x2  ();
void Swap     ();
void Iadd   (); 
void Ladd   (); 
void Fadd   (); 
void Dadd   (); 
void Isub   (); 
void Lsub   (); 
void Fsub   (); 
void Dsub   (); 
void Imul   (); 
void Lmul   (); 
void Fmul   (); 
void Dmul   (); 
void Idiv   (); 
void Ldiv   (); 
void Fdiv   (); 
void Ddiv   (); 
void Irem   (); 
void Lrem   (); 
void Frem   (); 
void Drem   (); 
void Ineg   (); 
void Lneg   (); 
void Fneg   (); 
void Dneg   (); 
void Ishl   (); 
void Lshl   (); 
void Ishr   (); 
void Lshr   (); 
void Iushr   ();
void Lushr   ();
void Iand   (); 
void Land   (); 
void Ior    (); 
void Lor    (); 
void Ixor   (); 
void Lxor   (); 
void Iinc   ();
void I2l ();
void I2f ();
void I2d ();
void L2i ();
void L2f ();
void L2d ();
void F2i ();
void F2l ();
void F2d ();
void D2i ();
void D2l ();
void D2f ();
void I2b ();
void I2c ();
void I2s ();
void Lcmp     ();
void Fcmpl    ();
void Fcmpg    ();
void Dcmpl    ();
void Dcmpg    ();
void Ifeq     ();
void Ifne     ();
void Iflt     ();
void Ifge     ();
void Ifgt     ();
void Ifle     ();
void If_icmpeq();
void If_icmpne();
void If_icmplt();
void If_icmpge();
void If_icmpgt();
void If_icmple();
void If_acmpeq();
void If_acmpne();
void GoTo        ();
void Jsr         ();
void Ret         ();
void Tableswitch ();
void Lookupswitch();
void Ireturn     ();
void Lreturn     ();
void Freturn     ();
void Dreturn     ();
void Areturn     ();
void Return      ();
void Getstatic      ();
void Putstatic      ();
void Getfield       ();
void Putfield       ();
void Invokevirtual  ();
void Invokespecial  ();
void Invokestatic   ();
void Invokeinterface();
void Invokedynamic  ();
void New            ();
void Newarray       ();
void Anewarray();
void Arraylength();
void Athrow();
void Checkcast();
void Instanceof();
void Monitorenter   ();
void Monitorexit();
void Wide            ();
void Multianewarray();
void Ifnull();
void Ifnonnull();
void Goto_w();
void Jsr_w();
void Breakpoint();
void Impdep1();
void Impdep2();

void (*inst_vector[256])() = {
Nop         	/*0x00 */,
Aconst_null 	/*0x01 */,
Iconst_m1   	/*0x02 */,
Iconst_0    	/*0x03 */,
Iconst_1    	/*0x04 */,
Iconst_2    	/*0x05 */,
Iconst_3    	/*0x06 */,
Iconst_4    	/*0x07 */,
Iconst_5    	/*0x08 */,
Lconst_0    	/*0x09 */,
Lconst_1    	/*0x0a */,
Fconst_0    	/*0x0b */,
Fconst_1    	/*0x0c */,
Fconst_2    	/*0x0d */,
Dconst_0    	/*0x0e */,
Dconst_1    	/*0x0f */,
Bipush      	/*0x10 */,
Sipush      	/*0x11 */,
Ldc         	/*0x12 */,
Ldc_w       	/*0x13 */,
Ldc2_w      	/*0x14 */,
Iload       	/*0x15 */,
Lload       	/*0x16 */,
Fload       	/*0x17 */,
Dload       	/*0x18 */,
Aload       	/*0x19 */,
Iload_0     	/*0x1a */,
Iload_1     	/*0x1b */,
Iload_2     	/*0x1c */,
Iload_3     	/*0x1d */,
Lload_0     	/*0x1e */,
Lload_1     	/*0x1f */,
Lload_2     	/*0x20 */,
Lload_3     	/*0x21 */,
Fload_0     	/*0x22 */,
Fload_1     	/*0x23 */,
Fload_2     	/*0x24 */,
Fload_3     	/*0x25 */,
Dload_0     	/*0x26 */,
Dload_1     	/*0x27 */,
Dload_2     	/*0x28 */,
Dload_3     	/*0x29 */,
Aload_0     	/*0x2a */,
Aload_1     	/*0x2b */,
Aload_2     	/*0x2c */,
Aload_3     	/*0x2d */,
Iaload      	/*0x2e */,
Laload      	/*0x2f */,
Faload      	/*0x30 */,
Daload      	/*0x31 */,
Aaload      	/*0x32 */,
Baload      	/*0x33 */,
Caload      	/*0x34 */,
Saload      	/*0x35 */,
Lstore      	/*0x37 */,
Istore      	/*0x36 */,
Fstore      	/*0x38 */,
Dstore      	/*0x39 */,
Astore      	/*0x3a */,
Istore_0    	/*0x3b */,
Istore_1    	/*0x3c */,
Istore_2    	/*0x3d */,
Istore_3    	/*0x3e */,
Lstore_0    	/*0x3f */,
Lstore_1    	/*0x40 */,
Lstore_2    	/*0x41 */,
Lstore_3    	/*0x42 */,
Fstore_0    	/*0x43 */,
Fstore_1    	/*0x44 */,
Fstore_2    	/*0x45 */,
Fstore_3    	/*0x46 */,
Dstore_0    	/*0x47 */,
Dstore_1    	/*0x48 */,
Dstore_2    	/*0x49 */,
Dstore_3    	/*0x4a */,
Astore_0    	/*0x4b */,
Astore_1    	/*0x4c */,
Astore_2    	/*0x4d */,
Astore_3    	/*0x4e */,
Iastore     	/*0x4f */,
Lastore     	/*0x50 */,
Fastore     	/*0x51 */,
Dastore     	/*0x52 */,
Aastore     	/*0x53 */,
Bastore     	/*0x54 */,
Castore     	/*0x55 */,
Sastore     	/*0x56 */,
Pop         	/*0x57 */,
Pop2        	/*0x58 */,
Dup         	/*0x59 */,
Dup_x1      	/*0x5a */,
Dup_x2      	/*0x5b */,
Dup2        	/*0x5c */,
Dup2_x1     	/*0x5d */,
Dup2_x2     	/*0x5e */,
Swap        	/*0x5f */,
Iadd        	/*0x60 */,
Ladd        	/*0x61 */,
Fadd        	/*0x62 */,
Dadd        	/*0x63 */,
Isub        	/*0x64 */,
Lsub        	/*0x65 */,
Fsub        	/*0x66 */,
Dsub        	/*0x67 */,
Imul        	/*0x68 */,
Lmul        	/*0x69 */,
Fmul        	/*0x6a */,
Dmul        	/*0x6b */,
Idiv        	/*0x6c */,
Ldiv        	/*0x6d */,
Fdiv        	/*0x6e */,
Ddiv        	/*0x6f */,
Irem        	/*0x70 */,
Lrem        	/*0x71 */,
Frem        	/*0x72 */,
Drem        	/*0x73 */,
Ineg        	/*0x74 */,
Lneg        	/*0x75 */,
Fneg        	/*0x76 */,
Dneg        	/*0x77 */,
Ishl        	/*0x78 */,
Lshl        	/*0x79 */,
Ishr        	/*0x7a */,
Lshr        	/*0x7b */,
Iushr       	/*0x7c */,
Lushr       	/*0x7d */,
Iand        	/*0x7e */,
Land        	/*0x7f */,
Ior         	/*0x80 */,
Lor         	/*0x81 */,
Ixor        	/*0x82 */,
Lxor        	/*0x83 */,
Iinc        	/*0x84 */,
I2l         	/*0x85 */,
I2f         	/*0x86 */,
I2d         	/*0x87 */,
L2i         	/*0x88 */,
L2f         	/*0x89 */,
L2d         	/*0x8a */,
F2i         	/*0x8b */,
F2l         	/*0x8c */,
F2d         	/*0x8d */,
D2i         	/*0x8e */,
D2l         	/*0x8f */,
D2f         	/*0x90 */,
I2b         	/*0x91 */,
I2c         	/*0x92 */,
I2s         	/*0x93 */,
Lcmp        	/*0x94 */,
Fcmpl       	/*0x95 */,
Fcmpg       	/*0x96 */,
Dcmpl       	/*0x97 */,
Dcmpg       	/*0x98 */,
Ifeq        	/*0x99 */,
Ifne        	/*0x9a */,
Iflt        	/*0x9b */,
Ifge        	/*0x9c */,
Ifgt        	/*0x9d */,
Ifle        	/*0x9e */,
If_icmpeq   	/*0x9f */,
If_icmpne   	/*0xa0 */,
If_icmplt   	/*0xa1 */,
If_icmpge   	/*0xa2 */,
If_icmpgt   	/*0xa3 */,
If_icmple   	/*0xa4 */,
If_acmpeq   	/*0xa5 */,
If_acmpne   	/*0xa6 */,
GoTo        	/*0xa7 */,
Jsr         	/*0xa8 */,
Ret         	/*0xa9 */,
Tableswitch 	/*0xaa */,
Lookupswitch    /*0xab */,
Ireturn         /*0xac */,
Lreturn         /*0xad */,
Freturn         /*0xae */,
Dreturn         /*0xaf */,
Areturn         /*0xb0 */,
Return          /*0xb1 */,
Getstatic       /*0xb2 */,
Putstatic       /*0xb3 */,
Getfield        /*0xb4 */,
Putfield        /*0xb5 */,
Invokevirtual   /*0xb6 */,
Invokespecial   /*0xb7 */,
Invokestatic    /*0xb8 */,
Invokeinterface /*0xb9 */,
Invokedynamic   /*0xba */,
New             /*0xbb */,
Newarray        /*0xbc */,
Anewarray   	/*0xbd */,
Arraylength 	/*0xbe */,
Athrow  		/*0xbf */,
Checkcast   	/*0xc0 */,
Instanceof  	/*0xc1 */,
Monitorenter    /*0xc2 */,
Monitorexit		/*0xc3 */,
Wide    		/*0xc4 */,
Multianewarray  /*0xc5 */,
Ifnull  		/*0xc6 */,
Ifnonnull   	/*0xc7 */,
Goto_w  		/*0xc8 */,
Jsr_w   		/*0xc9 */,
Breakpoint  	/*0xca */,
[0xcb ... 0xfd] = NULL,
Impdep1 		/*0xfe */,
Impdep2 		/*0xff */,
};

#endif