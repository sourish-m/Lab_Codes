/**
  Create a base class Fruit which has name ,taste and size as its attributes. A method called eat() 
  is created which describes the name of the fruit and its taste. Inherit the same in 2 other 
  class Apple and Orange and override the eat() method to represent each fruit taste.
 **/
class Fruit
{
    String name;
    String taste;
    String size;

    void eat(String name, String taste)
    {
        this.taste=taste;
        this.name=name;
        System.out.println("Name of Fruit is "+this.name+"; Taste of Fruit is "+this.taste);
    }
}
class Apple extends Fruit
{
    void eat()
    {
        this.taste="Sweet";
        this.name="Apple";
    }
}
class Orange extends Fruit
{
    void eat()
    {
        this.taste="Sour";
        this.name="Orange";
    }
}

class demoapple
{
    public static void main (String [] args)
    {
        Apple a= new Apple();
        a.eat();
        Orange b = new Orange();
        b.eat();
        Fruit c= new Fruit();
        c.eat("Mango","Sweet");
        System.out.println("Name of Fruit is "+a.name+"; Taste of Fruit is "+b.taste);
        System.out.println("Name of Fruit is "+b.name+"; Taste of Fruit is "+b.taste);
    }
}

