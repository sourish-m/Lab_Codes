//Q1. Write a program in Java to display name and roll number of students. Initialize respective array variables for 10 students. Handle ArrayIndexOutOfBoundsException, so that any such problem does not cause illegal termination of program

import java.util.*;
import java.io.*;
class question2
{
    public static void main (String [] args)
    {
        Scanner scan= new Scanner(System.in);
        int array_RollNumber[]= new int[10];
        String array_StudentName[] = new String [10];

        try{
            for ( int i=0; i<11; i++)
            {
                System.out.println("Enter Student Roll Number and Name");
                array_RollNumber[i]=scan.nextInt();
                array_StudentName[i]=scan.nextLine();
            }
        }
        catch (ArrayIndexOutOfBoundsException e)
        {
            System.out.println("Array is out of bounds"+e);
        }
    }
}
