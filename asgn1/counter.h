#ifndef TEMPLATE_H
#define TEMPLATE_H

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
