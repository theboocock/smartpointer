#ifndef _SMART_POINTER_H
#define _SMART_POINTER_H
//#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "counter.h"
namespace smart_pointers{
   template<typename T>
      class smart_pointer{
   public:
      counter<T> *c1;
   
      int get_count(){
         return c1->count;
      }
   
      T& operator*() {
         return *c1->data;
      }
      T* operator->() {
         return c1->data;
      }
      bool operator==(const smart_pointer &var1){
         if(c1  == var1.c1){
            return true;
         } else {
            return false;
         }
      }
      bool operator!=(const smart_pointer &var1){
         if(c1  == var1.c1){
            return false;
         } else {
            return true;
         }
      }
      bool operator<(const smart_pointer &var1){
         if(c1 > var1.c1){
            return false;
         } else {
            return true;
         }
      }
      bool operator>(const smart_pointer &var1){
         if(c1 < var1.c1){
            return false;
         } else {
            return true;
         }
      }
      bool operator>=(const smart_pointer &var1){
         if(c1 >= var1.c1){
            return true;
         } else {
            return false;
         }
      }
      bool operator<=(const smart_pointer &var1){
         if(c1 <= var1.c1){
            return true;
         } else {
            return false;
         }
      }
      smart_pointer & operator= (const smart_pointer &var1){
         if(this != &var1){
            c1->count--;
            if(c1->count == 0){
               std::cout << "deleting a counter\n";
               delete c1->data;
               delete c1;
            }
            c1 = var1.c1;
            c1->count++;
         }
         return *this;
      }
      smart_pointer(T* p){
         c1 = new counter<T>(p);
         c1->count = 1;
      }
      ~smart_pointer(){
         std::cout << "calling descructor for smrt pntr \n";
         c1->count--;
         if(c1->count == 0){
            std::cout << "deleting a counter\n";
            delete c1->data;
            delete c1;
         }
      }
   };
}

#endif
