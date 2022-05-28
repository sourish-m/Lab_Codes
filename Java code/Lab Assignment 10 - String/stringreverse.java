import java.util.*;
class stringreverse
{
    public static void main (String [] args)
    {
      Scanner sc= new Scanner (System.in);  
      System.out.println("Enter a String");
      StringTokenizer str = new StringTokenizer(sc.nextLine());
      String[] array_of_words = new String[ str.countTokens()];
      for ( int i=0;i<array_of_words.length;  i++)
      {
          array_of_words[i] = str.nextToken(" ");
      }
      for (int i=array_of_words.length-1;i>=0; i--)
          System.out.print(array_of_words[i]+ " ");

    }
}
