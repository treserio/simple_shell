.TH Conk_Shell 1 "28 Aug 2021" "Conk Shell"
.SH NAME
 Conk_Shell - a simple UNIX command line interpreter
.SH SYNOPSIS
.B Conk_shell.c
 \fb\ \fI[command]\fR [arguments ...]
.SH DESCRIPTION
 The (Conk_Shell) is a simple UNIX command line interpreter (Holberton School Project 0x17-Simple_Shell)
.SH Overview
Conk_Shell shell is a command-line interpreter that executes commands read from a terminal. Conk_Shell is a basic implementation that is similar to 
.B bash
or
.B cmd.
.SH Built-ins
Conk_shell has implemented the following built-ins:
.TP
.B -cd
changes current directory of the process. syntax:
.B cd [DIRECTORY]
.TP
.B -exit
the shell
.B exit and press ENTER.
.B
.TP
.B -env
Prints the current enviornment
.SH USAGE / COMPILATION
All files are to be compiled using "gcc"
.I string_of_pearls .c
- Contains the following built-ins for the shell:
.B  cd, exit, ls, ???
.I bsh.c
- Simple Shell
.I helper_functions.c
- Contains all helper functions for simple shell:
.B _strlen, _strncpy, _strcmp, _strcpy
.I path
- Finds the string in **env that contains the path
.I shell.h
- Contains prototypes for base functions, built-ins, and global variables
.SH Executable
a.out
.SH SEE ALSO
.SH (BUGS)
- None known at this time
Report bugs pertaining to the shell to https://github.com/treserio and https://github.com/niqualis
.SH AUTHOR
-TRES SERIO -NICK WALLACE