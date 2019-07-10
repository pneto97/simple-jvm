public class rodrigo{
    public static void main(String[] args) {
        int[][][] myNum = new int[3][40000][50000];
        myNum[0][35000][10] = 3;
        myNum[0][1][15] = 4;
        // int length = myNum.length;
        // if (myNum[1][1] < myNum[0][1]){
        //     myNum[0][0] = length + myNum[1][0];
        // }
        // else {
        //     myNum[0][0] = myNum[1][2] + length;
        // }
        myNum[0][1][10] = myNum[0][35000][10] + myNum[0][1][15];
        System.out.println(myNum[0][1][10]);
    }
}