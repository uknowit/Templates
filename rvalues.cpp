#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct A {
    A(){}
    ~A(){}
    
    A(const A& a)
    {
    }
    
    A& operator=(const A &rhs)
    {
        std::cout<<"Calling copy constructor operator "<<std::endl;
    }
    
    A& operator=(A&& rhs)
    {
        std::cout<<"Calling rvalue reference"<<std::endl;
    }

};

A foo() {A a ; return a;}


int main()
{
    A foo();
    std::cout<<"Stage1....."<<std::endl;
    A a = foo();
    std::cout<<"Stage2....."<<std::endl;
    a = foo();
}
