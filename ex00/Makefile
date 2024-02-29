# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 14:50:35 by himejjad          #+#    #+#              #
#    Updated: 2024/02/26 17:36:41 by himejjad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

SRC = main.cpp BitcoinExchange.cpp

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