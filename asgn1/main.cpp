/*GLOBAL LIST OF SMART POINTERS */
//#include <list>
#include "small.h"
#include "counter.h"
#include "smart_pointer.h"
#include <stdio.h>
#include <string>
#define SUCCESS 0
#define FAILURE 1


using namespace smart_pointers;
int main(void){
   smart_pointer<small> s1 = new small();
   smart_pointer<link> s2 = new link();
   /*
   std::cout << "address of counter s1: " << s1.c1 << "\n" ;
   std::cout << "address of counter s2: " << s2.c1 << "\n";
   *s1 = 4;
   *s2 = 5;
   std::cout << "s1: " << *s1 << "\n" ;
   std::cout << "s2: " << *s2 << "\n";
   if(s1 == s2){
      std::cout << "equal\n";
   }else {
      std::cout << "not equal\n";
   }
   s1 = s2;
   if(s1 == s2){
      std::cout << "equal\n";
   }else {
      std::cout << "not equal\n";
   }
   std::cout << "s1: " << *s1 << "\n" ;
   std::cout << "s2: " << *s2 << "\n";
   // // std::cout << "*s1: " << *s1 << "\n";
   // // std::cout << "*s2: " << *s2 << "\n";
   // printf("count 2: %d\ndata 2: %d\n", s2.get_count(), s2.get_data());
   //printf("count 1: %d\ndata 1: %d\n", s1.get_count(), s1.get_data());
   */
   return SUCCESS;
}
