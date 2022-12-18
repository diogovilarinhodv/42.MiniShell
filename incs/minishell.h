#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>    			// read, write & usleep
# include <stdlib.h>    			// malloc, free & exit
# include <stdio.h>					// printf

# include <readline/readline.h>
# include <readline/history.h>

//# include <dirent.h>
//# include <sys/types.h>
//# include <sys/wait.h>
//# include <sys/stat.h>
//# include <fcntl.h>
//# include <signal.h>
# include <stdbool.h>

//# include <termios.h>
//# include <curses.h>
# include <term.h>

//# include <string.h>
//# include <termcap.h>
//# include <errno.h>
//# include <sys/ioctl.h>

# include <string.h>
# include <fcntl.h>
# include <curses.h>
# include <termcap.h>
# include <errno.h>
# include <signal.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <termios.h>

# include "structs.h"
# include "functions.h"
# include "ansi_colors.h"

// MACROS
# define SUCCESS       		0
# define FAIL          		1

# define NO					0
# define YES				1

# define CONTINUE			0
# define END				1

# define NOT_FOUND			-1

# define LEFT_ARROW			1
# define RIGHT_ARROW		2
# define DOUBLE_RIGHT_ARROW	3

# define BUFFER_SIZE 		BUFSIZ

# ifdef unix
#  define IS_LINUX 1
#  define MAX_PATH 4096
# else
#  define IS_LINUX 0
#  define MAX_PATH 1024
# endif

# define CTRL_D 4
# define CTRL_C 3
# define ENTER_KEY 10
# define CTRL_B 28

# define EXIT_GENERAL_ERROR 2
# define EXIT_CMD_NOT_FOUND 127
# define EXIT_CMD_INTERRUPTED 130
# define EXIT_ERROR_FORMAT 258

#endif