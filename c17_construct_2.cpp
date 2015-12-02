#include "c17_construct_2.hpp"
#include <list>
#include <map>

using std::vector;
using std::map;
using std::list;
using std::cout;
using std::endl;
const int Curious::c1;
int main() 
{
    X x(12);
    Y de2();
    X *ptr{nullptr};
    X var{3};
    
    ptr = new X{4};
    X a[3] {0,1,2};
    cout<<a<<endl; 
    std::vector<X> v{1,2,3,4};
    std::vector<int> v1(12);/* Initializes vector with 12 elements as zero*/
    cout<<"Capacity v "<<v.capacity()<<" Capacity v1 "<<v1.capacity()<<endl;    
    
    std::vector<std::string> v_s1{77};
    std::vector<std::string> v_s2(77);
    std::vector<std::string> v_s3{"C++11 is crazy...."};
    std::vector<int*> v_si1{100,0};
   
    std::vector<std::vector<double>> d_vec = {
        {10,11,12,13,14,15,16},
        {10},
        //10,
        std::vector<double>{10,11,12,13},
        std::vector<double>{10},
        std::vector<double>(10),
    };

    cout<<"Capacity v_s1 "<<v_s1.capacity()<<" Capacity v_s2 "<<v_s2.capacity()
        <<" Capacity v_s3 "<<v_s3.capacity()<<endl;    

    S s1{"Bangalore"};
    S s2{new double(3.4)};
    S1 x11{1,2};
    S2 x12;
    S2 x22(1,2);
    
    S1 x21{1};/* b will be initialized with zero*/


    Handle<int> px;
    reference ref;
    
    vector<double> v_initializer = {1,2,3.456,99.99};
    list<std::pair<std::string,std::string>> languages = {{"Ritchie","C"},{"Straustrup","C++"},{"Alexandrscu","D"}};
    map<vector<std::string>,vector<int> > years = {
        {{"Ram","Kumar"},{1983,2005,2012}},
        {{"Shashi","kumar"},{1986,2007}},
        {{"Krishna","Kumar"},{1995,2016}}
    };

    initializer_list_test e_list{};
    initializer_list_test i_list{1};
    initializer_list_test int_list{1,23,33};
    
    vector<int> v_dc1(1);// one element with the default value (0)
    vector<int> v_dc1_2(1,2);// one element with the value 2

    vector<std::string> s_int2{"one","two"};
    vector<std::string> s_int3{"one","two","three"};

    f_initializer_list({1,2,3,4,5,6,7,8,9});
    f_mutable({1,2,3,4,5}, 6);
    
    vector<double> exp_v1(7);
    /* 
     * NO conversion from int to vector
     * vector<double> exp_v2 = 9;
     */

    vector<double> exp_v3{7};
    vector<double> exp_v4={9};
    g_exp();
    
    BB eod(12);
    

    const int *int_p = &Curious::c1;
    std::cout<<*int_p<<std::endl;
    delete ptr;
}
