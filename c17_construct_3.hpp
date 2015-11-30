#ifndef _C17_CONSTRUCT_3_HPP
#define _C17_CONSTRUCT_3_HPP

#include <iostream>
#include <string>
#include <initializer_list>
#include <tuple>
#include <cstring>
#include <valarray> 

using std::valarray;

class A 
{
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

template<class T> class Matrix 
{
    public:
        std::array<int, 2> dim;
        T* elem ;

        Matrix(T d1, T d2):dim{d1, d2},elem{ new T[d1*d2]}
        {
            std::cout<<"Calling Matrix constructor "<<std::endl;
        }
        ~Matrix(){delete[] elem;}
        int size() const {return dim[0]*dim[1];}

        Matrix(const Matrix& rhs)
        {
            this->elem = new T[sizeof(rhs.elem)]; 
            memcpy(this->elem, rhs.elem, sizeof(rhs.elem));
            std::cout<<"Calling Matrix copy con"<<std::endl;
        }
        Matrix& operator=(const Matrix& rhs)
        {
            delete[] elem;
            this->elem = new T[sizeof(rhs.elem)];
            memcpy(this->elem, rhs.elem, sizeof(rhs.elem));
            std::cout<<"Calling Matrix Assignment operator"<<std::endl;
        }

        Matrix(Matrix&& move_obj)
        {
            this->dim = move_obj.dim ;
            this->elem = move_obj.elem;
            move_obj.dim = {0, 0};
            move_obj.elem = nullptr;
            std::cout<<"Calling move constructor..."<<std::endl;
        }
        Matrix& operator=(Matrix &&){std::cout<<"Calling assignment operator...."<<std::endl;}
        
};

template<typename T> Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b)
{
    Matrix<T> res{a.dim[0], a.dim[1]};
    constexpr auto n = a.size();
    for (int i = 0; i!=n; ++i)
        res.elem[i] = a.elem[i]+b.elem[i];
    return res;
}

class gslice {
    valarray<size_t> size;
    valarray<size_t> stride;
    valarray<size_t> d1;

    public:
    gslice() = default;
    ~gslice() = default;
    gslice(const gslice& ) = default;
    gslice& operator=(const gslice&) = default;
    gslice(gslice&& temp) = default;
    gslice& operator=(gslice&& rhs) = default;
};

struct default_op {
    std::string m_str;
    int m_int;
    default_op(){std::cout<<"Default default_op constructor"<<std::endl;}
    ~default_op(){std::cout<<"Default default_op destructor"<<std::endl;}
    default_op(const default_op&){std::cout<<"Default default_op copy constructor"<<std::endl;}
    default_op(default_op&& ){std::cout<<"Default default_op move copy constructor"<<std::endl;}
    default_op& operator=(const default_op&){std::cout<<"Default default_op assignment operator"<<std::endl;}
    default_op& operator=(default_op&& ){std::cout<<"Default default_op move assignment operator"<<std::endl;}
};

#endif
