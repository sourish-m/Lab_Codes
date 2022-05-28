class si
{
public static void main (String [] arg)
{
	int rate,time;
	String a=arg[0];
	String b= arg[1];
	String c=arg[2];
	double principal=Double.parseDouble(a);
	rate=Integer.parseInt(b);
	time=Integer.parseInt(c);

	double interest=principal*rate*time/100;
	System.out.println("The Interest is "+interest);
}
}
