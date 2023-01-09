import java.util.Scanner;

class primechecker
{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter a Number:");
        int num = scan.nextInt();
        int sum = 0,ch=0;
        do {
            sum += num % 10;
            num = num / 10;
        } while (!(num == 0));


        for (int i = 2; i <=sum/2; i++) {
            if ((sum % i)==0)
                ch++;
        }

        if (ch!=0) System.out.println("Sum of Digits is Not Prime");
        else
            System.out.println("Sum of Digits is Prime");

    }

}



