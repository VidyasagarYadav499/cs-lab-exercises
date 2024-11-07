public class Tier2Handler implements SupportHandler {
    private SupportHandler nextHandler;

    @Override
    public void setNextHandler(SupportHandler nextHandler) {
        this.nextHandler = nextHandler;
    }

    @Override
    public void handleRequest(String request) {
        if (request.equals("tier2")) {
            System.out.println("Tier2Handler: Handling Tier 2 support request.");
        } else {
            if (nextHandler != null) {
                nextHandler.handleRequest(request);
            } else {
                System.out.println("Tier2Handler: No handler found for request type: " + request);
            }
        }
    }
}

