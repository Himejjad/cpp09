/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:23:46 by himejjad          #+#    #+#             */
/*   Updated: 2024/03/03 22:29:30 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <sys/time.h>


class PmergeMe
{
    private:
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        std::vector<unsigned int> vec_a, vec_b;
        std::deque<unsigned int> deq_a, deq_b;
        std::deque<std::pair<unsigned int, unsigned int> > deq;

    public:
        PmergeMe();
        bool flag;
        unsigned int tmp;
        ~PmergeMe();
        void algo_vec(int ac, char *av[], std::vector<std::pair<unsigned int, unsigned int> > &vec);
        void algo_deq(int ac, char *av[], std::deque<std::pair<unsigned int, unsigned int> > vec);
        void checkInput(char *av1, char *av2);
        void mergeSort(std::deque<std::pair<unsigned int, unsigned int> >& arr, int l, int r);
        void merge(std::deque<std::pair<unsigned int, unsigned int> >& arr, int l, int m, int r);
        // bool str_isDigit(std::string str);
};


#endif

