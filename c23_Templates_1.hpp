#ifndef _C23_TEMPLATES_1_HPP
#define _C23_TEMPLATES_1_HPP

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>
/*
 I Trivial default constructor

    The default constructor for class T is trivial (i.e. performs no action) if all of the following is true:

    The constructor is not user-provided (i.e., is implicitly-defined or defaulted)
    T has no virtual member functions
    T has no virtual base classes 

    T has no non-static members with default initializers. 

    (since C++11)

    Every direct base of T has a trivial default constructor
    Every non-static member of class type has a trivial default constructor 
 
II Trivial destructor

 The destructor for class T is trivial if all of the following is true:

    The destructor is not user-provided (meaning, it is implicitly-defined or defaulted)
    The destructor is not virtual (that is, the base class destructor is not virtual)
    All direct base classes have trivial destructors
    All non-static data members of class type (or array of class type) have trivial destructors 

*/
template <class T> class String 
{
    public:
        String();
        ~String();
        String(const String&);
        String& operator=(const String&);
        explicit String(T*);
        T& operator[](int n){return ptr[n];}
        //String& operator+=(T t);

    private:
        static const int short_max = 15;
        int size;
        T* ptr;
};   

template<typename T> struct Link
{
    Link *pre;
    Link *suc;
    T     val;
};

template<typename T> class LinkedList 
{
        Link<T> *head;
    public:
        LinkedList(){head = NULL;}
        //LinkedList(const T& t):head{new Link<T>{0,o,t}}{}
        LinkedList(const T& t):head{new Link<T>{0,0,t}}{}
        void print_all() const;
};

class Rec {
public:
        constexpr int square(){return x*x;}
private:
        int x,y,z;
        const char* name;
        const char* address;
};

void template_function(const LinkedList<int>& li, const LinkedList<Rec>& lr)
{
    li.print_all();
    //lr.print_all(); 
    /*Rec does not have << operator defined. Instantiated only if printall is  used on Rec*/
}
template<typename T> void LinkedList<T>::print_all() const 
{
    for(Link<T> *p = head; p; p = p->suc)
        std::cout << p->val;
}

template<typename T> struct X 
{
    int m1 = 7;
    static const int ABC = 123;
    static constexpr int DEF= 456;
    T m2;
    const T m3;
    static constexpr T m4 = ABC + DEF ;// constexpr in template cannot be non-static
    X(const T& x):m2{x} { m3 = m2;}
};

template<typename T> class Container 
{
    public:
        using value_type = T;
};

template<typename T> struct S_Mem 
{
    static constexpr Rec r1{};
    static const int m1 = 7;
    //static int m2 = 8; Not static constant
    static int m3;
    static void f1(){}
    static void f2();
};

constexpr int isqrt_helper(int sq, int d, int a)
{
    return sq <= a ? isqrt_helper(sq+d,d+2,a):d;
}

constexpr int isqrt(int x)
{
    return isqrt_helper(1,3,x)/2-1;
}

template<typename T> int S_Mem<T>::m3 = 99;
template<typename T> void S_Mem<T>::f2() {/**/}

template<typename T> struct Enum_X {
    enum E1{a,b};
    //enum E2;
    enum class E3;
    enum E4:char;
    struct C1{};
    struct C2;

};

template<typename T> struct Enum_X<T>::C2 {};
template<typename T> enum class Enum_X<T>::E3 {c,d};

template<typename Scalar> class Complex {
        Scalar re, im;
    public:
        Complex():re(0), im(0) {};
        Scalar real(){return this->re;}
        Scalar imag(){return this->im;}
        template<typename T> Complex(T rr, T ii = 0):re(rr), im(ii){}
        Complex(const Complex&) = default;
        template<typename T> Complex(const Complex<T>& c):re{c.real()}, im{c.imag()}{}
};

template<typename T, typename Allocator> class LinkList;

template<typename T> class NodeLink {
    template<typename U, typename Allocator> friend class LinkList;
    T val;
    NodeLink *succ;
    NodeLink *prev;
};

template<typename T, typename Allocator> class LinkList {
    public:
        class Iterator {
            NodeLink<T> *current_position;
        };
        Iterator begin();
        Iterator end();
};

template<typename T> struct SimpleIterator
{
    NodeLink<T> *current_position;

};

template<typename T, typename Allocator> class SimpleLinkList {
    public:
        SimpleIterator<T> begin() { SimpleIterator<T> ret; return ret;}
        SimpleIterator<T> end() { SimpleIterator<T> ret; return ret;}
};

/*Iterator does not depend on Allocator*/
LinkList<int, std::allocator<int> > my_link_list;
LinkList<int, std::allocator<int> >::Iterator my_link_list_iter;

/* Iterator depends on two arguments*/
template<typename T> void func_iterator(SimpleIterator<T> a, SimpleIterator<T> b)
{
}

void user(SimpleLinkList<int, std::allocator<int> > li, SimpleLinkList<int, std::allocator<std::string> > ls)
{
    func_iterator(li.begin(), li.end());

}

#endif
