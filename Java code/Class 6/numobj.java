public class numobj 
{
    static int count=0;
    numobj()
    {
        count++;
    }
    public static void main(String[] args) 
    {
        numobj obj1 = new numobj();
        numobj obj2 = new numobj();
        numobj obj3 = new numobj();
        numobj obj4 = new numobj();
        System.out.println("Number of objects created:"+count);
    }
}
