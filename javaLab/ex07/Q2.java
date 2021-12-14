import java.util.*;

interface StackAdt<T>{
    void push(T x);
    void pop();
    Boolean isFull();
    Boolean isEmpty();
    void display();
}


class StackImpl<T> implements StackAdt<T>{
  int top = -1, size;
  T[] data; 

  StackImpl(int size, T[] data){
    this.size = size;
    this.data = data; 
  }

  public Boolean isFull(){
    if(top == size){
      top--;
      return true;
    }
    return false;
  }

  public void push(T x){
    top++;
    if(isFull()){
      System.out.print("\nStack full! Cannot push!");
    }
    else{
      data[top] = x;
    }
  }

  public Boolean isEmpty(){
    if(top == -1){
      return true;
    }
    return false;
  }

  public void pop(){
    if(isEmpty()){
      System.out.print("\nStack empty! Cannot pop!");
    }
    else{
      top--;
    }
  }

  public void display(){
    if(isEmpty()){
      System.out.print("\nStack empty!");
    }
    else{
      int i = top;
      System.out.print("\nStack\n");
      System.out.print("top->");
      while(i >= 0){
        System.out.print(data[i] + " ");
        i--;
      }
    }
  }
}

class Q2{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter Integer stack size: ");
    int intSize = sc.nextInt();
    Integer[] intArr = new Integer[intSize];
    StackImpl<Integer> is = new StackImpl<Integer>(intSize, intArr);
    
    System.out.print("\nEnter Character stack size: ");
    int charSize = sc.nextInt();
    Character[] charArr = new Character[charSize];
    StackImpl<Character> cs = new StackImpl<>(charSize, charArr);

    System.out.print("\nEnter Double stack size: ");
    int doubSize = sc.nextInt();
    Double[] doubArr = new Double[doubSize];
    StackImpl<Double> ds = new StackImpl<>(doubSize, doubArr);
    
    int out=0,in,ch;
    while(out==0){
      System.out.print("\nEnter\n1 to create an Integer Stack\n2 for Character Stack\n3 for Double Stack\n4 to quit\n\n: ");
      ch = sc.nextInt();
      in=0;
      switch(ch){
        case 1:{
            while(in==0){
                System.out.print("\nEnter\n1 to Push\n2 to Pop\n3 to quit\n\n: ");
                ch = sc.nextInt();
                switch(ch){
                case 1:{
                    System.out.print("\nEnter element to be pushed: ");
                    int ele = sc.nextInt();
                    is.push(ele);
                    is.display();
                };break;
                case 2:{
                    is.pop();
                    is.display();

                };break;
                case 3:{
                    in=1;
                };break;
              }
            }
        };break;

        case 2:{
            while(in==0){
                System.out.print("\nEnter\n1 to Push\n2 to Pop\n3 to quit\n\n: ");
                ch = sc.nextInt();
                switch(ch){
                    case 1:{
                    System.out.print("\nEnter element to be pushed: ");
                    char ele = sc.next().charAt(0);
                    cs.push(ele);
                    cs.display();
                    };break;
                    case 2:{
                    cs.pop();
                    cs.display();
                    };break;
                    case 3:{
                        in=1;
                    };break;
                }
            }
        };break;

        case 3:{
          while(in==0){
            System.out.print("Enter\n1 to Push\n2 to Pop\n3 to quit\n\n: ");
            ch = sc.nextInt();
            switch(ch){
                case 1:{
                System.out.print("\nEnter element to be pushed: ");
                double ele = sc.nextDouble();
                ds.push(ele);
                ds.display();
                };break;
                case 2:{
                ds.pop();
                ds.display();
                };break;
                case 3:{
                    in=1;
                };break;
                
            }
        }
        };break;
        case 4:{
          out=1;
        };break;
        
      }
    }
  }
}
