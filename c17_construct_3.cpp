#include "c17_construct_3.hpp"
#include <utility>

int count_1 = 0;
int count_2 = 0;

int func_add_count(int i){ return i+count_1;}

Image::Image(const Image& copy_obj):shared(true),data{copy_obj.data}
{
    std::cout<<"Calling copy constructor....."<<std::endl;
}

void Image::write_block(void* copy,int buf_len)
{
    if(shared)
    {
        this->data = malloc(sizeof(void*)*buf_len);
        std::memcpy(this->data,  copy, sizeof(void*)*buf_len);
        shared = false;
    }
}

struct S 
{
    int m1{count_2};
    int m2{func_add_count(m1)};
    S(){++count_2;}
    std::tuple<int,int> get_members(){ return std::make_tuple(m1,m2);}
};

Matrix<int> opt_fun()
{
    Matrix<int> m4(3,3);
    return m4;
}

template<class T> void my_swap(T& a, T& b)
{
    T tmp = std::move(a);
    std::cout << "step 1....."<<std::endl;
    a = std::move(b);
    std::cout << "step 2....."<<std::endl;
    b = std::move(tmp);
}

default_op fun_default_op (default_op arg)
{
    default_op def_obj{};
    default_op def_cp_obj{def_obj};
    def_cp_obj = arg ;
    return def_cp_obj;
}

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
    
    Image img ;
    Image img_1 = img;
    void *buf = malloc(sizeof(void*) * 100);
    img_1.write_block(buf,100);
    free(buf);
    
    Matrix<int> m1(2,4);
    Matrix<int> m2 = m1;
    Matrix<int> m3 = opt_fun();
    m2 = m3;
    my_swap(m1,m3);
    default_op op_obj;
    op_obj = fun_default_op(op_obj);
    
    Invariant_Z vo;
    int val[10];
    Invariant_Z va{{1,2,3},1,&val[2]};
}
