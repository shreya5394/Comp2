#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int r = 20;
    int c = 30;

    int i,j;

	int* p = (int*)malloc(sizeof(int*)*20);
	
    for (i = 0; i <20; i++)
        for (j = 0; j < 30; j++)
        {
            int count = i;
            for (j = 0; j < c; j++)
            {
                p[i][j] = count++;
            }
            
        }
 
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < r; i++)
        free(p[i]);
 
	return 0;
}