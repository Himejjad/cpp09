#include "RPN.hpp"


int main(int ac, char **av) 
{
    RPN rpn(av[1]);
    (void) ac; 
    // (void)av;
    try 
    {
        rpn.calculator();
    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
    // std::string str2 = "hamza  5 ha\nhi";
    // std::string str3 = "imjjad ha";
    // std::stringstream str(str2);
    // str >> str3;

    // std::cout << str3 << std::endl;
    // str >> str3;

    // std::cout << str3 << std::endl;

    //   str >> str3;

    // std::cout << str3 << std::endl;


}