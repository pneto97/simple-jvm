#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include <stdio.h>





void Nop         (code_attribute *);
void Aconst_null (code_attribute *);
void Iconst_m1   (code_attribute *);
void Iconst_0    (code_attribute *);
void Iconst_1    (code_attribute *);
void Iconst_2    (code_attribute *);
void Iconst_3    (code_attribute *);
void Iconst_4    (code_attribute *);
void Iconst_5    (code_attribute *);
void Lconst_0    (code_attribute *);
void Lconst_1    (code_attribute *);
void Fconst_0    (code_attribute *);
void Fconst_1    (code_attribute *);
void Fconst_2    (code_attribute *);
void Dconst_0    (code_attribute *);
void Dconst_1    (code_attribute *);
void Bipush      (code_attribute *);
void Sipush      (code_attribute *);
void Ldc         (code_attribute *);
void Ldc_w       (code_attribute *);
void Ldc2_w      (code_attribute *);
void Iload  (code_attribute *);
void Lload  (code_attribute *);
void Fload  (code_attribute *);
void Dload  (code_attribute *);
void Aload  (code_attribute *);
void Iload_0(code_attribute *);
void Iload_1(code_attribute *);
void Iload_2(code_attribute *);
void Iload_3(code_attribute *);
void Lload_0(code_attribute *);
void Lload_1(code_attribute *);
void Lload_2(code_attribute *);
void Lload_3(code_attribute *);
void Fload_0(code_attribute *);
void Fload_1(code_attribute *);
void Fload_2(code_attribute *);
void Fload_3(code_attribute *);
void Dload_0(code_attribute *);
void Dload_1(code_attribute *);
void Dload_2(code_attribute *);
void Dload_3(code_attribute *);
void Aload_0(code_attribute *);
void Aload_1(code_attribute *);
void Aload_2(code_attribute *);
void Aload_3(code_attribute *);
void Iaload (code_attribute *);
void Laload (code_attribute *);
void Faload (code_attribute *);
void Daload (code_attribute *);
void Aaload (code_attribute *);
void Baload (code_attribute *);
void Caload (code_attribute *);
void Saload (code_attribute *);
void Istore   (code_attribute *);
void Lstore   (code_attribute *);
void Fstore   (code_attribute *);
void Dstore   (code_attribute *);
void Astore   (code_attribute *);
void Istore_0 (code_attribute *);
void Istore_1 (code_attribute *);
void Istore_2 (code_attribute *);
void Istore_3 (code_attribute *);
void Lstore_0 (code_attribute *);
void Lstore_1 (code_attribute *);
void Lstore_2 (code_attribute *);
void Lstore_3 (code_attribute *);
void Fstore_0 (code_attribute *);
void Fstore_1 (code_attribute *);
void Fstore_2 (code_attribute *);
void Fstore_3 (code_attribute *);
void Dstore_0 (code_attribute *);
void Dstore_1 (code_attribute *);
void Dstore_2 (code_attribute *);
void Dstore_3 (code_attribute *);
void Astore_0 (code_attribute *);
void Astore_1 (code_attribute *);
void Astore_2 (code_attribute *);
void Astore_3 (code_attribute *);
void Iastore  (code_attribute *);
void Lastore  (code_attribute *);
void Fastore  (code_attribute *);
void Dastore  (code_attribute *);
void Aastore  (code_attribute *);
void Bastore  (code_attribute *);
void Castore  (code_attribute *);
void Sastore  (code_attribute *);
void Pop      (code_attribute *);
void Pop2     (code_attribute *);
void Dup      (code_attribute *);
void Dup_x1   (code_attribute *);
void Dup_x2   (code_attribute *);
void Dup2     (code_attribute *);
void Dup2_x1  (code_attribute *);
void Dup2_x2  (code_attribute *);
void Swap     (code_attribute *);
void Iadd   (code_attribute *); 
void Ladd   (code_attribute *); 
void Fadd   (code_attribute *); 
void Dadd   (code_attribute *); 
void Isub   (code_attribute *); 
void Lsub   (code_attribute *); 
void Fsub   (code_attribute *); 
void Dsub   (code_attribute *); 
void Imul   (code_attribute *); 
void Lmul   (code_attribute *); 
void Fmul   (code_attribute *); 
void Dmul   (code_attribute *); 
void Idiv   (code_attribute *); 
void Ldiv   (code_attribute *); 
void Fdiv   (code_attribute *); 
void Ddiv   (code_attribute *); 
void Irem   (code_attribute *); 
void Lrem   (code_attribute *); 
void Frem   (code_attribute *); 
void Drem   (code_attribute *); 
void Ineg   (code_attribute *); 
void Lneg   (code_attribute *); 
void Fneg   (code_attribute *); 
void Dneg   (code_attribute *); 
void Ishl   (code_attribute *); 
void Lshl   (code_attribute *); 
void Ishr   (code_attribute *); 
void Lshr   (code_attribute *); 
void Iushr  (code_attribute *);
void Lushr  (code_attribute *);
void Iand   (code_attribute *); 
void Land   (code_attribute *); 
void Ior    (code_attribute *); 
void Lor    (code_attribute *); 
void Ixor   (code_attribute *); 
void Lxor   (code_attribute *); 
void Iinc   (code_attribute *);
void I2l (code_attribute *);
void I2f (code_attribute *);
void I2d (code_attribute *);
void L2i (code_attribute *);
void L2f (code_attribute *);
void L2d (code_attribute *);
void F2i (code_attribute *);
void F2l (code_attribute *);
void F2d (code_attribute *);
void D2i (code_attribute *);
void D2l (code_attribute *);
void D2f (code_attribute *);
void I2b (code_attribute *);
void I2c (code_attribute *);
void I2s (code_attribute *);
void Lcmp     (code_attribute *);
void Fcmpl    (code_attribute *);
void Fcmpg    (code_attribute *);
void Dcmpl    (code_attribute *);
void Dcmpg    (code_attribute *);
void Ifeq     (code_attribute *);
void Ifne     (code_attribute *);
void Iflt     (code_attribute *);
void Ifge     (code_attribute *);
void Ifgt     (code_attribute *);
void Ifle     (code_attribute *);
void If_icmpeq(code_attribute *);
void If_icmpne(code_attribute *);
void If_icmplt(code_attribute *);
void If_icmpge(code_attribute *);
void If_icmpgt(code_attribute *);
void If_icmple(code_attribute *);
void If_acmpeq(code_attribute *);
void If_acmpne(code_attribute *);
void GoTo        (code_attribute *);
void Jsr         (code_attribute *);
void Ret         (code_attribute *);
void Tableswitch (code_attribute *);
void Lookupswitch(code_attribute *);
void Ireturn     (code_attribute *);
void Lreturn     (code_attribute *);
void Freturn     (code_attribute *);
void Dreturn     (code_attribute *);
void Areturn     (code_attribute *);
void Return      (code_attribute *);
void Getstatic      (code_attribute *);
void Putstatic      (code_attribute *);
void Getfield       (code_attribute *);
void Putfield       (code_attribute *);
void Invokevirtual  (code_attribute *);
void Invokespecial  (code_attribute *);
void Invokestatic   (code_attribute *);
void Invokeinterface(code_attribute *);
void Invokedynamic  (code_attribute *);
void New            (code_attribute *);
void Newarray       (code_attribute *);
void Anewarray(code_attribute *);
void Arraylength(code_attribute *);
void Athrow(code_attribute *);
void Checkcast(code_attribute *);
void Instanceof(code_attribute *);
void Monitorenter   (code_attribute *);
void Monitorexit(code_attribute *);
void Wide            (code_attribute *);
void Multianewarray(code_attribute *);
void Ifnull(code_attribute *);
void Ifnonnull(code_attribute *);
void Goto_w(code_attribute *);
void Jsr_w(code_attribute *);
void Breakpoint(code_attribute *);
void Impdep1(code_attribute *);
void Impdep2(code_attribute *);

void (*inst_vector[256])(code_attribute *) = {
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