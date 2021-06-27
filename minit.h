#ifndef MINIT_H
# define MINIT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include  <sys/types.h>
#include  <signal.h>
#include <math.h>

int    *chartobinary(char c);
void    addbit(int a, int cpid);
void    addbi(int c, siginfo_t *sa, void *data);
char	*ft_itoa(int n);
typedef struct s_mint{
    int count;
    char c;
    int     countpid;
    int     getpid;
    int     reminder;
    char    tabpid[10];
    int     tab[8];
    
}           t_minit;

t_minit g_gl;

#endif