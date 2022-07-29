import java.util.LinkedList;
import java.util.Queue;

public class StackUsingQueue {
    Queue<Integer> q1= new LinkedList<>();
    Queue<Integer> q2= new LinkedList<>();

    public void push(Integer val){
        q1.add(val);
    }
    
    public void pop(){
        int size = q1.size();
        while(size>0)
        {
            q2.add(q1.remove());
            size--;
            
        }
        q2.remove();
        size = q2.size();
        while(size>0)
        {
            q1.add(q2.remove());
            size--;
            
        }
        
    }
    
    public void Display(){
        System.out.println(q1);
    }
    
    
	public static void main(String[] args)
	{
	    
	    StackUsingQueue st = new StackUsingQueue();
	    st.push(1);
	    st.push(3);
	    st.push(6);
	    st.push(6);
	    st.push(2);
	    
	    st.Display();
	    
	    st.pop();
	    
	    st.Display();
	    
	    st.pop();
	    
	    st.Display();
	   
	}
}
