class T9 extends T6{
    T6 blah;
    T9(int y){
        System.out.println("ola");
        z = y;
    }

    public static void main(String[] args) {
        System.out.println(x);
        T9 teste = new T9(5);
        T9 teste2 = new T9(7);
        System.out.println(teste.z);
        System.out.println(teste2.z);
        printChris();
        printChris(3);
    }
    
    public static void printChris(){
        System.out.println("Demetrio");
    }
    
    public static void printChris(int k){
        System.out.println("Jominha");
    }
}