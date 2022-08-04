public class SinglyLinkedListForQueue{    
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
           
    public void add(int data) {    
        Node newNode = new Node(data);    
            
        if(head == null) {    
            head = newNode;    
            tail = newNode;    
        }    
        else {   
            if(tail.data<=data)
            {
                tail.next = newNode;    
                tail = newNode; 
            }
            else{
                Node current = head;
                Node temp=null;
                while(current!=null){
                    if(current.data<data){
                        temp = current;
                        current=current.next;
                    }
                    else break;
                }
                
                if(temp==null){
                    newNode.next=current;
                    head=newNode;
                }else{
                    temp.next = newNode;
                    newNode.next = current;
                }
            }
        }    
    }    
    
    public void deleteMin(){
        head=head.next;
    }
        
    
     public int size(){
        Node current = head;
        int count = 0;
        while(current!=null){
            count++;
            current=current.next;
        }
        return count;
    }
    
    public void display() {    
        Node current = head;    
            
        if(head == null) {    
            System.out.println("List is empty");    
            return;    
        }    
        System.out.println("Nodes of singly linked list: ");    
        while(current != null) {    
            System.out.print(current.data + " ");    
            current = current.next;    
        }    
        System.out.println();    
    }    
        
    public static void main(String[] args) {    
            
        SinglyLinkedListForQueue sl = new SinglyLinkedListForQueue();    
        
        sl.add(7);      
        sl.add(1);    
        sl.add(2);    
        sl.add(5);          
        sl.add(9);          
        sl.add(3);  
        sl.add(4);    
            
        sl.display(); 
        System.out.println("Total Element: "+ sl.size());
        sl.deleteMin();
        
        sl.display(); 
         System.out.println("Total Element after deleteMin(): "+ sl.size());

        
    }    
}    