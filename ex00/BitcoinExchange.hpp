/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:29:42 by himejjad          #+#    #+#             */
/*   Updated: 2024/02/29 15:53:03 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include<cstring>
#include <iomanip>
#include <exception>
#include  <cstdlib>


class BitcoinExchange
{
private:
	std::string data;
	std::string inputFile;
public:
    std::map<std::string, float> map;
    BitcoinExchange();
    BitcoinExchange(const char *str);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
    void   check_year(size_t &i, size_t &end);
	void check_month(size_t &i, size_t &end);
	void check_forma(size_t &i, size_t &end);
	std::string	check_day(size_t &i, size_t &end);
	float check_value(size_t &i, size_t &end);
    void	  exchange();
	void   check_number(std::string &dst, size_t &i, size_t &end);
	float get_value(std::string &key);
   class exce : public std::exception
		{
			private:
				std::string message_;
			public:
				exce();
				exce(std::string message);
				const char *what() const _NOEXCEPT;
				~exce() _NOEXCEPT;
		};
};

