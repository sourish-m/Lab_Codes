import java.io.*;
import  java.util.Scanner;

class convert {
    // Function to convert decimal to octal
    static void decToOctal(int n)
    {
        // array to store octal number
        int[] octalNum = new int[100];

        // counter for octal number array
        int i = 0;
        while (n != 0) {
            // storing remainder in octal array
            octalNum[i] = n % 8;
            n = n / 8;
            i++;
        }

        // Printing octal number array in reverse order
        System.out.print("The Octal Number is ");
        for (int j = i - 1; j >= 0; j--)
            System.out.print(octalNum[j]);
        System.out.println();
    }

    static void dectohex (int dec_num)
    {
        int  rem;
        String hexdec_num="";

        /* hexadecimal number digits */

        char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

        while(dec_num>0)
        {
            rem = dec_num%16;
            hexdec_num = hex[rem] + hexdec_num;
            dec_num = dec_num/16;
        }
        System.out.print("Hexadecimal number is : "+hexdec_num+"\n");         
    } 
    // Driver Code
    public static void main(String[] args)
    {
        int n;
        Scanner in = new Scanner(System.in);

        System.out.print("Input a decimal number: ");
        n = in.nextInt();

        // Function Call
        decToOctal(n);
        dectohex(n);
    }
}
