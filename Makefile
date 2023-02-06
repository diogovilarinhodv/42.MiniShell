#################################################################################################
# 										VARIABLES												#
#################################################################################################

#	MAKEFLAGS += --silent

#NAME
NAME						=	minishell

# Compiler
Compile						=	cc -Wall -Wextra -Werror -fsanitize=address 

# Flags for Compiler
O_FLAG 						=	-o
C_FLAG 						=	-c

# Command for Library
AR							=	ar rc

INC							=	-I includes

# Folder Management
RM							=	rm -rf
CREATE_FOLDER 				=	mkdir -p

# Norminette
NORM 						=	norminette

#################################################################################################
# 										FOLDERS													#
#################################################################################################

SRC_FOLDER					=	srcs
OBJ_FOLDER					=	objs
INC_FOLDER					=	incs
LIB_FOLDER					=	libs


#################################################################################################
# 										FILES													#
#################################################################################################

SRC_FILES					=	$(wildcard *.c) $(wildcard srcs/*.c) $(wildcard srcs/*/*.c) $(wildcard srcs/*/*/*.c)

OBJ_FILES					=	$(SRC_FILES:%.c=$(OBJ_FOLDER)/%.o) $(SRC_FILES:srcs/%.c=$(OBJ_FOLDER)/srcs/%.o)

INC_FILES					=	$(wildcard incs/*.h) 

LIB_FILE					=	$(NAME).a


#################################################################################################
# 										RULES													#
#################################################################################################

# Convert C Files to Object Files
$(OBJ_FOLDER)/%.o:%.c	folders
					${Compile} $(INC) $(O_FLAG) $@ $(C_FLAG) $<

# all
all:				$(NAME)					

folders:				
					$(CREATE_FOLDER) $(OBJ_FOLDER)
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/1.checks_env
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/1.checks_env/1.is_valid
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/2.initialize
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/2.initialize/1.initialize_env
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/2.initialize/2.initialize_termcaps
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/2.initialize/3.initialize_signals
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/3.read_line
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/3.read_line/1.is
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/3.read_line/2.execute
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/3.read_line/3.history
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/3.read_line/4.input
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/4.check_line
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/5.input_handler
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/6.token_creation
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/7.set_tokens
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/8.execute
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/9.replace_tokens
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/10.replace_env_vars
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/11.builtins
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/11.builtins/1.builtin_cd
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/11.builtins/2.builtin_echo
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/11.builtins/3.builtin_export
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/12.file_descriptors
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/13.path_handler
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/14.env_handler
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/15.utils
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/16.libft
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/17.errors
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/18.free
					$(CREATE_FOLDER) $(LIB_FOLDER)

# Build Project
$(NAME): 			${OBJ_FILES}
					${AR} ${LIB_FOLDER}/${LIB_FILE} ${OBJ_FILES}
					${Compile} ${LIB_FOLDER}/${LIB_FILE} $(O_FLAG) $(NAME) -lreadline -lncurses -ltermcap

# Norminette
norm:
					$(NORM) $(INC_FILES) $(SRC_FILES)

# Clean Project
clean:
					${RM} ${OBJ_FOLDER}
					${RM} $(NAME)

fclean:				clean
					${RM} $(LIB_FOLDER)

# Clean and Build Project
re:					fclean all

# Phony (I dont remember what this do, i think is to reserve the name or something like that)
.PHONY:				all norm clean fclean re