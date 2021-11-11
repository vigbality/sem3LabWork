import java.util.Scanner;
class PANrequiredException extends Exception{
    PANrequiredException(){super("PAN Required!");}
}
class MinBalRequiredException extends Exception{
    MinBalRequiredException(){super("MIN Balance(500) not satisfied, can't withdraw!");}
}
class NotEnougMoneyInAccountException extends Exception{
    NotEnougMoneyInAccountException(){super("Not enough money in account, can't withdraw!");}
}
class AccountNotFoundException extends Exception{
    AccountNotFoundException(){super("Account not found!");}
}
class PANFormatMismatchException extends Exception{
    PANFormatMismatchException(){super("Invalid PAN format!");}
}
class BranchNotFoundException extends Exception{
    BranchNotFoundException(){super("Branch not found!");}
}

class Account{
    String name,branch,PAN_num;
    long acc_num,balance;
    Account(String name,String branch,long acc_num,String PAN_num,long balance){
        this.name=name;
        this.branch=branch;
        this.checkBranch();
        this.acc_num=acc_num;
        this.balance=balance;
        this.PAN_num=PAN_num;
        this.checkPanFormat();
    }
    void deposit(long amt){
        int auth=0;
        Scanner so = new Scanner(System.in);
        try{
            if(amt>25000) throw new PANrequiredException();
            else auth=1;
        }
        catch(PANrequiredException e){
            System.out.print("\nEnter PAN to continue: ");    
            if(!so.next().equals(this.PAN_num)) System.out.println("Incorrect PAN!!!");
            else auth=1;
        }
        finally{
            if(auth==1) this.balance+=amt;
            so.close();
        }
    }

    void withdraw(long amt){
        try{
            if(amt>balance) throw new NotEnougMoneyInAccountException();
            else if((this.balance-amt)<500) throw new MinBalRequiredException(); 
            else this.balance-=amt;
        }
        catch(NotEnougMoneyInAccountException e){
            System.out.println(e.getMessage());
        }
        catch(MinBalRequiredException e){
            System.out.println(e.getMessage());
        } 

    }
    void checkPanFormat(){
        try{
            if(this.PAN_num.length()!=10) throw new PANFormatMismatchException();
            else{
                for(int i=0;i<5;i++){
                    if(Character.isDigit(PAN_num.charAt(i))) throw new PANFormatMismatchException();
                }
                for(int i=5;i<9;i++){
                    if(Character.isLetter(PAN_num.charAt(i))) throw new PANFormatMismatchException();
                }
                if(Character.isDigit(PAN_num.charAt(9))) throw new PANFormatMismatchException();
            }
        }
        catch(PANFormatMismatchException e){
            System.out.println(e.getMessage());
        }
    }

    void searchAccount(long acc){
        try{
            if(acc==this.acc_num) System.out.println("Account Found!");
            else throw new AccountNotFoundException();
        }
        catch(AccountNotFoundException e){
            System.out.println(e.getMessage());
        }
    }

    void checkBranch(){
        String[] br= {"avadi","chennai","ambattur","kelavakam"};
        int yes=0;
        try{
            for(String i:br){
                if(i.equals(this.branch)){
                    yes=1;break;
                }
            }
            if(yes==0) throw new BranchNotFoundException();
        }
        catch(BranchNotFoundException e){
            System.out.println(e.getMessage());
        }
    }
}

public class Q2{
    public static void main(String args[]){
        System.out.println("\n****************************\n");
        
        Account a1=new Account("vigneshbalaji","avadi",222333,"ABCDE1234F",5000);
        a1.deposit(30000);

        System.out.println("\n****************************\n");

        Account a2=new Account("nandu","chennai",111666,"ABCDE6783F",2000);
        a2.withdraw(1800);

        System.out.println("\n****************************\n");

        a2.withdraw(4000);

        System.out.println("\n****************************\n");

        a2.searchAccount(222666);

        System.out.println("\n****************************\n");

        Account a3=new Account("balaji","kelavakam",435678,"12AW1234F",3000);

        System.out.println("\n****************************\n");

        Account a4=new Account("naresh","ooty",444555,"ABCDE1234F",5000);
        
        System.out.println("\n****************************\n");
    }
}