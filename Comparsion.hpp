#ifndef _COMPARSION_HPP
#define _COMPARSION_HPP

#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>

class NoCase {
    public:
        bool operator()(const std::string&, const std::string&) const;
};

struct CString_less {
    bool operator()(const char* p, const char* q) const 
    {
        return strcmp(p,q) < 0;
    }

};

#endif
