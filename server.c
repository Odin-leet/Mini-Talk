#include "minit.h"

void    binarrytochar(int *tab)
{
    
}

void    addbit(int a)
{

    g_gl.tab[g_gl.count] = a;
    g_gl.count++;
       printf("loool\n");

    if (g_gl.count == 8)
    {
            binarrytochar(g_gl.tab);
            //write(1,&g_gl.c,1);
            g_gl.count = 0;
            g_gl.c = 0;
    }
      

}

void    addbi(int c)
{
   if  (c == SIGUSR1)
    addbit(0);
    else
    addbit(1);
}
int     main()
{
    g_gl.count = 0;
    g_gl.c = 0;
    pid_t pid;
        pid = getpid();

    signal(SIGUSR1,addbi);
    signal(SIGUSR2,addbi);

    printf("%d\n",pid);
    
    while (1);
}