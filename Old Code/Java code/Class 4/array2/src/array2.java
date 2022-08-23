import java.util.Scanner;

class array2
{

        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter an array of size n");
            System.out.println("Enter value of n");
            int n = sc.nextInt();
            System.out.println("Now enter the values of the array elements");
            int[] arr = new int[n];
            for (int j = 0; j < n; j++)
                arr[j] = sc.nextInt();

            array2 a = new array2();
            a.MaxRepeat(arr);


        }

        public void MaxRepeat(int[] arr) {
            int maxCounter = 0;
            int element = 0;
            for (int i = 0; i < arr.length; i++) {
                int counter = 1;
                for (int j = i + 1; j < arr.length; j++) {
                    if (arr[i] == arr[j]) {
                        counter++;
                    }
                }
                if (maxCounter < counter) {
                    maxCounter = counter;
                    element = arr[i];
                }
            }
            System.out.println("Element repeating maximum no of times: " + element + ", maximum count: " + maxCounter);
        }
}
