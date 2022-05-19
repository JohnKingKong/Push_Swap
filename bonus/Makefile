# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvigneau <jvigneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 11:00:19 by jvigneau          #+#    #+#              #
#    Updated: 2022/05/19 15:35:14 by jvigneau         ###   ########.fr        #
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

SRCS	=	srcs/main_bonus.c srcs/quotes_bonus.c srcs/quotes_2_bonus.c\
			srcs/no_quotes_bonus.c srcs/no_quotes_2_bonus.c \
			srcs/init_bonus.c srcs/utils_bonus.c \
			srcs/push_bonus.c srcs/swap_bonus.c srcs/rotate_bonus.c \
			srcs/utils_2_bonus.c srcs/rev_rot_bonus.c 

HEADERS	=	push_swap_bonus.h 

vpath %.h include

OB		= @mkdir -p objs && mv ./srcs/*.o ./objs/ 

OBJS	=	${SRCS:.c=.o}

CC		=	@ gcc

RM		=	@rm -rf 

CFLAGS	=	-Wall -Wextra -Werror -o checker 

LIBS	=	../libs/libft/libft.a

NAME	=	checker

FTMAKE	=	@cd ../libs/libft && make -s

RUN		=	./checker

CLS		= 	clear

all		:	$(NAME)
			

$(NAME)	:	$(SRCS) $(OBJS) $(HEADERS)
			$(FTMAKE) 
			$(CC) $(SRCS) $(LIBS) $(CFLAGS)
			@mv ./checker ../checker 
			@if [ -p "./objs" ]; then \
				rm -rf ./objs; \
			fi
			$(OB)
			@clear
			@echo "__________________________________"
			@echo "\n\nPush Swap and The checker Ready!\n"
			@echo "__________________________________"
clean	:	
			${RM} ./objs
			@if [ -f "../checker" ]; then \
				rm ../checker; \
			fi
			$(FTMAKE) $@

fclean	:	clean
			$(RM) $(NAME)
			$(FTMAKE) $@
			
re		:	fclean all

run :		fclean all 
			@echo "Enter a variety of integers :"; \
			read ARGS; \
			$(RUN) $$ARGS
			
jr		: 
			clear
			@echo "$$JR"

tea	:
			clear
			@echo "$$TEA"

.PHONY	:	all clean fclean re bonus jr

.SILENT :   clean fclean

