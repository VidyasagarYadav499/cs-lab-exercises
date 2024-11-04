public class Main {
    public static void main(String[] args) {
        Cycle myBicycle = new Bicycle();
        Cycle myTricycle = new Tricycle();
        Cycle myUnicycle = new Unicycle();

        myBicycle.ride();
        myTricycle.ride();  
        myUnicycle.ride();
    }
}