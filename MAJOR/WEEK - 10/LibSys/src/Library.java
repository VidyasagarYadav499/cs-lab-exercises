import java.util.ArrayList;
import java.util.List;

public class Library {
    private List<Book> books;
    private List<Member> members;

    // Constructor.
    public Library() {
        books = new ArrayList<>();
        members = new ArrayList<>();
    }

    public void addBook(Book book) {
        books.add(book);
    }

    public void addMember(Member member) {
        members.add(member);
    }

    public void lendBook(Book book, Member member) {
        if (books.contains(book) && (book.isLent() == false)) {
            book.lend(member);
            System.out.println("Book: " + book.getTitle() + " lent to " + member.getName());
        } else {
            System.out.println("Book: " + book.getTitle() + ", is not available.");
        }
    }

    public void returnBook(Book book) {
        if (books.contains(book) && book.isLent()) {
            book.returnBook();
            System.out.println("Book: " + book.getTitle() + ", is returned.");
        } else {
            System.out.println("Book: " + book.getTitle() + ", is not currently lent.");
        }
    }
}
