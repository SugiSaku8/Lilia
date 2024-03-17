// get.c
#include <stdio.h>
#include <string.h>
#include "./API/include/system_info.h"
#include "./API/include/cpu_info.h"
#include "./API/include/memory_info.h"
#include "./API/include/hardware_info.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "./API/CException/CException.h"

void encrypt_and_save(const char *data, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("fopen");
        return;
    }
    fwrite(data, sizeof(char), strlen(data), file);
    fclose(file);
    if (chown(filename, 0, 0) != 0) {
        perror("chown");
        return;
    }
    if (chmod(filename, S_IRUSR | S_IWUSR) != 0) {
        perror("chmod");
        return;
    }
}

int main() {
    Try{
    char info = "";
    print_system_info();
    print_cpu_info();
    print_memory_info();
    print_hardware_info();
    encrypt_and_save(info, "./info.txt");
    }Catch(e){
        printf("An error occurred during get system information:%d\n",e)
    }
    return 200;
}
