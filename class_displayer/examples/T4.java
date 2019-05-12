interface MyInterface{

    public void method1();
    public int method2();
}

class T4 implements MyInterface{

    public void method1(){
        System.out.println("Metodo 1!");
    }

    public int method2(){
        int a = 2;
        return a;
    }

    public static void main(String arg[]){
        MyInterface obj = new T4();
        obj.method1();
        System.out.println("Method " + obj.method2());
    }
}

