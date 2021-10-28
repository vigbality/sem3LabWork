import java.util.Scanner;

class Person{
    String name, address;
    Person(String name, String address){
        this.name=name; this.address=address;
    }
    public String getName(){return name;}
    public String getAddress(){return address;}
    public void setAddress(String address){this.address=address;}
}

class Employee extends Person{s
    String empid, dept;
    int basic;
    Employee(String name, String address, String empid, String dept, int basic){
        super(name,address);
        this.empid=empid; this.dept=dept; this.basic=basic;
    }
    public int getEmpid(){ return Intege4102r.parseInt(empid); }
    public String getDept(){return depy}
}
