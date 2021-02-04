# название
NAME		= pathfinder

# директория для src
SRC_DIR		= src/
# директория для inc
OBJ_DIR		= obj/
# директория для .h
INC_DIR		= inc/
# список подкаталогов в src 
DIRS		= $(notdir $(wildcard $(SRC_DIR)*))
# список только исходных C-файлов без расширений 
FILES		= $(foreach dir, $(DIRS), $(basename $(wildcard \
			  $(SRC_DIR)$(dir)/*.c)))
# добавление расширений в .c файлы
SRC			= $(FILES:%=%.c)
# добавление расширений в .o файлы
OBJ			= $(SRC:src/%.c=$(OBJ_DIR)%.o)
# список файлов headers
INC_H		= $(wildcard $(INC_DIR)*.h)


# основной каталог с любыми библиотеками
LIB_DIR		= .
# список всех имен библиотек в LIB_DIR
LIB_LIST	= libmx
# указать путь к библиотеке ../libs/<lib_name>/
LIB_DIRS	= $(foreach libdirs, $(LIB_LIST), $(LIB_DIR)/$(libdirs)/)
# создать путь к ../libs/<lib_name>/<lib_name>.a 
LIB_BIN		= $(join $(LIB_DIRS), $(addsuffix .a, $(LIB_LIST)))
# создать путь к ../libs/<lib_name>/inc
LIB_INC		= $(addsuffix $(INC_DIR), $(LIB_DIRS))


# компилятор
CC			= clang
# главные флаги
GFLAGS		= -std=c11 -pipe -Wall -Wextra -Werror -Wpedantic\
	-Wno-unused-command-line-argument -Wno-unused-variable \
	-Wno-unused-function -Wno-unused-parameter -g

# папка с headers файлами 
IFLAGS		= $(addprefix -I, $(LIB_INC) $(INC_DIR))

COMPILE		= $(CC) $(GFLAGS) $(IFLAGS) $(LIB_BIN)
MAKE_M		= make -sf Makefile -C
MKDIR		= mkdir -p
RM			= /bin/rm -rf

# проверка актуальности библиотек 
all: $(NAME)

$(NAME): $(LIB_LIST) $(OBJ_DIR) $(OBJ)
	@$(COMPILE) $(OBJ) -lmx -o $(NAME)
	@printf "\r\33[2K$@ \033[35;1mcreated\033[0m\n"

$(LIB_BIN): $(LIB_LIST)

# сделать для всех библиотек 
$(LIB_LIST): $(LIB_DIRS)
	@$(MAKE_M) $(LIB_DIR)/$@

# сделать каталоги для файлов obj 
$(OBJ_DIR):
	@$(MKDIR) $@ $(foreach dir, $(DIRS), $@/$(dir))

# объединение файлов obj 
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_H) $(LIB_BIN)
	@$(COMPILE) -o $@ -c $<
	@printf "\r\33[2K$(NAME) \033[37;1mcompile \033[0m$(<:$(SRC_DIR)/%.c=%)"

clean:
	@$(MAKE_M) $(LIB_DIR)/$(LIB_LIST) $@
	@$(RM) $(OBJ_DIR)
	@printf "obj in $(NAME)\t \033[36;1mdeleted\033[0m\n"

uninstall:
	@$(MAKE_M) $(LIB_DIR)/$(LIB_LIST) $@
	@$(RM) $(OBJ_DIR) $(NAME)
	@printf "$(NAME)\t \033[36;1muninstalled\033[0m\n"

reinstall: uninstall all

.PHONY: all clean uninstall reinstall $(LIB_LIST)
