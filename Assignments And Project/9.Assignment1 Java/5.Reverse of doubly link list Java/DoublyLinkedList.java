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
    
    public void reverseMade(){
        Node curr = head;
        Node tempStore = new Node(0);
        
        if(head==null){
            System.out.println("Empty List");  
            return;  
        }

        head =tail;
        tail = curr;
        while(curr != null) {  
            tempStore = curr.next;
            curr.next = curr.previous;
            curr.previous=tempStore;
            curr=curr.previous;
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

        dl.reverseMade();
        
        dl.display();
    }  
}  