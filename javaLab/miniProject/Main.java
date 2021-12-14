import Logic.Game;
import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String p1,p2;
		System.out.print("Enter player 1 name: ");
		p1=sc.next();
		System.out.print("Enter player 2 name: ");
		p2=sc.next();
		Game g=new Game(p1,p2);
		int chance=0,done=0;
		int []status1=new int[2];	
		int []status2=new int[2];
		int choice;
		while(done!=1){
			switch(chance%2){
				case 0:{
					System.out.println("\n\n***********************************************\n"+g.getP1Name()+"'s turn\n***********************************************\n");
					System.out.println("********opponent hand********");
					status2=g.getP2();
					System.out.println("Left: "+status2[0]+"  "+"Right: "+status2[1]);
					System.out.println("\n\n********Your hand********");
					status1=g.getP1();
					System.out.println("Left: "+status1[0]+"  "+"Right: "+status1[1]);
					System.out.print("\n-------------------------------------\ntouch\n[1]left with left\n[2]left with right\n[3]right with left\n[4]right with right\n[5]divide\nyour choice: ");
					choice=sc.nextInt();
					switch(choice){
						case 1:{
							status2[0]+=status1[0];
							g.updateP2(status2);
						};break;
						case 2:{
							status2[0]+=status1[1];
							g.updateP2(status2);
						};break;
						case 3:{
							status2[1]+=status1[0];
							g.updateP2(status2);
						};break;
						case 4:{
							status2[1]+=status1[1];
							g.updateP2(status2);
						};break;
						case 5:{
							System.out.print("Enter New Left: ");
							status1[0]=sc.nextInt();
							System.out.print("Enter New Right: ");
							status1[1]=sc.nextInt();
							g.updateP1(status1);
						};break;
					}
				};break;
				
				case 1:{
					System.out.println("\n\n***********************************************\n"+g.getP2Name()+"'s turn\n***********************************************\n");
					System.out.println("********opponent hand*********");
					status1=g.getP1();
					System.out.println("Left: "+status1[0]+"  "+"Right: "+status1[1]);
					System.out.println("\n\n********Your hand********");
					status2=g.getP2();
					System.out.println("Left: "+status2[0]+"  "+"Right: "+status2[1]);
					System.out.print("\n-------------------------------------\ntouch\n[1]left with left\n[2]left with right\n[3]right with left\n[4]right with right\n[5]divide\nyour choice: ");
					choice=sc.nextInt();
					switch(choice){
						case 1:{
							status1[0]+=status2[0];
							g.updateP1(status1);
						};break;
						case 2:{
							status1[0]+=status2[1];
							g.updateP1(status1);
						};break;
						case 3:{
							status1[1]+=status2[0];
							g.updateP1(status1);
						};break;
						case 4:{
							status1[1]+=status2[1];
							g.updateP1(status1);
						};break;
						case 5:{
							System.out.print("Enter New Left: ");
							status2[0]=sc.nextInt();
							System.out.print("Enter New Right: ");
							status2[1]=sc.nextInt();
							g.updateP2(status2);
						};break;
					}
				};break;
			}
			
			status1=g.getP1(); status2=g.getP2();
			if(status1[0]==0&&status1[1]==0){
				System.out.println(g.getP2Name()+" WINS THE GAME!");
				done=1;
			}
			else if(status2[0]==0&&status2[1]==0){
				System.out.println(g.getP1Name()+" WINS THE GAME!");
				done=1;
			}
			else chance++;
			
			
		}
	}
}
