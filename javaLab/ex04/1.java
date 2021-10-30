import java.util.Scanner;

class Person{
    private String name, address;
    public Person(String name, String address){
        this.name=name; this.address=address;
    }
    public String getName(){return name;}
    public String getAddress(){return address;}
    public void setAddress(String address){this.address=address;}
}

class Employee extends Person{
    private String empid, dept;
    private int basic;
    public Employee(String name, String address, String empid, String dept, int basic){
        super(name,address);
        this.empid=empid; this.dept=dept; this.basic=basic;
    }
    public int getEmpid(){return Integer.parseInt(empid);}
    public String getDept(){return dept;}
    public void setDept(String dept){this.dept=dept;}
    public void setBasic(int basic){this.basic=basic;}
    public int getBasic(){return basic;}
    public float calSalary(){return (float)basic;}
}

class Faculty extends Employee{
    private String designation, course;
    public Faculty(String name, String address, String empid, String dept, int basic, String designation, String course){
        super(name, address, empid, dept, basic);
        this.designation=designation; this.course=course;
    }
    public String getDesig(){return designation;}
    public void setDesig(String designation){this.designation=designation;}
    public String getcourse(){return course;}
    public void setcourse(String course){this.course=course;}
    public float calSalary(){return super.calSalary();}
}

interface Student{
    public float getMarks();
    public float calGPA();
}


class TeachingAssistant extends Employee implements Student{
    private String project, course;
    private float marks;
    public TeachingAssistant(String name, String address, String empid, String dept, int basic, String project, String course, float marks){
        super(name, address, empid, dept, basic);
        this.project=project; this.course=course; this.marks=marks;
    }
    public String getProject(){return project;}
    public String getcourse(){return course;}
    public void setcourse(String course){this.course=course;}
    public float getMarks(){return marks;}
    public float calGPA(){return marks/10;}
    public float calSalary(){return super.calSalary();}
}


class TestDriver{
  public static void main(String[] args){
    String name, address, empid, dept, project, course,designation;
    int basic; float marks;
    Scanner so= new Scanner(System.in);
    System.out.println("\n\nENTER DETAILS FOR TEACHING ASSISTANT\n\n");
    System.out.print("Enter Name: ");
    name=so.next();
    System.out.print("Enter Address: ");
    address=so.next();
    System.out.print("Enter Employee ID: ");
    empid=so.next();
    System.out.print("Enter Department: ");
    dept=so.next();
    System.out.print("Enter Project: ");
    project=so.next();
    System.out.print("Enter Course: ");
    course=so.next();
    System.out.print("Enter Basic: ");
    basic=so.nextInt();
    System.out.print("Enter Marks: ");
    marks=so.nextFloat();
    TeachingAssistant ta=new TeachingAssistant(name, address, empid, dept, basic, project, course, marks);
    System.out.println("\nDetails entered:");
    System.out.println("Name: "+ta.getName());
    System.out.println("Address: "+ta.getAddress());
    System.out.println("Employee ID: "+ta.getEmpid());
    System.out.println("Department: "+ta.getDept());
    System.out.println("Project: "+ta.getProject());
    System.out.println("Course: "+ta.getcourse());
    System.out.println("Basic: "+ta.getBasic());
    System.out.println("Marks: "+ta.getMarks());
    System.out.println("CGPA: "+ta.calGPA());
    System.out.println("Salary: "+ta.calSalary());

    System.out.println("\n\nENTER DETAILS FOR FACULTY\n\n");
    System.out.print("Enter Name: ");
    name=so.next();
    System.out.print("Enter Address: ");
    address=so.next();
    System.out.print("Enter Employee ID: ");
    empid=so.next();
    System.out.print("Enter Department: ");
    dept=so.next();
    System.out.print("Enter Basic: ");
    basic=so.nextInt();
    System.out.print("Enter Course: ");
    course=so.next();
    System.out.print("Enter Designation: ");
    designation=so.next();

    Faculty f = new Faculty(name, address, empid, dept, basic, designation, course);
    System.out.println("\nDetails entered:");
    System.out.println("Name: "+f.getName());
    System.out.println("Address: "+f.getAddress());
    System.out.println("Employee ID: "+f.getEmpid());
    System.out.println("Department: "+f.getDept());
    System.out.println("Designation: "+f.getDesig());
    System.out.println("Course: "+f.getcourse());
    System.out.println("Basic: "+f.getBasic());
    System.out.println("Salary: "+f.calSalary());
    so.close();
  }
}