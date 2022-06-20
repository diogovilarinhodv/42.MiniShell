#################################################################################################
# 										VARIABLES												#
#################################################################################################

#	MAKEFLAGS += --silent

#NAME
NAME						=	minishell

# Compiler
Compile						=	gcc -Wall -Wextra -Werror -fsanitize=address

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

SRC_FILES					=	$(wildcard *.c) $(wildcard srcs/*.c) $(wildcard srcs/*/*.c)

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
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/builtins
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/errors
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/libft
					$(CREATE_FOLDER) $(OBJ_FOLDER)/$(SRC_FOLDER)/utils
					$(CREATE_FOLDER) $(LIB_FOLDER)

# Build Project
$(NAME): 			${OBJ_FILES}
					${AR} ${LIB_FOLDER}/${LIB_FILE} ${OBJ_FILES}
					${Compile} ${LIB_FOLDER}/${LIB_FILE} $(O_FLAG) $(NAME) -lreadline

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