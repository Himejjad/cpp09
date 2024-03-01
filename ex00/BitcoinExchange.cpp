/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:13:27 by himejjad          #+#    #+#             */
/*   Updated: 2024/03/01 16:59:01 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const char *str)
{
	std::ifstream dataBase("data.csv");
	if(!dataBase.is_open())
	{
        throw exce("there is some error in data base file !");
	}
	std::ifstream file(str);
	if(!file.is_open())
	{
        throw exce("there is some error in input file !");
	}
	getline(file, inputFile, '\0');
	getline(dataBase, data, '\0');
	if(inputFile.empty() || data.empty())
        throw exce("empty file !");
	else if (inputFile.substr(0, inputFile.find('\n', 0)) != "date | value")
        throw exce("bad file !");
	else if (inputFile.find('\n', 0) >= inputFile.size() - 1)
        throw exce("no data !");
	for(size_t i = 19; data[i] ; i++)
	{
		std::stringstream ss(data.substr(i+11, data.find('\n', i) - (i + 11)));
		double value;
		ss >> value;
		// std::cout << std::setprecision(10) << value << std::endl;
		map[data.substr(i, 10)] = value;
			// std::map<std::string , double>::iterator it = map.begin();
			// for(;it != map.end(); it++)
			// std::cout << it->first << ":" << std::setprecision(7) << it->second << std::endl;  
		i = data.find('\n', i);
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
	{
		map.clear();
		std::map<std::string, float>::const_iterator it = obj.map.begin();
		for (;it != obj.map.end(); it++)
			map[it->first] = it->second;
		data = obj.data;
		inputFile = obj.inputFile;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::check_forma(size_t &i, size_t &end)
{
	if(inputFile[i+4] != '-' || inputFile[i+7] != '-'
	|| inputFile[i+10] != ' ' || inputFile[i+11] != '|'
	|| inputFile[i+12] != ' ' || inputFile[i+13] == ' '
	|| inputFile[i+13] == '\n' || inputFile[i+13] == '\t')
	{
		throw exce("Error: bad input => " + inputFile.substr(i, end - i));
	}
}

void BitcoinExchange::check_year(size_t &i, size_t &end)
{
	std::string dst;
	int         di(0);

	dst = inputFile.substr(i, 4);
	for (size_t j = 0; dst[j]; j++)
	{
		if(!isdigit(dst[j]))
			throw exce("Error: bad input => " + inputFile.substr(i, end - i));
	}
	di = std::atoi(dst.c_str());
	if(di > 2024 || di < 2009)
		throw exce ("Error: date is out of range in year !");
	
}

void BitcoinExchange::check_month(size_t &i, size_t &end)
{
	std::string dst;
	int         di(0);

	dst = inputFile.substr(i + 5, 2);
	for (size_t j = 0; dst[j]; j++)
	{
		if(!isdigit(dst[j]))
			throw exce("Error: bad input => " + inputFile.substr(i, end - i));
	}
	di = std::atoi(dst.c_str());
	if(di > 12 || di < 1)
		throw exce("Error: date is out of range in month !");
}

std::string BitcoinExchange::check_day(size_t &i, size_t &end)
{
	std::string dst;
	int         di;

	dst = inputFile.substr(i + 8, 2);
	for (size_t j = 0; dst[j]; j++)
	{
		if(!isdigit(dst[j]))
			throw exce("Error: bad input => " + inputFile.substr(i, end - i));
	}
	di = std::atoi(dst.c_str());
	if(di > 31 || di < 1)
		throw exce("Error: date is out of range in day !");
 
	return (inputFile.substr(i, 10));
}

void BitcoinExchange::check_number(std::string &dst, size_t &i, size_t &end)
{
	int dot = 0;
	if((!isdigit(dst[0]) && dst[0] != '-' && dst[0] != '+') || !isdigit(inputFile[end - 1]))
		throw exce("Error: bad input => " + inputFile.substr(i, end - i));
	if((dst[0] == '-' || dst[0] == '+') && (dst[1] == '.'))
		throw exce("Error: bad input => " + inputFile.substr(i, end - i));
	for (size_t j = 1; dst[j]; j++)
	{
		if(dst[j] == '.')
			dot++;
		if((!isdigit(dst[j]) && dst[j] != '.') || (dot > 1))   
			throw exce("Error: bad input => " + inputFile.substr(i, end - i));
	}
}

float BitcoinExchange::check_value(size_t &i, size_t &end)
{
	std::string	dst;
	float		di;

	dst = inputFile.substr(i + 13, end - (i + 13));
	check_number(dst, i, end);
	di = std::atof(dst.c_str());
	if(di > 1000)
		throw exce("Error: too large a number");
	if(di < 0)
		throw exce("Error: not a positive number.");
	return (di);
}

float BitcoinExchange::get_value(std::string &key)
{
	if(key < map.begin()->first || key > (--map.end())->first)
		throw exce("Error : date is out of range !");
	if (!map.count(key)) 
	{
		std::map<std::string , float>::iterator lower_date = map.lower_bound(key);
		lower_date--;
		return lower_date->second;
	} 
    return map.find(key)->second;
}

void BitcoinExchange::exchange(void)
{
	size_t end;
	for (size_t i = inputFile.find('\n') + 1; i < inputFile.size() ; ++i)
	{
		end = inputFile.find('\n', i);
		if(!end || end > inputFile.size())
			end = inputFile.size();
		try
		{
			check_forma(i, end);
			check_year(i, end);
			check_month(i, end);
			std::string date = check_day(i, end);
			float value = check_value(i, end);
			float amount = get_value(date) * value;
			std::cout << date << " => " << value << " = " << std::setprecision(7) << amount << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		i = end;
	}
}

BitcoinExchange::exce::exce(std::string message) : message_(message)
{
}
BitcoinExchange::exce::exce()
{
	
}

const char *BitcoinExchange::exce::what() const throw()
{
	return (message_.c_str());
}

BitcoinExchange::exce:: ~exce()  _GLIBCXX_NOTHROW
{
	
}