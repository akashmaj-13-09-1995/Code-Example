public class SinglyLinkedList {     
    class Node{    
        int data;    
        Node next;    
            
        public Node(int data) {    
            this.data = data;    
            this.next = null;    
        }    
    }    
     
      
    public Node head = null;    
    public Node tail = null;    
    
    public void addNode(int data) {   
        Node newNode = new Node(data);    
            
        if(head == null) {     
            head = newNode;    
            tail = newNode;    
        }    
        else {      
            tail.next = newNode;       
            tail = newNode;    
        }    
    }    
          
    public void display() {      
        Node curr = head;    
            
        if(head == null) {    
            System.out.println("Empty List");    
            return;    
        }    
        System.out.println("Nodes: ");    
        while(curr != null) {       
            System.out.print(curr.data + " ");    
            curr = curr.next;    
        }    
        System.out.println();    
    }
    
    public int size(){
        Node curr = head;
        int count = 0;
        while(curr!=null){
            count++;
            curr=curr.next;
        }
        return count;
    }
    
    public void swap(int pos,int next_prev){
        if(size()==0){
            System.out.println("Empty List");
            return; 
        }
        
     
        
        if(size()<pos){           
            System.out.println("No Element is present in position: "+pos);
            return;
        }
        else if(next_prev==1){
            if(size()==pos)
                System.out.println("No Next adjacent Element is present after Positon: "+pos);
            else if(size()==2){
                    Node curr=head;
                    tail=head;
                    head=curr.next;
                    head.next=tail;
                    tail.next=null;
                    return;
            }
            else if(pos==1){
                Node temp = head.next;
                head.next=head.next.next;
                temp.next=head;
                head=temp;
            }
            else{
                Node curr = head;
                int currpos=1;
                while(currpos!=pos-1){
                    curr=curr.next;
                    currpos++;
                }
                
                Node temp;
                temp = curr.next;
                curr.next = temp.next;
                temp.next=curr.next.next;
                curr.next.next=temp;
                return;
            }
        }
        else if(next_prev==0){
            if(1==pos)
                System.out.println("No Previous adjacent Element is present before Positon: "+pos);
            else if(size()==2){
                    Node curr=head;
                    tail=head;
                    head=curr.next;
                    head.next=tail;
                    tail.next=null;
			  return;
            }
            else if(pos==2){
                Node temp = head.next;
                head.next=head.next.next;
                temp.next=head;
                head=temp;
		    return;
            }
            else{
                Node curr = head;
                int currpos=1;
                while(currpos!=pos-2){
                    curr=curr.next;
                    currpos++;
                }
                
                Node temp;
                temp = curr.next;
                curr.next = temp.next;
                temp.next=curr.next.next;
                curr.next.next=temp;
                return;
            }
        }
    }
        
    public static void main(String[] args) {    
            
        SinglyLinkedList sl = new SinglyLinkedList();    
                
        sl.addNode(1);    
        sl.addNode(2);    
        sl.addNode(3);    
        sl.addNode(4);    
              
        sl.display(); 
        
        sl.swap(1,0); //Swap funtion takes the position where we want to swap and next_prev value(0/1),
        //0 for swap with Previous element and 1 for next Element
                    // System.out.println(sList.size());

        sl.display();
        
        sl.swap(3,0);
        
        sl.display();

    }    
}    