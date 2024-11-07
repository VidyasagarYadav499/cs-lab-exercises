public interface SupportHandler {
    void setNextHandler(SupportHandler nextHandler);
    void handleRequest(String requestType);
}
