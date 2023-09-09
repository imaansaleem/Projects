let age=2;
function p_age(person_age){
    if(person_age<2)
        console.log("You are a baby");
    else if(person_age>=2 && person_age < 4)
        console.log("You are a toddler");
    else if(person_age>=4 && person_age < 13)
        console.log("You are a kid");
    else if(person_age>=13 && person_age < 20)
        console.log("You are a teenager");
        else if(person_age>=20 && person_age < 65)
        console.log("You are a adult");
        else if(person_age>=65)
        console.log("You are a elder");
}
p_age(age);
age=10;
p_age(age);
age=15;
p_age(age);
age=23;
p_age(age);
age=70;
p_age(age);
