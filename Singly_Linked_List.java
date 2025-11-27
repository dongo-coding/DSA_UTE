import java.util.Scanner;

class Node {
    int data;
    Node next;

Node (int x){
    this.data = x;
    this.next=null;
    }
}

public class Main {
    static Node createNode(int x){
        return new Node(x);
    }

    static void printList(Node k){
        Node p=k;
        while(p!=null){
            System.out.print(p.data+" ");
            p=p.next;
        }
    }

    static Node addElement(Node p,int x){
        Node temp = createNode(x);
        p.next = temp;
        return temp;
    }

public static void main (String[] args){
    Scanner sc = new Scanner(System.in);

    int n,x;

    n=sc.nextInt();
    x=sc.nextInt();

    Node k = createNode(x);

    Node p=k;

    for(int i=1;i<n;i++){
        x=sc.nextInt();
        p=addElement(p,x);
    }

    printList(k);
    sc.close();
    }
}
