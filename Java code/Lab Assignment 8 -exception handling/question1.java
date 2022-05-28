import java.lang.*;
class question1
{
    public static void main(String[] args) 
    {

        String name = args[0];
        int age = Integer.parseInt(args[1]);

        try
        {

            if(age < 18 || age >= 60)
            {
                throw new NumberFormatException("Age Entered Must be between 18 to 60");
            }
            System.out.println("Name: "+name+" Age: "+age);

        } catch (NumberFormatException e) {System.out.println(e); }
    }
}
