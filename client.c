#include "minit.h"

int    *chartobinary(char c)
{
    int     *tab;
    int i = 7;

    tab = malloc(sizeof (int) * 8);
    while (i >= 0)
    {
        tab[7 - i] = (c & (1 << i)) >> i;
        i--;
    }
  // for (int i = 0; i < 8; i++)
  //     printf("%d|", tab[i]);
  // printf("\n");
    return(tab);
}

int main(int argc, char **argv)
{
    int *bit;
    char    c;
    int     i;
    int     j;
    pid_t   pid;

    i = 0;
    pid = atoi(argv[1]);
    while (argv[2][j] != '\0')
    {
         bit = chartobinary(argv[2][j]);
         i = 0;
    while (i < 8)
    {
        if (bit[i] == 0)
            kill(pid,SIGUSR1);
        else if (bit[i] == 1)
            kill(pid,SIGUSR2);
        sleep(1);
        i++;
    }
    j++;
    }
   

   // c = argv[1][0];
  //  bit = 0;
    
      
    return(0);

    
}