/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:20:18 by himejjad          #+#    #+#             */
/*   Updated: 2024/03/01 12:04:03 by himejjad         ###   ########.fr       */
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

RPN::exce:: ~exce() _NOEXCEPT
{
	
}




RPN::RPN(/* args */)
{
}

RPN::~RPN()
{
}

RPN::RPN(const std::string& input) : text(input) {}

bool RPN::is_number(const std::string& str) 
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
        if (rnp.size() > 1 && !is_number(rnp))
            throw(exce("Error : bad input"));
        else if (is_number(rnp)) 
        {
            if (std::atoi(rnp.c_str()) > 10)
                throw(exce("Error : bad input"));
            std::cout << std::atoi(rnp.c_str()) << std::endl;
            stack_.push(std::atoi(rnp.c_str()));
        } 
        if (stack_.size() >= 2 && rnp.size() == 1) 
        {
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
                        throw(exce("Error : bad input"));
                    result = operand1 / operand2;
                    break;
                default:
                    throw(exce("Error : bad input"));
            }
            stack_.push(result);
        } 
        else
            throw(exce("Error : bad input"));
    }
    if (stack_.size() != 1)
        throw(exce("Error : bad input"));
    std::cout << stack_.top() << std::endl;
}