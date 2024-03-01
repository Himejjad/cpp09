# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 14:50:35 by himejjad          #+#    #+#              #
#    Updated: 2024/03/01 17:40:56 by himejjad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SRC = main.cpp PmergeMe.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98 

all :  ${NAME}


${NAME} : ${SRC}
	@c++  ${FLAGS} ${SRC}  -o ${NAME}
	@echo "all's ready"
clean :
	@rm -f ${NAME}
	@echo "all's clean"
fclean :clean 

re :fclean all