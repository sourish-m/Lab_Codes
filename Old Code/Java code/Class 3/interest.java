import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import static java.lang.System.*;

public class interest
{
    public static void main(String []args)throws IOException
    {
        BufferedReader in =new BufferedReader(new InputStreamReader(System.in));
        out.println("Enter Principal Value");
        double prn=Double.parseDouble(in.readLine());
        out.println("Enter Rate");
        double rate=Double.parseDouble(in.readLine());
        out.println("Enter time in years");
        int    time=Integer.parseInt(in.readLine());

        double ci= (prn * (Math.pow((1 + rate / 100), time))-prn);
        out.println("The compound interest for the given amount is "+ci);
    }
}

