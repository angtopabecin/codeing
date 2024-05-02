#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
long int ogretmenTcno,ogretmenTcno1,ogrenciTc,ogrenciTc1;
string ogretmenSifre,ogretmenSifre1,ogrenciName;
int ogrenciNo,ogrenciNo1,ogrenciNo2;
char dersSecim;
int girisSecim,ogrenciSecim,ogretmenSecim;
short int matNot,ingNot,sosNot,bedNot,dinNot,turNot,gorNot;
int main(){
    ifstream ogretmenGiris;
    ogretmenGiris.open("ogretmen",ios::in);
    ogretmenGiris.seekg(0,ios::beg);
    if(!ogretmenGiris){
        cerr<<"Ogretmen Dosyasi Acilamadi "<<endl;
    }
    ifstream ogrenciGiris;
    ogrenciGiris.open("ogrenci",ios::in);
    if(!ogrenciGiris){
        cerr<<" Ogrenci Dosyasi Acilamadi "<<endl;
    }
    ofstream ogrenciNot;
    ogrenciNot.open("ogrenciNot",ios::app);
    if(!ogrenciNot){
        cerr<<"Ogrenci Not Dosyasi Acilamadi "<<endl;
    }
    while(ogretmenGiris>>ogretmenTcno>>ogretmenSifre);
        cout<<"Ogrenci Yonetimi  Bilgi Sistemi"<<endl;
        cout<<"1.Ogretmen Giris"<<endl;
        cout<<"2.Ogrenci Giris"<<endl;
            do{   
                cin>>girisSecim;
                switch(girisSecim){
                    case 1: 
                        cout<<"Ogretmen Girisi"<<endl;
                        cout<<"Tc Kimlik Numaranizi Giriniz : ";
                        cin>>ogretmenTcno1;
                        cout<<"Sifrenizi Giriniz : ";
                        cin>>ogretmenSifre1;
                            if(ogretmenTcno == ogretmenTcno1 && ogretmenSifre == ogretmenSifre1){
                                cout<<"Giris Basarili"<<endl;
                                cout<<"Not Girmek Istediginiz Ogrencinin Okul Numarasini Giriniz : "<<endl;
                                cin>>ogrenciNo2;
                                while(ogrenciGiris>>ogrenciTc>>ogrenciNo>>ogrenciName);
                                if(ogrenciNo1 == ogrenciNo2){
                                    cout<<"1.Ogrenci Not Giris "<<endl;
                                    cout<<"2.Sinav Tarih Girisi (Sadece Idare) "<<endl;
                                    cin>>ogretmenSecim;
                                    do{
                                        switch(ogretmenSecim){
                                            case 1:
                                                cout<<"Not Girmek Istediginiz Dersi Seciniz : "<<endl;
                                                cout<<"Matematik (M) Turkce (T) Sosyal (S) Beden (B) Ingilizce (I) Gorsel Sanatlar (G) Din (D)"<<endl;
                                                cout<<"Kaydetmek Icin (K) Tusuna Basiniz  "<<endl;
                                                    do{
                                                        cin>>dersSecim;
                                                        switch(dersSecim){
                                                            case 'M':
                                                                cout<<"Matematik"<<endl;
                                                                cin>>matNot;
                                                            break;
                                                            case 'T':           
                                                                cout<<"Turkce"<<endl;
                                                                cin>>turNot;  
                                                            break;
                                                            case 'S':
                                                                cout<<"Sosyal"<<endl;
                                                                cin>>sosNot;                                               
                                                            break;
                                                            case 'B':
                                                                cout<<"Beden"<<endl;
                                                                cin>>bedNot;                                              
                                                            break;
                                                            case 'I':
                                                                cout<<"Ingilizce"<<endl;
                                                                cin>>ingNot;
                                                            break;
                                                            case 'G':
                                                                cout<<"Gorsel Sanatlar"<<endl;
                                                                cin>>gorNot;
                                                            break;
                                                            case 'D':
                                                                cout<<"Din Kulturu Ve Ahlak Bilgisi"<<endl;
                                                                cin>>dinNot;
                                                            break;
                                                            case 'K':
                                                                cout<<"Basariyla Kaydedilmistir "<<endl;
                                                                if(ogrenciNo1 == ogrenciNo2){
                                                                    ogrenciNot<<ogrenciNo1<<" "<<matNot<<" "<<turNot<<" "<<sosNot<<" "<<ingNot<<" "<<bedNot<<" "<<gorNot<<" "<<dinNot<<endl;
                                                                };
                                                                ogrenciNot.close();
                                                                exit(1);
                                                            break;
                                                            }
                                                            }while(girisSecim != 'K');
                                            break;
                                }
                                    }while(ogretmenSecim !=4 );
                                }
                            }
                            
                            else {
                                cout<<"Tc Kimlik No Veya Sifre Hatali "<<endl;
                                exit(1);
                            }
                        
                        
                    break;
                    case 2:
                        cout<<"Ogrenci Girisi "<<endl;
                        cout<<"Tc Kimlik Numaranizi Giriniz : ";
                        cin>>ogrenciTc1;
                        cout<<"Okul Numaranizi Giriniz : ";
                        cin>>ogrenciNo2;
                        while(ogrenciGiris>>ogrenciTc>>ogrenciNo1>>ogrenciName);
                        if(ogrenciTc1 == ogrenciTc && ogrenciNo1 == ogrenciNo2){
                            cout<<"Giris Basarili "<<endl<<ogrenciName<<endl;
                            cout<<"1.Ders Notlari "<<endl;
                            cout<<"2.Sinav Tarihleri "<<endl;
                            cout<<"3.Devamsizlik Bilgileri "<<endl;
                            cout<<"4.Cikis "<<endl;
                            do{
                                cin>>ogrenciSecim;
                                switch(ogrenciSecim){
                                    case 1:
                                        cout<<"Ders Notlari "<<endl;
                                        if(ogrenciNo1 == ogrenciNo2){
                                            cout<<"Matematik " <<"  Turkce"<<"    Sosyal "<<"  Ingilizce "<<" Beden "<<" Gorsel "<<"  Din"<<endl;
                                            cout<<matNot<<"             "<<turNot<<"         "<<sosNot<<"          "<<ingNot<<"        "<<bedNot<<"      "<<gorNot<<"      "<<dinNot<<endl;
                                        }
                                    break;
                                    case 2:
                                        cout<<"Sinav Tarihleri "<<endl;
                                    break;
                                    case 3:
                                        cout<<"Devamsizlik Bilgileri "<<endl;
                                    break;
                                    case 4:
                                        cout<<"Basariyla Cikis Yapilmistir "<<endl;
                                        exit(1);
                                    break;
                                }
                            }while(ogrenciSecim != 4);
                        }
                        else{
                            cout<<"Tc Numarasi Ile Okul Numarasi Eslesmiyor"<<endl;
                            exit(1);
                        }
                        
                    break;
                    case 3:
                        exit(1);
                    break;
                    }
            }while(girisSecim != 3);



        






}
