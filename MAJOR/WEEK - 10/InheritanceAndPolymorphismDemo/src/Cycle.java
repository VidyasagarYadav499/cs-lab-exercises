class Cycle {
    protected int wheels;

    public Cycle(int wheels) {
        this.wheels = wheels;
    }

    public void ride() {
        System.out.println("Riding a cycle with " + wheels + " wheels.");
    }

    public int getWheels() {
        return wheels;
    }
}