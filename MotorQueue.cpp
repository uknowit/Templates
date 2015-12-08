#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string> 
#include <sstream>
#include "Stack.hpp"
#include "StackImpl.hpp"

bool check_motor_queue_can_be_formed(MyStack<int,1000> stack_ref)
{
    bool ret_value = true;
    return ret_value;
}

int main()
{
    int no_of_elements, min_element = 0;
    std::string input_string;
    int raw_input;
    std::cin>>no_of_elements>>std::ws;
    MyStack<int,1000> input_seq;
    MyStack<int,1000> side_street_seq;
    MyStack<int,1000> arranged_seq; 
    std::getline(std::cin,input_string);
    std::istringstream iss(input_string);
    std::string word;
    try 
    {
        while(iss >> word) 
        {
            input_seq.push(atoi(word.c_str()));
            if(min_element > atoi(word.c_str()) || min_element == 0)
                min_element = atoi(word.c_str());
        }

    }
    catch(StackException& stack_exp)
    {
        std::cout<<"Caught stack exception...."<<stack_exp.what()<<std::endl;
    }

    if(check_motor_queue_can_be_formed(input_seq))
        std::cout<<"yes"<<std::endl;
}
