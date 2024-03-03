// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   deque_sort.cpp                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/03/03 13:24:51 by himejjad          #+#    #+#             */
// /*   Updated: 2024/03/03 19:32:31 by himejjad         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */


#include "PmergeMe.hpp"


void    PmergeMe::algo_vec(int ac, char *av[], std::vector<std::pair<unsigned int, unsigned int> > &vec)
{
    //              Time
    (void) av;
    // flag = false;
    struct timeval start, end;
    long sec, micro;

    gettimeofday(&start, NULL);
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (vec[i].first > vec[i].second)
            std::swap(vec[i].first, vec[i].second);
    }

    for (size_t i = 0; i < vec.size(); i++)
        vec_b.push_back(vec[i].first);

    for (size_t i = 0; i < vec.size(); i++)
        vec_a.push_back(vec[i].second);

    std::sort(vec_b.begin(), vec_b.end());

    for (size_t i = 0; i < vec_a.size(); i++)
        vec_b.insert(std::lower_bound(vec_b.begin(), vec_b.end(), vec_a[i]), vec_a[i]);
    if (flag)
        vec_b.insert(std::lower_bound(vec_b.begin(), vec_b.end(), tmp), tmp);

    std::cout << "\nAfter  : "; 

    for (size_t i = 0; i < vec_b.size(); i++)
        std::cout << vec_b[i] << " ";

    gettimeofday(&end, NULL);
    sec = end.tv_sec - start.tv_sec;
    micro = end.tv_usec - start.tv_usec;
    long diff = (sec / 1000000) + (micro);
    std::cout << "\nTime to process a range of " << ac << " elements with std::vector : " << diff  << " us" << "\n";
}

void    PmergeMe::checkInput(char *av1, char *av2)
{
    if (std::atoi(av1) < 0 || std::atoi(av2) < 0)
    {
        std::cerr << "Invalid Input: Number Less Than 0\n";
        exit(0);
    }
}
