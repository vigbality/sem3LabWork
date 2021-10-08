import java.util.*;
class Employee{
    String name,desg;
    int id,years,hours;
    float basic,DA,HRA,LIC,PF,gpay,ded,netpay;
    Employee(int idp, String namep, String desigp, int hoursp, int yearsp, float basicp, float licp){
        id=idp; name=namep; desg=desigp; hours=hoursp; years=yearsp; basic=basicp; LIC=licp;
        if(desg.equals("Intern")){
            DA=2000;
            HRA=1000;
            PF=500;
        }
        else{
            HRA= (float)0.1*basic;
            PF= (float)0.08*basic;
            if(desg.equals("Manager")) DA=(float)0.4*basic;
            else DA=(float)0.3*basic;
        }
    }
    void display(){
        System.out.println("---------------PAY SLIP---------------");
        System.out.println("Name : "+name);
        System.out.println("ID : "+id);
        System.out.println("Designation : "+desg);
        if(desg.equals("Intern")){
            System.out.println("Hours Worked : "+hours);
            System.out.println("Hourly wage : "+500);
        }
        else{
            System.out.println("Years of experience : "+years);
            System.out.println("Basic Pay : "+basic);
        }
        System.out.println("DA : "+DA);
        System.out.println("HRA : "+HRA);
        System.out.println("LIC : "+LIC);
        System.out.println("PF : "+PF);
        System.out.println("GROSS : "+gpay);
        System.out.println("DEDUCTION : "+ded);
        System.out.println("NET : "+netpay);
        System.out.println("--------------------------------------");
        if(!desg.equals("Intern") && years>=3){
            System.out.println("Employee is eligible for promotion");
        }
    }

    void calculate(){
        if(desg.equals("Intern")){
            gpay=hours*500 + DA + HRA;
        }
        else{
            gpay=basic+DA+HRA;
        }
        ded=LIC+PF;
        netpay=gpay-ded;
    }
}
class Driver{
    static Scanner so = new Scanner(System.in);
    static void input(int i, Employee []arr){
        String name,desg;
        int id,years=0,hours=0;
        float basic=0,LIC;
        System.out.println("Enter ID: ");
        id=so.nextInt();
        System.out.println("Enter consumerName: ");
        name=so.next();
        System.out.println("Enter designation: ");
        desg=so.next();
        if(desg.equals("Intern")){
            System.out.println("Enter hours: ");
            hours=so.nextInt();
            System.out.println("Enter LIC");
            LIC=so.nextFloat();
        }
        else{
            System.out.println("Enter years of exp: ");
            years=so.nextInt();
            System.out.println("Enter basic pay: ");
            basic=so.nextFloat();
            System.out.println("Enter LIC");
            LIC=so.nextFloat();
        }
        arr[i]= new Employee(id, name, desg, hours, years,  basic,  LIC);     
    }
    public static void main(String args[]){
        int n;  
        System.out.println("Enter n value: ");
        n=so.nextInt();
        Employee []arr = new Employee[n];       
        for(int i=0;i<n;i++){ 
            input(i,arr);
            arr[i].calculate();
        }
        for(int j=0;j<n;j++){
            arr[j].display();
        }
        so.close();
    }
}