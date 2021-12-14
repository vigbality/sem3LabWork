import java.util.*;
class Sort<T extends Comparable<T>>{
  int size;
  T[] data;

  Sort(int size, T[] data){
    this.size = size;
    this.data = data;
  }

  void sortArray(){
    for(int i = 0; i < size; i++){
      T small = data[i];
      int pos = i;
      for(int j = i; j < size; j++){
        if(data[j].compareTo(small) < 0){
          small = data[j];
          pos = j;
        }
      }
      T temp = data[pos];
      data[pos] = data[i];
      data[i] = temp;
    }
    System.out.print("\nThe sorted array\n");
    for(int i = 0; i < size; i++){
      System.out.print(data[i] + " ");
    }
  }
}

class Q3{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter Integer array size: ");
    int intSize = sc.nextInt();
    Integer[] intArr = new Integer[intSize];
    Sort<Integer> intS = new Sort<>(intSize, intArr);
    for(int i = 0; i < intSize; i++){
      System.out.print("\nEnter element " + (i + 1) + ": ");
      intArr[i] = sc.nextInt();
    }
    intS.sortArray();
    System.out.print("\nEnter Character array size: ");
    int charSize = sc.nextInt();
    Character[] charArr = new Character[charSize];
    Sort<Character> charS = new Sort<>(charSize, charArr);
    for(int i = 0; i < charSize; i++){
      System.out.print("\nEnter element " + (i + 1) + ": ");
      charArr[i] = sc.next().charAt(0);
    }
    charS.sortArray();
    System.out.print("\nEnter Double array size: ");
    int doubSize = sc.nextInt();
    Double[] doubArr = new Double[doubSize];
    Sort<Double> doubS = new Sort<>(doubSize, doubArr);
    for(int i = 0; i < doubSize; i++){
      System.out.print("\nEnter element " + (i + 1) + ": ");
      doubArr[i] = sc.nextDouble();
    }
    doubS.sortArray();
  }
}