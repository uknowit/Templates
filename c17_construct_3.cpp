#include "c17_construct_3.hpp"

int count_1 = 0;
int count_2 = 0;

int func_add_count(int i){ return i+count_1;}

struct S 
{
    int m1{count_2};
    int m2{func_add_count(m1)};
    S(){++count_2;}
    std::tuple<int,int> get_members(){ return std::make_tuple(m1,m2);}
};

int main()
{
    A a;
    std::tuple<int,int> ret = a.return_init_tuple();
    std::cout<<std::get<0>(ret)<<" "<<std::get<1>(ret)<<std::endl;
    S s1;
    std::cout<<std::get<0>(s1.get_members())<<" "<<std::get<1>(s1.get_members())<<std::endl;
    ++count_1;
    S s2;
    std::cout<<std::get<0>(s2.get_members())<<" "<<std::get<1>(s2.get_members())<<std::endl;
}
