const display = document.getElementById("display");


function appendToDisplay(input){
    display.value += input;
}
function clear(){
    display.value = "";
}
