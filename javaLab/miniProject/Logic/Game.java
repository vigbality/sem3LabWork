package Logic;
public class Game{
	int p1Left,p1Right,p2Left,p2Right;
	String p1Name,p2Name;
	public Game(String p1, String p2){
			p1Left=1; p1Right=1;
			p2Left=1; p2Right=1;
			p1Name=p1; p2Name=p2;
	}
	public int[] getP1(){
		int []status = new int[2];
		status[0]=p1Left; status[1]=p1Right;
		return status;
	}
	public int[] getP2(){
		int []status = new int[2];
		status[0]=p2Left; status[1]=p2Right;
		return status;
	}
	public void updateP1(int []status){
		p1Left=status[0]; p1Right=status[1];
		p1Left%=5;p1Right%=5;
	}
	public void updateP2(int []status){
		p2Left=status[0]; p2Right=status[1];
		p2Left%=5;p2Right%=5;
	}
	public String getP1Name(){
		return p1Name;
	}
	public String getP2Name(){
		return p2Name;
	}
}
