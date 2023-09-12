const username=["Admin","Umair","Ahmad","Hamza","Qasim"];

function print_users(users){
    let i=0;
    while(i<users.length){
        if(users.length!=0){
            if(users[i]=="Admin")
                console.log("Hello Admin, would you like to see a status report?");
            else
                console.log("Hello "+users[i]+" Thank you for logging in again!");
        }
        else
            console.log("usernames list is Empty. We need to find some users!");
        i++;
    }
}

print_users(username);
const length=username.length;

for(let j=0;j<length;j++)
    username.pop();

print_users(username);