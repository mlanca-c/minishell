# **************************************************************************** #
# Minishell
#
# version: 4
# Author: mlanca-c
# URL: https://github.com/mlanca-c/
# **************************************************************************** #

PROJECT	:= minishell

USER1	:= mlanca-c
USER2	:= josantos

USERS	:= ${USER1} ${josantos}

# **************************************************************************** #
# Project Variables
# **************************************************************************** #

NAME1	:= minishell

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

CFLAGS		:= -Wall -Wextra -Werror
RDFLAG		:= -lreadline
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
LIB_ROOT	:= libraries/
BIN_ROOT	:= ./
# TST_ROOT	:= testing/
# BON_ROOT	:= bonus/

# **************************************************************************** #
# Libraries
# **************************************************************************** #

LIB1	:= libft/
LIB_LIST	:= ${LIB1}

LIB_DIRS_LIST	:= $(addprefix ${LIB_ROOT}, ${LIB_LIST})

LIBS			:= $(addprefix ${LIB_ROOT}, ${LIB1}libft.a)

# **************************************************************************** #
# Content Folders
# **************************************************************************** #

DIRS			:= ./

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
INCS += -I${LIB_DIRS_LIST}/${INC_ROOT}

BINS := ${addprefix ${BIN_ROOT},${NAMES}}

# **************************************************************************** #
# VPATHS
# **************************************************************************** #

vpath %.o ${OBJ_ROOT}
vpath %.h ${INC_ROOT}
vpath %.c ${SRC_DIRS}
vpath %.a ${LIB_DIRS}

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

RM	:= rm -rf

# **************************************************************************** #
# Mandatory Targets
# **************************************************************************** #

${OBJ_DIRS}%.o: ${SRC_DIRS}%.c
	${CC} ${FLAGS} ${INCS} -c $< -o $@ ${BLOCK}

.PHONY: all
all: ${BINS}

${BIN_ROOT}${NAME1}: ${LIBS} ${OBJS}
	${AT} ${CC} ${FLAGS} ${RDFLAG} ${INCS} ${OBJS} ${LIBS} -o $@ ${BLOCK}
	${AT}printf "Object files created .................. ${_SUCCESS}\n" ${BLOCK}
	${AT}printf "Binary file compiled .................. ${_SUCCESS}\n" ${BLOCK}
	${AT}printf "Binary file ready ..................... ${_SUCCESS}\n" ${BLOCK}

# **************************************************************************** #
# Library Targets
# **************************************************************************** #

${LIBS}:
	${AT} ${MAKE} -C ${LIB_ROOT}${LIB1} ${BLOCK}

.PHONY: clean_libft
clean_libft:
	${AT} ${MAKE} clean -C ${LIB_ROOT}${LIB1} ${BLOCK}

.PHONY: fclean_libft
fclean_libft:
	${AT} ${MAKE} fclean -C ${LIB_ROOT}${LIB1} ${BLOCK}

.PHONY: re_libft
re_libft:
	${AT} ${MAKE} re -C ${LIB_ROOT}${LIB1} ${BLOCK}

# **************************************************************************** #
# Clean Targets
# **************************************************************************** #

.PHONY: clear
clear:
	${AT}clear ${BLOCK}

.PHONY: clean
clean: clean_libft
	${AT}${RM} ${OBJ_ROOT}
	${AT}mkdir -p ${OBJ_ROOT} ${BLOCK}
	${AT}printf "Object files cleaned .................. ${_SUCCESS}\n" ${BLOCK}

.PHONY: fclean
fclean: clean
	${AT}${RM} ${BINS}
	${AT}printf "Binary files removed .................. ${_SUCCESS}\n" ${BLOCK}

.PHONY: re
re: fclean all

.PHONY: re_libft
update: re_libft

.PHONY: clean_all
clean_all: fclean fclean_libft

# **************************************************************************** #
# Debug Targets
# **************************************************************************** #

debug_san: FLAGS += ${DFLAGS} ${FSANITIZE}
debug_san: all

debug: FLAGS += ${DFLAGS}
debug: all
	${AT} lldb ./${BIN_ROOT}${NAME1} ${BLOCK}

debug_re: fclean debug

# **************************************************************************** #
# Test Targets
# **************************************************************************** #

.PHONY: run
run: ${BINS}
	${AT} ./${BIN_ROOT}${NAME1} ${BLOCK}

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
	${AT}mkdir -p ${LIB_ROOT} ${BLOCK}
	${AT}git clone git@github.com:${USER1}/Generic-README.git ${BLOCK}
	${AT}mv Generic-README/README.md ./ ${BLOCK}
	${AT}rm -rf Generic-README ${BLOCK}
	${AT}${SED} 's/NAME/${PROJECT}/g' README.md ${BLOCK}
	${AT}git init ${BLOCK}
	${AT}echo "*.o\n*.d\n.vscode\na.out\n.DS_Store" > .gitignore ${BLOCK}
	${AT}git add README.md ${BLOCK}
	${AT}git add .gitignore ${BLOCK}
	${AT}git add Makefile ${BLOCK}
	${AT}git commit -m "first commit - via Makefile (automatic)" ${BLOCK}
	${AT}git branch -M main ${BLOCK}
	${AT}git remote add origin git@github.com:${USER1}/${PROJECT}.git ${BLOCK}
	${AT}git status ${BLOCK}
	${AT}printf "Poject folders created ................ ${_SUCCESS}\n" ${BLOCK}
	${AT}printf "Cloned Generic-README to project ...... ${_SUCCESS}\n" ${BLOCK}
	${AT}printf "README.md created ..................... ${_SUCCESS}\n" ${BLOCK}
	${AT}printf "Git Repository initialized ............ ${_SUCCESS}\n" ${BLOCK}
	${AT}printf "README.md added to repository ......... ${_SUCCESS}\n" ${BLOCK}
	${AT}printf ".gitignore added to repository......... ${_SUCCESS}\n" ${BLOCK}
	${AT}printf "Makefile added to repository .......... ${_SUCCESS}\n" ${BLOCK}
	${AT}printf "Setup ready ........................... ${_SUCCESS}\n" ${BLOCK}
	${AT}printf "[${YELLOW} push ${RESET}]: git push -u origin main\n" ${BLOCK}

# **************************************************************************** #
