#include "Namespace.hpp"
#include <iostream>
#include <vector>
void N::h(int number)
{
    std::cout<<number<<std::endl;
}


void fun_namespace_1()
{
    int i = 0;
    using namespace X;
    i++;
    j++;
    ::k++;
    X::k++;
}

void fun_namespace_2()
{
    int i = 0;
    //using X::i; results in redeclaration of i
    using X::j;
    using X::k;
    i++;
    j++;
    k++;
    Name_composition::h(k);

}


using namespace Estd;
template<typename T> void print(const std::vector<T>& my_vec)
{
    for(auto& x: my_vec)
        std::cout<<x<<' ';
    std::cout<<'\n';
}

void fun_namespace_3()
{
    std:vector<int> v {7, 3, 9, 4, 0, 1};
    sort(v);
    print(v);
}

int main()
{
    std::cout<<"23rd December"<<std::endl;
    fun_namespace_3();
    return 0;
}

