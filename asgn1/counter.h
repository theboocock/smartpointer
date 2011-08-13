#ifndef COUNTER_H
#define COUNTER_H

#include "pointer_list.h"
template <class T>
class counter{
 public:
   int count;
   T *data;
   counter(T *p){
      data = p;
   }
   ~counter(){
      delete data;
   }
   };

#endif
