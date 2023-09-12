const ordinalNumbers=[1,2,3,4,5,6,7,8,9];
let i=0;
while(i<ordinalNumbers.length){
    if(ordinalNumbers[i]==1)
        console.log("1st");
    else if(ordinalNumbers[i]==2)
        console.log("2nd");
    else if(ordinalNumbers[i]==3)
        console.log("3rd");
    else
        console.log(ordinalNumbers[i]+"th");
    i++;
}