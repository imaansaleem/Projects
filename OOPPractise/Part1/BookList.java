import java.sql.SQLOutput;

class BookList {

    int list_size;
    private Book[] list;
    public BookList() {
        list_size=0;
        list = new Book[100];
    }

    void Add_Book(Book b){
        list[list_size] = b;
        list_size++;
    }

    void print_list(){

        int counter = 0;
        if(list_size>0){
            Book x=list[0];
            System.out.println("Library Books: (" + x.getLibraryBookObjects() + ")");
            for (Book book : list) {
                if (book instanceof LibraryBook)
                    System.out.println(book);
                counter++;
                if (counter == list_size) {
                    break;
                }
            }
        }
        else
            System.out.println("Library Books: (0)");

        System.out.println("___");

        counter = 0;
        if(list_size>0){
            Book x = list[0];
            System.out.println("Bookstore Books: (" + x.getStoreBookObjects()+ ")");
            for (Book book : list) {
                if (book instanceof BookstoreBook)
                    System.out.println(book);
                counter++;
                if (counter == list_size) {
                    break;
                }
            }
        }
        System.out.println("___\nTake care now!");
    }
}