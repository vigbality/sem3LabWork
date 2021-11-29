import shapes.*;
public class Q1{
    public static void main(String[] args) {
        System.out.println("*********** square side 10* **************");
        Square squareObj= new Square(10);
        System.out.println("Area: " + squareObj.returnArea());
        System.out.println("Perimeter: " + squareObj.returnPerimeter());
        System.out.println("*********** triangle h 10 b 8.66 **************");
        Triangle triangleObj = new Triangle(10, 8.66);
        System.out.println("Area: " + triangleObj.returnArea());
        System.out.println("Perimeter: " + triangleObj.returnPerimeter(10,10,10));
        System.out.println("*********** circle r 100 ***********");
        Circle circleObj = new Circle(100);
        System.out.println("Area: " + circleObj.returnArea());
        System.out.println("Perimeter: " + circleObj.returnPerimeter());
        System.out.println("*************************************");
    }
    
    
}
