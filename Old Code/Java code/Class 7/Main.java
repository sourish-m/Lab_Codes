import java.util.*;
class Person{
    private String myName ;
    private int myAge;
    private String myGender;

    public Person(String name, int age, String gender){
        myName = name;
        myAge = age;
        myGender = gender;
    }
    public String getName(){
        return myName;
    }
    public int getAge(){
        return myAge;
    }
    public String getGender(){
        return myGender;
    }
    public void setName(String name){
        myName = name;
    }
    public void setAge(int age){
        myAge = age;
    } public void setGender(String gender){
        myGender = gender;
    }
    public String toString(){
        return myName + ", age: " + myAge + ", gender: " + myGender;
    }
}
class Student extends Person
{
    private String myIdNum;
    private double myGPA;
    public Student(String name, int age, String gender,String idNum, double gpa)
    {
        super(name, age, gender);
        myIdNum = idNum;
        myGPA = gpa;
    }
    public String getIdNum(){
        return myIdNum;
    }
    public double getGPA(){
        return myGPA;
    }
    public void setIdNum(String idNum){
        myIdNum = idNum;
    }
    public void setGPA(double gpa){
        myGPA = gpa;
    }
    // overrides the toString method in the parent class
    public String toString(){
        return super.toString() + ", student id: " + myIdNum + ", gpa: " + myGPA;
    }
}
class collegeStudent extends Student
{
    private int year;
    private String major;

    public collegeStudent(String name, int age, String gender,String idNum, double gpa,int
            year,String major){
        super(name,age,gender,idNum,gpa);
        this.year = year;
        this.major =major;}
    public void setYear(int year)
    {
        this.year=year;
    }
    public void setmajor(String major)
    {
        this.major=major;
    }
    public int getYear()
    {
        return year;
    }
    public String getmajor()
    {
        return major;
    }
    public String toString(){
        return super.toString() + ", year: " + year + ", major: " + major;
    }
}
class Teacher extends Person
{
    private float salary;
    private String subject;

    public Teacher(String name, int age, String gender,float salary, String subject){
        // use the super class' constructor
        super(name, age, gender);
        // initialize what's new to Student
        this.salary = salary;
        this.subject = subject;
    }
    public void setSalary(float salary )
    {
        this.salary=salary;
    }
    public void setSubject(String subject)
    {
        this.subject=subject;
    }
    public float getSalary()
    {
        return salary ;
    }  public String getSubject()
    {
        return subject;
    }
    public String toString(){
        return super.toString() + ", salary: " + salary + ", subject: " + subject;
    }
}
public class Main
{
    public static void main(String[] args) {

        Person a = new Person("Ajay",24,"Male");
        Student b = new Student("Mohan", 30,"Male","12" ,1);

        collegeStudent cg1=new collegeStudent("Andy",20,"M","1",9,2020,"CSE");
        Teacher c = new Teacher("Mike",23,"M", 95000,"CSE");
        System.out.println(a);
        System.out.println(b);
        System.out.println(cg1);
        System.out.println(c);

    }
}  
