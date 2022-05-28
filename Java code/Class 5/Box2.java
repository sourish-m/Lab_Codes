import java.util.Scanner;
public class Box {
    double a,b,c;

    Box(double width,double height,double depth)
    {
        a=height;
        b=width;
        c=depth;
    }
    double calcvol()
    {
        double v=a*b*c;
        return v;
    }
}

class Box2
{
    public static void main(String[] args)
    {
        double h,w,d;
        System.out.println("Enter the dimensions of the box");
        System.out.println("Enter Height of Box");
        Scanner sc= new Scanner(System.in);
        h=sc.nextDouble();
        System.out.println("Enter width of Box");
        w=sc.nextDouble();
        System.out.println("Enter Depth of Box");
        d=sc.nextDouble();

        Box b = new Box(h,w,d);
        System.out.println("Volume of Box is "+b.calcvol());

    }

}
}
