#include <stdio.h>
#include <stdlib.h>

void leak_example() {
    FILE *fp = fopen("test.txt", "r");
    if (fp == NULL) return;

    char buffer[100];
    fread(buffer, sizeof(char), 100, fp);

    
}

int main() {
    leak_example();
    return 0;
}
