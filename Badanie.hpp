#ifndef BADANIE_HPP
#define BADANIE_HPP

class Badanie {
public:
   static  void testInsert(int size, int samples, int operations);
    static void testRemove(int size, int samples, int operations);
    static void testFind(int size, int samples, int operations);
};

#endif
