#ifndef _C23_TEMPLATES_2_HPP
#define _C23_TEMPLATES_2_HPP

#include <iostream>
#include <string>
#include <cstdio>

/*
 *  https://gcc.gnu.org/bugzilla/show_bug.cgi?id=17152
 *  To make something a friend which isn't known: for a friend declaration, if 
 *  name lookup doesn't find an existing name, and if it is a declaration 
 *  of either a function or a function template, then this injects the 
 *  name into the surrounding namespace. However, this doesn't apply for 
 *  a function template specialization, as in your case, if the actual 
 *  template declaration isn't available. Thus the compiler complains 
 *  that you are trying to declare something you can't declare (a non-function, 
 *  non-template). It should be obvious that the compiler can't do anything 
 *  about it unless you provide a declaration of the general template. 
 */
template<typename T> class Matrix;
template<typename T> class Vector;

template<typename T> Vector<T> operator*(const Matrix<T>& m, const Vector<T> &v)
{
    Vector<T> r;
    return r;
}

template<typename T> class Vector
{
    T v[4];
    public:
        friend Vector operator* <>(const Matrix<T>&, const Vector&);
};

template<typename T> class Matrix 
{
    Vector<T> v[4];
    public:
    friend Vector<T> operator* <>(const Matrix&, const Vector<T>&);
};

class C;
using C2 = C;

template<typename T> class  MyClass 
{
    friend C;
    //friend C2; compiles with warning 
    //friend C3;
    friend class C4;
};

template<typename T> class my_other_class 
{
    friend T;
    friend MyClass<T>;
    //friend class T; class is redundant
};


#endif
