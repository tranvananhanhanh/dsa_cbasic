#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    // Iterate through the command-line arguments in reverse order
    for (int i = argc - 1; i > 0; i--) {
        printf("%s ", argv[i]);
    }
    
    printf("\n");

    return 0;
}