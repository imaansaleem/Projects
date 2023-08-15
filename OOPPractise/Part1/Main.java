import java.util.Objects;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String input;
        System.out.println("Welcome to the book program!\n");
        BookList l = new BookList(); // creating object of book list
        do{
            System.out.print("\nWould you like to create a book object? (yes/no): ");
            Scanner scanner = new Scanner(System.in); //creating new scanner object to take input
            input = scanner.nextLine();
            input = input.toLowerCase();

            if (input.equals("yes")) {
                System.out.print("\nPlease enter the author, title ad the isbn of the book separated by /: ");
                String i = scanner.nextLine();
                String[] parts = i.split("/");

                String author = parts[0];
                String title = parts[1];
                String isbn = parts[2];

                System.out.println("\nGot it!");

                System.out.print("\nNow, tell me if it is a bookstore book or a library book (enter BB for bookstore book or LB for library book): ");

                String book;
                double price=0.0;
                String sale="";
                int deduction=0;

                while(true){
                    book = scanner.nextLine();
                    book = book.toUpperCase();
                    if(book.equals("BB")) { //create the object on the basis of type
                        System.out.println("Got it!");
                        System.out.print("Please enter the list price of " + title.toUpperCase() + " by " + author.toUpperCase() + ": ");
                        price = scanner.nextDouble();
                        scanner.nextLine();

                        while(true) {
                            System.out.print("\nIs this on sale?(y/n): ");
                            sale = scanner.nextLine();
                            sale = sale.toLowerCase();
                            if (Objects.equals(sale, "y")) {
                                System.out.print("\nDeduction percentage: ");
                                String s = scanner.nextLine();
                                deduction = Integer.parseInt(s.replace("%", "")); //remove % and store it in int
                                System.out.println("Got it");
                                break;
                            }

                            else if(Objects.equals(sale, "n")){
                                break;
                            }

                            else {
                                System.out.println("\nWrong Input. Try again");
                            }
                        }
                        break;
                    }

                    else if(Objects.equals(book, "LB")) {
                        System.out.println("Got it!");
                        break;
                    }

                    else {
                        System.out.print("\nOops! That’s not a valid entry. Please try again: ");
                    }
                }

                Book b = select_object(book, author, title, isbn); //polymorphism
                l.Add_Book(b); //everytime new object is created it must be added to the list
                if(book.equals("BB")) {
                    if(sale.equals("y")) {
                        b.setOnsale(true); //setting variable of bookstore class
                    }
                    else {
                        b.setOnsale(false);
                    }
                    b.setPrice(price);
                    b.setDeduction(deduction);
                    System.out.println("\nHere is your bookstore book information");
                    System.out.println(b);
                }

                else {
                    System.out.println("\nHere is your  library book information");
                    System.out.println(b);
                }
            }

            else if (input.equals("no")) {
                System.out.println("Sure!\n");
                System.out.println("Here are all your books....");
                l.print_list();
            }

            else {
                System.out.println("I’m sorry but " + input + " isn’t a valid answer. Please enter either yes or no:\n");
            }
        }while(!input.equals("no"));

    }

    public static Book select_object(String object_type, String author, String title, String isbn){
        if(Objects.equals(object_type, "BB"))//create the object on the basis of type
            return new BookstoreBook(author, title, isbn);

        else
            return new LibraryBook(author, title, isbn);
    }
}

