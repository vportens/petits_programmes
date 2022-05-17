# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2022/04/10 22:31:39 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(shell uname), Linux)
	YASL =	./ressources/yasl_linux
else
	YASL =	./ressources/yasl_macos
endif

RM = 	rm -rf

# **************************************************************************** #
#	MAKEFILE	#

#MAKEFLAGS += --silent

SHELL := bash

B =		$(shell tput bold)
BLA =	$(shell tput setaf 0)
RED =	$(shell tput setaf 1)
GRE =	$(shell tput setaf 2)
YEL =	$(shell tput setaf 3)
BLU =	$(shell tput setaf 4)
MAG =	$(shell tput setaf 5)
CYA =	$(shell tput setaf 6)
WHI =	$(shell tput setaf 7)
D =		$(shell tput sgr0)
BEL =	$(shell tput bel)
CLR =	$(shell tput el 1)

# **************************************************************************** #
#	SRCS	#

SRC =	./src/
EX00 =	ex00/yasl_hw
EX01 =	ex01/yasl_aff_param
EX02 =	ex02/yasl_do
EX03 =	ex03/yasl_repeat
EX04 =	ex04/yasl_fact
EX05 =	ex05/yasl_split
EX06 =	ex06/yasl_interactive
DISP =	display/display_b64

# *************************************************************************** #

define	test
	@$(YASL) $(SRC)$(1) > you
	@printf $(2) > expected
	@if [[ ! -z $$(diff you expected) ]]; then \
		printf "$(D)$(B)$(MAG)$(1)$(D)\n" ; \
		printf "\t$(D)$(B)$(GRE)expected:$(D)\n$(GRE)"; \
		cat expected; \
		printf "$(D)\t$(B)$(RED)you:$(D)\n$(RED)"; \
		cat you; \
		printf "$(D)\n" ; \
		exit 1; \
	fi;
endef

# *************************************************************************** #
#	RULES	#

all:	test

man:
	less ./ressources/yasl.0

test:	ex00 ex01 ex02 ex03 ex04 ex05 fclean #ex06
	@printf "$(D)$(B)$(GRE)done$(D)\n"

ex00:
	$(call test,$(EX00),"Hello world\n")
	$(call test,$(EX00) hello,"Hello world\n")

ex01:
	$(call test,$(EX01),"")
	$(call test,$(EX01) Hello World 42 "Be Cool","Hello\nWorld\n42\nBe Cool\n")
	$(call test,$(EX01) "\n","\\\n\n")
	$(call test,$(EX01) "","\n")

ex02:
	$(call test,$(EX02),"")
	$(call test,$(EX02) 1,"")
	$(call test,$(EX02) 1 +,"")
	$(call test,$(EX02) 1 + 1 no,"")
	$(call test,$(EX02) 42 no 42,"no isn't supported\n")
	@$(YASL) $(SRC)$(EX02) 21 - 42 > you
	@echo "-21" > expected
	@diff you expected
	$(call test,$(EX02) 3 "+" 20,"23\n")
	$(call test,$(EX02) 3 "*" 5,"15\n")
	$(call test,$(EX02) 9 / 3,"3\n")
	$(call test,$(EX02) 42 % 10,"2\n")
	$(call test,$(EX02) 42 ">" 21,"1\n")
	$(call test,$(EX02) 42 "<" 21,"0\n")
	$(call test,$(EX02) 42 ">=" 42,"1\n")
	$(call test,$(EX02) 42 "<=" 21,"0\n")
	$(call test,$(EX02) 42 == 21,"0\n")
	$(call test,$(EX02) 42 == 42,"1\n")
	$(call test,$(EX02) 42 != 21,"1\n")
	$(call test,$(EX02) 42 != 42,"0\n")
	$(call test,$(EX02) yes + 42,"use int\n")
	$(call test,$(EX02) 2n + 5,"7\n")
	$(call test,$(EX02) "","")
	$(call test,$(EX02) "" "","")
	$(call test,$(EX02) "" "" "","use int\n")

ex03:
	$(call test,$(EX03),"")
	$(call test,$(EX03) 1,"")
	$(call test,$(EX03) 0 yes,"use int > 0\n")
	$(call test,$(EX03) 1 yes,"yes\n")
	$(call test,$(EX03) 2 yes,"yesyes\n")
	$(call test,$(EX03) 2 yes no,"yesyes\nnonono\n")
	$(call test,$(EX03) 4 Bonjour "how are you?","BonjourBonjourBonjourBonjour\nhow are you?how are you?how are you?how are you?how are you?\n")
	$(call test,$(EX03) 1 "************" "******" "****" "---","************\n************\n************\n------------\n")
	$(call test,$(EX03) no yes no,"use int\n")
	$(call test,$(EX03) 2y yes no,"yesyes\nnonono\n")
	$(call test,$(EX03) "","")
	$(call test,$(EX03) "" "","use int > 0\n")

ex04:
	$(call test,$(EX04),"")
	$(call test,$(EX04) 1 1,"")
	$(call test,$(EX04) 0,"1\n")
	$(call test,$(EX04) 1,"1\n")
	$(call test,$(EX04) 2,"2\n")
	$(call test,$(EX04) 3,"6\n")
	$(call test,$(EX04) 4,"24\n")
	$(call test,$(EX04) 10,"3628800\n")
	$(call test,$(EX04) 100,"overflow\n")
	$(call test,$(EX04) 010,"40320\n")
	$(call test,$(EX04) "","use int > 0\n")

ex05:
	$(call test,$(EX05),"")
	$(call test,$(EX05) 1,"")
	$(call test,$(EX05) hey no,"only 1 char alowed to split\n")
	$(call test,$(EX05) e llezz,"ll\nzz\n")
	$(call test,$(EX05) e eeelleeezzeee,"ll\nzz\n")
	$(call test,$(EX05) e eee,"")
	$(call test,$(EX05) a ljksdpoiapoipoialljlaiuoiu,"ljksdpoi\npoipoi\nlljl\niuoiu\n")
	@$(YASL) $(SRC)$(EX05) " " " Lorem ipsum dolor sit amet, consectetur adipiscing elit. " > you
	@printf "Lorem\nipsum\ndolor\nsit\namet,\nconsectetur\nadipiscing\nelit.\n" > expected
	@diff you expected
	$(call test,$(EX05) "","")
	$(call test,$(EX05) "" "","only 1 char alowed to split\n")
	$(call test,$(EX05) "e" "","no empty string\n")

#ex06:
#	$(call test,$(EX06),"")
#	1 1 %^D

fclean:
	@$(RM) you
	@$(RM) expected

re:		fclean all

.PHONY: all man test fclean re ex00 ex01 ex02 ex03 ex04 ex05 ex06 display

# **************************************************************************** #
