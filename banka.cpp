#include <iostream>
#include <string>
#include <fstream>
#include <istream>
using namespace std;
int menu1;
int kullanicino;
int kullanicino2;
int kullanicisifre;
int kullanicisifre2;
int kartliislemler;
int bakiye;
int paracekme;
int parayatirma;
int kartsizislem;
int kyktc;
int kyktcgirdi;
int kykodeme;
string kykisim;
string kullaniciisim;
int main(){
    ifstream kykokuma;
    kykokuma.open("vize",ios::in);
    if(!kykokuma){
        cerr<<"error:dosya acilamadi"<<endl;
    }
    ifstream dosyaoku;
    dosyaoku.open("kullanici",ios::in);
    if(!dosyaoku){
        cerr<<"error:dosya acilamadi"<<endl;
    }
    while(dosyaoku>>kullanicino>>kullanicisifre>>kullaniciisim>>bakiye){
    while(kykokuma>>kyktc>>kykodeme>>kykisim){
    cout<<"Merhaba Iyi Gunler "<<endl;
    cout<<"1.Kartli Islem "<<endl;
    cout<<"2.Kartsiz Islem"<<endl;
    cout<<"3.Cikis"<<endl;
    cin>>menu1;
        switch(menu1){
            case 1:
                cout<<"kullanici no gir"<<endl;
                cin>>kullanicino2;
                cout<<"lutfen sifrenizi giriniz"<<endl;
                cin>>kullanicisifre2;
                if(kullanicino==kullanicino2 && kullanicisifre==kullanicisifre2){
                    cout<<"Giris basarili"<<endl;
                    cout<<"Hosgeldiniz Sayin "<<endl;
                    cout<<kullaniciisim<<endl;
                    do{
                    cout<<"---Yapilabilecek Islemler---"<<endl;
                    cout<<"1.Bakiye Sorgulama "<<endl;
                    cout<<"2.Para Cekme "<<endl;
                    cout<<"3.Para Yatirma"<<endl;
                    cout<<"4.Cikis"<<endl;
                    cin>>kartliislemler;
                        switch(kartliislemler){
                            case 1:
                                cout<<"Bakiyeniz :";
                                cout<<bakiye<<endl;
                            break;
                            case 2:     
                                cout<<"Cekmek Istediginiz Miktari Giriniz :"<<endl;
                                cin>>paracekme;
                                    if(bakiye>=paracekme){
                                        bakiye=bakiye-paracekme;
                                        cout<<"Kalan Bakiyeniz :";
                                        cout<<bakiye<<endl;
                                    }
                            break;
                            case 3:
                                cout<<"Yatirmak Istediginiz Miktari Giriniz"<<endl;
                                cin>>parayatirma;
                                bakiye=bakiye+parayatirma;
                                cout<<"Yeni Bakiyeniz :";
                                cout<<bakiye;
                            break;

                        }
                    }while(kartliislemler!=4);
                }
                else if(kullanicino != kullanicino2 && kullanicisifre!=kullanicisifre2){
                    cout<<"kullanici no yada sifre hatali"<<endl;
                }
            break;
            case 2:
                do{
                cout<<"Yapilabilecek Islemler"<<endl;
                cout<<"1.KYK Ilk Odeme"<<endl;
                cout<<"2.Telefon Numarası Ile Para Cekme"<<endl;
                cout<<"3.Fatura Yatirma Islemleri"<<endl;
                cout<<"3.Cikis"<<endl;
                cin>>kartsizislem;
                    switch(kartsizislem){
                        case 1: 
                            cout<<"Lutfen Tc Kimlik Numaranizi Giriniz :"<<endl;
                            cin>>kyktcgirdi;
                                if(kyktc == kyktcgirdi){
                                    cout<<"Hosgeldiniz Sayin"<<endl;
                                    cout<<kykisim<<endl;
                                    cout<<"Bu Ayki KYK Odemeniz :"<<endl;
                                    cout<<kykodeme<<endl;
                                }
                        break;
                        case 2:
                        break;
                        case 3:
                        break;
                    }
                }while(kartsizislem!=3);
            break;
            case 3:
                cout<<"Iyi GÜnler"<<endl;
                exit(1);
            break;
        }
    
 

    }
    }
}                                                         