#ifndef POINTER_LIST_H_
#define POINTER_LIST_H_

#include <map>

class pointer_list{

 private:
   int num_smart_pointers;
   map<int, smart_pointer*> count_map;
   static pointer_list* instance;
   pointer_list(){
      num_smart_pointers = 0;           
   }

 public:
   static pointer_list* get_instance(){
      if (instance = 0){
         this->instance = pointer_list();
         return instance;
      }else{
         return instance; 
      }
   }

   void add_to_list(smart_pointer * to_add){
      map[num_smart_pointers++] = to_add;
   }

   void print_all_counts(){
      
   }   
}
   


