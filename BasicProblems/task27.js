let alien_color="green";
function color(col){
    if(alien_color=="green")
        console.log("You just earned 5 points");
    else if(alien_color=="yellow")
        console.log("You just earned 10 points");
    else if(alien_color=="red")
        console.log("You just earned 15 points");
}
color(alien_color);
alien_color="red";
color(alien_color);
alien_color="yellow";
color(alien_color);

