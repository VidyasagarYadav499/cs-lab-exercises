public class Tier3Handler implements SupportHandler {
    private SupportHandler nextHandler;

    @Override
    public void setNextHandler(SupportHandler nextHandler) {
        this.nextHandler = nextHandler;
    }

    @Override
    public void handleRequest(String request) {
        if (request.equals("tier3")) {
            System.out.println("Tier3Handler: Handling Tier 3 support request.");
        } else {
            if (nextHandler != null) {
                nextHandler.handleRequest(request);
            } else {
                System.out.println("Tier3Handler: No handler found for request type: " + request);
            }
        }
    }
}