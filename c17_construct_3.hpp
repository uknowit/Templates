#ifndef _C17_CONSTRUCT_3_HPP
#define _C17_CONSTRUCT_3_HPP

#include <iostream>
#include <string>
#include <initializer_list>
#include <tuple>
class A {
    public:
        A(){}
        std::tuple<int,int> return_init_tuple() 
        { 
            return std::make_tuple(a,b);
        }
    private:
        int a{9};
        int b{10};
};
#endif
