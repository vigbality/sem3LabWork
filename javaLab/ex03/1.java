import java.util.Scanner;

class Person{
	Scanner so=new Scanner(System.in);
	private int aadhar;
	private String name;
	private String address;
	private char gender;
	public Person(int aadharp, String namep, String addressp, char genderp){
		aadhar=aadharp;
		name=namep;
		address=addressp;
		gender=genderp;
	}
	public String getName(){
		return name;
	}
	public String getAddress(){
		return address;
	}
	public void setAddress(String addressp){
		address=addressp;
	}
	public char getGender(){
		return gender;
	} 
	public void display(){
		System.out.print(aadhar+" "+name+" "+address+" "+gender);
	}
}

class Student extends Person{
	private String program;
	private int year;
	private float totalmark;
	public Student(int aadharp, String namep, String addressp, char genderp, int yearp, float totalp){
		super(aadharp,namep,addressp,genderp);
		year=yearp;
		totalmark=totalp;
	}
	public String getProgram(){
		return program;
	}
	public int getYear(){
		return year;
	}
	public void setYear(int yearp){
		year=yearp;
	}
	public float getTotal(){
		return totalmark;
	}
	public void setTotal(float totalp){
		totalmark=totalp;
	}
	public float calGPA(){
		float data=totalmark/10;
		return data;
	}
	public void display(){
		super.display();
		System.out.println(" "+year+" "+totalmark);
	}	
	
}

class Faculty extends Person{
	private String designation;
	private String department;
	private float basicpay;
	public Faculty(int aadharp, String namep, String addressp, char genderp, String desig, String dept, float pay){
		super(aadharp,namep,addressp,genderp);
		designation=desig;
		department=dept;
		basicpay=pay;
	}
	public String getDesig(){
		return designation;
	}
	public void setDesig(String desig){
		designation=desig;
	}
	public void setBasic(float pay){
		basicpay=pay;
	}
	public float getBasic(){
		return basicpay;
	}
	public double calSalary(){
		double gross,ded;
		gross=basicpay*(1.0+0.6+0.1);
		ded=basicpay*(0.085+0.08);
		return gross-ded;
	}
	public void display(){
		super.display();
		System.out.println(" "+designation+" "+department+" "+basicpay);
	}
}

class TestInheritance{
	public static void main(String[] args){
		Student stuObj=new Student(12345,"vignesh","avadi",'m',2002,100);
		Faculty facObj=new Faculty(12346,"balaji","kalavakam",'m',"HOD","cse",80000);
		System.out.println("\n************Functions from Person class using student object*************");
		System.out.println("getName: "+stuObj.getName());
		System.out.println("getAddress: "+stuObj.getAddress());
		System.out.println("**set Address to kalavakam**");
		stuObj.setAddress("kalavakam");
		System.out.println("getAddress: "+stuObj.getAddress());
		System.out.println("\n\n************Student object*************");
		System.out.print("Display function: ");
		stuObj.display();
		System.out.println("getYear: "+stuObj.getYear());		
		System.out.println("**Set year to 2004**");
		stuObj.setYear(2004);
		System.out.println("getYear: "+stuObj.getYear());
		System.out.println("getTotal: "+stuObj.getTotal());
		System.out.println("**set total to 80**");
		stuObj.setTotal(80);
		System.out.println("getTotal: "+stuObj.getTotal());
		System.out.println("calGPA: "+stuObj.calGPA());
		System.out.println("\n\n************Faculty object*************");
		System.out.print("Display function: ");
		facObj.display();
		System.out.println("getDesig: "+facObj.getDesig());
		System.out.println("**set desig to Principal**");
		facObj.setDesig("Principal");
		System.out.println("getDesig: "+facObj.getDesig());
		System.out.println("getBasic: "+facObj.getBasic());
		System.out.println("**set Basic to 1,00,000**");
		facObj.setBasic(100000);
		System.out.println("getBasic: "+facObj.getBasic());
		System.out.println("calSalary: "+facObj.calSalary());
	}
}
