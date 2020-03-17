#include <iostream>
#define SIZE 3

class stack{
    int *tab=new int[SIZE];
    int it=-1;
    int maxsize=SIZE;
  public:
    int pop();
    int push(int x);
    int top();
    int size();
    bool empty();
};


int stack::push(int x){
  if(it>=maxsize-1){
    maxsize=maxsize*2;
    int *newtab = new int[maxsize];
    for(int i=0;i<it+1;i++){
       newtab[i]=tab[i];
     }
    tab=newtab;
    it++;
    tab[it]=x;
    return 0;
  }else{
    it++;
    tab[it]=x;
  return 0;
}
}


int stack::pop(){
  if(it==-1){
    std::cout<<"blad"<<std::endl;
    return 1;
  }else it--;
  return 0;
}

int stack::size(){
  int size;
  size=it+1;
  return size;
}

int stack::top(){
  if(it==-1){
    std::cout<<"stos pusty"<<std::endl;
    return 1;
  }else {
      std::cout<<tab[it]<<std::endl;
      return tab[it];
    }
}

bool stack::empty(){
  if(it==-1)return true;
  else return false;
}

int main(){
  stack stos;
  int wybor=0;

  while(wybor!=6){
    std::cout<<"\n1-dodaj element na stos"<<std::endl;
    std::cout<<"2-usun element ze stosu"<<std::endl;
    std::cout<<"3-top"<<std::endl;
    std::cout<<"4-czy pusty"<<std::endl;
    std::cout<<"5-ile elementow na stosie"<<std::endl;
    std::cout<<"6-koniec"<<std::endl;
    std::cin>>wybor;
  switch(wybor){
    case 1:
    int x;
    std::cout<<"podaj wartosc: ";
    std::cin>>x;
    stos.push(x);
    break;

    case 2:
    stos.pop();
    break;

    case 3:
    stos.top();
    break;

    case 4:
    if(stos.empty())std::cout<<"stos pusty"<<std::endl;
      else std::cout<<"stos niepusty"<<std::endl;
    break;

    case 5:
    std::cout<<stos.size()<<std::endl;
    break;
   }
  }return 0;
}
