#include  "c17_construct_1.hpp"

using std::string;

work beta;

class Vector 
{
    public:
        Vector(int s):elem{new double[s]},sz{s}{std::cout<<"Filling elem"<<std::endl;};
        ~Vector(){std::cout<<"Deleting elem"<<std::endl;delete[] elem;}
    private:
        double *elem;
        int sz;
};

struct S1 
{
    string s;
};

struct X { X(int){}};

struct S2 
{
    public:
        S2(int x_initializer):x(x_initializer){std::cout<<"Default constructor"<<std::endl;}
        X* getX(){return x1;}
    private:
    /* initialzation happens when S2 created, 
     * S2 creation needs to have required 
     * parameter for initializng X
     */
    X x;
    X *x1;
};

string indent(string arg)
{
    return arg;
}

Vector *f(int size)
{
    Vector v1(size);
    return new Vector(size+size);
}

void g(int size_s)
{
    Vector* p = f(size_s);

    delete p;
}

void draw(Shape* shape)
{
    shape->draw();
    delete shape;
}

int main() 
{

    string s1{"Brahma"};
    s1 = indent(s1);

    string s2 {"Vishnu"};
    s1 = s2;
    g(10);

    S1 x;
    S2 x1{1};

    //S2 x2;/* Does not compile. Requires initialization of S2.x*/
    S2 *x3 = new S2(12);
    if(x1.getX() == NULL)
        std::cout<<"Pointer initialized with NULL"<<std::endl;
    delete x3;    
    
    //NonLocal nonlocal_obj; /* Destructor is private*/
    NonLocal *non_local_obj = new NonLocal;
    //delete non_local_obj; /* Cannot invoke delete on class with private destructor*/
    non_local_obj->destroy();

    Circle *circ = new Circle;
    draw(circ);
    
    work k1{"Kuvempu", "Malenada chitragalu", 1953};
    work k2(k1);
    work default_work{};
    work alpha;    
    std::cout<<"default_work......"<<default_work.to_string()<<std::endl;
    std::cout<<"alpha_work........"<<alpha.to_string()<<std::endl;
    std::cout<<"beta_work........."<<beta.to_string()<<std::endl;

    if(alpha.buf == NULL)
        std::cout<<"Buffer initialized with NULL....."<<std::endl;
    if(beta.buf == NULL)
        std::cout<<"Beta buffer initialized with NULL"<<std::endl;

    std::cout<<alpha.buf<<beta.buf<<std::endl;
}
