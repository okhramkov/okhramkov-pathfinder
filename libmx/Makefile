NAME = libmx.a

SRC_DIR = src

OBJ_DIR = obj

INC_DIR = inc

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:%.c=%.o)))

INC_FILES = $(wildcard $(INC_DIR)/*.h)

CC = clang

C_FLAGS = -std=c11 $(addprefix -W, all error extra pedantic) -g

AR = ar

AR_FLAGS = rcs

MKDIR = mkdir -p
RM = rm -rf

all: $(NAME)

print:
	@printf "$(OBJ_FILES)"
	@printf "\n\n"
	@printf "$(SRC_FILES)"

$(NAME): $(OBJ_FILES)
	@$(AR) $(AR_FLAGS) $@ $^
	@printf "\r\33[2K$@\t\033[35;1mcreated\033[0m\n"

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@$(CC) $(C_FLAGS) -c $< -o $@ -I $(INC_DIR)
	@printf "\r\33[2K$(NAME)\033[37;1m\t compile \033[0m$(<:$(SRC_DIR)/%.c = %)\r"

$(OBJ_DIR):
	@$(MKDIR) $@

clean:
	@$(RM) $(OBJ_DIR)
	@printf "$(OBJ_DIR) in $(NAME)\t \033[36;1mdeleted\033[0m\n"

uninstall:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@printf "$(NAME)\t \033[36;1muninstalled\033[0m\n"

reinstall: uninstall all

.PHONY: all uninstall clean reinstall
