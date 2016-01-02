#ifndef name_space_test_hpp
#define name_space_test_hpp

#include "stdio.h"
#include "algorithm"
namespace N {
    struct S { int i; };
    void f(S);
    void g(S);
    void h(int);
}

struct Base {
    void f(N::S);
};

struct D : Base {
    void mf(N::S);
    void g(N::S x) {
        f(x);
        mf(x);
        //h(1);
    };
};

namespace X {

    int i,j,k;
}
int k;

namespace Name_composition {
    using namespace N;
    using namespace X;
}

namespace Estd {
    using namespace std;
    template<typename C> void sort(C& c) 
    {
        std::sort(c.begin(), c.end());
    }

    template<typename C, typename P> void sort(C& c, P p)
    {
        std::sort(c.begin(), c.end(), p);
    }
};
#endif
