# **************************************************************************** #
# libft3.0
#
# version: 4
# Author: mlanca-c
# URL: https://github.com/mlanca-c/libft3.0
# **************************************************************************** #

PROJECT	:= libft3.0

USER1	:= mlanca-c
USER2	:= josantos

USERS	:= ${USER1}

# **************************************************************************** #
# Project Variables
# **************************************************************************** #

NAME1	:= libft.a

NAMES	:= ${NAME1}

# **************************************************************************** #
# Configs
# **************************************************************************** #

# Verbose levels
# 0: Make will be totaly silenced
# 1: Make will print echos and printf
# 2: Make will not be silenced but target commands will not be printed
# 3: Make will print each command
# 4: Make will print all debug info
#
# If no value is specified or an incorrect value is given make will print each
# command like if VERBOSE was set to 3.
#
# @author fletcher97

VERBOSE 	:= 1

# **************************************************************************** #
# Colors and Messages
# **************************************************************************** #

GREEN		:= \e[38;5;118m
YELLOW		:= \e[38;5;226m
RED			:= \e[38;5;9m
RESET		:= \e[0m

_SUCCESS	:= [${GREEN} ok ${RESET}]
_FAILURE	:= [${RED} ko ${RESET}]
_INFO		:= [${YELLOW} info ${RESET}]

# **************************************************************************** #
# Compiler and Flags
# **************************************************************************** #

CC			:= gcc
CLIB		:= ar -rc

CFLAGS		:= -Wall -Wextra -Werror
DFLAGS		:= -g
OFLAGS		:= -03
FSANITIZE	:= -fsanitize=address
PTHREADS	:= -pthread

FLAGS		:= ${CFLAGS}

# **************************************************************************** #
# Root Folders
# **************************************************************************** #

SRC_ROOT	:= sources/
OBJ_ROOT	:= objects/
INC_ROOT	:= includes/
BIN_ROOT	:= ./
# TST_ROOT	:= testing/
# BON_ROOT	:= bonus/

# **************************************************************************** #
# Libraries
# **************************************************************************** #

# **************************************************************************** #
# Content Folders
# **************************************************************************** #

DIRS	:= ./ ft_array/ ft_character/ ft_conversion/ ft_dlist/ ft_llist/ ft_math/
DIRS	+= ft_memory/ ft_print/ ft_stack/ ft_string/ get_next_line/

SRC_DIRS_LIST	:= $(addprefix ${SRC_ROOT},${DIRS})

SRC_DIRS		= $(subst :,${SPACE},${SRC_DIRS_LIST})
OBJ_DIRS		= $(subst ${SRC_ROOT},${OBJ_ROOT},${SRC_DIRS})

INC_DIRS		= ${INC_ROOT}

# **************************************************************************** #
# Files
# **************************************************************************** #

SRCS = $(foreach dir,${SRC_DIRS},$(wildcard ${dir}*.c))
OBJS = $(subst ${SRC_ROOT},${OBJ_ROOT},${SRCS:.c=.o})

INCS := ${addprefix -I,${INC_DIRS}}

BINS := ${addprefix ${BIN_ROOT},${NAMES}}

# **************************************************************************** #
# VPATHS
# **************************************************************************** #

vpath %.o ${OBJ_ROOT}
vpath %.h ${INC_ROOT}
vpath %.c ${SRC_DIRS}
vpath %.a ./

# **************************************************************************** #
# Conditions
# **************************************************************************** #

ifeq ($(shell uname), Linux)
	SED	:= sed -i.tmp --expression
else ifeq ($(shell uname), Darwin)
	SED	:= sed -i.tmp
endif

ifeq (${VERBOSE}, 0)
	MAKEFLAGS += --silent
	BLOCK := &/dev/null
else ifeq (${VERBOSE}, 1)
	MAKEFLAGS += --silent
	AT := @
else ifeq (${VERBOSE}, 2)
	AT := @
else ifeq (${VERBOSE}, 4)
	MAKEFLAGS += --debug=v
endif

# **************************************************************************** #
# Other Variables
# **************************************************************************** #

RM		:= rm -rf

# **************************************************************************** #
# Mandatory Targets
# **************************************************************************** #


.PHONY: all
all: ${BINS}

${BIN_ROOT}${NAME1}: ${OBJS}
	${AT} ${CLIB} $@ $^ ${BLOCK}

# **************************************************************************** #
# Library Targets
# **************************************************************************** #

# **************************************************************************** #
# Clean Targets
# **************************************************************************** #

.PHONY: clear
clear:
	${AT}clear ${BLOCK}

.PHONY: clean
clean: clear
	${AT}${RM} ${OBJ_ROOT}
	${AT}mkdir -p ${OBJ_ROOT} ${BLOCK}

.PHONY: fclean
fclean: clear clean
	${AT}${RM} ${BINS}

.PHONY: re
re: clear fclean all

# **************************************************************************** #
# Debug Targets
# **************************************************************************** #

debug_san: FLAGS += ${DFLAGS} ${FSANITIZE}
debug_san: clear all

debug: FLAGS += ${DFLAGS}
debug: clear all

debug_re: clear fclean debug

# **************************************************************************** #
# Test Targets
# **************************************************************************** #

# **************************************************************************** #
# Norminette Targets
# **************************************************************************** #

.PHONY: norm
norm: clear
	${AT}norminette ${SRCS} ${INC_ROOT} ${BLOCK}
	${AT}printf "Target working accordingly ............ ${_SUCCESS}\n" ${BLOCK}

.PHONY: norm_status
norm_status: clear
	${AT}printf "[${YELLOW} FILES No ${RESET}]:" ${BLOCK}
	${AT}norminette ${SRCS} ${INC_ROOT}|wc -l ${BLOCK}
	${AT}printf "${_SUCCESS}:" ${BLOCK}
	${AT}norminette ${SRCS} ${INC_ROOT}|grep -wc "OK" ${BLOCK}
	${AT}printf "Target working accordingly ............ ${_SUCCESS}\n" ${BLOCK}

# **************************************************************************** #
# Setup Targets
# **************************************************************************** #

.PHONY: .init
.init: clear
	${AT}mkdir -p ${SRC_ROOT} ${BLOCK}
	${AT}mkdir -p ${INC_ROOT} ${BLOCK}
	${AT}mkdir -p ${OBJ_ROOT} ${BLOCK}
	${AT}git init ${BLOCK}
	${AT}echo "*.o\n*.d\n.vscode\na.out\n.DS_Store" > .gitignore ${BLOCK}
	${AT}git add .gitignore ${BLOCK}
	${AT}git add Makefile ${BLOCK}
	${AT}git commit -m "first commit - via Makefile (automatic)" ${BLOCK}
	${AT}git branch -M main ${BLOCK}
	${AT}git remote add origin git@github.com:${USER1}/${PROJECT}.git ${BLOCK}
	${AT}git status ${BLOCK}
	${AT}printf "Poject folders created ................ ${_SUCCESS}\n" ${BLOCK}
	${AT}printf "Git Repository initialized ............ ${_SUCCESS}\n" ${BLOCK}
	${AT}printf ".gitignore added to repository......... ${_SUCCESS}\n" ${BLOCK}
	${AT}printf "Makefile added to repository .......... ${_SUCCESS}\n" ${BLOCK}
	${AT}printf "Setup ready ........................... ${_SUCCESS}\n" ${BLOCK}
	${AT}printf "[${YELLOW} push ${RESET}]: git push -u origin main\n" ${BLOCK}

# **************************************************************************** #
# Target Templates
# **************************************************************************** #

define make_obj
${1} : ${2}
	$${AT}mkdir -p $${@D} $${BLOCK}
	$${AT} $${CC} $${CFLAGS} $${INCS} -c $$< -o $$@ $${BLOCK}
endef

# **************************************************************************** #
# Target Generator
# **************************************************************************** #

$(foreach src,${SRCS},$(eval\
$(call make_obj,$(subst ${SRC_ROOT},${OBJ_ROOT},${src:.c=.o}),${src})))

