class Tier1Handler implements SupportHandler {
    private SupportHandler nextHandler;

    @Override
    public void setNextHandler(SupportHandler nextHandler) {
        this.nextHandler = nextHandler;
    }

    @Override
    public void handleRequest(String request) {
        if (request.equals("tier1")) {
            System.out.println("Tier1Handler: Handling Tier 1 support request.");
        } else {
            if (nextHandler != null) {
                nextHandler.handleRequest(request);
            } else {
                System.out.println("Tier1Handler: No handler found for request type: " + request);
            }
        }
    }
}
