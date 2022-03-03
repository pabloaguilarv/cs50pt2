#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const int BLOCK_SIZE = 512;

typedef uint8_t BYTE;

typedef struct
{
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    char *input = argv[1];
    FILE *inptr = fopen(input, "r");

    if (inptr == NULL)
    {
        printf("Could not open %s. \n", input);
        return 2;
    }

    int cnt = 0;
    BYTE buffer[BLOCK_SIZE];
    FILE *img = NULL;
    char *filename = malloc(8);
    int is_saving = 0;
    int start_saving = 0;

    while (fread(buffer, 1, BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            printf("Found %i images so far. \n", cnt);
            cnt++;
        }

    }
}