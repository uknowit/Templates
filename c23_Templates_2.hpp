#ifndef _C23_TEMPLATES_2_HPP
#define _C23_TEMPLATES_2_HPP

#include <iostream>
#include <string>
#include <cstdio>

template<typename T> class Matrix;
template<typename T> class Vector
{
    T v[4];
    public:
        //friend Vector operator* <>(const Matrix<T>&, const Vector&);
        template<typename T1> friend Vector<T1> operator* (const Matrix<T>&, const Vector&);
};
#endif
