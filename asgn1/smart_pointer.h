#ifndef _SMART_POINTER_H
#define _SMART_POINTER_H
//#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "counter.h"
#include "pointer_list.h"

namespace smart_pointers{
   using namespace std;
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
            if(c1 != 0){               
               c1->count--;
               if(c1->count == 0){
                  delete c1->data;
                  delete c1;
               }
            }
            c1 = var1.c1;
            c1->count++;
         }
         return *this;
      }
      smart_pointer(){
         c1 =0 ;
      }
       
      smart_pointer(T* p){
         c1 = new counter<T>(p);
         c1->count = 1;
      }
      smart_pointer(const smart_pointer &var1){       
         c1 = var1.c1;
         c1->count++;
      }
      ~smart_pointer(){
         c1->count--;
         if(c1->count == 0){
            delete c1->data;
            delete c1;
         }
      }
   };

   static void print_all_counts(const char * var){
      cout << "wow" <<endl;
}

#endif
