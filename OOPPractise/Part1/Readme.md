# Homework

The goal of this coding exercise is to create two classes, `BookstoreBook` and `LibraryBook`. Both classes have these attributes:

- `author`: String
- `title`: String
- `isbn`: String

The `BookstoreBook` has an additional data member to store the price of the book and whether the book is on sale or not. If a bookstore book is on sale, we need to add the reduction percentage (like 20% off, etc.). For a `LibraryBook`, we add the call number (that tells you where the book is in the library) as a string. The call number is automatically generated by the following procedure: The call number is a string with the format `xx.yyy.c`, where `xx` is the floor number that is randomly assigned (our library has 99 floors), `yyy` are the first three letters of the author’s name (we assume that all names are at least three letters long), and `c` is the last character of the ISBN.
In each of the classes, add the setters, the getters, at least three constructors (of your choosing), and override the `toString` method (see sample run below). Your code should display the list of all books keyed in by the user.
Create an abstract class that you call `Book`. The class `Book` should have the fields and the code that is shared by both the `BookstoreBook` and the `LibraryBook` classes. Both of those classes extend the `Book` class. Test your code with an array of 100 elements of `Book`. Call that array list (You can't have an array to store the `BookstoreBook` objects and another one to store the `LibraryBook` objects. One array (list) to hold all the book objects that your code creates).
Create a class that you call `BookList` in which you put list as a private field. Your code must have the following structure:

## Sample Run

Welcome to the book program!<br>
Would you like to create a book object? (yes/no): yEs<br>
Please enter the author, title, and the isbn of the book separated by /: Ericka Jones/Java made Easy/458792132<br>
Got it!<br>
Now, tell me if it is a bookstore book or a library book (enter BB for bookstore book or LB for library book): BLB<br>
Oops! That's not a valid entry. Please try again: Bookstore<br>
Oops! That's not a valid entry. Please try again: bB<br>
Got it!<br>
Please enter the list price of JAVA MADE EASY by ERICKA JONES: 14.99<br>
Is it on sale? (y/n): y<br>
Deduction percentage: 15%<br>
Got it<br>

Here is your bookstore book information<br>
[458792132-JAVA MADE EASY by ERICKA JONES, $14.99 listed for $12.74]<br>
Would you like to create a book object? (yes/no): yeah<br>
I'm sorry but yeah isn't a valid answer. Please enter either yes or no: yes<br>
Please enter the author, title, and the isbn of the book separated by /: Eric Jones/Java made Difficult/958792130<br>
Got it!<br>
Now, tell me if it is a bookstore book or a library book (enter BB for bookstore book or LB for library book): LB<br>
Got it!<br>
Here is your library book information<br>
[958792130-JAVA MADE DIFFICULT by ERIC JONES-09.ERI.0]<br>
Would you like to create a book object? (yes/no): yes<br>
Please enter the author, title, and the isbn of the book separated by /: Erica Jone/Java made too Difficult/958792139<br>
Got it!<br>
Now, tell me if it is a bookstore book or a library book (enter BB for bookstore book or LB for library book): LB<br>
Got it!<br>
Here is your library book information<br>
[958792139-JAVA MADE TOO DIFFICULT by ERICA JONE-86.ERI.9]<br>
Would you like to create a book object? (yes/no): no<br>
Sure!<br>
Here are all your books…<br>
Library Books (2)<br>
[958792130-JAVA MADE DIFFICULT by ERIC JONES-09.ERI.0]<br>
[958792139-JAVA MADE TOO DIFFICULT by ERICA JONE-86.ERI.9]<br>

Bookstore Books (1)<br>
[458792132-JAVA MADE EASY by ERICKA JONES, $14.99 listed for $12.74]