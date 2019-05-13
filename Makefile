##
## EPITECH PROJECT, 2018
## PSU_myftp_2017
## File description:
## makefile
##

CC      = 	gcc

RM      = 	rm -rf

NAME    = 	server

SRCS    =   	src/main.c \
		        src/init_prog.c \
		        src/accept_client.c \
		        src/loop_connection.c \
		        src/init_tab.c \
		        src/get_next_line.c \
		        src/command.c \
		        src/command2.c \
		        src/command3.c \
		        src/check_authentification.c \
		        src/recup_ip.c \
		        src/transfert.c

OBJS    = 	$(SRCS:.c=.o)

CFLAGS  =  	-W -Wall -Wextra -I include -g3

all:    	$(NAME)

$(NAME): 	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re:     	fclean all

.PHONY: 	all clean fclean re
