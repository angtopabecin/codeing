#include <iostream>
using namespace std;
class Node{
    public:
        int item;
        Node* link;
        Node(){item=0;link=NULL;}
};
class Queue{
    public:
        void enqueue(int);
        int dequeue();
        Queue(){Front=NULL;Rear=NULL;}
    private:
        Node* Front;
        Node* Rear;
    
};
void Queue::enqueue (int qitem){
    Node* newNode=new Node;
    newNode->item=qitem;
    newNode->link=NULL;
    if(Front== NULL){
        Front=newNode;

    }
    else{
        Rear->link=newNode;
    }
    Rear=newNode;
}
int Queue::dequeue(){
    if(Front!=NULL){
        Node* delNode=Front;
        Front=delNode->link;
        if(Front==NULL) Rear=NULL;
        int dequeueitem=delNode->item;
        delete(delNode);
        return dequeueitem;
    }
}
int main(){
    int sayi;
    Queue QUE;
    for(int i=0;i<10;i++){
        cin>>sayi;
        QUE.enqueue(sayi);
    }
    cout<<QUE.dequeue();
    int sayilar=QUE.dequeue();
    cout<<sayilar<<endl;
    sayilar=QUE.dequeue();
    cout<<sayilar<<endl;
    sayilar=QUE.dequeue();
    cout<<sayilar<<endl;
}