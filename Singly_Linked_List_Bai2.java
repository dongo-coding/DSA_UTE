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
        System.out.println();
    }

    static Node addElement(Node p,int x){
        Node temp = createNode(x);
        p.next = temp;
        return temp;
    }
    
    static Node deleteAll(Node head, int x){
        while(head!=null && head.data==x){
            head=head.next;
        }
        
        Node p=head;
        
        while (p != null && p.next != null) {
            if (p.next.data == x) {
                p.next = p.next.next;
            } else {
                p = p.next;
            }
        }
        return head;
    }
    
    static void sortList(Node head) {
        for (Node i = head; i != null; i = i.next) {
            for (Node j = i.next; j != null; j = j.next) {
                if (i.data > j.data) {
                    int temp = i.data;
                    i.data = j.data;
                    j.data = temp;
                }
            }
        }
    }
    
    static void sortEvenValues(Node head) {
        int[] even = new int[10000];
        int count = 0;

        Node p = head;
        while (p != null) {
            if (p.data % 2 == 0) {
                even[count++] = p.data;
            }
            p = p.next;
        }
        
         for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if (even[i] > even[j]) {
                    int tmp = even[i];
                    even[i] = even[j];
                    even[j] = tmp;
                }
            }
        }

        
        p = head;
        int idx = 0;
        while (p != null) {
            if (p.data % 2 == 0) {
                p.data = even[idx++];
            }
            p = p.next;
        }
    }


public static void main (String[] args){
     Scanner sc = new Scanner(System.in);
    Node head = createNode(6);
        Node p = head;

        int[] a = {3, 2, 5, 1, 4, 7};
        for (int x : a) {
            p = addElement(p, x);
        }

        System.out.println("Danh sách ban đầu:");
        printList(head);

        sortList(head);
        System.out.println("Sau khi sắp xếp tăng dần:");
        printList(head);
        
         System.out.print("Nhập giá trị cần xóa x = ");
        int x = sc.nextInt();

        System.out.println("Sau khi xoá tất cả các giá trị x trong Linked List:");
        head = deleteAll(head, x);
        printList(head);

        System.out.println("Sắp xếp số chẵn theo thứ tự tăng dần:");
        sortEvenValues(head);
        printList(head);
    }
}
