function titleCase(str) { //this function will convert a string to title case
    let wordsArray = str.toLowerCase().split(' ');
    wordsArray = wordsArray.map(el => el.charAt(0).toUpperCase() + el.slice(1))
    return wordsArray.join(' ');
}

let personName;//Declared a variable
personName = prompt("Please enter your full name!");  //Taking input of Person's name
if (personName) {  //displaying name in required cases if person has entered his name
    console.log("Your name in uppercase is " + personName.toUpperCase()); //converting to uppercase
    console.log("Your name in lowercase is " + personName.toLowerCase()); //converting to lowercase
    console.log("Your name in titlecase is " + titleCase(personName)); //converting to titlecase
}
else console.log("Alas! You didn't write your name!"); //if person has not entered his name 
