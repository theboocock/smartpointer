#ifndef SMART_POINTER_TEMPLATE_H_
#define SMART_POINTER_TEMPLATE_H_

template <class T>
class smart_pointer_template{
 public:
   T* my_data;
   unsigned int count;
   smart_pointer_template(T* p){
      my_data = p;
      count = 1;
   }
   ~smart_pointer_template(){
      
   }
   void get_count(){
      return count;
   }
   void set_data(T p){
      *my_data =p;
   }
   T get_data(){
      return *my_data;
   }
};
#endif
