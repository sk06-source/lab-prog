//program 1

//program 2
abstract class Main {
    public String fname = "john";
    public int age = 24;
    public abstract void study(); 
}
class Student extends Main{
    public int grad_yeat = 2018;
    public void study(){
        System.out.println("Studying all day long");
    }
}
 class Second { //second file
    public static void main(String[] args){
        Student my_obj = new Student();
        System.out.println("Name: " + my_obj.fname);
        System.out.println("Age: " + my_obj.age);
        System.out.println("Graduation year: " + my_obj.grad_year);
        my_obj.study();
    }
}

//program 3


