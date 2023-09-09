const fruits=["Mango","Banana","Apple"];
function find_string(arr, fruit){
    for(i=0;i<arr.length;i++){
        if(fruit==arr[i])
            return true;
    }
    return false;
}

if(find_string(fruits,"PineApple"))
    console.log("You really like PineApples");
if(find_string(fruits,"Mango"))
    console.log("You really like Mangoes!");
if(find_string(fruits,"Pomegrant"))
    console.log("You really like Pomegrant!");
if(find_string(fruits,"Banana"))
    console.log("You really like Banana!");
if(find_string(fruits,"Apple"))
    console.log("You really like Apple!");