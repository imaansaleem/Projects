const username=["Admin","Umair","Ahmad","Hamza","Qasim"];
let i=0;
while(i<username.length){
    if(username[i]=="Admin")
        console.log("Hello Admin, would you like to see a status report?");
    else
        console.log("Hello "+username[i]+" Thank you for logging in again!");
    i++;
}