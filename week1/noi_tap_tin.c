#include <stdio.h>
#include <stdlib.h>
//nối 2 vào 1

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    char *source_file = argv[1];
    char *destination_file = argv[2];

    FILE *source = fopen(source_file, "a");
    if (source == NULL) {
        printf("Error: Cannot open source file '%s'\n", source_file);
        return 2;
    }

    FILE *destination = fopen(destination_file, "r");
    if (destination == NULL) {
        printf("Error: Cannot create or open destination file '%s'\n", destination_file);
        fclose(source);
        return 3;
    }

    int ch;
    while ((ch = fgetc(destination)) != EOF) {
        fputc(ch, source);
    }
    
    fclose(source);
    fclose(destination);

    printf("File '%s' appened to '%s' successfully.\n",  destination_file,source_file);

    return 0;
}