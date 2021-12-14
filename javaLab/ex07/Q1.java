import java.util.*;
class max<T extends Comparable<T>>{
  T[] arr;
  max(T[] arr){
    this.arr = arr;
  }

  T compare(){
    T maxVal = arr[0];
    for(int i = 1; i < arr.length; i++){
      if(arr[i].compareTo(maxVal) > 0){
        maxVal = arr[i];
      }
    }
    return maxVal;
  }
}

public class Q1{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    System.out.println("Character Array");
    System.out.print("Enter Size of array: ");
    int size = sc.nextInt();
    Character[] charArr = new Character[size];
    for(int i = 0; i < size; i++){
      System.out.print("\nElement " + (i + 1) + ": ");
      charArr[i] = sc.next().charAt(0);
    }
    max<Character> m1 = new max<Character>(charArr);
    System.out.println("\nThe largest element: " + m1.compare());


    System.out.println("\n\nInteger Array");
    System.out.print("\nEnter Size of array: ");
    size = sc.nextInt();
    Integer[] intArr = new Integer[size];
    for(int i = 0; i < size; i++){
      System.out.print("\nElement " + (i + 1) + ": ");
      intArr[i] = sc.nextInt();
    }
    max<Integer> m2 = new max<Integer>(intArr);
    System.out.println("\nThe largest element: " + m2.compare());
    sc.close();
  }
}

