#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
    PmergeMe obj;
    obj.flag = false;
    if ((ac - 1) % 2 != 0)
    {
        obj.flag = true;
        obj.tmp = std::atoi(av[ac - 1]);
        if (std::atoi(av[ac - 1]) < 0)
            exit(1);
        ac-=1;
    }

    std::cout << "Before : "; 
    if (ac < 6)
    {
        for (int i = 1; i < ac; i++)
            std::cout << av[i] << " ";
    }
    else
    {
        for (size_t i = 1; i < 6; i++)
            std::cout << av[i] << " ";
        std::cout << "[...]";
    }


    //                          VECTOR

        std::vector<std::pair<unsigned int, unsigned int> > vec;
        for (int i = 1; i < ac; i+=2)
        {
            if (isdigit(*av[i]))
            {
                obj.checkInput(av[i], av[i + 1]);    
                vec.push_back(std::make_pair(std::atoi(av[i]), std::atoi(av[i + 1])));
            }
        }
        std::vector<unsigned int> vec_a, vec_b;
        obj.algo_vec(ac, av, vec);

    //                          DEQUE

        std::deque<std::pair<unsigned int, unsigned int> > deq;
        for (int i = 1; i < ac; i+=2)
        {
            if (isdigit(*av[i]))
            {
                obj.checkInput(av[i], av[i + 1]);    
                deq.push_back(std::make_pair(std::atoi(av[i]), std::atoi(av[i + 1])));
            }
        }
        std::deque<unsigned int> dec_a, dec_b;
        obj.algo_deq(ac, av, deq);
}