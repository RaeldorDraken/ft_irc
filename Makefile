# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 16:55:15 by rabril-h          #+#    #+#              #
#    Updated: 2023/12/09 17:05:10 by rabril-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ircserv

RM = rm -f
CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98 -g -fsanitize=address 


FILES = main 

src = $(addsuffix .cpp, $(FILES))

vpath %.cpp src src/commands

OBJ_DIR = bin
OBJ = $(addprefix $(OBJ_DIR)/, $(src:.cpp=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))

$(OBJ_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(@D)
	@${CC} $(CFLAGS) -MMD -c $< -o $@
	@echo "All files compiled"

all:
	@$(MAKE) $(NAME) --no-print-directory

$(NAME):: $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ) $(DEP) --no-print-directory
	@$(RM) -r $(OBJ_DIR) --no-print-directory
	@echo "Objects cleaned"

fclean: clean
	@$(RM) $(NAME) --no-print-directory
	@echo "All compilation files removed"