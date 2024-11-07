public class Main {
    public static void main(String[] args) {

        SupportHandler tier1Support = new Tier1Handler();
        SupportHandler tier2Support = new Tier2Handler();
        SupportHandler tier3Support = new Tier3Handler();

        tier1Support.setNextHandler(tier2Support);
        tier2Support.setNextHandler(tier3Support);

        System.out.println("Sending request to tier1...");
        tier1Support.handleRequest("tier1");

        System.out.println("Sending request to tier2...");
        tier1Support.handleRequest("tier2");

        System.out.println("Sending request to tier2...");
        tier1Support.handleRequest("tier3");

        System.out.println("\nSending unknown request...");
        tier1Support.handleRequest("unknown");
    }
}