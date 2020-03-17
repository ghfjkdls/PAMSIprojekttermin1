#include <iostream>
#define SIZE 3

class queue{
    int *tab=new int[SIZE];
    int front=0;
    int back=0;
    int maxsize=SIZE;
  public:
    int pop();
    int push(int x);
    int top();
    int size();
    bool empty();
};

int queue::push(int x){
  if(size()>=maxsize-1){
    std::cout<<"powiekszam"<<std::endl;
    int *newtab = new int[2*maxsize];
    for(int i=0;i<size();i++){
       newtab[i]=tab[(front+i)%maxsize];
     }
    maxsize=maxsize*2;
    tab=newtab;
    tab[back]=x;
    back=(back+1)%maxsize;
    return 0;
 }else{
    tab[back]=x;
    back=(back+1)%maxsize;
  return 0;
 }
}

int queue::pop(){
  if(empty()){
    std::cout<<"blad"<<std::endl;
    return 1;
  }else front=(front+1)%maxsize;
  return 0;
}

int queue::size(){
  int size;
  size=(maxsize - front + back) % maxsize;
  return size;
}

int queue::top(){
  if(empty()){
    std::cout<<"stos pusty"<<std::endl;
    return 1;
  }else {
      std::cout<<tab[front]<<std::endl;
      return tab[front];
    }
}

bool queue::empty(){
  if(front==back)return true;
  else return false;
}


int main(){
  queue queue;
  int wybor=0;

  while(wybor!=6){
    std::cout<<"\n1-dodaj element na koniec kolejki "<<std::endl;
    std::cout<<"2-usun element z poczatku kolejki"<<std::endl;
    std::cout<<"3-wyswietl i wczytaj pierwszy element kolejki"<<std::endl;
    std::cout<<"4-czy pusty"<<std::endl;
    std::cout<<"5-ile elementow na w kolejce"<<std::endl;
    std::cout<<"6-koniec"<<std::endl;
    std::cin>>wybor;
  switch(wybor){
    case 1:
    int x;
    std::cout<<"podaj wartosc: ";
    std::cin>>x;
    queue.push(x);
    break;

    case 2:
    queue.pop();
    break;

    case 3:
    queue.top();
    break;

    case 4:
    if(queue.empty())std::cout<<"stos pusty"<<std::endl;
      else std::cout<<"stos niepusty"<<std::endl;
    break;

    case 5:
    std::cout<<queue.size()<<std::endl;
    break;
   }
  }return 0;
}
