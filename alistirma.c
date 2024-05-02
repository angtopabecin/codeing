#include <stdio.h>
#include <stdlib.h>
int paratutari;
int islem,faturaislem;
int tcno,kykparacekme,kykistmiktar;
int odno,suno,sodno,eno,eodno,dno,dodno;
int kartsizislem,kartsizislemno;
int sgk,bagkur,sgkkod,bagkurod,sgksecim,bagkursecim,sgkbagkura,bagkurkod,sgkod;
int kksec,kkno,kkod;
int kart;
int kullanicino,sifre;
int kullanicitc;
int kykbakiye,telno;
int sgkborc,sgkborc1;
int bakiye;
int suborc;
int kayitlitc;
int bagkurno,telno,borc;
int bagkurborc;
int sgkno,borckontrol;
int suborckontorl;
int yenibakiye;
int giriskontrol(int kullanicino, int sifre, int *bakiye) {
    FILE *dosya;
    FILE *tmp;
    int kayitlikullanicino, kayitlisifre, kayitlibakiye;
    dosya = fopen("kullanici.txt", "r");
    tmp = fopen("tmp.txt", "w");
    while (fscanf(dosya, "%d %d %d", &kayitlikullanicino, &kayitlisifre, &kayitlibakiye) == 3) {
        if(kayitlikullanicino == kullanicino && kayitlisifre == sifre){
            *bakiye = kayitlibakiye;
        }
        if (kayitlikullanicino == kullanicino && kayitlisifre == sifre) {
            fprintf(dosya,"%d %d %d\n",kayitlikullanicino,kayitlisifre,*bakiye);
            return 1;
        } 
        else if (kayitlikullanicino != kullanicino && kayitlisifre != sifre){
            fprintf(dosya, "%d %d %d\n", kayitlikullanicino, kayitlisifre, kayitlibakiye);
        }
    }
    fclose(dosya);
    fclose(tmp);
    remove("kullanici.txt");
    rename("tmp.txt", "kullanici.txt");
    return 0;
}

int kykkontrol(int kullanicitc,int *kykbakiye){
    FILE *dosyaa;
    FILE *a;
    int kayitlitc;
    int kykkayitlibakiye;
    dosyaa = fopen("kyk.txt","r");
    a = fopen("ac.txt","w");
    while (fscanf(dosyaa,"%d %d",&kayitlitc,&kykkayitlibakiye) == 2){
        if(kayitlitc == kullanicitc){
            *kykbakiye = kykkayitlibakiye;
            fprintf(a,"%d %d",kayitlitc,*kykbakiye);
            fclose(a);
            return 1;
        }
        else {
            fprintf(a,"%d %d ",kayitlitc,kykkayitlibakiye);
            fclose(a);
        }
    }
    fclose(dosyaa);
    rename("ac.txt","kyk.txt");
    remove("kyk.txt");
    return 0;
}
int sgkbagkur(int sgkno,int *sgkborc){
    FILE *sgkf;
    int kayitlisgkno;
    int kayitlisgkborc;
    sgkf = fopen("sgk.txt","r");
    while(fscanf(sgkf,"%d %d",&kayitlisgkno,&kayitlisgkborc) == 2){
        if(kayitlisgkno == sgkno){
            *sgkborc = kayitlisgkborc;
            fclose(sgkf);
            return 1;
        }
    }
    fclose(sgkf);
    return 0;
}
int sgkbagkurkontrol(int bagkurno,int *bagkurborc){
    FILE *bagkur;
    int kayitlibagkurno;
    int kayitlibagkurborc;
    bagkur = fopen("bagkur.txt","r");
    while(fscanf(bagkur,"%d %d",&kayitlibagkurno,&kayitlibagkurborc) == 2){
        if(kayitlibagkurno == bagkurno){
            *bagkurborc = kayitlibagkurborc;
            fclose(bagkur);
            return 1;
        }
    }
    fclose(bagkur);
    return 0;
}
int telfaturakontrol(int telno,int *borc){
    FILE *b;
    int kayitlitelno;
    int kayitliborc;
    b = fopen("telfatura.txt","r");
    while(fscanf(b,"%d %d",&kayitlitelno,&kayitliborc) == 2){
        if(kayitlitelno == telno){
            *borc = kayitliborc;
            fclose(b);
            return 1;
        }
    }
    fclose(b);
    return 0;

}
int sukontrol(int suno,int *suborc){
    FILE *su;
    int kayitlisuno;
    int kayitlisuborc;
    su = fopen("sufatura.txt","r");
    while(fscanf(su,"%d %d",&kayitlisuno,&kayitlisuborc) == 2){
        if(kayitlisuno == suno){
            *suborc = kayitlisuborc;
            fclose(su);
            return 1;
        }
    }
    fclose(su);
    return 0;

}
int main(){
    printf("-----------------------\n");
    printf(" Merhabalar Iyi Gunler \n");
    printf("-----------------------\n");
    printf("Lutfen Islem Turu Seciniz \n"); 
    printf("1.Kartsiz Islemler \n");
    printf("2.Kartli Islemler\n");
    scanf("%d",&kart);
    if(kart!=1 && kart!=2){
        printf("Hatali Islem Yaptiniz \n");
    }
    switch(kart){
        case 1:
    	do{
            printf(" \n");
            printf("*Yapilabilecek Islemler* \n");
            printf("1.KYK Ilk Odeme \n");
            printf("2.SGK/BAGKUR Odemesi \n");
            printf("3.Fatura Yatirma Islemleri \n");
            printf("4.Cikis\n");
            scanf("%d",&kartsizislem);
            if(kartsizislem !=1 && kartsizislem !=2 && kartsizislem !=3 && kartsizislem !=4 && kartsizislem !=5 ){
                printf("Hatali Islem Yaptiniz");
                exit(1);
            } 
            switch(kartsizislem){
                case 1:
                    printf("Lutfen TC Kimlik Numaranizin Son 4 Hanesini Giriniz : \n");
                    scanf("%d",&kullanicitc);
                    if(kykkontrol(kullanicitc,&kykbakiye)){
                        printf("Girisi Basarili \n");
                        if(kykkontrol(kullanicitc,&kykbakiye)){
                            printf("Ilk Ay KYK Odemeniz :%dTL\n",kykbakiye);
                            printf("Para Cekmek Icin 1 Tusuna Basiniz \n");
                            printf("Cikmak Icin 2 Tusuna Basiniz \n");
                            scanf("%d",&kykparacekme);
                            if(kykparacekme!=1 && kykparacekme!=2){
                                printf("Hatali Islem Girdiniz \n");
                                exit(1);
                            }
                            switch(kykparacekme){
                                case 1:
                                printf("Lutfen Cekmek Istediginiz Miktari Giriniz :\n");
                                scanf("%d",&kykistmiktar);
                                    if(kykistmiktar<kykbakiye){
                                        kykbakiye=kykbakiye-kykistmiktar;
                                        printf("Kalan KYK Bakiyeniz :%d \n",kykbakiye);
                                        break;
                                    }
                                    else if(kykistmiktar>kykbakiye){
                                        printf("Bakiyeniz Yetersiz\n");
                                        break;
                                    }
                                    case 2:
                                    printf("\n");
                                break;
                            }
                            }
                    }
                    else {
                        printf("Hatali TC Girdiniz \n");
                        exit(1);
                    }
                break;
                case 2:
                    printf("SGK/BAGKUR Secimi Yapiniz \n");
                    scanf("%d",&sgkbagkura);
                    if(sgkbagkura != 1 && sgkbagkura != 2){
                        printf("Hatali Islem Girdiniz \n");
                        exit(1);

                    }
                    switch(sgkbagkura){
                        case 1:
                            printf("Lutfen SGK Kayit Numaranizi Giriniz :\n");
                            scanf("%d",&sgkno);
                            if(sgkbagkur(sgkno,&sgkborc)){
                                printf("Giris Basarili\n");
                            }
                            if(sgkbagkur(sgkno,&sgkborc)){
                                printf("SGK Borcunuz :%dTL \n",sgkborc);
                                printf("SGK Borcunuzu Odemek Icin Lutfen 1 Tusuna Basiniz \n");
                                printf("Cikmak Icin 2 Tusuna Basiniz \n");
                                scanf("%d",&sgksecim);
                                switch(sgksecim){
                                    case 1:
                                        printf("Yatirmak Istenilen Miktari Giriniz: \n");                                    
                                        scanf("%d",&sgkborc1);
                                        printf("Kontrol Saglaniyor\n");
                                        if(sgkborc == sgkborc1){
                                            printf("Isleminiz Basariyla Gerceklestirilmistir \n");
                                        }
                                        else{
                                            printf("Eksik Para Yatirdiniz");
                                        
                                        }
                                    break;
                                    case 2:
                                        printf("Lutfen Cikmak Icin 5 Tusuna Basiniz \n");
                                    break;    
                                }
                            }
                            else{
                                printf("Hatali SGK Kayit Numarasi Girdiniz \n");
                                exit(1);
                            }
                        break;
                        case 2:
                            printf("Lutfen BAGKUR Kayit Numaranizi Giriniz : \n");
                            scanf("%d",&bagkurno);
                            if(sgkbagkurkontrol(bagkurno,&bagkurborc)){
                                printf("Giris Basarili \n");
                            }
                            if(sgkbagkurkontrol(bagkurno,&bagkurborc)){
                                printf("BAGKUR Borcunuz :%dTL \n",bagkurborc);
                                printf("BAGKUR Borcunuzu Odemek Icin Lutfen 1 Tusuna Basiniz \n");
                                printf("Cikmak Icin 2 Tusuna Basiniz \n");
                                scanf("%d",&bagkursecim);
                                if(bagkursecim != 1 && bagkursecim != 2){
                                    printf("Hatali Islem Girdiniz \n");
                                }
                                if(bagkursecim == 1){
                                    scanf("%d",&bagkurod);
                                    if(bagkurod != 1 && bagkurod != 2){
                                        printf("Hatali Islem Girindiz \n");
                                        exit(1);
                                    }
                                    switch(bagkurkod){
                                        case 1:
                                        printf("Lutfen Yatirmak Istediginiz Miktari Giriniz \n");
                                        scanf("%d",&bagkurod);
                                        if(bagkurod == bagkurborc){
                                            printf("Kontorl Ediliyor.. \n");
                                            printf("Odeme Isleminiz Gerceklestirilmistir \n");
                                        }
                                        else if(bagkurod != bagkurborc){
                                            printf("Kontorl Ediliyor.. \n");
                                            printf("Eksik Veya Fazla Para Yatirdiniz \n");
                                            printf("Paraniz Iade Ediliyor\n");
                                        }
                                        break;
                                        case 2:
                                            printf("\n");
                                        break;
                                }
                            }
                            else{
                                printf("Hatali BAGKUR Kayit Numarasi Girdiniz \n");
                                exit(1);
                            }
                        break;
                        
                    }
                    }
                break;
                case 3:
                    printf("Lutfen Yatirmak Istedinigiz Fatura Turunu Seciniz : \n");
                    printf("1.Telefon Faturasi \n");
                    printf("2.Su Faturasi \n");
                    printf("3.Elektrik Faturasi \n");
                    printf("4.Dogal Gaz Faturasi \n");
                    do{
                    scanf("%d",&faturaislem);
                    if(faturaislem != 1 && faturaislem != 2 && faturaislem != 3 && faturaislem!= 4 ){
                        printf("Hatali Islem Girdiniz \n");
                        exit(1);
                    }
                    switch(faturaislem){
                        case 1:
                            printf("Yatirmak Istediginiz Telefon Numarasinin Son 4 Rakamini Giriniz : \n");
                            scanf("%d",&telno);
                            if(telfaturakontrol(telno,&borc)){
                                printf("Telefon Numarasi Dogrulandi\n");

                            }
                            if(telfaturakontrol(telno,&borc)){
                            printf("Bu Numaraya Ait Bu Ayki Fatura Tutari :%d \n",borc);
                            printf("Odeme Yapmak  Icin 1 Tusuna Basiniz \n");
                            printf("Cikmak Icin 2 Tusuna Basiniz \n");
                            scanf("%d",&odno);
                            switch(odno){
                                case 1:
                                    printf("Parayi Yatiriniz \n");
                                    printf("Lutfen Yatirilacak Olan Borc Miktarini giriniz\n");
                                    scanf("%d",&borckontrol);
                                    if(borckontrol == borc){
                                        printf("Kontrol Saglaniyor...\n");
                                        printf("Isleminiz Basariyla Gerceklestirilmistir \n");
                                        printf("Cikmak Icin 5 Tusuna Basiniz \n ");
                                    }
                                    if(borckontrol > borc){
                                        printf("Kontrol Saglaniyor...\n");
                                        printf("Fazla Para Yatiramazsiniz \n");
                                        printf("Para Iadesi Yapilmaktadir \n");
                                        printf("Cikmak Icin 5 Tusuna Basiniz\n");
                                        break;
                                    }
                                    if(borckontrol < borc){
                                        printf("Kontrol Saglaniyor...\n");
                                        printf("Eksik Para Yatirdiniz \n");
                                        printf("Para Iadesi Yapilmaktadir\n");
                                        printf("Cikmak Icin 5 Tusuna Basiniz \n");
                                        break;
                                    }
                                break;
                                case 2:
                                break;
                            }
                            }                                    
                            else {
                                printf("Hatali Islem veya Hatali Telefon Numarasi \n");
                                exit(1);
                            }
                        break;
                        case 2:
                            printf("Su Abonelik Numaranizi Giriniz :\n");
                            scanf("%d",&suno);
                            if(sukontrol(suno,&suborc)){
                                printf("Abonelik Numaraniz Dogrulanmistir \n");
                            }
                                if(sukontrol(suno,&suborc)){
                                    printf("Bu Ayin Su Faturasi : %dTL \n",suborc);
                                    printf("Odeme Yapmak Icin 1 Tusuna Basiniz \n");
                                    printf("Cikmak Icin 2 Tusuna Basiniz \n");
                                    scanf("%d",&sodno);
                                    switch(sodno){
                                        case 1:
                                            printf("LUtfen Yatirdiginiz Miktari Giriniz \n");
                                            scanf("%d",&suborckontorl);
                                            if(suborc == suborckontorl){
                                                printf("Odeme Islemi Basariyla Gerceklestirilmistir \n");
                                                break;
                                            }
                                            if(suborc < suborckontorl){
                                                printf("Kontrol Saglaniyor... \n");
                                                printf("Fazla Para Yatiramazsiniz \n");
                                                printf("Paraniz Iade Ediliyor\n");
                                                break;
                                            }
                                            if(suborc > suborckontorl){
                                                printf("Kontrol Saglaniyor... \n");
                                                printf("Eksik Para Yatirdiniz \n");
                                                printf("Paraniz Iade Ediliyor\n");
                                                break;
                                            }
                                        break;
                                        case 2:
                                        break;
                                }
                                }
                            else{
                                printf("Hatali Abonelik Numarasi Tusladiniz \n");
                                exit(1);
                            }
                        break;
                        case 3:
                            printf("Elektrik Abonelik Numaranizi Giriniz : \n");
                            scanf("%d",&eno);
                            if(eno==2412){
                            printf("Bu Ayin Elektrik Faturasi : 600TL \n");
                            printf("Odeme Yapmak Icin 1 Tusuna Basiniz \n");
                            printf("Cikmak Icin 2 Tusuna Basiniz : \n");
                            scanf("%d",&eodno);
                                if(eodno==1){
                                    bakiye=bakiye-600;
                                    printf("Kalan Bakiyeniz : %dTL \n",bakiye);
                                    break;
                                }
                                else if(eodno==2){
                                    printf("Lutfen Cikmak Icin  5 Tusuna Basiniz \n");
                                break;
                                }
                            }
                            else{
                                printf("Hatali Abonelik Numarasi Tusladiniz \n");
                                exit(1);
                            }             
                        break;
                        case 4:
                            printf("Dogal Gaz Abonelik Numaranizi Giriniz : \n");
                            scanf("%d",&dno);
                                if(dno==3223){
                                    printf("Bu Ayin Dogal Gaz Faturasi : 1400TL \n");
                                    printf("Odeme Yapmak Icin 1 Tusuna Basiniz : \n");
                                    printf("Cikmak Icin 2 Tusuna Basiniz \n");
                                    scanf("%d",&dodno);
                                        switch(dodno){
                                            case 1:
                                                bakiye=bakiye-1400;
                                                printf("Kalan Bakiyeniz : %dTL \n",bakiye);
                                            break;                                        
                                        
                                            case 2:
                                                printf("Lutfen Cikmak Icin 5 Tusuna Basiniz \n");
                                            break;
                                            }
                                    }
                                else{
                                    printf("Hatali Abonelik Numarasi Tusladiniz \n");
                                    exit(1);
                                }
                        break; 
                        case 5:
                            printf("    --------------------\n");
                            printf("     IYI GUNLER DILERIZ\n");
                            printf("    --------------------\n"); 
                            exit(1); 
                        break; 
                    }
                    }while(faturaislem != 5);
                break;
                case 4:
                    printf("    --------------------\n");
                    printf("     IYI GUNLER DILERIZ\n");
                    printf("    --------------------\n"); 
                    exit(1); 
                break;                  
            }
        }while(kartsizislem!=4);
    case 2:
        printf("Lutfen Kullanici Hesap Numaranizi Giriniz: ");
        scanf("%d",&kullanicino);
        printf("Lutfen Sifrenizi Giriniz : ");
        scanf("%d",&sifre);
        if(giriskontrol(kullanicino,sifre,&bakiye)){
            printf("      ----------------\n");
            printf("       Giris Basarili \n");
            printf("      ----------------\n");
        }
        if(giriskontrol(kullanicino,sifre,&bakiye)){
            do{
                printf("***Yapilabilecek Islemler*** \n");
                printf("1.Kart Bakiyesi \n");
                printf("2.Para Cekme \n");
                printf("3.Para Yatirma \n");
                printf("4.Kart Iade \n");
                printf("Lutfen Yapmak Istediginiz Islemi Seciniz \n");
                scanf("%d",&islem);    
                switch(islem){
                    case 1:
                        printf("Kart Bakiyeniz :%dTL \n",bakiye);
                    break;   
                    case 2:
                        printf("Lutfen Cekmek Istediginiz Miktari Giriniz : \n");
                        scanf("%d",&paratutari);
                        if(paratutari>bakiye){
                        printf("Yetersiz Bakiye \n");
                        }
                        else{
                        bakiye=bakiye-paratutari;
                        printf("Kalan Bakiyeniz :%dTL \n",bakiye);
                        yenibakiye=bakiye;
                        }
                    break;
                    case 3:
                        printf("Lutfen Yatirmak Istediginiz Para Miktarini Giriniz : \n");
                        scanf("%d", &paratutari);
                        bakiye = bakiye + paratutari;
                        printf("Yeni Bakiyeniz : %dTL \n",bakiye);
                        yenibakiye=bakiye;
                    break;
                    case 4:
                        printf("Kartinizi Almayi Unutmayiniz\n");
                        printf("    --------------------\n");
                        printf("     IYI GUNLER DILERIZ\n");
                        printf("    --------------------\n");
                    break;
                }
            }while(islem!=4);                   
        }
    
        else{
            printf("Hatali Kullanici No Veya Sifre \n");
        break;
        }
              
    break;
       
    }    
}

