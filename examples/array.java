class array{
    public static void main(String[] args) {
        byte array[] = new byte[270];
        byte number = 0;
        int i = 0,j = 0;
        while (i <= 270){
            array[i] = number;
            i=i+1;
            number++;
        }
        while (j<270){
            System.out.println(array[j]);
            j++;
        }
    }
}