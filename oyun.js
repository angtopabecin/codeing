const cnv = document.getElementById("harita");
const ctx = cnv.getContext("2d");

const cnvyukseklik = 800;
const cnvgenislik = 600;
var xEksen = 0;

const draw = (x,y,w,h,renk) =>{
    ctx.fillStyle = renk;
    ctx.fillRect(x,y,w,h);
}


const draw2 = (x,y,w,h,renk) =>{
    ctx.fillStyle = renk;
    ctx.fillRect(x,y,w,h);
    
}

const karakter = {
    x:40,
    y:20,
    w:40,
    h:40,
    renk:'black',
    xHareket:2,
    yYareket:3,
}

const ciz = () => {
    draw(0,0,cnvyukseklik,cnvgenislik,"orange");
    draw2(karakter.x,karakter.y,karakter.w,karakter.h,karakter.renk);
}




const game = () => {
    ciz();
    
}

const kare  = 50;
setInterval(game ,1000/kare);




const hareket = () => {
    hareketArt();
 
}


function hareketArt(){
    karakter.x = +2 + karakter.x;
}















