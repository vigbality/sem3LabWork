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
		String data;
		System.out.println("Enter name: ");
		data=so.nextLine();
		return data;
	}
	public String getAddress(){
		String data;
		System.out.println("Enter address: ");
		data=so.nextLine();
		return data;
	}
	public void setAddress(String addressp){
		address=addressp;
	}
	public char getGender(){
		char data;
		data=so.next().charAt(0);
		return data;
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
		String data;
		System.out.println("Enter program title: ");
		data=so.nextLine();
		return data;
	}
	public int getYear(){
		int data;
		System.out.println("Enter year: ");
		data=so.nextInt();
		return data;
	}
	public void setYear(int yearp){
		year=yearp;
	}
	public float getTotal(){
		float data;
		System.out.println("Enter total: ");
		data=so.nextFloat();
		return data;
	}
	public void setTotal(float totalp){
		totalmark=totalp;
	}
	public float calGPA(){
		float data=totalmark/10;
		return data;
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
		String data;
		System.out.println("Enter designation: ");
		data=so.nextLine();
		return data;
	}
	public void setDesig(String desig){
		designation=desig;
	}
	public void setBasic(float pay){
		basicpay=pay;
	}
	public float getBasic(){
		float data;
		System.out.println("Enter basicPay: ");
		data=so.nextFloat();
		return data;
	}
	public double calSalary(){
		double gross,ded;
		gross=basicpay*(1.0+0.6+0.1);
		ded=basicpay*(0.085+0.08);
		return gross-ded;
	}
}

class TestInheritance{
	public static void main(String[] args){
		Person perObj=new Person(12345,"vignesh","avadi",'m');
		System.out.println(perObj.getGender());
	}
}
