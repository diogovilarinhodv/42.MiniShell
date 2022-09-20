#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>    			// read, write & usleep
# include <stdlib.h>    			// malloc, free & exit
# include <stdio.h>					// printf
# include "structs.h"
# include "functions.h"
# include "ansi_colors.h"

# include <readline/readline.h>
# include <readline/history.h>

# include <dirent.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdbool.h>

// MACROS

# define SUCCESS        0
# define FAIL           1

# define NO				0
# define YES			1

# define CONTINUE		0
# define END			1

# define NOT_FOUND		-1

// FREEDOM STATUS
# define FREEDOM_ALL        0
# define FREEDOM_LST_CMD    1
# define FREEDOM_ENV        2
# define FREEDOM_LINE       3

#endif