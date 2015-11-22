#ifndef _C17_CONSTRUCT_2_HPP
#define _C17_CONSTRUCT_2_HPP

#include <iostream>
#include <initializer_list>
#include <vector>

struct X {
    X(int m_X):m_x{m_X}{}
    private:
    int m_x ;
};


struct Y:X {
    X m{0};
    Y(int a):X{a},m{a}{};
    Y():X{0}{};

};

struct S {
    S(const char *){}
    S(double *){}

};

struct S1 {
    int a, b;
};

struct S2 {
    S2(int a = 0,int b = 0):aa(a),bb(b){}
    int aa,bb;
};

template<class T>
struct Handle 
{
    T* p;
    Handle(T* pp = new T{}):p{pp}{}
};

int global{9};
struct reference {
    const int x{7};
    /* requires default constructor
    const int y;
    int& r2;*/
    const int& r{9};
    int& r1{global};
    
};

void f_initializer_list(std::initializer_list<int> args)
{
    for(int index = 0;index != args.size(); index++)
        std::cout<<args.begin()[index]<<" ";
    std::cout<<""<<std::endl;
    
    for(auto x:args)
        std::cout<<x<<" ";
    std::cout<<""<<std::endl;
    
    for(auto p = args.begin(); p != args.end(); ++p)
        std::cout<<*p<<" ";
    std::cout<<""<<std::endl;
}

int f_mutable(std::initializer_list<int> list, int new_val)
{
    /* Initializer list are read only or mutable . They cannot be changed
    *list.begin() = new_val;*/
    std::vector<int> u_vector(list.size(),0);
    std::uninitialized_copy(list.begin(),list.end(),u_vector.begin());
    std::cout<<"Initialize with size...  "<<u_vector.size()<<std::endl;
    return *list.begin();
}

void f_exp(const std::vector<double>& arg){}

void g_exp()
{
    std::vector<double> g_v1{9};
    std::vector<double> g_v2={9};
    f_exp({9});
    std::cout<<g_v1.capacity()<<"   "<<g_v2.capacity()<<std::endl;
}

struct initializer_list_test {
    initializer_list_test(){std::cout<<"Default constructor for initializer_list_test"<<std::endl;}
    initializer_list_test(int index){std::cout<<"Constructor with int as an argument.."<<std::endl;}
    initializer_list_test(std::initializer_list<int> int_list){std::cout<<"Constructor with initializer list as argument"<<std::endl;}

};

struct B { B(int val){std::cout<<"Initialized with ... "<<val<<std::endl;}};
struct BB:B {BB(int val):B{val}{std::cout<<"Initialized BB"<<std::endl;}};
//struct BBB:BB { BBB(int):B(int){}};

#endif
