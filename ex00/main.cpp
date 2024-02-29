#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
     try
     {
          (void) ac;
          BitcoinExchange btc(av[1]);
          btc.parsInput();

     }
     catch(const std::string str)
     {
          std::cerr << str << '\n';
     }
}