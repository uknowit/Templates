#include "c17_construct_3.hpp"

int main()
{
    A a;
    std::tuple<int,int> ret = a.return_init_tuple();
    std::cout<<std::get<0>(ret)<<" "<<std::get<1>(ret)<<std::endl;
}
