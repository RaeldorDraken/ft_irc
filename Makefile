# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabril-h <rabril-h@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 16:55:15 by rabril-h          #+#    #+#              #
#    Updated: 2024/01/24 20:06:01 by rabril-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ircserv

RM = rm -f
CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98 -g -fsanitize=address 


FILES = main classes/Server classes/network/server classes/execs/server \
classes/Client classes/Channel classes/ACommand classes/commands/Join \
classes/commands/Privmsg classes/commands/Pass classes/commands/Nick classes/commands/Cap\
classes/commands/Real classes/commands/Name classes/commands/Ping classes/commands/Pong \
classes/commands/Invite classes/commands/Kick classes/commands/Mode classes/commands/Names \
classes/commands/Topic classes/commands/Part classes/commands/User classes/commands/Who classes/Messages classes/utils/Utils


src = $(addsuffix .cpp, $(FILES))

vpath %.cpp src src/classes #src/commands

OBJ_DIR = bin
OBJ = $(addprefix $(OBJ_DIR)/, $(src:.cpp=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))

$(OBJ_DIR)/%.o: %.cpp 
	@mkdir -p $(@D)
	${CC} $(CFLAGS) -MMD -c $< -o $@


all:
	@$(MAKE) $(NAME) #--no-print-directory

$(NAME):: $(OBJ) Makefile
	@echo "Executable compiled!"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ) $(DEP) #--no-print-directory
	@$(RM) -r $(OBJ_DIR) #--no-print-directory
	@echo "Objects cleaned"

fclean: clean
	@$(RM) $(NAME) #--no-print-directory
	@echo "All compilation files removed"

re:	fclean all

.PHONY: all clean fclean re

-include $(DEP)
