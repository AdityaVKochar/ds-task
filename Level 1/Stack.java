public class Stack<T> {

    Node<T> top;

    Stack() {
        top = null;
    }

    Stack(T d) {
        top = new Node<T>(d);
    }

    void push(T d) {
        if (top == null) {
            top = new Node<T>(d);
            return;
        }
        top = new Node<T>(d, top);
    }

    T top() {
        if (top == null) {
            return null;
        }
        return top.data;
    }

    T pop() {
        if (top == null) {
            return null;
        }
        T data = top.data;
        top = top.next;
        return data;
    }

    T getMin() {
        if (top == null) {
            return null;
        }
        T min = top.data;
        Node<T> temp = top;
        while (temp != null) {
            if (((Comparable<T>) min).compareTo(temp.data) > 0) {
                min = temp.data;
            }
            temp = temp.next;
        }
        return min;
    }

    T getMax() {
        if (top == null) {
            return null;
        }
        T max = top.data;
        Node<T> temp = top;
        while (temp != null) {
            if (((Comparable<T>) max).compareTo(temp.data) < 0) {
                max = temp.data;
            }
            temp = temp.next;
        }
        return max;
    }
    
}
