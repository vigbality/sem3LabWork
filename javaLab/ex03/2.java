import java.util.Scanner;
abstract class Shape{
	protected String color="red";
	public Shape(){}
	public Shape(String colorp){
		color=colorp;
	}
	public String getColor(){
		return color;
	}
	public void setColor(String colorp){
		color=colorp;
	}
}


class Circle extends Shape{
	protected float radius=(float)1.0;
	public Circle(){ }
	public Circle(float radiusp){
		radius=radiusp;
	}
	public Circle(float radiusp,String colorp){
		super(colorp);
		radius=radiusp;
	}
	public float getRadius(){
		return radius;
	}
	public void setRadius(float radiusp){
		radius=radiusp;
	}
	public float getArea(){
		return (float)3.14*radius*radius;
	}
	public float getPerimeter(){
		return (float)(2*3.14*radius);
	}
	
}

class Rectangle extends Shape{
	protected float width=(float)1.0;
	protected float length=(float)1.0;
	public Rectangle(){}
	public Rectangle(float widthp, float lengthp){
		width=widthp;
		length=lengthp;
	}
	public Rectangle(float widthp, float lengthp, String colorp){
		super(colorp);
		width=widthp;
		length=lengthp;
	} 
	public float getWidth(){
		return width;
	}
	public void setWidth(float widthp){
		width=widthp;
	}
	public float getLength(){
		return length;
	}
	public void setLength(float lengthp){
		length=lengthp;
	}
	public float getArea(){
		return (float)length*width;
	}
	public float getPerimeter(){
		return (float)2*(length+width);
	}
	
}

class Square extends Rectangle{
	public Square(){}
	public Square(float side){
		super(side,side);
	}
	public Square(float side, String color){
		super(side,side,color);
	}
	public float getSide(){
		return super.length;
	}
	public void setSide(float side){
		super.length=side;
		super.width=side;
	}
}


class TestShape{
	public static void main(String []args){
		Scanner so= new Scanner(System.in);
		int n,u;System.out.println("Enter no of entries: ");
		n=so.nextInt();
		Shape []data= new Shape[n];
		int []shapeNo=new int[n];
		for(int i=0;i<n;i++){
			System.out.println("\n*************************************************");
			System.out.println("Enter\n1 for circle\n2 for rectangle\n3 for square");
			u=so.nextInt();
			System.out.println("*************************************************\n");
			switch(u){
				case 1:{
					float rad;
					System.out.println("Enter radius:");
					rad=so.nextFloat();
					data[i]=new Circle(rad);
					shapeNo[i]=u;
				};break;
				case 2:{
					float l,w;
					System.out.println("Enter lenght:");
					l=so.nextFloat();
					System.out.println("Enter Width:");
					w=so.nextFloat();
					data[i]=new Rectangle(w,l);
					shapeNo[i]=u;
				};break;
				case 3:{
					float sid;
					System.out.println("Enter side:");
					sid=so.nextFloat();
					data[i]=new Square(sid);
					shapeNo[i]=u;
				};break;
			}
		}
		for(int j=0;j<n;j++){
			System.out.println("\n************************Shape: "+(j+1)+"*************************");
			switch(shapeNo[j]){
				case 1:{
					System.out.println("Area: "+ ((Circle) data[j]).getArea());
					System.out.println("Perimeter: "+ ((Circle) data[j]).getPerimeter());
				};break;
				case 2:{
					System.out.println("Area: "+ ((Rectangle) data[j]).getArea());
					System.out.println("Perimeter: "+ ((Rectangle) data[j]).getPerimeter());
				};break;
				case 3:{
					System.out.println("Area: "+ ((Square) data[j]).getArea());
					System.out.println("Perimeter: "+ ((Square) data[j]).getPerimeter());
				};break;
			}			
		}
		so.close();
	}
}

