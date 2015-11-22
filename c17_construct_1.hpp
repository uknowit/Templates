#ifndef _C17_CONSTRUCT_1_HPP
#define _C17_CONSTRUCT_1_HPP

#include <string>
#include <iostream>
#include <sstream>

class NonLocal {
    public:
        void destroy(){this->~NonLocal();}
    private:
        ~NonLocal(){}
};

class Shape {
    public:
        virtual void draw() { std::cout<<"Using default draw...."<<std::endl;}
        virtual ~Shape(){std::cout<<"Deleting shape object....."<<std::endl;}
};

class Circle:public Shape {
    public:
        void draw() {std::cout<<"Using real draw...."<<std::endl;}
        ~Circle(){std::cout<<"Deleting real shape circle.... "<<std::endl;}
};


struct work {
public:
    std::string author;
    std::string name;
    int year;
    std::string to_string()
    {
        std::stringstream stream;
        stream<<author;
        stream<<"  ";
        stream<<name;
        stream<<"  ";
        stream<<year;
        return stream.str();
    }
    char buf[16*1024];
};

#endif
