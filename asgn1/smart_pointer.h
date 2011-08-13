#ifndef _SMART_POINTER_H
#define _SMART_POINTER_H
//#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "counter.h"
#define null 0


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
            if(c1 != null){               
               c1->count--;
               pointer_list::get_instance()->decrement_count(c1->data);
               if(c1->count == 0){
                  delete c1;
                  pointer_list::get_instance()->erase(c1->data);
               }
            } else {
               pointer_list::get_instance()->decrement_count(null);
            }
            c1 = var1.c1;
            if(var1.c1 != null){
               c1->count++;
               pointer_list::get_instance()->add_to_list(c1->data);
            } else {
               pointer_list::get_instance()->add_to_list(null);  
            }
         }
         return *this;
      }
      smart_pointer(){
         c1 = null;
         pointer_list::get_instance()->add_to_list(null);
      }
       
      smart_pointer(T* p){
         c1 = new counter<T>(p);
         c1->count = 1;
         pointer_list::get_instance()->add_to_list(c1->data);
      }
      smart_pointer(const smart_pointer &var1){
         cout << var1.c1 << endl;
         c1 = var1.c1;
         if(c1 != 0){
         c1->count++;
          pointer_list::get_instance()->add_to_list(c1->data);
         } else {
            pointer_list::get_instance()->add_to_list(null);
         }
      }
      ~smart_pointer(){
         c1->count--;
         pointer_list::get_instance()->decrement_count(c1->data);
         if(c1->count == 0){
            delete c1;
            pointer_list::get_instance()->erase(c1->data);
         }
      }
   };
}

   static void print_all_counts(const char * var){
      pointer_list::get_instance()->print_all_counts(var);
}

#endif
