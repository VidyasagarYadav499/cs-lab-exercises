class Bicycle extends Cycle {
    public Bicycle() {
        super(2);  // A bicycle has 2 wheels
    }

    @Override
    public void ride() {
        System.out.println("Riding a bicycle with " + wheels + " wheels.");
    }
}