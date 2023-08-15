abstract class Book {
    private String author;
    private String title;
    private String isbn;

    // Parent class implementation of getLibraryBookObjects()
    private static int LibraryBookObjects = 0;
    // Parent class implementation of getStoreBookObjects()
    private static int StoreBookObjects = 0;

    public static void setLibraryBookObjects(int libraryBookObjects) {
        LibraryBookObjects = libraryBookObjects;
    }

    public static void setStoreBookObjects(int storeBookObjects) {
        StoreBookObjects = storeBookObjects;
    }

    public int getLibraryBookObjects() {
        return LibraryBookObjects;
    }

    public int getStoreBookObjects() {
        return StoreBookObjects;
    }

    public Book() {
        this("Unknown Author", "Unknown Title", "123456789");
    }

    public Book(String title, String isbn) {
        this("Unknown Author",title,isbn);
    }
    public Book(String author, String title, String isbn) {
        this.author = author;
        this.title = title;
        this.isbn = isbn;
    }

    public void setPrice(double price) {
    }

    public void setDeduction(int deduction) {
    }

    public void setOnsale(boolean onsale) {
    }
    public String getAuthor() {
        return author;
    }

    public String getIsbn() {
        return isbn;
    }

    public String toString(){
        return "["+isbn + "-" + title.toUpperCase() + " by " + author.toUpperCase();
    }
}

