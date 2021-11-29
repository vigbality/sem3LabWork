package shapes;

public class Triangle {
    double height, base;
    public Triangle(double height, double base){
        this.height=height;
        this.base=base;
    }
    public double returnArea(){
        return (0.5*base*height);
    }
    public double returnPerimeter(double a, double b, double c){
        return (a+b+c);
    }
}
