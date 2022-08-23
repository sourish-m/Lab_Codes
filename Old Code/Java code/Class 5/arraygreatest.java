import java.util.Scanner;
public class arraygreatest
{
    public static void main( String []arg)
    {
        int arr[][] = new int[3][3];
        int k=0, max=Integer.parseInt(arg[0]);
        
        for (int i = 0; i < 3; i++) 
            for (int j = 0; j < 3; j++) 
            {
                arr[i][j] = Integer.parseInt(arg[k]);
                k++;
                if (arr[i][j]>max)
                {
                    max = arr[i][j];
                }
            }
        System.out.println("The greatest integer in the array is "+ max);
    }}
