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
    /* Local variable that cannot be destoryed...
    Not_on_stack no_stack;*/
    Not_on_stack *no_stack_p = new Not_on_stack;
    no_stack_p->fun_dest();    
    
    Not_on_free_store no_free_store;
    no_free_store.func_new();
    /* Cannot allocate object on free store when
     * class memory allocation operator is deleted
    Not_on_free_store *no_free_store_p = new Not_on_free_store;*/
    return 0;
}
