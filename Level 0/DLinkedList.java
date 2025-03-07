public class DLinkedList<T> {
    
    private Node<T> head, tail;

    DLinkedList() {
        head = tail = null;
    }

    DLinkedList(T d) {
        head = tail = new Node<T>(d);
    }

    DLinkedList(Node<T> n) {
        head = tail = n;
    }

    DLinkedList(T arr[]) {

        if(arr.length==0) {
            head = tail = null;
            return;
        }

        head = tail = new Node<T>(arr[0]);
        for (int i = 1; i < arr.length; i++) {
            tail.next = new Node<T>(arr[i], null, tail);
            tail = tail.next;
        }
    }

    void addTail(T d) {
        if (head == null) {
            head = tail = new Node<T>(d);
            return;
        }
        tail.next = new Node<T>(d, null, tail);
        tail = tail.next;
    }

    void addHead(T d) {
        if (head == null) {
            head = tail = new Node<T>(d);
            return;
        }
        head = new Node<T>(d, head, null);
        head.next.prev = head;
    }

    void printForward() {
        Node<T> temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    void printBackward() {
        Node<T> temp = tail;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.prev;
        }
        System.out.println();
    }

    

}
