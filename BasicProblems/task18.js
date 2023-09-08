let places=["China","India","Saudi Arabia","Dubai"];
console.log("Array in original Order");
places.forEach(n=>console.log(n));
let sortedNames=[];
let i=0;
while(i<places.length){
    sortedNames.push(places[i]);
    i++;
}
sortedNames.sort();
console.log("Array in sorted Order");
sortedNames.forEach(n=>console.log(n));
console.log("Array is still in original Order");
places.forEach(n=>console.log(n));
console.log("Reverse Alphabatical order");
let reversed = sortedNames;
reversed.reverse();
reversed.forEach(n=>console.log(n));
console.log("Array is still in original Order");
places.forEach(n=>console.log(n));
places.reverse();
console.log("Reversed array");
places.forEach(n=>console.log(n));
places.reverse();
console.log("Original array");
places.forEach(n=>console.log(n));
places.sort();
console.log("Array in sorted Order");
places.forEach(n=>console.log(n));
places.reverse();
console.log("Reversed array");
places.forEach(n=>console.log(n));

