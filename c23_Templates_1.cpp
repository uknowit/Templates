#include "c23_Templates_1.hpp"
#include <cstring>

template<class T> String<T>::String() 
{
    ptr = (T*)malloc(short_max * sizeof(T*));
    size = short_max;
}

template<class T> String<T>::String(T* arg_ptr)
{
    ptr = arg_ptr;
}

template<class T> String<T>::~String() 
{
    free(ptr);
}

template<class T> String<T>::String(const String& arg)
{
    this->ptr = (T*)malloc( arg.size * sizeof(T*));
    this->size = arg.size;
}

template<class T> String<T>& String<T>::operator=(const String& rhs)
{
    free(this->ptr);
    this->ptr = (T*)malloc(rhs.size * sizeof(T*));
    this->size = rhs.size;
}

int main()
{
    std::cout<<"Starting with Templates....."<<std::endl;
    String<char> char_string;
    char *name = (char*)malloc(15);
    strncpy(name, "Shashi", strlen("Shashi"));
    String<char> other_char_string(name);
    String<char> second_char_string(char_string);
    String<char> third_char_string;
    third_char_string = second_char_string;
    String<wchar_t> japanese;
    Container<int>::value_type happy = 23;
    Container<std::string>::value_type name_alias = "Templates Programming";
    constexpr int s1 = isqrt(9);
    constexpr int s2 = isqrt(981);

    std::cout<<s1<<"  "<<s2<<std::endl; 
    return 0;
}
