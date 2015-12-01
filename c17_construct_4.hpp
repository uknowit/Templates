#ifndef _C17_CONSTRUCT_4_HPP
#define _C17_CONSTRUCT_4_HPP

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

struct foo{};
struct shape{};
template<class T> class Handle 
{
    private:
            T* p;
    public:
            Handle(T* pp):p(pp){}
            T& operator*(){return p;}
            ~Handle(){delete p;}
};

class Base {
    
    public:
    Base(){}
    Base& operator=(const Base& arg) = delete;
    Base(const Base& arg) = delete;

    Base(Base&& arg) = delete;
    Base& operator=(Base&& arg) = delete;

    private:
};

#endif
