public class Main {
    public static void main(String[] args) {
        Library library = new Library();

        Book book1 = new Book("Book1", "Author1");
        Book book2 = new Book("Book2", "Author2");

        library.addBook(book1);
        library.addBook(book2);

        Member member1 = new Member("Vidyasagar");
        Member member2 = new Member("Saurav");

        library.addMember(member1);
        library.addMember(member2);

        library.lendBook(book1, member1);
        library.lendBook(book2, member2);
        library.returnBook(book1);
    }
}
