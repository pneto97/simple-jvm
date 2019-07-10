/**
 * @file instructions.h
 * @brief Instruções da JVM, contendo ponteiros para funções.
 */
#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include <stdio.h>

/**
 * @brief Funcao que realiza um NOP
 * @param code_attribute
 */
void Nop         (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Aconst_null
 * @param code_attribute
 */
void Aconst_null (code_attribute *); //Verificar
/**
 * @brief Funcao que realiza um Iconst_m1
 * @param code_attribute
 */
void Iconst_m1   (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Iconst_0
 * @param code_attribute
 */
void Iconst_0    (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Iconst_1
 * @param code_attribute
 */
void Iconst_1    (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Iconst_2
 * @param code_attribute
 */
void Iconst_2    (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Iconst_3
 * @param code_attribute
 */
void Iconst_3    (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Iconst_4
 * @param code_attribute
 */
void Iconst_4    (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Iconst_5
 * @param code_attribute
 */
void Iconst_5    (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Lconst_0
 * @param code_attribute
 */
void Lconst_0    (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Lconst_1
 * @param code_attribute
 */
void Lconst_1    (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Fconst_0
 * @param code_attribute
 */
void Fconst_0    (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Fconst_1
 * @param code_attribute
 */
void Fconst_1    (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Fconst_2
 * @param code_attribute
 */
void Fconst_2    (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Dconst_0 
 * @param code_attribute
 */
void Dconst_0    (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Dconst_1
 * @param code_attribute
 */
void Dconst_1    (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Bipush
 * @param code_attribute
 */
void Bipush      (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Sipush 
 * @param code_attribute
 */
void Sipush      (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Ldc
 * @param code_attribute
 */
void Ldc         (code_attribute *); //Feito (verificar case String)
/**
 * @brief Funcao que realiza um Ldc_w
 * @param code_attribute
 */
void Ldc_w       (code_attribute *); //Feito (verificar case String)
/**
 * @brief Funcao que realiza um Ldc2_w
 * @param code_attribute
 */
void Ldc2_w      (code_attribute *); //Feito
// Paulo
/**
 * @brief Funcao que realiza um Iload
 * @param code_attribute
 */
void Iload  (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Lload 
 * @param code_attribute
 */
void Lload  (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Fload 
 * @param code_attribute
 */
void Fload  (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Dload
 * @param code_attribute
 */
void Dload  (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Aload
 * @param code_attribute
 */
void Aload  (code_attribute *); //Verificar
/**
 * @brief Funcao que realiza um Iload_0
 * @param code_attribute
 */
void Iload_0(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Iload_1
 * @param code_attribute
 */
void Iload_1(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Iload_2
 * @param code_attribute
 */
void Iload_2(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Iload_3
 * @param code_attribute
 */
void Iload_3(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Lload_0
 * @param code_attribute
 */
void Lload_0(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Lload_1
 * @param code_attribute
 */
void Lload_1(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Lload_2
 * @param code_attribute
 */
void Lload_2(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Lload_3
 * @param code_attribute
 */
void Lload_3(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Fload_0
 * @param code_attribute
 */
void Fload_0(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Fload_1
 * @param code_attribute
 */
void Fload_1(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Fload_2
 * @param code_attribute
 */
void Fload_2(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Fload_3
 * @param code_attribute
 */
void Fload_3(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Dload_0
 * @param code_attribute
 */
void Dload_0(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Dload_1
 * @param code_attribute
 */
void Dload_1(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Dload_2
 * @param code_attribute
 */
void Dload_2(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Dload_3
 * @param code_attribute
 */
void Dload_3(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Aload_0
 * @param code_attribute
 */
void Aload_0(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Aload_1
 * @param code_attribute
 */
void Aload_1(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Aload_2
 * @param code_attribute
 */
void Aload_2(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Aload_3
 * @param code_attribute
 */
void Aload_3(code_attribute *); //Feito

//Jominha
/**
 * @brief Funcao que realiza um Iaload
 * @param code_attribute
 */
void Iaload (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Laload
 * @param code_attribute
 */
void Laload (code_attribute *); //Feito (NECESSITA VERIFICAR)
/**
 * @brief Funcao que realiza um Faload
 * @param code_attribute
 */
void Faload (code_attribute *); //Feito (NECESSITA VERIFICAR)
/**
 * @brief Funcao que realiza um Daload
 * @param code_attribute
 */
void Daload (code_attribute *); //Feito (NECESSITA VERIFICAR)
/**
 * @brief Funcao que realiza um Aaload
 * @param code_attribute
 */
void Aaload (code_attribute *); //Feito falta testar!!
/**
 * @brief Funcao que realiza um Baload
 * @param code_attribute
 */
void Baload (code_attribute *); //Feito (NECESSITA VERIFICAR)
/**
 * @brief Funcao que realiza um Caload
 * @param code_attribute
 */
void Caload (code_attribute *); //Feito (NECESSITA VERIFICAR)
/**
 * @brief Funcao que realiza um Saload
 * @param code_attribute
 */
void Saload (code_attribute *); //Feito (NECESSITA VERIFICAR)
/**
 * @brief Funcao que realiza um Istore
 * @param code_attribute
 */
void Istore   (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Lstore
 * @param code_attribute
 */
void Lstore   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Fstore
 * @param code_attribute
 */
void Fstore   (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Dstore
 * @param code_attribute
 */
void Dstore   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Astore
 * @param code_attribute
 */
void Astore   (code_attribute *); //Feito (NECESSSITA VERIFICAR)
/**
 * @brief Funcao que realiza um Istore_0
 * @param code_attribute
 */
void Istore_0 (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Istore_1
 * @param code_attribute
 */
void Istore_1 (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Istore_2
 * @param code_attribute
 */
void Istore_2 (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Istore_3
 * @param code_attribute
 */
void Istore_3 (code_attribute *); //Feito

// Jomas
/**
 * @brief Funcao que realiza um Lstore_0
 * @param code_attribute
 */
void Lstore_0 (code_attribute *);   //Feito
/**
 * @brief Funcao que realiza um Lstore_1
 * @param code_attribute
 */
void Lstore_1 (code_attribute *);   //Feito
/**
 * @brief Funcao que realiza um Lstore_2
 * @param code_attribute
 */
void Lstore_2 (code_attribute *);   //Feito
/**
 * @brief Funcao que realiza um Lstore_3
 * @param code_attribute
 */
void Lstore_3 (code_attribute *);   //Feito
/**
 * @brief Funcao que realiza um Fstore_0
 * @param code_attribute
 */
void Fstore_0 (code_attribute *);   //Feito
/**
 * @brief Funcao que realiza um Fstore_1
 * @param code_attribute
 */
void Fstore_1 (code_attribute *);   //Feito e testado
/**
 * @brief Funcao que realiza um Fstore_2
 * @param code_attribute
 */
void Fstore_2 (code_attribute *);   //Feito e testado
/**
 * @brief Funcao que realiza um Fstore_3
 * @param code_attribute
 */
void Fstore_3 (code_attribute *);   //Feito e testado
/**
 * @brief Funcao que realiza um Dstore_0
 * @param code_attribute
 */
void Dstore_0 (code_attribute *);   //Feito
/**
 * @brief Funcao que realiza um Dstore_1
 * @param code_attribute
 */
void Dstore_1 (code_attribute *);   //Feito
/**
 * @brief Funcao que realiza um Dstore_2
 * @param code_attribute
 */
void Dstore_2 (code_attribute *);   //Feito
/**
 * @brief Funcao que realiza um Dstore_3
 * @param code_attribute
 */
void Dstore_3 (code_attribute *);   //Feito
/**
 * @brief Funcao que realiza um Astore_0
 * @param code_attribute
 */
void Astore_0 (code_attribute *);   //Feito (NECESSSITA VERIFICAR)
/**
 * @brief Funcao que realiza um Astore_1
 * @param code_attribute
 */
void Astore_1 (code_attribute *);   //Feito (NECESSSITA VERIFICAR)
/**
 * @brief Funcao que realiza um Astore_2
 * @param code_attribute
 */
void Astore_2 (code_attribute *);   //Feito (NECESSSITA VERIFICAR)
/**
 * @brief Funcao que realiza um Astore_3
 * @param code_attribute
 */
void Astore_3 (code_attribute *);   //Feito (NECESSSITA VERIFICAR)
//Lucao
/**
 * @brief Funcao que realiza um Iastore
 * @param code_attribute
 */
void Iastore  (code_attribute *);   //Feito e testado
/**
 * @brief Funcao que realiza um Lastore 
 * @param code_attribute
 */
void Lastore  (code_attribute *);   //Feito Verificar!
/**
 * @brief Funcao que realiza um Fastore
 * @param code_attribute
 */
void Fastore  (code_attribute *);   //Feito Verificar!
/**
 * @brief Funcao que realiza um Dastore
 * @param code_attribute
 */
void Dastore  (code_attribute *);   //Feito Verificar!
/**
 * @brief Funcao que realiza um Aastore
 * @param code_attribute
 */
void Aastore  (code_attribute *);   //Feito e testado
/**
 * @brief Funcao que realiza um Bastore
 * @param code_attribute
 */
void Bastore  (code_attribute *);   //Feito Verificar!
/**
 * @brief Funcao que realiza um Castore
 * @param code_attribute
 */
void Castore  (code_attribute *);   //Feito Verificar!
/**
 * @brief Funcao que realiza um Sastore
 * @param code_attribute
 */
void Sastore  (code_attribute *);   //Feito Verificar!

// Lucao
/**
 * @brief Funcao que realiza um Pop
 * @param code_attribute
 */
void Pop      (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Pop2
 * @param code_attribute
 */
void Pop2     (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Dup
 * @param code_attribute
 */
void Dup      (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Dup_x1
 * @param code_attribute
 */
void Dup_x1   (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Dup_x2
 * @param code_attribute
 */
void Dup_x2   (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Dup2
 * @param code_attribute
 */
void Dup2     (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Dup2_x1
 * @param code_attribute
 */
void Dup2_x1  (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Dup2_x2
 * @param code_attribute
 */
void Dup2_x2  (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Swap
 * @param code_attribute
 */
void Swap     (code_attribute *); //Feito

/**
 * @brief Funcao que realiza um Iadd
 * @param code_attribute
 */
void Iadd   (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Ladd
 * @param code_attribute
 */
void Ladd   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Fadd
 * @param code_attribute
 */
void Fadd   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Dadd
 * @param code_attribute
 */
void Dadd   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Isub
 * @param code_attribute
 */
void Isub   (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Lsub
 * @param code_attribute
 */
void Lsub   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Fsub
 * @param code_attribute
 */
void Fsub   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Dsub
 * @param code_attribute
 */
void Dsub   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Imul
 * @param code_attribute
 */
void Imul   (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Lmul
 * @param code_attribute
 */
void Lmul   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Fmul
 * @param code_attribute
 */
void Fmul   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Dmul
 * @param code_attribute
 */
void Dmul   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Idiv
 * @param code_attribute
 */
void Idiv   (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Ldiv
 * @param code_attribute
 */
void Ldiv   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Fdiv   (cod
 * @param code_attribute
 */
void Fdiv   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Ddiv
 * @param code_attribute
 */
void Ddiv   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Irem
 * @param code_attribute
 */
void Irem   (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Lrem
 * @param code_attribute
 */
void Lrem   (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Frem
 * @param code_attribute
 */
void Frem   (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Drem
 * @param code_attribute
 */
void Drem   (code_attribute *); //Feito

// Chris 
/**
 * @brief Funcao que realiza um Ineg
 * @param code_attribute
 */
void Ineg   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Lneg
 * @param code_attribute
 */
void Lneg   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Fneg
 * @param code_attribute
 */
void Fneg   (code_attribute *); //Feito e testado 
/**
 * @brief Funcao que realiza um Dneg
 * @param code_attribute
 */
void Dneg   (code_attribute *); //Feito e testado 
/**
 * @brief Funcao que realiza um Ishl
 * @param code_attribute
 */
void Ishl   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Lshl
 * @param code_attribute
 */
void Lshl   (code_attribute *); //Feito e testado 
/**
 * @brief Funcao que realiza um Ishr
 * @param code_attribute
 */
void Ishr   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Lshr
 * @param code_attribute
 */
void Lshr   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Iushr
 * @param code_attribute
 */
void Iushr  (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Lushr
 * @param code_attribute
 */
void Lushr  (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Iand
 * @param code_attribute
 */
void Iand   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Land
 * @param code_attribute
 */
void Land   (code_attribute *); //Feito e testado 
/**
 * @brief Funcao que realiza um Ior
 * @param code_attribute
 */
void Ior    (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Lor
 * @param code_attribute
 */
void Lor    (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Ixor
 * @param code_attribute
 */
void Ixor   (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Lxor
 * @param code_attribute
 */
void Lxor   (code_attribute *); //Feito e testado 
/**
 * @brief Funcao que realiza um Iinc
 * @param code_attribute
 */
void Iinc   (code_attribute *); //Feito e testado

//PAULIN
/**
 * @brief Funcao que realiza um I2l (code_a
 * @param code_attribute
 */
void I2l (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um I2f
 * @param code_attribute
 */
void I2f (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um I2d
 * @param code_attribute
 */
void I2d (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um L2i
 * @param code_attribute
 */
void L2i (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um L2f
 * @param code_attribute
 */
void L2f (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um L2d
 * @param code_attribute
 */
void L2d (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um F2i
 * @param code_attribute
 */
void F2i (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um F2l
 * @param code_attribute
 */
void F2l (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um F2d
 * @param code_attribute
 */
void F2d (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um D2i
 * @param code_attribute
 */
void D2i (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um D2l
 * @param code_attribute
 */
void D2l (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um D2f
 * @param code_attribute
 */
void D2f (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um I2b
 * @param code_attribute
 */
void I2b (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um I2c
 * @param code_attribute
 */
void I2c (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um I2s
 * @param code_attribute
 */
void I2s (code_attribute *); //Feito e testado

// Lucao
/**
 * @brief Funcao que realiza um Lcmp
 * @param code_attribute
 */
void Lcmp     (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Fcmpl
 * @param code_attribute
 */
void Fcmpl    (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Fcmpg
 * @param code_attribute
 */
void Fcmpg    (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Dcmpl
 * @param code_attribute
 */
void Dcmpl    (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Dcmpg
 * @param code_attribute
 */
void Dcmpg    (code_attribute *); //Feito

// Demetrio
/**
 * @brief Funcao que realiza um Ifeq
 * @param code_attribute
 */
void Ifeq     (code_attribute *); //Feito 
/**
 * @brief Funcao que realiza um Ifne
 * @param code_attribute
 */
void Ifne     (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Iflt
 * @param code_attribute
 */
void Iflt     (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Ifge
 * @param code_attribute
 */
void Ifge     (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Ifgt
 * @param code_attribute
 */
void Ifgt     (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Ifle
 * @param code_attribute
 */
void Ifle     (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um If_icmpeq
 * @param code_attribute
 */
void If_icmpeq(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um If_icmpne
 * @param code_attribute
 */
void If_icmpne(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um If_icmplt
 * @param code_attribute
 */
void If_icmplt(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um If_icmpge
 * @param code_attribute
 */
void If_icmpge(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um If_icmpgt
 * @param code_attribute
 */
void If_icmpgt(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um If_icmple
 * @param code_attribute
 */
void If_icmple(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um If_acmpeq
 * @param code_attribute
 */
void If_acmpeq(code_attribute *); //Feito
/**
 * @brief Funcao que realiza um If_acmpne
 * @param code_attribute
 */
void If_acmpne(code_attribute *); //Feito

/**
 * @brief Funcao que realiza um GoTo       
 * @param code_attribute
 */
void GoTo        (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Jsr        
 * @param code_attribute
 */
void Jsr         (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Ret        
 * @param code_attribute
 */
void Ret         (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Tableswitch
 * @param code_attribute
 */
void Tableswitch (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Lookupswitch
 * @param code_attribute
 */
void Lookupswitch(code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Ireturn    
 * @param code_attribute
 */
void Ireturn     (code_attribute *); //Feito Verificar!
/**
 * @brief Funcao que realiza um Lreturn    
 * @param code_attribute
 */
void Lreturn     (code_attribute *); //Feito Verificar!
/**
 * @brief Funcao que realiza um Freturn    
 * @param code_attribute
 */
void Freturn     (code_attribute *); //Feito Verificar!
/**
 * @brief Funcao que realiza um Dreturn    
 * @param code_attribute
 */
void Dreturn     (code_attribute *); //Feito Verificar!
/**
 * @brief Funcao que realiza um Areturn    
 * @param code_attribute
 */
void Areturn     (code_attribute *); //Feito Verificar!
/**
 * @brief Funcao que realiza um Return     
 * @param code_attribute
 */
void Return      (code_attribute *); //Feito Verificar!
/**
 * @brief Funcao que realiza um Getstatic  
 * @param code_attribute
 */
void Getstatic      (code_attribute *); //Incompleto
/**
 * @brief Funcao que realiza um Putstatic  
 * @param code_attribute
 */
void Putstatic      (code_attribute *);
/**
 * @brief Funcao que realiza um Getfield   
 * @param code_attribute
 */
void Getfield       (code_attribute *);
/**
 * @brief Funcao que realiza um Putfield   
 * @param code_attribute
 */
void Putfield       (code_attribute *);
/**
 * @brief Funcao que realiza um Invokevirtual
 * @param code_attribute
 */
void Invokevirtual  (code_attribute *); //Incompleto
/**
 * @brief Funcao que realiza um Invokespecial
 * @param code_attribute
 */
void Invokespecial  (code_attribute *);
/**
 * @brief Funcao que realiza um Invokestatic
 * @param code_attribute
 */
void Invokestatic   (code_attribute *);
/**
 * @brief Funcao que realiza um Invokeinterface
 * @param code_attribute
 */
void Invokeinterface(code_attribute *);
/**
 * @brief Funcao que realiza um Invokedynamic
 * @param code_attribute
 */
void Invokedynamic  (code_attribute *);
/**
 * @brief Funcao que realiza um New        
 * @param code_attribute
 */
void New            (code_attribute *);
/**
 * @brief Funcao que realiza um Newarray   
 * @param code_attribute
 */
void Newarray       (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Anewarray  
 * @param code_attribute
 */
void Anewarray      (code_attribute *); //Feito falta testar!!
/**
 * @brief Funcao que realiza um Arraylength
 * @param code_attribute
 */
void Arraylength    (code_attribute *); //Feito e testado
/**
 * @brief Funcao que realiza um Athrow     
 * @param code_attribute
 */
void Athrow         (code_attribute *); 
/**
 * @brief Funcao que realiza um Checkcast  
 * @param code_attribute
 */
void Checkcast      (code_attribute *);
/**
 * @brief Funcao que realiza um Instanceof 
 * @param code_attribute
 */
void Instanceof     (code_attribute *);
/**
 * @brief Funcao que realiza um Monitorenter
 * @param code_attribute
 */
void Monitorenter   (code_attribute *); // Não necessário
/**
 * @brief Funcao que realiza um Monitorexit
 * @param code_attribute
 */
void Monitorexit    (code_attribute *); // Não necessário
/**
 * @brief Funcao que realiza um Wide       
 * @param code_attribute
 */
void Wide           (code_attribute *);
/**
 * @brief Funcao que realiza um Multianewarray
 * @param code_attribute
 */
void Multianewarray (code_attribute *); // Não feito
/**
 * @brief Funcao que realiza um Ifnull     
 * @param code_attribute
 */
void Ifnull         (code_attribute *); //Feito Verificar!
/**
 * @brief Funcao que realiza um Ifnonnull  
 * @param code_attribute
 */
void Ifnonnull      (code_attribute *); //Feito Verificar!
/**
 * @brief Funcao que realiza um Goto_w     
 * @param code_attribute
 */
void Goto_w         (code_attribute *); //Feito
/**
 * @brief Funcao que realiza um Jsr_w      
 * @param code_attribute
 */
void Jsr_w          (code_attribute *); //Feito

/**
 * @brief vetor de ponteiro para função
 * 
 */
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
Istore      	/*0x36 */,
Lstore      	/*0x37 */,
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
[0xca ... 0xff] = NULL,
};

#endif