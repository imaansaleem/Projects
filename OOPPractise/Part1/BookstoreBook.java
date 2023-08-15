public class BookstoreBook extends Book{
    private double price;
    private int deduction;
    private boolean Onsale; //1 means book on sale 0 means not

    public BookstoreBook() {
        this("Unknown Author", "Unknown Title", "123456789");
    }

    public BookstoreBook(String title, String isbn) {
        this("Unknown Author", title, isbn);
    }
    public BookstoreBook(String author, String title, String isbn) {
        super(author, title, isbn);
        int c = getStoreBookObjects()+1;
        setStoreBookObjects(c);
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setDeduction(int deduction) {
        this.deduction = deduction;
    }

    public void setOnsale(boolean onsale) {
        Onsale = onsale;
    }

    public String toString(){
        System.out.print(super.toString());
        return ", $" + price + " listed for $" + price_calculation() + "]";
    }

    public double price_calculation() {
        double new_price;
        if(deduction==0){
            new_price=price;
            return new_price;
        }
        else{
            new_price = (price * deduction) / 100;
            return price - new_price;
        }
    }
}
