typedef struct object{
    union obj
    {
        class_instance;
        interface_instance;
        array;
        null;
    };
    
}object;

typedef struct object_handler{
    class_structure *class;
    heap *instance;
} Ref;

typedef struct heap{
    // LIsta/vetor/pilha de object
}

typedef struct interface_instance{
    data;
    fields;
    class_structure *class;
}

typedef struct array{
    data;
    arraysize;
}

// Loaded -> Classes
// Heap -> Objetos: Instância de Classe, Instância de Interface, Array Dinâmicos, Null

classLoader(nome){
    // SE classe não existe nas Classes carregadas
        // busca o arquivo, cria class_structure
        // Instaciar os fields estáticos da classe 
        // retorna endereço da nova classe carregada
    // retorna endereço da nova classe carregada
}

newClassInstance(){
    // IF not ifClassLoaded()
        // class = classLoader()
 
    // class_inst = createClassInstance(class) <- Instacia os fields da classe na heap
    // 

    // Retornar class_inst
}