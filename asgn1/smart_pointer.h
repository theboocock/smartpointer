#ifndef _SMART_POINTER_H
#define _SMART_POINTER_H
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


template<class T> class smart_pointer{
  public:
   struct counter{
      T *data;
      int count;
   };
   counter* c1;
   
   int get_count(){
      return c1->count;
   }
   T get_data(){
      return *c1->data;
   }
   void set_data(T x){
      *c1->data = x;
   }
   T *give_data(){
      return c1->data;
   }
   smart_pointer & operator= (const smart_pointer &var1){
      std::cout << "in operator overload\n";
      if(this != &var1){
         if(c1->count == 1){
            delete c1->data;
         }
         c1->count--;
         c1 = var1.c1;
         c1->count++;
      }
      return *this;
   }
   smart_pointer(T* p){
      std::cout << p << "\n";
      std::cout << "dasdasdasd\n";
      c1->data = p;
      //c1->count = 1;

      
   }
   ~smart_pointer(){
      std::cout << "start \n";
      c1->count--;
      if(c1->count == 0){
         std::cout << *c1->data << "\n";
         delete c1->data;
      }
   }
};

#endif
