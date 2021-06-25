#ifndef MINIT_H
# define MINIT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include  <sys/types.h>
#include  <signal.h>

int    *chartobinary(char c);
void    addbit(char a);
void    addbi(int c);

typedef struct s_mint{
    int count;
    char c;
    int     tab[8];
}           t_minit;

t_minit g_gl;

#endif