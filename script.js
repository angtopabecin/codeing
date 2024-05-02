var deger = document.getElementById("girdi");



var randomSayi;
var oyunBaslamaDegeri = 1;
var i;
var oyunBitirmeDegeri = 0;


function yakinlikDegerlendirme (){
    document.getElementById('yakinlikDegerlendirme').innerHTML = "Oyun Başlamıştır";
    
}
function fazla(){
    document.getElementById('yakinlikDegerlendirme').innerHTML = "Fazlaaaa...";
        
}


function az(){
    document.getElementById('yakinlikDegerlendirme').innerHTML = "AAAzzzz...";
}

function sicak(){
    document.getElementById('yakinlikDegerlendirme').innerHTML = "Sıcaksıınnn... Ve Sen Büyüksüünnn";

}

function soguk(){
    document.getElementById('yakinlikDegerlendirme').innerHTML = "Soğuksssuuunnn... Ve Sen Küçüksüüünn";
}

function degerEkran(input){
    deger.value += input;
}


function ekranTemzile(){
    deger.value = "";
}


function sonucDegerlendir(){
    console.log(deger.value);
    console.log(randomSayi);
    if(oyunBitirmeDegeri < 8 && deger.value == randomSayi){
        alert("Oyunu Kazandiniz");
        window.location.reload();
        deger.value = "";
    }
    else if(oyunBitirmeDegeri == 8){
        alert("Oyunu Kazanamadiniz");
        window.location.reload();
        deger.value = "";
    }
    oyunBitirmeDegeri += 1;
    if(deger.value > randomSayi){
        fazla();
    }
    if(deger.value < randomSayi ){
        az();
    }
    if(deger.value-randomSayi < 10 && deger.value > randomSayi){
        sicak();

    }
    if(randomSayi-deger.value < 10 && deger.value < randomSayi){
        soguk();
    }
    
}

function oyunBasla(){
    randomSayi = Math.floor(Math.random() * 101 );
    if(oyunBaslamaDegeri == 1){
        alert("yusuf");
    }
    oyunBaslamaDegeri += 1;

    yakinlikDegerlendirme ();
    

}