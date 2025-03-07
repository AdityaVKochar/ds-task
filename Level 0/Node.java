public class Node<T> {
    T data;
    Node<T> next, prev;

    Node(T d) {
        data = d;
        next = prev = null;
    }

    Node() {
        next = prev = null;
    }

    Node(T d, Node<T> n, Node<T> p) {
        data = d;
        next = n;
        prev = p;   
    }

    Node(T d, Node<T> n) {
        data = d;
        next = n;
        prev = null;
    }

    
}