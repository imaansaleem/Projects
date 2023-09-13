const magician_names=["JAY MARSHALL","MAX MAVEN","David Blaine","Derren Brown"];
function show_magicians(arr){
    arr.forEach(n=>console.log(n));
}

function make_great(arr){
    for(let i=0;i<arr.length;i++){
        arr[i]="Great "+arr[i];
    }
}
make_great(magician_names);
show_magicians(magician_names);