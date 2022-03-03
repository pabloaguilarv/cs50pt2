
#include <stdio.h>
#include <cs50.h>

// Create tower function for the main loop
void tower(h)
{
    for (int i = 1; i <= h; i++)
    {
        //This prints spaces before the block to get
        //a symmetric tower.
        //Starts s as 0 and goes to h-i.
        for (int s = 0; s < h - i; s++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    tower(h);
}