#include <iostream>

struct elem{
  int data;
  elem *next;
};

class list{
    elem *head, *tail;
    public:
    list(){
      head=NULL;
      tail=NULL;
    }
    void insertback(int value);
    void insertfront(int value);
    void display();
    void insertpos(int pos, int value);
    void deletefront();
    void deleteback();
    void deletepos(int pos);
    int size();
    void displayfront();
    void displayback();
  };


  void list::insertback(int value){
      elem *temp=new elem;
      temp->data=value;
      temp->next=NULL;
      if(head==NULL){
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else{
        tail->next=temp;
        tail=temp;
      }
    }

  void list::insertfront(int value){
    elem *temp=new elem;
    temp->data=value;
    temp->next=head;
    head=temp;
  }

  void list::insertpos(int pos, int value){
    elem *pre=new elem;
    elem *cur=new elem;
    elem *temp=new elem;
    cur=head;
    for(int i=0;i<pos;i++){
      pre=cur;
      cur=cur->next;
    }
    temp->data=value;
    pre->next=temp;
    temp->next=cur;
}

int list::size(){
  int size=0;
  elem *temp=new elem;
  temp=head;
  while(temp!=NULL){
    temp=temp->next;
    size++;
  }
  return size;
}

void list::deletefront(){
  elem *temp=new elem;
  temp=head;
  head=head->next;
  delete temp;
}

void list::deleteback(){
  elem *current=new elem;
  elem *previous=new elem;
  current=head;
  while(current->next!=NULL){
    previous=current;
    current=current->next;
  } tail=previous;
  previous->next=NULL;
  delete current;
}

void list::deletepos(int pos){
  elem *current=new elem;
  elem *previous=new elem;
  current=head;
  for(int i=1;i<pos;i++){
    previous=current;
    current=current->next;
  } previous->next=current->next;
}

void list::display(){
  elem *temp=new elem;
  temp=head;
  while(temp!=NULL){
    std::cout<<temp->data<<std::endl;
    temp=temp->next;
  }
}

void list::displayfront(){
  elem *temp=new elem;
  temp=head;
  std::cout<<temp->data<<std::endl;
}

void list::displayback(){
  elem *temp=new elem;
  temp=head;

  for(int i=1;i<size();i++) temp=temp->next;
  std::cout<<temp->data<<std::endl;
}

  int main(){

    list list;
    int menu=0, value, pos;

    while(menu != 99){
        std::cout<<"\n1-sprawdz czy lista jest pusta"<<std::endl;
        std::cout<<"2-dodaj element na poczatek"<<std::endl;
        std::cout<<"3-dodaj element na koniec"<<std::endl;
        std::cout<<"4-dodaj element na zadana pozycje"<<std::endl;
        std::cout<<"5-usun poczatkowy element"<<std::endl;
        std::cout<<"6-usun ostatni element"<<std::endl;
        std::cout<<"7-usun wybrany element"<<std::endl;
        std::cout<<"8-wyswietl liste"<<std::endl;
        std::cout<<"9-wyswietl pierwszy element"<<std::endl;
        std::cout<<"10-wyswietl ostatni element"<<std::endl;
        std::cout<<"99-koniec"<<std::endl;
        std::cin>>menu;

        switch(menu){
          case 1: if(list.size()) std::cout<<"lista nie jest pusta"<<std::endl;
            else std::cout<<"lista jest pusta"<<std::endl;
          break;

          case 2: std::cout<<"podaj wartosc"<<std::endl;
          std::cin>>value;
          list.insertfront(value);
          break;

          case 3: std::cout<<"podaj wartosc"<<std::endl;
          std::cin>>value;
          list.insertback(value);
          break;

          case 4: std::cout<<"podaj wartosc"<<std::endl;
          std::cin>>value;
          std::cout<<"podaj pozyce"<<std::endl;
          std::cin>>pos;
          if(pos<=list.size()+1 && pos>1) list.insertpos(pos, value);
            else std::cout<<"podano zla wartosc pozycji"<<std::endl;
          break;

          case 5: if(list.size()) list.deletefront();
            else std::cout<<"lista jest pusta"<<std::endl;
          break;

          case 6: if(list.size()) list.deleteback();
            else std::cout<<"lista jest pusta"<<std::endl;
          break;

          case 7: std::cout<<"podaj pozyce"<<std::endl;
          std::cin>>pos;
          if(pos<=list.size() && pos>1) list.deletepos(pos);
            else std::cout<<"podano zla pozycje"<<std::endl;
          break;

          case 8: list.display();
          break;

          case 9: list.displayfront();
          break;

          case 10: list.displayback();
          break;
        }
    }

    return 0;
  }
