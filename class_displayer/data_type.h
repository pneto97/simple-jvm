
enum primitive_data_type { 
    BYTE,
    SHORT,
    INT,
    LONG,
    CHAR,
    FLOAT,
    DOUBLE,
    RETURN_ADDR, 
};

enum reference_data_type { 
    CLASS,
    ARRAY,
    INTERFACE,
    NULL,
};

typedef union {
    primitive_data_type tag;
    reference_data_type tag;
} types;
