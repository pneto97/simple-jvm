package pasta_teste;

public class chrisport {
    static int x = 1;
    public int z;

    public chrisport(){
        System.out.println("Construido");
    }

    public chrisport(int t,int x){
        
        System.out.println("Construido");
        x = 2;
        System.out.println(x);
        this.z = 4;
    }

    public static void printChris(){
        System.out.println("Chris");
    }
}