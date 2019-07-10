public class rodrigo{
    public static void main(String[] args) {
        int[][] myNum = {{10,20,30},{40,50,60}};
        int length = myNum.length;
        if (myNum[1][1] < myNum[0][1]){
            myNum[1][0] = length + myNum[1][0];
        }
        else {
            myNum[0][0] = myNum[1][0] + length;
        }
        System.out.println(myNum[1][1]);
    }
}