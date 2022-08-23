interface student
{
    void Display_Grade();
    void Attendance();
}
class UG_Students implements student
{
    double grade=0.00,attnd=0.00;
    public void Display_Grade ()
    {
       System.out.println("The Grade of the UG Student is "+grade);
    }
   public void Attendance()
   {
      System.out.println("% Attendance of the UG Student is "+attnd);
   } 
}

class PG_Students implements student
{
    double grade=0.00,attnd=0.00;
    public void Display_Grade ()
    {
       System.out.println("The Grade of the PG Student is "+grade);
    }
   public void Attendance ()
   {
      System.out.println("% Attendance of the PG Student is "+attnd);
   } 
}

class studentdemo
{
    public static void main (String [] args)
    {
        UG_Students a = new UG_Students();
        PG_Students b = new PG_Students();
        a.grade=9.87;a.attnd=90.00;
        b.grade=8.41;b.attnd=87.00;

        // Call functions for each object
        a.Display_Grade();
        a.Attendance();
        b.Display_Grade();
        b.Attendance();
    }
}
