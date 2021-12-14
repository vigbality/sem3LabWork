import java.util.*;

class Driver
{
    public static void main(String[] args) 
    {
    	ArrayList<Integer> l1= new ArrayList();
    	ArrayList<Integer> l2= new ArrayList();
    	ArrayList<Integer> l3= new ArrayList();
    	ArrayList<Integer> l4= new ArrayList();
    	ArrayList<Integer> l5= new ArrayList();
    	int ch=0;
    	Scanner sc= new Scanner( System.in);
        System.out.print("Enter size of ArrayList 1:");
        int n1=sc.nextInt();
        sc.nextLine();
        for (int i=0; i<n1; ++i)
        {
        	System.out.print("Enter element " + (i+1)+":");
        	l1.add(sc.nextInt());
        }
        
        System.out.print("Enter size of ArrayList 2:");
        int n2=sc.nextInt();
        sc.nextLine();
        for (int i=0; i<n2; ++i)
        {
        	System.out.print("Enter element " + (i+1)+":");
        	l2.add(sc.nextInt());
        }
        
        while(ch!=5)
        {
		System.out.println("\n1.Merge two lists\t2.Find union of two lists\t3.Find intersection of two lists\t4.compare two lists\t\t5.Exit program\n");
		System.out.print("Enter choice:");
		ch=sc.nextInt();
		
		if(ch==1)
		{
			l3.addAll(l1);
			l3.addAll(l2);
			System.out.println("The merged ArrayList is " + l3);
		}
		
		else if (ch==2)
		{
			Set<Integer> set = new HashSet<Integer>();
			set.addAll(l3);
			l4.addAll(set);
			
			System.out.println("The union ArrayList is " + l4);
		}
		
		else if( ch==3)
		{
			for( Integer v: l1)
				if(l2.contains(v))
					l5.add(v);
			
			System.out.println("The intersection ArrayList is " + l5);
		}
		
		else if( ch==4)
		{
			if(l1.equals(l2))
				System.out.println("The two arraylists are equal");
			else
				System.out.println("The two arrayLists are not equal!");
		}
	}

}
}
