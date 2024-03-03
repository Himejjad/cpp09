// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.cpp                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/03/02 12:03:16 by himejjad          #+#    #+#             */
// /*   Updated: 2024/03/03 19:18:49 by himejjad         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "PmergeMe.hpp"

// int main(int argc, char const *argv[])
// {
//     try
//     {
//         std::vector<int > vec;
//         std::deque<int > deq;
//         PmergeMe object(argc, argv);
//         object.stock_vector(vec);
//         object.stock_deque(deq);
//         object.print(vec, "before vec: ");
//         object.print(deq, "before deq: ");
//         std::cout << "======================" << std::endl;
//         object.sort_vector(vec);
//         object.sort_deque(deq);
//         object.print(vec, "after  vec: ");
//         object.print(deq, "after  deq: ");
//         std::cout << "======================" << std::endl;
//         object.print_vector_time(vec);
//         object.print_deque_time(deq);
//     }
//     catch (const char *text)
//     {
//         std::cout << text << std::endl;    
//     }
//     return 0;
// }