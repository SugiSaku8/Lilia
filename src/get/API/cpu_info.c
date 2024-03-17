#include "cpu_info.h"
#include <stdio.h>

void print_cpu_info() {
    FILE *cpuinfo = fopen("/proc/cpuinfo", "r");
    if (cpuinfo == NULL) {
        perror("fopen");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), cpuinfo)) {
        printf("%s", line);
    }

    fclose(cpuinfo);
}
