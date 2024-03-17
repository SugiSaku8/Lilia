#include "include/system_info.h"
#include <stdio.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>

void print_system_info() {
    struct utsname unameData;
    struct sysinfo sysInfo;

    if (uname(&unameData) != 0) {
        perror("uname");
        return;
    }

    printf("OS: %s %s %s\n", unameData.sysname, unameData.nodename, unameData.release);

    if (sysinfo(&sysInfo) != 0) {
        perror("sysinfo");
        return;
    }

    printf("Total RAM: %lu\n", sysInfo.totalram);
}
