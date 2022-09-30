##
## EPITECH PROJECT, 2022
## my_teams client
## File description:
## Makefile
##

SRC_PATH	=	src/
CMD_PATH	=	response/
LIB_PATH	=	../../lib/
EXTENSION_FILE	=	.c

RESPONSE_FILES	=	channel_print_threads	\
					error_already_exist	\
					error_unauthorized	\
					error_unknown_channel	\
					error_unknown_team	\
					error_unknown_thread	\
					error_unknown_user	\
					event_channel_created	\
					event_logged_in	\
					event_logged_out	\
					event_private_message_received	\
					event_team_created	\
					event_thread_created	\
					event_thread_reply_received	\
					print_channel	\
					print_channel_created	\
					print_reply_created	\
					print_subscribed	\
					print_team	\
					print_team_created	\
					print_teams	\
					print_thread	\
					print_thread_created	\
					print_unsubscribed	\
					print_user	\
					print_users	\
					print_help	\
					private_message_print_messages	\
					team_print_channels	\
					thread_print_replies	\
					other_error	\
					event_user_use	\
					do_nothing	\

RESPONSE	= $(addprefix $(CMD_PATH), $(RESPONSE_FILES))

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

LIB	= $(addprefix $(LIB_PATH), $(LIB_FILES))

SRC_FILES	=	usage	\
				client	\
				call_from_response	\
				init	\
				$(LIB)	\
				$(RESPONSE)

SRC	= $(addprefix $(SRC_PATH), $(addsuffix $(EXTENSION_FILE), $(SRC_FILES)))

MAIN	=	main.c
OBJ	=	$(SRC:.c=.o) $(MAIN:.c=.o)
NAME	=	../myteams_cli
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
