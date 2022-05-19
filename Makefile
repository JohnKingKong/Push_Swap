# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 11:00:19 by jvigneau          #+#    #+#              #
#    Updated: 2022/05/18 17:43:35 by jvigneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
define JR

	BIG LEAK!!!! A PICTURE OF ME WORKING

                        .="=.
                      _/.-.-.\_     _
                     ( ( o o ) )    ))
                      |/  "  \|    //
      .-------.        \'---'/    //
     _|~~ ~~  |_       /`"""`\\  ((
   =(_|_______|_)=    / /_,_\ \\  \\
     |:::::::::|      \_\\_'__/ \  ))
     |:::::::[]|       /`  /`~\  |//
     |o=======.|      /   /    \ //
     `"""""""""`  ,--`,--'\/\   //
                  '-- "--'  '--'
endef
export JR

define TEA

		TEABAG THAT MOTHERF***ER

            .------.____
         .-'       \ ___)
      .-'         \\\\
   .-'        ___  \\)
.-'          /  (\  |)
         __  \  ( | |
        /  \  \__'| |
       /    \____).-'
     .'       /   |
    /     .  /    |
  .'     / \/     |
 /      /   \     |
       /    /    _|_
       \   /    /\ /\\
        \ /    /__v__\\
         '    |       |
              |     .#|
              |#.  .##|
              |#######|
              |#######|

endef
export TEA

SRCS	=	srcs/push_swap.c srcs/with_quotes.c srcs/with_quotes_2.c \
			srcs/without_q.c srcs/without_q_2.c srcs/push.c srcs/test.c \
			srcs/swap.c srcs/rotate.c srcs/rev_rot.c srcs/small_algo.c \
			srcs/init.c srcs/utils.c srcs/big_algo1.c srcs/big_algo2.c

HEADERS	=	push_swap.h

vpath %.h include/

OB		= @mkdir -p objs && mv ./srcs/*.o ./objs/ 

OBJS	=	${SRCS:.c=.o}

CC		=	@gcc

RM		=	@rm -rf

CFLAGS	=	-Wall -Wextra -Werror -o push_swap

LIBS	=	./libs/libft/libft.a

NAME	=	push_swap

FTMAKE	=	@cd ./libs/libft && make -s 

RUN		=	./push_swap

CLS		= 	clear

all		:	$(NAME)
			

$(NAME)	:	$(SRCS) $(OBJS) $(HEADERS)
			@if [ ! -d "./objs" ]; then \
				clear && \
				echo "__________________________________" && \
				echo "\n       Compiling.....\n" && \
				echo "__________________________________" && \
				touch a ;\
			fi 
			$(FTMAKE) 
			@ if [ ! -d "./objs" ]; then \
				echo "__________________________________" && \
				echo "\n      Libft compiled \n" && \
				echo "__________________________________"; \
			fi
			$(CC) $(SRCS) $(LIBS) $(CFLAGS)
			@if [ -p "./objs" ]; then \
				rm -rf ./objs; \
			fi
			$(OB)
			@if [ -f "./a" ]; then \
				sleep 1 && \
				echo "__________________________________" && \
				echo "\n Project succesfully compiled!\n" && \
				echo "__________________________________" && \
				rm -f ./a; else \
				clear && \
				echo "__________________________________" && \
				echo "\n              Done\n" && \
				echo "__________________________________"; \
			fi
			
clean	:	
			@clear
			@echo "__________________________________"
			@echo "\n     Clearing object files... \n"
			@echo "__________________________________"
			${RM} ./objs
			$(FTMAKE) $@
			@sleep 1
			@echo "__________________________________"
			@echo "\n     Cleaning Successful! \n"
			@echo "__________________________________"
			@sleep 1

fclean	:	clean
			@echo "__________________________________"
			@echo "\n     Clearing other files... \n"
			@echo "__________________________________"
			@if [ -f "./push_swap" ]; then \
				rm -rf ./push_swap; \
			fi
			@if [ -f "./checker" ]; then \
				cd ./bonus && make -s fclean; \
			fi
			$(FTMAKE) $@
			@sleep 1
			@echo "__________________________________"
			@echo "\n         Cleaning done!\n"
			@echo "__________________________________"
			@sleep 1
			
re		:	fclean all

run :		fclean all 
			@echo "Enter a variety of integers :"; \
			read ARGS; \
			$(RUN) $$ARGS
			
bonus :		fclean all
			@cd ./bonus && make -s fclean
			@cd ./bonus && make -s

bonus_run :	fclean small bonus

jr		: 
			clear
			@echo "$$JR"

tea	:
			clear
			@echo "$$TEA"

.PHONY	:	all clean fclean re bonus jr

.SILENT :   clean fclean

