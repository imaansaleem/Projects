const current_users=["Asif","Umair","Ahmad","Hamza","Qasim"];
const new_users=["HASSAN","ABDULLAH","AHMAD","HAMZA","ALI"];

function check_existence(arr,user){
    for(let j=0;j<arr.length;j++){
        if(arr[j].toLowerCase()==user.toLowerCase()){
            return true;
        }
    }
    return false;
} 

let i;
let input_user;
for(i=0;i<new_users.length;i++){
    if(check_existence(current_users,new_users[i])){
        console.log(new_users[i]+" already exits! You need to enter a new username");
        while(true){
            input_user=prompt("Enter Username: ");
            if(!check_existence(current_users,input_user)){
                if(!check_existence(new_users,input_user)){
                    console.log(input_user+" is available");
                    new_users[i]=input_user;
                    break;
                }
                else
                    console.log(input_user+" already exits! You need to enter a new username");
            }
            else
                console.log(input_user+" already exits! You need to enter a new username");
        }
    }
    else
        console.log(new_users[i]+" is available");
}

new_users.forEach(n=>console.log(n));