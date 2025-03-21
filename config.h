#include "defs.h"

static const int max_username_length = 128;
static const int max_hostname_length = 128;
static const int max_uptime_length   = 40;

static struct art_entry arts[] = {
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
            "\033[35m /‾\\ \033[0m",
            "\033[35m( \033[37mo \033[35m\\\033[0m",
            "\033[35m/   /\033[0m",
            "\033[35m\\__/ \033[0m"
        }
    },
    {
        "arch",
        {
            "\033[34m   /\\   \033[0m",
            "\033[34m  /\\ \\  \033[0m",
            "\033[34m /    \\ \033[0m",
            "\033[34m/__/\\__\\\033[0m"
        }
    }
};
