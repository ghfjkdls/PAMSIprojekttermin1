#include <iostream>
#include <list>
#include <stdlib.h>


int main(){
  std::list<int> list;
  int wybor=0;
  while(wybor!=12){
    std::cout << "\n1-wyswietl liste" << std::endl;
    std::cout << "2-wyswietl liczbe elementow listy" << std::endl;
    std::cout << "3-wyswweitl ostatni element" << std::endl;
    std::cout << "4-wyswietl pierwszy element" << std::endl;
    std::cout << "5-dodaj losowy elemt na poczatek listy" << std::endl;
    std::cout << "6-dodaj losowy element na koniec listy" << std::endl;
    std::cout << "7-dodaj k elementow na pocatek listy" << std::endl;
    std::cout << "8-dodaj l elementow na koniec listy" << std::endl;
    std::cout << "9-usun element z konca listy" << std::endl;
    std::cout << "10-usun j elementow z konca listy" << std::endl;
    std::cout << "11-usun wszystkie elementy listy" << std::endl;
    std::cout << "12-koniec" << std::endl;

    std::cin >> wybor;

    switch(wybor){
      case 1:
        for (std::list<int>::iterator it=list.begin(); it != list.end(); ++it)
        std::cout << *it<<std::endl;
      break;

      case 2:
        std::cout <<list.size()<< std::endl;
      break;

      case 3:
        if(list.empty())std::cout << "lista pusta" << std::endl;
          else  std::cout << list.back()<<std::endl;
      break;

      case 4:
        if(list.empty())std::cout << "lista pusta" << std::endl;
          else  std::cout << list.front()<<std::endl;
      break;

      case 5:
        list.push_front(rand());
      break;

      case 6:
        list.push_back(rand());
      break;

      case 7:
        int k;
        std::cout<<"podaj k: ";
        std::cin>>k;
        for(int i=0;i<k;i++) list.push_front(rand());
      break;

      case 8:
        int l;
        std::cout<<"podaj l: ";
        std::cin>>l;
        for(int i=0;i<l;i++) list.push_back(rand());;
      break;;

      case 9:
      if(list.empty())std::cout << "lista pusta" << std::endl;
        else  list.pop_back();
      break;

      case 10:
        int j;
        std::cout<<"podaj j: ";
        std::cin>>j;
        for(int i=0;i<j;i++) {
          if(list.empty()){
              std::cout << "lista pusta" << std::endl;
              break;
            }
            else list.pop_back();
        }
      break;

      case 11:
        while(list.size()) list.pop_back();
      break;
    }
  }

  return 0;
}
