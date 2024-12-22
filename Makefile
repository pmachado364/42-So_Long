# Color codes
RED    = \033[1;31m
ORANGE = \033[1;33m
RESET  = \033[0m
GREEN  = \033[1;32m
WHITE  = \033[1;37m

# SYMBOLS
SUCCESS = $(WHITE)[$(GREEN)✅$(WHITE)] $(GREEN)
ERROR = $(WHITE)[$(RED)❌$(WHITE)] $(RED)



#   $$$$$$\                  $$\                               
#  $$  __$$\                 $$ |                              
#  $$ /  \__| $$$$$$\        $$ | $$$$$$\  $$$$$$$\   $$$$$$\  
#  \$$$$$$\  $$  __$$\       $$ |$$  __$$\ $$  __$$\ $$  __$$\ 
#   \____$$\ $$ /  $$ |      $$ |$$ /  $$ |$$ |  $$ |$$ /  $$ |
#  $$\   $$ |$$ |  $$ |      $$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |
#  \$$$$$$  |\$$$$$$  |      $$ |\$$$$$$  |$$ |  $$ |\$$$$$$$ |
#   \______/  \______/$$$$$$\\__| \______/ \__|  \__| \____$$ |
#                     \______|                       $$\   $$ |
#                                                    \$$$$$$  |
#                                                     \______/ 


#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./lib/minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11
NAME = so_long
NAME_BONUS = so_long_bonus

INC = -I$(INC_DIR) -I$(LIB_DIR) -I.
RM	= rm -rf

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_DIR = src
SRC_BONUS_DIR = src_bonus
OBJ_DIR = obj
OBJ_BONUS_DIR = obj_bonus
INC_DIR = include
LIB_DIR = lib

SRC = $(wildcard $(SRC_DIR)/*.c)
SRC_BONUS = $(wildcard $(SRC_BONUS_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
OBJS_BONUS = $(patsubst $(SRC_BONUS_DIR)/%.c,$(OBJ_BONUS_DIR)/%.o,$(SRC_BONUS))
LIBFT_PATH = $(LIB_DIR)/Libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX_PATH = $(LIB_DIR)/minilibx-linux
MLX = $(MLX_PATH)/libmlx_Linux.a

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: dependencies $(NAME)
bonus: dependencies $(NAME_BONUS)

dependencies: 
	@$(MAKE) -C $(LIBFT_PATH) --no-print-directory --silent
	@$(MAKE) -C $(MLX_PATH) --no-print-directory --silent

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(OBJ_BONUS_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS) $(DEPS) $(LIBFT) $(MLX)
	@echo "Building $(NAME)..."
	@$(CC) $(CFLAGS) $(INC) -o $@ $(OBJS) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx $(MLXFLAGS)
	@echo "$(SUCCESS)$(NAME)$(GREEN) compiled successfully.$(RESET)"

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT) $(MLX)
	@echo "Building $(NAME_BONUS)..."
	@$(CC) $(CFLAGS) $(INC) -o $@ $(OBJS_BONUS) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx $(MLXFLAGS)
	@echo "$(SUCCESS)$(NAME)$(GREEN) compiled successfully.$(RESET)"

-include $(OBJS:.o=.d)

clean:
	@$(MAKE) clean -C $(LIBFT_PATH) --no-print-directory --silent
	@$(MAKE) clean -C $(MLX_PATH) --no-print-directory --silent
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS) $(OBJ_DIR) $(OBJ_BONUS_DIR) 
	@$(MAKE) fclean -C $(LIBFT_PATH) --no-print-directory --silent
	@$(MAKE) clean -C $(MLX_PATH) --no-print-directory --silent
	@$(RM) $(LIB_DIR)/minilibx-linux
	@echo "$(SUCCESS)$(RED)Executable and all objects deleted.$(RESET)"

re: fclean all

#==============================================================================#
#                                 MLX LIB                                      #
#==============================================================================#

download:
	@wget https://cdn.intra.42.fr/document/document/27195/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz -C lib
	@rm minilibx-linux.tgz