/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:20:18 by himejjad          #+#    #+#             */
/*   Updated: 2024/03/01 16:59:51 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include<cstring>
#include <iomanip>
#include <exception>
#include <cstdlib>

class RPN
{
private:
    std::stack<float> stack_;
    std::string text;
public:
    RPN(/* args */);
    void calculator();
    bool check_number(const std::string& str);
    RPN(const std::string& input);
    ~RPN();
    class exce : public std::exception
		{
			private:
				std::string message_;
			public:
				exce();
				exce(std::string message);
				const char *what() const  _GLIBCXX_NOTHROW;
				~exce()  _GLIBCXX_NOTHROW;
		};
};

