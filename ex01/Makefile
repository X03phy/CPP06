# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 16:11:52 by ebonutto          #+#    #+#              #
#    Updated: 2025/05/13 18:03:00 by ebonutto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serialization
CPPC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = obj/
SRC_DIR = src/
INC_DIR = include/

SRC = main.cpp \
	  Serialization.cpp
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p $(OBJ_DIR)
	$(CPPC) $(CPPFLAGS) -I $(INC_DIR) -o $@ -c $< 

$(NAME): $(OBJ)
	$(CPPC) $(CPPFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re