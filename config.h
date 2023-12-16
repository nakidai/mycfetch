#include "defs.h"

#define MAX_USERNAME_LENGTH 128
#define MAX_HOSTNAME_LENGTH 128
#define MAX_UPTIME_LENGTH   40

struct art_entry arts[] = {
    {
        "cat",
        {
            " ╱|、    ",
            "(˚ˎ。7   ",
            "| 、˜〵  ",
            "じしˍ,)ノ"
        }
    },
    {
        "freebsd",
        {
            "\033[31m_    _\033[0m",
            "\033[31m\\‾‾‾‾/\033[0m",
            "\033[31m|^vv^|\033[0m",
            "\033[31m\\____/\033[0m"
        }
    },
    {
        "gentoo",
        {
            " /‾\\ ",
            "( o \\",
            "/   /",
            "\\__/ "
        }
    },
    {
        "arch",
        {
            "   /\\    ",
            "  /\\ \\  ",
            " /    \\  ",
            "/__/\\__\\"
        }
    }
};
