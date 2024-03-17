#include "./include/memory_info.h"
#include <stdio.h>

void print_memory_info() {
    FILE *meminfo = fopen("/proc/meminfo", "r");
    if (meminfo == NULL) {
        perror("fopen");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), meminfo)) {
        printf("%s", line);
    }

    fclose(meminfo);
}
