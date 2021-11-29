package shapes;
public class Square{
    float side;
    public Square(float side){
        this.side=side;
    }
    public double returnArea(){
        return (side*side);
    }
    public double returnPerimeter(){
        return (4*side);
    }
}
