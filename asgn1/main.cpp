/*GLOBAL LIST OF SMART POINTERS */
//#include <list>

#include "smart_pointer.h"
#include <stdio.h>
#define SUCCESS 0
#define FAILURE 1

//using namespace smart_pointer;
int main(void){
   smart_pointer<int> s1 = new int();
   // smart_pointer<int> s2 = new int();

   // std::cout << &s1 << "\n" ;
   // std::cout << &s2 << "\n";
   // s2.set_data(5);
   // s1.set_data(4);
   // s1 = s2;
   
   // std::cout << "&s1: " << &s1 << "\n" ;
   // std::cout << "&s2: " << &s2 << "\n";
   // // std::cout << "*s1: " << *s1 << "\n";
   // // std::cout << "*s2: " << *s2 << "\n";
   // printf("count 2: %d\ndata 2: %d\n", s2.get_count(), s2.get_data());
   //printf("count 1: %d\ndata 1: %d\n", s1.get_count(), s1.get_data());
   
   return SUCCESS;
}
