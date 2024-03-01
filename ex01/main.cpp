#include "RPN.hpp"


int main(int ac, char **av) 
{
    RPN rpn(av[1]);
    (void) ac;
    try 
    {
        rpn.calculator();
    } catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}