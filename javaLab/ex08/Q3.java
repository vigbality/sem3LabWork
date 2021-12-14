import java.util.*;

class Driver
{
	public static void main( String args[])
	{
		Scanner sc= new Scanner( System.in);
		int ele;
		LinkedList<Integer> l= new LinkedList<Integer> ();
		
		System.out.println("First let us populate the doubly linked list with a few starting values.");
		System.out.print("Enter the number of elements:");
		int n=sc.nextInt();
		System.out.print("Enter the elements:");
		for (int i=0; i<n; ++i)
		{
			l.add(sc.nextInt());
		}
		
		
		while(true)
		{
			char ch= menu(sc);
			if(ch=='a')
			{
				System.out.print("Enter the element:");
				ele= sc.nextInt();
				l.addFirst(ele);
				l.addLast(ele);
			}
			
			else if(ch=='b')
			{
				l.pollFirst(); l.pollLast();
			}	
			
			else if(ch=='c')
			{
				System.out.print("Enter element:");
				ele= sc.nextInt();
				System.out.print("Enter the position:");
				int pos= sc.nextInt();
				l.add(pos-1,ele);
			}
			else if(ch=='d')
			{
				System.out.print("Enter the element to be deleted:");
				ele= sc.nextInt();
				l.remove(l.indexOf(ele));
			}
			else if( ch=='e')
			{
				System.out.print("Enter the element to be searched for:");
				ele= sc.nextInt();
				if (l.indexOf(ele)>-1)
					System.out.println("Element found at position "+ (l.indexOf(ele)+1));
				else
					System.out.println("Element not found!");
			}
			else if( ch=='f')
			{
				System.out.println("The list in forward direction is "+l);
				Collections.reverse(l);
				System.out.println("The list in backward direction is "+ l);
				Collections.reverse(l);
			}
			else if( ch=='g')
			{
				Collections.sort(l);
			}
			else if( ch=='h')
			{
				System.out.print("Enter element to be replaced:");
				ele= sc.nextInt();
				LinkedList <Integer> l2= new LinkedList<Integer> ();
				System.out.print("Enter the number of elements of the new list:");
				n=sc.nextInt();
				System.out.print("Enter the elements:");
				for (int i=0; i<n; ++i)
				{
					l2.add(sc.nextInt());
				}
				
				LinkedList l1= new LinkedList();
				l1.addAll(l);
				
				l1.set(l1.indexOf(ele), l2);
				
				
				l.clear();
				l.addAll(l1);
			}
			
			else if( ch=='i')
			{
				Set set= new HashSet ();
				set.addAll(l);
				l.clear();
				l.addAll(set);
			}
			
			else
			{
				System.out.println("Bye!");
				break;
			}
			
			if(ch!='f')
				System.out.println("The list is "+ l);
			
		}
		
		sc.close();
		
	}
	
	public static char menu(Scanner sc)
	{
		System.out.println("\nMENU:\n\na. Insert element on both sides\t\t\t\tb. Delete element on both sides\nc. Insert an element at a particular position\t\td. Delete a particular element\ne. Search for a particular element\t\t\tf. Display list in forward order and backward order\ng. Sort the elements in LinkedList\t\t\th. Replace one element in the list with another list\ni. Remove duplicate elements\t\t\t\tj. Exit program");
		
		System.out.print("Enter your choice (character):");
		return( sc.next().charAt(0));
	}
}
