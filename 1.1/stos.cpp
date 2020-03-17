#include <iostream>
#include <stack>
#include <stdlib.h>


int main(){
  std::stack<int> stos;
  int wybor=0;
  while(wybor!=7){
    std::cout << "\n1-dodaj losowy element na szczyt" << std::endl;
    std::cout << "2-dodaj m losowych elementow na szczyt" << std::endl;
    std::cout << "3- wyswietl element na szczycie" << std::endl;
    std::cout << "4-usun element ze szczytu" << std::endl;
    std::cout << "5-usun k elementow ze szczytu" << std::endl;
    std::cout << "6-wyswietl liczbe elementow na stosie" << std::endl;
    std::cout << "7-zakoncz" << std::endl;
    std::cin >> wybor;

    switch(wybor){
      case 1:
        stos.push(rand());
      break;

      case 2:
        int m;
        std::cout << "podaj m " << std::endl;
        std::cin >> m;
        for(;m>0;m--) stos.push(rand());
      break;

      case 3:
        if(stos.empty())std::cout << "stos pusty" << std::endl;
          else std::cout << stos.top() << std::endl;
      break;

      case 4:
        if(stos.empty())std::cout << "stos pusty" << std::endl;
          else  stos.pop();
      break;

      case 5:
      int k;
      std::cout << "podaj k " << std::endl;
      std::cin >> k;
      for(;k>0;k--) {
        if(stos.empty()){
            std::cout << "stos pusty" << std::endl;
            break;
          }
          else  stos.pop();
      }
      break;

      case 6:
        std::cout << stos.size() <<std::endl;
      break;

      default:;
    }
  }

  return 0;
}
