public class rodrigo{
    public static void main(String[] args) {
        int[] myNum = {10, 50, 30, 40};
        if (myNum[1] < myNum[2]){
            myNum[1] = myNum[2] + myNum[3];
        }
        else {
            myNum[2] = myNum[2] + myNum[3];
        }
        System.out.println(myNum[2]);
    }
}