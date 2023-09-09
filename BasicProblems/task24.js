let animal = "dog";
console.log("Is variable animal contains string 'dog'? I predict True.");
console.log(animal == "dog");
console.log("Is string 'Ahmad' Equal to 'Hamza'? I predict False.");
console.log("Ahmad"=="Hamza");

let personName="UMAIR";
console.log("Is string 'umair' Equal to it's lowercase? I predict True.");
console.log("UMAIR"==(personName.toLowerCase()));
let person="UMAIR";
console.log("Is string 'UMAIR' Equal to it's lowercase? I predict False.");
console.log("UMAIR"==(person.toLowerCase()));

console.log("Is sum of 5 and 10 equal to 15? I predict True.");
console.log((5+10)==15);
console.log("Is 7 greater than 10? I predict False.");
console.log(7>10);

console.log("Is 8 less than 10 along with 3 greater than 1? I predict True.");
console.log(8<10 && 3>1);
console.log("Is 10 equal to 5 or 8 equal to 5? I predict False.");
console.log(10==5 || 8==5); 

const countries=["Afghanistan","Albania","Algeria","Andorra","Bhutan"];
console.log("Is string 'Algeria' present in countries array? I predict True.");
country="Algeria";
function find_string(arr, con){
    for(i=0;i<arr.length;i++){
        if(con==arr[i])
            return true;
    }
    return false;
}

console.log(find_string(countries,country));

console.log("Is string 'Pakistan' present in countries array? I predict False.");
country="Pakistan";
console.log(find_string(countries,country));

console.log("Is string 'India' not present in countries array? I predict True.");
country="India";
console.log(!find_string(countries,country));

console.log("Is string 'Bhutan' not present in countries array? I predict False.");
country="Bhutan";
console.log(!find_string(countries,country));