import java.util.ArrayList;
import java.util.List;

public class Member {
    private String name;
    private List<Book> currentlyBorrowedBooks;

    public Member(String name) {
        this.name = name;
        currentlyBorrowedBooks = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public void borrowBook(Book book) {
        currentlyBorrowedBooks.add(book);
    }

    public void returnBook(Book book) {
        currentlyBorrowedBooks.remove(book);
    }
}
