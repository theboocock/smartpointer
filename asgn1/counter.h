#ifndef COUNTER_H
#define COUNTER_H

template <class T>
class counter{
 public:
   T *data;
   int count;
   counter(T *p){
      data = p;
   }
};

#endif
