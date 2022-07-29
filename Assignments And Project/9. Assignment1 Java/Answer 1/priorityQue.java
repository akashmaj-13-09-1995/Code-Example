import java.util.*;

public class priorityQue {
    		
    Queue<Integer> pq = new PriorityQueue<>();

    public void add(Integer val){
        pq.add(val);
    }
    public void deleteMin(){
        pq.remove();    
    }
    
    public void display(){
        System.out.print(pq);
    }
    
	public static void main(String args[])
	{
        priorityQue priorQu = new priorityQue();
        
        
		priorQu.add(3);
		priorQu.add(5);
		priorQu.add(7);
		priorQu.add(1);
		priorQu.add(2);
		priorQu.add(4);

        priorQu.deleteMin();

        priorQu.display();
        
    	}
}
