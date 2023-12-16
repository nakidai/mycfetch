#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>

#ifdef _WIN32
#include <wdm.h>
#include <winsock.h>
#include <winbase.h>
#else
#include <sys/utsname.h>
#include <unistd.h>
#endif /* _WIN32 */

#include "config.h"
#include "defs.h"

void die(int code, char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(code);
}

void getuptime(char *buffer, int max_length)
{
    struct timespec uptime;
    clock_gettime(CLOCK_BOOTTIME, &uptime);
    int days    = uptime.tv_sec / 86400;
    int hours   = uptime.tv_sec / 3600 % 24;
    int minutes = uptime.tv_sec / 60 % 60;
    int seconds = uptime.tv_sec % 60;

    if (uptime.tv_sec < 60)
        snprintf(buffer, max_length, "Up %d seconds", seconds);
    else if (uptime.tv_sec < 3600)
        snprintf(buffer, max_length, "Up %d minutes", minutes);
    else if (uptime.tv_sec < 86400)
        snprintf(buffer, max_length, "Up %d hours, %d minutes", hours, minutes);
    else
        snprintf(buffer, max_length, "Up %d days, %d hours, %d minutes", days, hours, minutes);
}

int main(int argc, char **argv)
{
    char **art = NULL;
    if (argc > 2)
    {
        die(1, "usage: %s [artname]\n", argv[0]);
    }
    else if (argc == 2)
    {
        for (int i = 0; i < sizeof(arts)/sizeof(struct art_entry); ++i)
            if (!strcmp(arts[i].name, argv[1])) { art = arts[i].art; break; }
        if (!art) die(1, "Art %s not found\n", argv[1]);
    } else
    {
        art = arts[0].art;
    }

    char hostname[MAX_HOSTNAME_LENGTH];
    char username[MAX_USERNAME_LENGTH];
    char uptime[MAX_UPTIME_LENGTH];
#ifdef _WIN32
    RTL_OSVERSIONINFOW version_buffer = {.dwOSVersionInfoSize = sizeof(RTL_OSVERSIONINFOW)};
    RtlGetVersion(&version_buffer);
    GetUserNameA(username, MAX_USERNAME_LENGTH);
#else
    struct utsname uname_buf;

    getlogin_r(username, MAX_USERNAME_LENGTH);
    uname(&uname_buf);
#endif
    gethostname(hostname, MAX_HOSTNAME_LENGTH);
    getuptime(uptime, MAX_UPTIME_LENGTH);

    printf("%s %s@%s\n", art[0], username, hostname);
    printf("%s --\n",    art[1]);
#ifdef _WIN32
    printf("%s NT %u.%u %s\n", art[2], version_buffer.dwMajorVersion, version_buffer.dwMinorVersion, version_buffer.szCSDVersion);
#else
    printf("%s %s %s\n", art[2], uname_buf.sysname, uname_buf.release);
#endif
    printf("%s %s\n",    art[3], uptime);
    return 0;
}
