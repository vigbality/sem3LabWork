class MinorCitizenException extends Exception{
    MinorCitizenException(String m){super(m);}
}

class Person{
    private String name,age,aadhaar;
    void getInput(String name, String age, String aadhaar){
        this.name=name;
        this.age=age;
        this.checkAgeFormat();
        this.aadhaar=aadhaar;
        this.checkAadhaarFormat();
    }

    void checkAgeFormat(){
        try{
            for(int i=0;i<age.length();i++){
                if(Character.isLetter(age.charAt(i))) throw new NumberFormatException();;
            }            
        }
        catch(NumberFormatException e){
            System.out.println("Invalid Age Format!");
            this.age=null;
        }
    }
  
    void checkAadhaarFormat(){
        try{
            for(int i=0;i<aadhaar.length();i++){
                if(!Character.isDigit(aadhaar.charAt(i))) throw new NullPointerException();
            }               
        }
        catch(NullPointerException e){
            System.out.println("Invalid Aadhaar format!");
            this.aadhaar=null;
        } 
    }

    void display(){
        System.out.println("Name: "+name);
        System.out.println("Age: "+age);
        System.out.println("Aadhaar: "+aadhaar);
    }

    void canVote(){
        if(this.age==null){}
        else{
            try{
                if(Integer.parseInt(age)<18) throw new MinorCitizenException("Ineligible to vote!");
            }
            catch(MinorCitizenException e){
                System.out.println(e.getMessage());       
            }
        }       
    }

    void hasAadhar(){
        if(this.aadhaar==null) System.out.println("No valid aadhar found!");
        else System.out.println("Valid aadhar found!");
    }
}

public class Q1{
    public static void main(String arg[]){
        Person p1=new Person();
        Person p2=new Person();
        Person p3=new Person();
        System.out.println("****************************");
        p1.getInput("Vigneshbalaji","19","402938782374");
        p1.display();
        p1.canVote();
        p1.hasAadhar();
        System.out.println("****************************");
        p2.getInput("naresh","15","402937656474");
        p2.display();
        p2.canVote();
        p2.hasAadhar();
        System.out.println("****************************");
        p3.getInput("nandu","20","402ghi656474");
        p3.display();
        p3.canVote();
        p3.hasAadhar();
    
    }
}