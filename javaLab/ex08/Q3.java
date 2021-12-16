import java.util.*;

class Q3{
	public static void main( String args[]){
		Scanner sc= new Scanner( System.in);
		int ele;
		LinkedList<Integer> l= new LinkedList<Integer> ();
		
		System.out.print("Enter the number of elements: ");
		int n=sc.nextInt();
		System.out.print("Enter the elements: ");
		for (int i=0; i<n; ++i){
			l.add(sc.nextInt());
		}
		
		
		while(true){
			char ch= menu(sc);
			if(ch=='a'){
				System.out.print("Enter the element: ");
				ele= sc.nextInt();
				l.addFirst(ele);
				l.addLast(ele);
			}
			
			else if(ch=='b'){
				l.pollFirst(); l.pollLast();
			}	
			
			else if(ch=='c'){
				System.out.print("Enter element:");
				ele= sc.nextInt();
				System.out.print("Enter the position:");
				int pos= sc.nextInt();
				l.add(pos-1,ele);
			}
			else if(ch=='d'){
				System.out.print("Enter the element to be deleted:");
				ele= sc.nextInt();
				l.remove(l.indexOf(ele));
			}
			else if( ch=='e'){
				System.out.print("Enter the element to be searched for:");
				ele= sc.nextInt();
				if (l.indexOf(ele)>-1)
					System.out.println("Element found at position "+ (l.indexOf(ele)+1));
				else
					System.out.println("Element not found!");
			}
			else if( ch=='f'){
				System.out.println("The list in forward direction is "+l);
				Collections.reverse(l);
				System.out.println("The list in backward direction is "+ l);
				Collections.reverse(l);
			}
			else if( ch=='g'){
				Collections.sort(l);
			}
			else if( ch=='h'){
				System.out.print("Enter element to be replaced:");
				ele= sc.nextInt();
				LinkedList <Integer> l2= new LinkedList<Integer> ();
				System.out.print("Enter the number of elements of the new list:");
				n=sc.nextInt();
				System.out.print("Enter the elements:");
				for (int i=0; i<n; ++i){
					l2.add(sc.nextInt());
				}
				
				LinkedList l1= new LinkedList();
				l1.addAll(l);
				
				l1.set(l1.indexOf(ele), l2);
				
				
				l.clear();
				l.addAll(l1);
			}
			
			else if( ch=='i'){
				Set set= new HashSet ();
				set.addAll(l);
				l.clear();
				l.addAll(set);
			}
			
			else{
				break;
			}
			
			if(ch!='f')
				System.out.println("The list is "+ l);
			
		}
		
		sc.close();
		
	}
	
	public static char menu(Scanner sc){
		System.out.println("\nMENU:\n\n[a] Insert element on both sides\n[b] Delete element on both sides\n[c] Insert an element\n[d] Delete element\n[e] Search element\n[f] Display list in forward and backward order\n[g] Sort the elements\n[h] Replace element\n[i] Remove duplicate elements\n[j] Exit");
		
		System.out.print("your choice: ");
		return( sc.next().charAt(0));
	}
}
