let myFriends=["Ali","Ahsan","Nouman","Taha"];
myFriends[0]="Ahmad";
myFriends.forEach(n=>console.log(`Hello ${n}! We are arranging a meetup on Sunday and we expect to join us over a diner!`));
console.log("We found a bigger dinner table So we are inviting more guests");
myFriends.unshift("Umair");
let start = 2;
let deleteCount = 0;
myFriends.splice(start, deleteCount, 'Hamza');
myFriends.forEach(n=>console.log(`Hello ${n}! We are arranging a meetup on Sunday and we expect to join us over a diner!`));