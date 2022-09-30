##
## EPITECH PROJECT, 2022
## my_teams server
## File description:
## Makefile
##

SRC_PATH	=	src/
TEAMS_PATH	=	teams/
CMD_PATH	=	commands/
CMD_CREATE_PATH	=	create/
CMD_INFO_PATH	=	info/
CMD_LIST_PATH	=	list/
LIB_PATH	=	../../lib/
LINKED_LIST_PATH	=	linked_list/
EXTENSION_FILE	=	.c

COMMANDS_FILES	=	create    \
					help  \
					info  \
					list  \
					login \
					logout \
					messages  \
					send_msg  \
					subscribe \
					subscribed    \
					unsubscribe   \
					use   \
					user  \
					users \
					$(CMD_CREATE_PATH)channels  \
					$(CMD_CREATE_PATH)replies   \
					$(CMD_CREATE_PATH)teams \
					$(CMD_CREATE_PATH)threads   \
					$(CMD_LIST_PATH)channels  \
					$(CMD_LIST_PATH)replies   \
					$(CMD_LIST_PATH)teams \
					$(CMD_LIST_PATH)threads   \
					$(CMD_INFO_PATH)channel  \
					$(CMD_INFO_PATH)team   \
					$(CMD_INFO_PATH)thread \
					$(CMD_INFO_PATH)user   \



TEAMS_FILES	=

LIB_FILES	= 	linked_list/user/access_generic_list	\
				linked_list/user/del_generic_list	\
				linked_list/user/information_generic_list	\
				linked_list/user/add_generic_list	\
				my_getline	\
				to_array	\
				clean_str	\
				uuid		\
				my_strcat		\
				lib

COMMANDS	= $(addprefix $(TEAMS_PATH)$(CMD_PATH), $(COMMANDS_FILES))
TEAMS	= $(addprefix $(TEAMS_PATH), $(TEAMS_FILES))
LIB	= $(addprefix $(LIB_PATH), $(LIB_FILES))

SRC_FILES	=	usage	\
				server	\
				init	\
				exec_command	\
				is_logged	\
				$(LIB)	\
				$(COMMANDS)	\
				$(TEAMS)

SRC	= $(addprefix $(SRC_PATH), $(addsuffix $(EXTENSION_FILE), $(SRC_FILES)))

MAIN	=	main.c
OBJ	=	$(SRC:.c=.o) $(MAIN:.c=.o)
NAME	=	../myteams_server
TEST_NAME	=	unitest
VERSION	=	-std=gnu17
ERROR	=	-Wall -Wextra
DEBUG	=	-g3
CFLAGS	=	-I ./include -I ../common -I ../lib/include -I ../libs/myteams
LDFLAGS	+=	-L ../libs/myteams/ -lmyteams -luuid
UTFLAGS	=	--coverage -lcriterion
RM	=	rm -rf
CC	=	gcc

all:	$(NAME)
$(NAME):	$(OBJ)
	$(CC) $(VERSION) -o $(NAME) $(SRC) $(MAIN) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *.gc*

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

unitest	:
	$(CC) -o $(TEST_NAME) $(SRC_TEST) $(UTFLAGS) $(CFLAGS) $(ERROR)

tests_run: fclean unitest
		./unitest
	gcovr --exclude tests/ --branches
	gcovr --exclude tests/

.PHONY: re clean fclean all tests_run

re: fclean all
