public class Book {
    private String title;
    private String author;
    private boolean isLent;
    private Member currentlyLentTo;

    public Book(String title, String author) {
        this.title = title;
        this.author = author;
        this.isLent = false;
    }

    public String getTitle() {
        return title;
    }

    public boolean isLent() {
        return isLent;
    }

    public void lend(Member member) {
        isLent = true;
        currentlyLentTo = member;
    }

    public void returnBook() {
        isLent = false;
        currentlyLentTo = null;
    }
}