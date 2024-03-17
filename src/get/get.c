// get.c
#include <stdio.h>
#include <string.h>
#include "system_info.h"
#include "cpu_info.h"
#include "memory_info.h"
#include "hardware_info.h"

void encrypt_and_save(const char *data, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("fopen");
        return;
    }

    char encrypted[256];
    for (int i = 0; i < strlen(data); i++) {
        encrypted[i] = data[i] ^ 0xFF; // XOR暗号化
    }
    encrypted[strlen(data)] = '\0';

    fwrite(encrypted, sizeof(char), strlen(encrypted), file);
    fclose(file);
}

int main() {
    char info[1024] = "";
    print_system_info();
    print_cpu_info();
    print_memory_info();
    print_hardware_info();
    encrypt_and_save(info, "info.txt");
    return 0;
}
