let myFriends=["Ali","Ahsan","Nouman","Taha"];
myFriends[0]="Ahmad";
myFriends.unshift("Umair");
let start = 2;
let deleteCount = 0;
myFriends.splice(start, deleteCount, 'Hamza');
console.log("We have space for only two and can invite only two people for dinner.");
while(myFriends.length>2){
    const name=myFriends.pop();
    console.log(name+" Sorry We can’t invite You to dinner.");
}
myFriends.forEach(n=>console.log(`Hello ${n}! You are invited to the dinner!`));
myFriends.pop();
myFriends.pop();
myFriends.forEach(n=>console.log(n));