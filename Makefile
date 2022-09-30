##
## EPITECH PROJECT, 2022
## myftp
## File description:
## Makefile
##

all:
	make -C server
	make -C client

clean:
	cd server && make clean && cd ..
	cd client && make clean && cd ..

fclean:
	cd server && make fclean && cd ..
	cd client && make fclean && cd ..

re: fclean all