/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:13:12 by himejjad          #+#    #+#             */
/*   Updated: 2024/02/29 16:13:16 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
     if (ac == 2)
     {
          try
          {
               (void) ac;
               BitcoinExchange btc(av[1]);
               btc.exchange();
          }
          catch(std::exception &e)
          {
               std::cerr << e.what() << '\n';
          }
     }
     else
     std::cerr << "Usage : ./btc input.txt" <<std::endl;
}