import java.util.Scanner;

class array1
{
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter 10 numbers");
        int[] arr=new int[10];
        for(int i=0;i<10;i++)
        {
            arr[i]=sc.nextInt();
        }
        // sort array using selection sort
        for (int i=0;i<9;i++)
        {
            int min = i;
            for (int j = i+1; j <10; j++)
            {
                if (arr[j] < arr[min])
                {
                    min = j;
                }
            }


            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }

        System.out.println("The greatest two numbers of the array are\t"+arr[9]+" and\t"+arr[8]+" and the smallest two numbers of the array are\t"+arr[0]+" and\t"+arr[1]);

    }
}