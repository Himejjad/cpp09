# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 14:50:35 by himejjad          #+#    #+#              #
#    Updated: 2024/02/29 19:21:28 by himejjad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

SRC = main.cpp RPN.cpp

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