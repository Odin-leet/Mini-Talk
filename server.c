#include "minit.h"

void    binarrytochar(int *tab, int cpid)
{
    int     i;
    char    c;

    c = 0;
    i = 7;

    while (i >= 0)
    {
        c |= (tab[7 - i] << i);
        i--;
    }
    if (!c)
    {
        int ret = kill(cpid, SIGUSR1);
    }

    write(1,&c,1);
}

void    addbit(int a, int cpid)
{

    g_gl.tab[g_gl.count] = a;
    g_gl.count++;
      // printf("loool\n");

    if (g_gl.count == 8)
    {
            binarrytochar(g_gl.tab, cpid);
            //write(1,&g_gl.c,1);
            g_gl.count = 0;
            g_gl.c = 0;
    }
      

}

void    addbi(int c, siginfo_t *sa, void *data)
{
   if  (c == SIGUSR1)
    addbit(0, sa->si_pid);
    else
    addbit(1, sa->si_pid);
}
int     main()
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = addbi;

    g_gl.count = 0;
    g_gl.c = 0;
    pid_t pid;
    char *pidchar;

    pidchar = ft_itoa(pid);
    pid = getpid();
    printf("pid = %d \n",pid);
    sigaction(SIGUSR1,&sa, NULL);
    sigaction(SIGUSR2,&sa, NULL);
    while (1)
    {   
        pause();
    }
}