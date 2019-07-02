public class T6 {
    static int x = 1;
    int z = 3;

    T6(){
        System.out.println("Construido");
        x = 2;
        System.out.println(x);
        this.z = 4;
    }

    public static void printChris(){
        System.out.println("Chris");
    }
}