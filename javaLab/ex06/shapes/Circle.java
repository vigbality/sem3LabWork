package shapes;

public class Circle {
    float radius;
    public Circle(float radius){
        this.radius=radius;
    }
    public double returnArea(){
        return (3.14*radius*radius);
    }
    public double returnPerimeter(){
        return (2*3.14*radius);
    }
}
