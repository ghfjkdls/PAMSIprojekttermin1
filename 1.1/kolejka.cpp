#include <iostream>
#include <queue>
#include <stdlib.h>


int main(){
  std::queue<int> queue;
  int wybor=0;
  while(wybor!=7){
    std::cout << "\n1-dodaj losowy element na koniec" << std::endl;
    std::cout << "2-dodaj l losowych elementow na koniec" << std::endl;
    std::cout << "3-usun element z poczatku kolejki" << std::endl;
    std::cout << "4-usun k elementow z poczatku" << std::endl;
    std::cout << "5-wyswietl pierwszy element" << std::endl;
    std::cout << "6-wyswietl liczbe elementow w kolejce" << std::endl;
    std::cout << "7-zakoncz" << std::endl;
    std::cin >> wybor;

    switch(wybor){
      case 1:
        queue.push(rand());
      break;

      case 2:
        int l;
        std::cout << "podaj l " << std::endl;
        std::cin >> l;
        for(;l>0;l--) queue.push(rand());
      break;

      case 3:
        if(queue.empty())std::cout << "koejka pusta" << std::endl;
          else  queue.pop();
      break;

      case 4:
        int k;
        std::cout << "podaj k " << std::endl;
        std::cin >> k;
        for(;k>0;k--) {
          if(queue.empty()){
              std::cout << "kolejka pusta" << std::endl;
              break;
            }
            else  queue.pop();
          }
      break;

      case 5:
        if(queue.empty())std::cout << "kolejka pusta" << std::endl;
          else std::cout << queue.front() << std::endl;
      break;

      case 6:
        std::cout << queue.size() <<std::endl;
      break;

      default:;
    }
  }

  return 0;
}
