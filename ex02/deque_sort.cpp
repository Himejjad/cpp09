/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_sort.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:17:05 by himejjad          #+#    #+#             */
/*   Updated: 2024/03/03 22:31:47 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// void    PmergeMe::algo_deq(int ac, char *av[], std::deque<std::pair<unsigned int, unsigned int> > deq)
// {
//     (void) av;
//     struct timeval start, end;
//     long sec, micro;

//     gettimeofday(&start, NULL);
//     for (size_t i = 0; i < deq.size(); i++)
//     {
//         if (deq[i].first > deq[i].second)
//             std::swap(deq[i].first, deq[i].second);
//     }

//     for (size_t i = 0; i < deq.size(); i++)
//         deq_b.push_back(deq[i].first);

//     for (size_t i = 0; i < deq.size(); i++)
//         deq_a.push_back(deq[i].second);

//     std::sort(deq_b.begin(), deq_b.end());

//     for (size_t i = 0; i < deq_a.size(); i++)
//         deq_b.insert(std::lower_bound(deq_b.begin(), deq_b.end(), deq_a[i]), deq_a[i]);
//     if (flag)
//         deq_b.insert(std::lower_bound(deq_b.begin(), deq_b.end(), tmp), tmp);

//     std::cout << "\nAfter  : "; 

//     for (size_t i = 0; i < deq_b.size(); i++)
//         std::cout << deq_b[i] << " ";

//     gettimeofday(&end, NULL);
//     sec = end.tv_sec - start.tv_sec;
//     micro = end.tv_usec - start.tv_usec;
//     long diff = (sec / 1000000) + (micro);
//     std::cout << "\nTime to process a range of " << ac << " elements with std::deque : " << diff  << " us" << "\n";
// }




void  PmergeMe::algo_deq(int ac, char *av[], std::deque<std::pair<unsigned int, unsigned int> > deq) 
{
    (void) av;
    struct timeval start, end;
    long sec, micro;

    gettimeofday(&start, NULL);
        
    for (size_t i = 0; i < deq.size(); i++) {
        if (deq[i].first > deq[i].second)
            std::swap(deq[i].first, deq[i].second);
    }

    mergeSort(deq, 0, deq.size() - 1);

    std::cout << "\nAfter  : "; 
    for (size_t i = 0; i < deq.size(); i++)
        std::cout << deq[i].second << " ";
    gettimeofday(&end, NULL);
    sec = end.tv_sec - start.tv_sec;
    micro = end.tv_usec - start.tv_usec;
    long diff = sec * 1000000 + micro;
    std::cout << "\nTime to process a range of " << ac << " elements with std::deque : " << diff  << " us" << "\n";
}
    

void  PmergeMe::merge(std::deque<std::pair<unsigned int, unsigned int> >& arr, int l, int m, int r) 
{
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<std::pair<unsigned int, unsigned int> > L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) 
    {
        if (L[i].second <= R[j].second) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
        }
        while (i < n1) 
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) 
        {
            arr[k] = R[j];
            j++;
            k++;
        }
}

void  PmergeMe::mergeSort(std::deque<std::pair<unsigned int, unsigned int> >& arr, int l, int r) 
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
