#ifndef _SMART_POINTER_H
#define _SMART_POINTER_H
#include <stdlib.h>
#include <stdio.h>
#include <iostream>



class smart_pointer{
 protected:
   int *count;
   int *data;
 public:
   int get_count(){
      return *count;
   }
   int get_data(){
      return (int)*data;
   }
   void increment_count(){
      (*count)++;
   }
   void set_data(int x){
      *data = x;
   }
   int *give_count(){
      return count;
   }
   int *give_data(){
      return data;
   }
    smart_pointer & operator= ( smart_pointer &var1){
      std::cout << "in operator overload\n";
      if(this != &var1){
         if(*count == 1){
            delete count;
            delete data;
         }
         count = var1.give_count();
         data = var1.give_data();
         var1.increment_count();
      }
      return *this;
   }
   smart_pointer(int* p){
      data = p;
      count = new int();;
      *count = 1;
   }
   ~smart_pointer(){
      std::cout << "start \n";
      (*count)--;
      if(*count == 0){
         std::cout << *data << "\n";
         delete count ;
         delete data;
      }
   }
};

#endif
