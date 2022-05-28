// to convert temp in Celsius to Fahrenheit
class temp
{
public static void main (String [] args)
{
	double temp=Double.parseDouble(args[0]);
	double tempF=temp*9/5+32;
	System.out.println("Temperature in Fahrenheit is "+tempF);
}
}
