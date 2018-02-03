#include <iostream>
#include "TSTs.h"
//5
//she
//he
//say
//shr
//her
//yasherhs
int main(int argc, char* argv[])
{
    TSTs aho;
    aho.insert("abc");
    aho.insert("cde");
    aho.construct_fail();
    int c = aho.recognize("abcdef");
    return 0;
}
