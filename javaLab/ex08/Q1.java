import java.util.*;

class Driver
{
    public static void main(String[] args) 
    {
        ArrayList<String> l= new ArrayList();
        Scanner sc= new Scanner( System.in);
        System.out.print("Enter size of ArrayList:");
        int n1=sc.nextInt();
        sc.nextLine();
        for (int i=0; i<n1; ++i)
        {
        	System.out.print("Enter element " + (i+1)+":");
        	l.add(sc.nextLine());
        }
        
        System.out.print("Enter the string to be appended:");
        String s= sc.nextLine();
        l.add(s);
        System.out.println("The ArrayList is " + l);
        System.out.print("Enter the string to be inserted at specific position:");
        s=sc.nextLine();
        System.out.print("Enter the position of insertion:");
        int pos= sc.nextInt();
        sc.nextLine();
        l.add(pos-1, s);
        System.out.println("The ArrayList is " + l);
         
        System.out.print("Enter the string to be searched:");
        s=sc.nextLine();
        System.out.println("The position of the string is "+ (l.indexOf(s)+1));
        
        System.out.println("The ArrayList is " + l);
        
        System.out.print("Enter the letter:");
        char c= sc.next().charAt(0);
        sc.nextLine();
        System.out.print("The strings with the given letter:");
        for (String v: l)
        {
        	if(v.charAt(0)==c)
        		System.out.print(v+" ");
        		
        }
        
        System.out.print("\nEnter the substring:");
        s=sc.nextLine();
        System.out.print("The strings with the given substring:");
        for (String v: l)
        {
        	if(v.indexOf(s)!=-1)
        		System.out.print(v+" ");
        		
        }
        
        Collections.sort(l);
        
        System.out.println("\nThe sorted ArrayList is " + l);
        
        System.out.print("Enter element to be removed:");
        s=sc.nextLine();
        
        l.remove(s);
        
        System.out.println("The ArrayList is " + l);
        
        System.out.print("Enter element to be replaced:");
        s=sc.nextLine();
        System.out.print("Enter the new string:");
        String s2= sc.nextLine();
        
        l.set(l.indexOf(s),s2);
        
        System.out.println("The ArrayList is " + l);
        
        Set<String> set = new HashSet<String>();
        set.addAll(l);
        l.clear();
        l.addAll(set);
        System.out.println("The ArrayList after removing duplicates is " + l);
        
    }
        
    
}
