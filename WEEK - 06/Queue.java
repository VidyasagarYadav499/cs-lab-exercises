public class Queue {
    private int front;
    private int rear;
    private int size;
    private int[] qArr;

    Queue(int size) {
        this.size = size;
        qArr = new int[size];
        front = -1;
        rear = -1;
    }

    public void enqueue(int value) {
        if (rear >= size - 1) {
            System.out.println("Queue is full!");
            return;
        }

        if (front == -1) {
            qArr[++front] = value;
            rear++;
        } else {
            rear++;
            qArr[rear] = value;
        }
    }

    public void dequeue() {
        if (rear == -1) {
            System.out.println("Queue is empty! Deletion not possible!");
            return;
        }
        rear--;
    }

    public void print() {
        if (rear == -1) {
            System.out.println("Queue is empty!");
            return;
        }
        for (int i = front; i <= rear; i++) {
            System.out.print(qArr[i] + " ");
        }
    }
}
