// This is an implementation of a Stack data structure with basic push and pop operations.

public class Stack {
    private int maxSize;
    private int top;
    private int[] stackArr;

    public Stack(int size) {
        maxSize = size;
        stackArr = new int[maxSize];
        top = -1;
    }

    public void push(int value) {
        if (top == maxSize - 1) {
            System.out.println("Stack Overflow!");
        } else {
            top++;
            stackArr[top] = value;
        }
    }

    public void pop() {
        if (top == -1) {
            System.out.println("Stack Underflow!");
            return;
        } else {
            top--;
        }
    }

    public void print() {
        if (top == -1) System.out.println("Empty Stack");
        for (int i = top; i >= 0; i--) {
            System.out.println(stackArr[i]);
        }
    }
}
