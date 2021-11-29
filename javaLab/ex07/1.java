import java.util.*;
class maximum<T extends Comparable <T>>{
  T[] arr;
  maximum(T[] arr){
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

class Q1{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    System.out.println("Character Array");
    System.out.print("Size of array: ");
    int size = sc.nextInt();
    Character[] carr = new Character[size];
    for(int i = 0; i < size; i++){
      System.out.print("\nElement " + (i + 1) + ": ");
      carr[i] = sc.next().charAt(0);
    }
    maximum<Character> m1 = new maximum<Character>(carr);
    System.out.println("\nThe largest element: " + m1.<Character>compare());


    System.out.println("Integer Array");
    System.out.print("\nSize of array: ");
    size = sc.nextInt();
    Integer[] iarr = new Integer[size];
    for(int i = 0; i < size; i++){
      System.out.print("\nElement " + (i + 1) + ": ");
      iarr[i] = sc.nextInt();
    }
    maximum<Integer> m2 = new maximum<Integer>(iarr);
    System.out.println("\nThe largest element: " + m2.<Integer>compare());
  }
}

