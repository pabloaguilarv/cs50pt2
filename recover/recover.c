#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Create contant for block size
const int BLOCK_SIZE = 512;

// init Byte type
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Warn about wrong input
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Create pointers
    char *input = argv[1];
    FILE *inptr = fopen(input, "r");

    // Warn about file not being found.
    if (inptr == NULL)
    {
        printf("Could not open %s. \n", input);
        return 2;
    }

    // Create counter for file name, buffer, image, and filename allocation.
    // Also, booleans when first image is found.
    int cnt = 0;
    BYTE buffer[BLOCK_SIZE];
    FILE *img = NULL;
    char *filename = malloc(8);
    int is_saving = 0;
    int start_saving = 0;

    // Start reading loop and keep as long as blocks are found
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {
        // Check for headers. Last part checks 4th position and normalizes last byte so we don't have to write 16 conditionals.
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Check wether we are currently saving and image.
            if (is_saving == 1)
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", cnt);
                cnt++;
                img = fopen(filename, "w");
            }
            else
            {
                // Start writing files
                sprintf(filename, "%03i.jpg", cnt);
                cnt++;
                img = fopen(filename, "w");
                start_saving = 1;
                is_saving = 1;
            }
        }

        // Write blocks onto image.
        if (start_saving == 1)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
        }
    }

    // Close files and free memory.
    fclose(img);
    fclose(inptr);
    free(filename);
}