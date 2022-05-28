class circle
{
public static void main (String [] args)
{
	String a=args[0];
	double radius=Double.parseDouble(a);
	double area=3.141*radius*radius;
	double circumference=3.141*2*radius;
	System.out.println("Area of circle= "+area+" Circumference of circle= "+circumference);
}
}

