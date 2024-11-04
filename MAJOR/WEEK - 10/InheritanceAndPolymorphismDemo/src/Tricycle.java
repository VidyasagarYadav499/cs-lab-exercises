class Tricycle extends Cycle {
    public Tricycle() {
        super(3);
    }

    @Override
    public void ride() {
        System.out.println("Riding a tricycle with " + wheels + " wheels.");
    }
}