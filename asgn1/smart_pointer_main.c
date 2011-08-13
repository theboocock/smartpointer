/*
  SMARTPTRMAIN.C
  --------------
*/

#include "smart_pointer.h"

using namespace smart_pointers;

/*
  class LINK
  ----------
  an extremely simple linked list class
*/
class linker
{
 public:
   smart_pointer<linker> next;
   int data;
};

/*
  class BIG
  ---------
  a class that takes up a lot of memory
*/
class big
{
 public:
   int big_array[1000000];
};

/*
  TEST_SCOPE()
  ------------
  function to test whether scope is handled properly
*/
void test_scope(void)
{
   smart_pointer<big> b = new big();
   smart_pointer<big> b2 = b;
   print_all_counts("test scope");
}

/*
  MAIN()
  ------
  Test the smart_pointer code
*/
int main(void)
{
   /*
     Simple Tests
   */
   smart_pointer<int> p;
   smart_pointer<int> q;
   cout << "got here " << endl;
   q = p;
      //*p = 5;
   print_all_counts("first");
   // smart_pointer<int> q = p;
   q = p;
   cout << "q's counts and p's count " << p.get_count() << "  " << q.get_count() << "\n";
   cout << "p = " << *p << " q = " << *q << endl;
   print_all_counts("second");
   smart_pointer<int> r = new int();
   *r = 2;
   print_all_counts("third");
   p = r;
   cout << "p = " << *p << " q = " << *q << " r = " << *r << endl;
   print_all_counts("fourth");
   q = p;
   cout << "p = " << *p << " q = " << *q << " r = " << *r << endl;
   q = p = r = 0;
   print_all_counts("fifth");

   /*
     test a circular linked list, there should be no way of deleting
     this list - in other words, garbage is created
   */
   smart_pointer<linker> l = new linker();
   l->data = 1;
   assert(l->data == (*l).data);
   l->next = new linker(); 
   l->next->next = new linker(); 
   l->next->next->next = l;
   l = 0;
   print_all_counts("after linked list");

   /*
     test the allocation/deletion of big objects
     Warning: make sure that your code deallocates properly before
     trying to do this. If it doesn't deallocate, then you will be
     trying to allocate 1G of memory which will usually mean bad
     things. If it does deallocate, you'll only use 1M of memory for
     this part.
   */
   smart_pointer<big> b = new big();
   for (int i=0; i < 1000; i++){
      b = new big();
   }
   // print_all_counts("after big");

   /*
     test that scoping doesn't cause any problem
   */
   test_scope();
   print_all_counts("last");

   return 0;
}

