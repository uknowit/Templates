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

class D 
{
    public:
        D(int val):m_val{val}{}
        int get_val() {return m_val;}

    private:
        int m_val;
};

class HashFunction 
{
    public:
        HashFunction(std::string name){m_name = name;}
    private:
        std::string m_name;
};

int g_func(D d)
{

}

class Simplified_constr 
{
    public:
        Simplified_constr():a(7),b(5){}//,hash_function{"MD5"},state{"Constructor run"}{}
        Simplified_constr(int a_val):a{a_val},b{5}{}//,hash_function{"MD5"},state{"Constructor run"}{}
        Simplified_constr(D d):a{7},b{g_func(d)}{}//,hash_function{"MD5"},state{"Constructor run"}{}
    private:
        int a,b;
        HashFunction hash_function{"MD5"};
        std::string state{"Constructor run"};

};  

class Image 
{
    public:
        Image(){data = NULL;}
        ~Image()
        {
            if(NULL!=data)
            {
                std::cout<<"Calling destrutor for image"<<std::endl;
                free(data);
            }
        }
        Image(const Image& a);
        void write_block(void* copy,int buf_len);
    private:
        void *data;
        void *clone();
        bool shared;
};

#endif
