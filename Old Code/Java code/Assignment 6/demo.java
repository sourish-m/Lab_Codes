/**
 Create a class Account with two overloaded constructors. First constructor is used for 
initializing, name of account holder, account number and initial amount in account. Second 
constructor is used for initializing name of account holder, account number, address, type 
of account and current balance. Account class is having methods Deposit(), WithDraw(), 
and GetBalance().Make necessary assumption for data members and return types of the 
methods. Create objects of Account class and use them.
**/
import java.util.*;
import java.lang.*;
class Account
{
    int account_Number;
    String account_Holder;
    int account_Balance;
    String holder_Address;
    String account_Type; 
Account() //default constructor
{};
Account(String name,int id,int bal)
{
    account_Holder=name;
    account_Number=id;
    account_Balance=bal;
}
Account(String name, int id, String addr, String type, int bal)
{
    account_Holder=name;
    account_Number=id;
    account_Balance=bal;
    account_Type=type;
    holder_Address=addr;
}
void Deposit( int amount)
{
    account_Balance+=amount;
}
void Withdraw( int amount)
{
    account_Balance-=amount;
}

void GetBalance()
{
    System.out.println("Balance is "+account_Balance+" For Account Holder "+account_Holder);

}
}
class demo
{
    public static void main (String [] args)
    {
        int amnt=0,n;
        Account a = new Account("Tom",1201,3000);
        Account b = new Account("Jerry",1202,"Delhi","Savings",5000);
        Account obj= new Account();
        System.out.println("Enter account id ");
        Scanner sc = new Scanner(System.in);
        int id=sc.nextInt();
        if (a.account_Number==id)
            obj=a;
        else
            obj=b;
        for (;;)
        {
            System.out.println("Press 1 to Withdraw, 2 to Deposit and 3 to Check Balance. Press 4 to Exit.");
             n= sc.nextInt();
            if (n==1||n==2)
            {
                System.out.println("Enter amount");
                 amnt=sc.nextInt();
            }
            switch(n)
            {
                case 1: a.Withdraw(amnt);
                        break;
                case 2: a.Deposit(amnt);
                        break;
                case 3: a.GetBalance();
                        break;
                case 4: System.exit(0);
                default: 
                        System.out.println("Wrong Choice Entered");
            }

        }
    }
}
