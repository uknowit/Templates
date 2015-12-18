#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string> 
#include <sstream>
#include "Stack.hpp"
#include "StackImpl.hpp"

bool check_motor_queue_can_be_formed(MyStack<int,1000> input_seq,int min_element)
{
    bool ret_value = true, stack_empty = false;
    MyStack<int,1000> side_street_seq;
    MyStack<int,1000> arranged_seq; 
    int current_input_element = 0;
    while(!stack_empty)
    {
        if(input_seq.get_stack_size() != 0)
        {
            current_input_element = input_seq.pop();
            if(arranged_seq.get_stack_size() == 0 )
            {
                if(current_input_element == min_element)
                {
                    arranged_seq.push(current_input_element);
                }
                else
                {
                    side_street_seq.push(current_input_element);
                    continue;
                }
            }
            else if (current_input_element > arranged_seq.top_of_stack())
            {
                if((side_street_seq.get_stack_size() != 0))
                {
                    if((current_input_element < side_street_seq.top_of_stack()))
                    {
                        side_street_seq.push(current_input_element);
                    }
                    else
                    {
                        arranged_seq.push(side_street_seq.pop());
                        input_seq.push(current_input_element);
                    }
                }
                else
                {
                    side_street_seq.push(current_input_element);
                }
            }
            else if(current_input_element < arranged_seq.top_of_stack())
            {
                ret_value = false;
                break;
            }
        }
        else if(side_street_seq.get_stack_size() != 0)
        {
            current_input_element = side_street_seq.pop();
            if(current_input_element < arranged_seq.top_of_stack())
            {
                ret_value = false;
                break;
            }
            else
            {
                arranged_seq.push(current_input_element);
            }
        }
        else
        {
            break;
        }
    }
    return ret_value;
}

int main()
{
    int  min_element = 0;
    std::string input_string;
    int raw_input;
    MyStack<int,1000> input_seq;
    MyStack<int,1000> r_input_seq;
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
    while(input_seq.get_stack_size() != 0)
    {
        r_input_seq.push(input_seq.pop());
    }
    if(check_motor_queue_can_be_formed(r_input_seq, min_element))
        std::cout<<"yes.."<<std::endl;
    else
        std::cout<<"no.."<<std::endl;
}