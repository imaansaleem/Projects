let myFriends=["Ali","Ahsan","Nouman","Taha"];
myFriends.forEach(n=>console.log(`Hello ${n}! We are arranging a meetup on Sunday and we expect to join us over a diner!`));
const first = myFriends[0];
console.log(first+" will not make it");
myFriends[0]="Ahmad";
myFriends.forEach(n=>console.log(`Hello ${n}! We are arranging a meetup on Sunday and we expect to join us over a diner!`));