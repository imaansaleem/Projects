import java.util.Random;

public class LibraryBook extends Book{
    private String call_number;

    LibraryBook() {
        this("Unknown Author", "Unknown Title", "123456789");
    }

    LibraryBook(String title, String isbn){
        this("Unknown Author", title, isbn);
    }
    LibraryBook(String author, String title, String isbn){
        super(author, title, isbn);
        String number = generate_call_number();
        setCall_number(number);
        int c = getLibraryBookObjects()+1;
        setLibraryBookObjects(c);
    }

    public void setCall_number(String call_number) {
        this.call_number = call_number;
    }

    public String toString(){
        System.out.print(super.toString());
        return "-" + call_number + "]";
    }

    String generate_call_number(){ //it consists of three parts
        String number="";
        Random random = new Random();
        int randomNumber = random.nextInt(99) + 1; // generating random number from 1-99
        if(randomNumber < 10)
            number+="0";
        String str = Integer.toString(randomNumber); //conversion from integer to string
        number+=str; //first part
        number+=".";
        String firstThree =  getAuthor().substring(0, 3); //getting first 3 digits
        firstThree = firstThree.toUpperCase();
        number+=firstThree; //second part has first 3 digits of author name
        number+=".";
        char lastChar = getIsbn().charAt(getIsbn().length()-1);//getting last character of string
        number+=lastChar;//last part has last character of isbn
        return number;
    }
}
