import java.util.*;
class Student{
    int id;
    String dept;
    int m1,m2,m3;//assuming out of 100
    Student(int idp, String deptp, int m1p, int m2p, int m3p){
        id=idp; dept=deptp; m1=m1p; m2=m2p; m3=m3p;
    }
    float calGpa(){
        return ((float)(m1+m2+m3)/300)*10;
    }
    boolean Search(int idp){
        if(idp==id) return true;
        else return false;

    }
    boolean Search(int idp, String deptp){
        if(idp==id && deptp.equals(dept)) return true;
        else return false;
    }
    void display(){
        System.out.println("ID: "+id);
        System.out.println("Dept: "+dept);
        System.out.println("M1: "+m1);
        System.out.println("M2: "+m2);
        System.out.println("M3: "+m3);
    }
}

class Driver{
    public static void main(String []args){
        Scanner so = new Scanner(System.in);
        Student []arr = new Student[20];
        int n; 
        int id; String dept; int m1,m2,m3;
        System.out.println("Enter the n value: ");
        n = so.nextInt();
        for(int i=0;i<n;i++){
            System.out.println("Enter id: ");
            id=so.nextInt();
            System.out.println("Enter dept: ");
            dept=so.next();
            System.out.println("Enter mark1: ");
            m1=so.nextInt();
            System.out.println("Enter mark2: ");
            m2=so.nextInt();
            System.out.println("Enter mark3: ");
            m3=so.nextInt();
            arr[i]= new Student(id, dept, m1, m2, m3);
        }
        System.out.println("Enter id to search and display: ");
        id=so.nextInt();
        for(int j=0;j<n;j++){
            if(arr[j].Search(id)){
                arr[j].display();
                System.out.println("Grade: "+arr[j].calGpa());
            }
        }
        System.out.println("Enter dept to filter: ");
        dept=so.next();
        for(int k=0;k<n;k++){
            if(arr[k].Search(id,dept)){
                arr[k].display();
                System.out.println("Grade: "+arr[k].calGpa());
            }
        }
        so.close();
        }
}