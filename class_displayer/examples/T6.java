// File Name : ExcepTest.java
import java.io.*;

public class T6 {
   
   public static void main(String args[]) {
      String oi;
      oi = "ola pnc";
      try {
         int a[] = new int[2];
         System.out.println("Access element three :" + a[3] + oi);
      } catch (ArrayIndexOutOfBoundsException e) {
         System.out.println("Exception thrown  :" + e);
      }
      System.out.println("Out of the block");
   }
}