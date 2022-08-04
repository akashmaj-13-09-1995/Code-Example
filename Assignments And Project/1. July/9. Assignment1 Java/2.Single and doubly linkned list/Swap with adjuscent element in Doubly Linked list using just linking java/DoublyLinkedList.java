public class DoublyLinkedList {  
    
    class Node{  
        int data;  
        Node previous;  
        Node next;  
  
        public Node(int data) {  
            this.data = data;  
        }  
    }  
  
    Node head, tail = null;  
  
    public void add(int data) {  
        Node newNode = new Node(data);  
  
        if(head == null) {  
            head = tail = newNode;  
            head.previous = null;  
            tail.next = null;  
        }  
        else {  
            tail.next = newNode;  
            newNode.previous = tail;  
            tail = newNode;  
            tail.next = null;  
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
        int count=0;
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
                System.out.println("No Next adjuscent Element is present after Positon: "+pos);
            else if(size()==2){
                    head=tail;
                    tail = head.previous;
                    head.next=head.previous;
                    head.previous=null;
                    tail.previous=tail.next;
                    tail.next=null;
                    return;
            }
            else if(pos==1){
                Node temp = head.next;
                head.next=head.next.next;
                temp.next.previous=head;
                head.previous = temp;
                temp.next = head;
                temp.previous = null;
                head = temp;
                return;
            }
            else{
                Node curr = head;
                int currpos=1;
                while(currpos!=pos){
                    curr=curr.next;
                    currpos++;
                }
                
                Node temp = curr.next;
                if(temp.next!=null){
                curr.next=temp.next;
                curr.next.previous=curr;
                curr.previous.next = temp;
                temp.previous = curr.previous;
                temp.next = curr;
                curr.previous = temp;
                    return;
                }
                else{
                    curr.previous.next=temp;
                    temp.previous=curr.previous;
                    temp.next=curr;
                    curr.next=null;
                    curr.previous=temp;
                    tail=curr;
                    return;
                }
            }
        }
        
        else if(next_prev==0){
            if(1==pos)
                System.out.println("No Previous adjuscent Element is present before Positon: "+pos);
            else if(size()==2){
                    head=tail;
                    tail = head.previous;
                    head.next=head.previous;
                    head.previous=null;
                    tail.previous=tail.next;
                    tail.next=null;
                    return;
            }
            else if(pos==size()){
                Node temp = tail.previous;
                tail.previous=tail.previous.previous;
                temp.previous.next=tail;
                tail.next = temp;
                temp.previous = tail;
                temp.next = null;
                tail = temp;
                return;
            }
            else{
                Node curr = head;
                int currpos=1;
                while(currpos!=pos){
                    curr=curr.next;
                    currpos++;
                }
                
                Node temp = curr.previous;
                if(temp.previous!=null){
                curr.previous=temp.previous;
                curr.previous.next=curr;
                curr.next.previous = temp;
                temp.next = curr.next;
                temp.previous = curr;
                curr.next = temp;
                    return;
                }
                else{
                    temp.next=curr.next;
                    curr.next.previous=temp;
                    curr.previous=null;
                    curr.next=temp;
                    temp.previous=curr;
                    head=curr;
                    return;
                }
            }
        }
        
        
    }
    
    public static void main(String[] args) {  
  
        DoublyLinkedList dl = new DoublyLinkedList();  
        dl.add(1);  
        dl.add(2);  
        dl.add(3);  
        dl.add(4);  
        dl.add(5);  
  
        dl.display();  

        dl.swap(1,0);//Swap funtion takes the position where we want to swap and next_prev value(0/1),
        //0 for swap with Previous element and 1 for next Element
        
        dl.display();
        
        dl.swap(3,0);
        
        dl.display();
    }  
}  