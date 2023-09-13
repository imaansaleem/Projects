let magician_names=["JAY MARSHALL","MAX MAVEN","David Blaine","Derren Brown"];
function show_magicians(arr){
    arr.forEach(n=>console.log(n));
}

function make_great(arr){
    let  arr2=[];
    for(let i=0;i<arr.length;i++){
        arr2[i]="Great "+arr[i];
    }
    return arr2;
}

let names_copy=[];
for(let j=0;j<magician_names.length;j++){
    names_copy[j]=magician_names[j];
}

let great_magicians=make_great(names_copy);
show_magicians(great_magicians);
show_magicians(magician_names);
