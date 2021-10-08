import java.util.*;

class Customer{
	int consumerNo;
	String ConsumerName;
	int prevMonthReading;
	int currMonthReading;
	char type;
	Customer(int cNo, String cName, int prevR, int currR, char t){
		consumerNo=cNo;
		ConsumerName=cName;
		prevMonthReading=prevR;
		currMonthReading=currR;
		type=t;
	}
	float calBillAmt(){
		int units = currMonthReading - prevMonthReading;
		double amt = 0;
		if(type=='d'){
			if(units<=100) amt = units;
			else if(units<=200) amt = 100 + 2.5*(units-100);
			else if(units<=500) amt = 100+250+4*(units-200);
			else amt = 100+250+1200+(units-500)*6;
		}
		else{
			if(units<=100) amt = 2*units;
			else if(units<=200) amt = 200 + 4.5*(units-100);
			else if(units<=500) amt = 200+450+6*(units-200);
			else amt = 200+450+1800+(units-500)*7;
		}
		return (float)amt;
	}
}
class EB{
	public static void main(String []args){
		Scanner sobj = new Scanner(System.in);
		System.out.println("Enter consumer num: ");
		int cNo= sobj.nextInt();
		System.out.println("Enter consumer name: ");
		sobj.next();//to clear newline from buffer
		String cName = sobj.nextLine();
		System.out.println("Enter previous month reading: ");
		int prev = sobj.nextInt();
		System.out.println("Enter current month reading: ");
		int curr = sobj.nextInt();
		System.out.println("Enter type domestic or commercial (d/c):  ");
		char t = sobj.next().charAt(0);
		Customer c1= new Customer(cNo, cName, prev, curr, t);
		System.out.println("Bill Amount: "+c1.calBillAmt());
		sobj.close();
	}
}
