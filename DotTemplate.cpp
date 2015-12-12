#include <bitset>
#include <cstddef>
#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;

template<class charT, size_t N> basic_string<charT> bitSetToString(const bitset<N> &bs) 
{
    return bs. template to_string<charT, char_traits<charT>, allocator<charT> >();
}


template<typename T> class MemberTemplate 
{
    public:
    template<class X> MemberTemplate(const X& val) 
    {
        X x = val;
        std::cout<< x <<std::endl;
    }
        
};

template<class T> class Outter 
{
    public:
    template<class R> class Inner 
    {
        public:
            void f();
    };
};

template<class T> template<class R> void Outter<T>::Inner<R>::f() 
{
    cout<<"Outter      == "<< typeid(T).name() <<endl;
    cout<<"Inner       == "<< typeid(R).name() <<endl;
    cout<<"Full Inner  == "<< typeid(*this).name() <<endl;
}

int main() 
{
    bitset<10> bs;
    bs.set(1);
    bs.set(5);
    cout << bs << endl;
    string s = bitSetToString<char>(bs);
    cout<< s <<endl;
    std::string name = "Shashi kumar";
    MemberTemplate<double> mTemp(name);
    Outter<string>::Inner<bool> inner;
    inner.f();
}