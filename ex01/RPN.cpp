/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:20:18 by himejjad          #+#    #+#             */
/*   Updated: 2024/03/01 17:25:06 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::exce::exce(std::string message) : message_(message)
{
}
RPN::exce::exce()
{
	
}

const char *RPN::exce::what() const throw()
{
	return (message_.c_str());
}

RPN::exce:: ~exce()  _GLIBCXX_NOTHROW
{
	
}




RPN::RPN(/* args */)
{
}

RPN::~RPN()
{
}

RPN::RPN(const std::string& input) : text(input) {}

bool RPN::check_number(const std::string& str) 
{
    for (size_t i = 0; i < str.length(); ++i) 
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

 void RPN::calculator() 
{
    std::stringstream str(text.c_str());
    std::string rnp;
    float result = 0;
    while (str >> rnp) 
    {
        if (rnp.size() > 1 && !check_number(rnp))
            throw(exce("5Error"));
        else if (check_number(rnp)) 
        {
            if (std::atoi(rnp.c_str()) > 10)
                throw(exce("4Error"));
            stack_.push(std::atoi(rnp.c_str()));
            // std::cout <<"here 1 : " <<stack_.top() << std::endl;
        } 
        else if (stack_.size() == 2) 
        {
            // for(size_t i = 0; i < stack_.size(); i++)
            //     std::cout <<"here 1 : " << stack_.top() - 1 << ":" << stack_.size() <<std::endl;
            float operand2 = stack_.top();
            stack_.pop();
            float operand1 = stack_.top();
            stack_.pop();
            switch (rnp[0]) 
            {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0)
                        throw(exce("ERROR"));
                    result = operand1 / operand2;
                    break;
                default:
                    throw(exce("Error"));
            }
            stack_.push(result);
        // std::cout <<"here 6 : " <<stack_.top() << std::endl;

        } 
        else
            throw(exce("1Error"));
    }
    // std::cout << stack_.size() <<std::endl; 
    if (stack_.size() != 1)
        throw(exce("3Error"));
    std::cout << stack_.top() << std::endl;
}