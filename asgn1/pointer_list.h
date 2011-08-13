#ifndef POINTER_LIST_H_
#define POINTER_LIST_H_

#include <map>
#include <iostream>

class pointer_list{
 private:
   int num_smart_pointers;
   std::map<void *, int > count_map;
   static pointer_list* instance;
   pointer_list();

 public:
   static pointer_list* get_instance();
   void add_to_list(void * to_add);
   void print_all_counts(const char * var);
   void erase           (void * to_delete);
   void decrement_count(void * to_incr);
   };

#endif


