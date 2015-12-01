#include "c17_construct_4.hpp"

void func_handle()
{
    Handle<int> h1{new int{7}};
    /*Handle<int> h2 {h1} ;*/ //deprecated, compilation is fine....
}

template<class T> T* clone(T* p)
{
    return new T;
}

foo* clone(foo* p) = delete;

void func_template_delete(shape* ps)
{
    shape *ps1 = clone(ps);
    cout<<ps1<<std::endl;
    //foo pf1 = clone(new foo);
}

int main()
{
    func_handle();
    Base X1;
    //Base X2{X1}; Default Copy & move constructor 
    //and assignment operator deleted
    func_template_delete(new shape);
    return 0;
}
