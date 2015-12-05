#ifndef _C23_TEMPLATES_1_HPP
#define _C23_TEMPLATES_1_HPP

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>

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
    std::string name;
    std::string address;
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


#endif
