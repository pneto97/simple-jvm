package pasta_teste;

public class chrisport {
    static int x = 1;
    public int z = 10000;

    public chrisport(){
        System.out.println("Construido");
    }

    public chrisport(int t,int x){
        
        System.out.println("Construido");
        this.x = this.x + 2;
        System.out.println(this.x);
        this.z += 4;
    }

    public static void printChris(){
        System.out.println("Chris");
    }
}