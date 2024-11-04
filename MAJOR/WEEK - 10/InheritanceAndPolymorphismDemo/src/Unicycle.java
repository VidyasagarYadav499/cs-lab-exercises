class Unicycle extends Cycle {
    public Unicycle() {
        super(1);
    }

    @Override
    public void ride() {
        System.out.println("Riding a unicycle with " + wheels + " wheel.");
    }
}