#include <iostream>
using namespace std;
class BiNode{
    public:
        BiNode* llink;
        int item;
        BiNode* rlink;

};
class DoublyList{
    public:
        void addleft(int);
        void addright(int);
        void rightprint();
        DoublyList(){Lleft=Lright=NULL;}
    private:
        BiNode* Lleft;
        BiNode* Lright;
};
void DoublyList::addleft(int additem){
    BiNode* newNode = new BiNode;
    newNode->item=additem; 
    newNode->llink=NULL;
    newNode->rlink=NULL;
    newNode->rlink=Lleft;
    if(Lleft==NULL){
        Lright=newNode;
    }
    else{
        Lleft->llink=newNode;

    }
    Lleft=newNode;
}
void DoublyList::addright(int additem){
    BiNode* newNode=new BiNode;
    newNode->item=additem;
    newNode->llink=NULL;
    newNode->llink=Lright;
    if(Lright==NULL){
        Lleft=newNode;

    }
    else{
        Lright->rlink=newNode;
    }
    Lright=newNode;
}
void DoublyList::rightprint(){
    BiNode* tmpNode=Lleft;
    while(tmpNode != NULL){
        cout<<tmpNode->item;
        tmpNode=tmpNode->rlink;
    }
}
int main(){
    int sayi;
    DoublyList DL;
    for(int i=0;i<5;i++){
        cin>>sayi;
        DL.addleft(sayi);
    }
    for(int i=0;i<5;i++){
        cin>>sayi;
        DL.addright(sayi);
    }
    DL.rightprint();
}

