#include "pointer_list.h"

pointer_list *pointer_list::instance;
using namespace std;

pointer_list::pointer_list(){
   num_smart_pointers = 0;
}

void pointer_list::add_to_list(void * to_add){
  map<void *,int>::iterator it;
  if((it = count_map.find(to_add)) != count_map.end()){
     it->second++;
   }
   else{ count_map[to_add] = 1;}      
}

pointer_list* pointer_list::get_instance() {
   if (instance ==  0){
      instance = new pointer_list();
   }
   return instance; 
}

void pointer_list::print_all_counts(const char * var){
   cout << var <<  " begin" << endl;
   map<void *,int>::iterator it;
   for(it = count_map.begin(); it  != count_map.end(); it++){
      cout<< "\tlocation = " << (long)it->first << ", count = " << it->second << endl;
   }
   cout << var << " end"   << endl;  
}

void pointer_list::erase(void *to_delete){
   count_map.erase(to_delete);
}

void pointer_list::decrement_count(void * to_incr){
   map<void *,int>::iterator it;
   if((it = count_map.find(to_incr)) != count_map.end()){
      it->second--;
   }
}



