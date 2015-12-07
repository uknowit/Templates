#include "Stack.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string> 
#include <sstream>
int main()
{
    int no_of_elements, min_element = 0;
    std::string input_string;
    int raw_input;
    std::cin>>no_of_elements>>std::ws;
    MyStack<int, 1000> input_seq;
    MyStack<int, 1000> side_street_seq;
    MyStack<int, 1000> arranged_seq; 
    std::getline(std::cin,input_string);
    std::istringstream iss(input_string);
    std::string word;
    while(iss >> word) 
    {
        input_seq.push(atoi(word.c_str()));
        if(min_element > atoi(word.c_str()) || min_element == 0)
            min_element = atoi(word.c_str());
    }

}

