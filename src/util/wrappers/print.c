#include "print.h"
#include "../types.h"
#include <stdio.h>
#include <stdarg.h>

static switch_t debug_enabled = ON;

static void vprint_with_color(const char *color, const char *prefix, const char *fmt, va_list args, int prefix_only) {
    if (prefix_only) {
        if (color && prefix) printf("%s%s%s: ", color, prefix, CLR_RESET);
        else if (prefix) printf("%s: ", prefix);
    } else {
        if (color) printf("%s", color);
        if (prefix) printf("%s: ", prefix);
    }

    vprintf(fmt, args);

    if (!prefix_only) printf("%s", CLR_RESET);
    printf("\n");
}

void set_debug_enabled(switch_t enabled) {
    debug_enabled = enabled;
}

void println(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprint_with_color(NULL, NULL, fmt, args, 0);
    va_end(args);
}

void debugln(const char *fmt, ...) {
    if (!debug_enabled)
        return;

    va_list args;
    va_start(args, fmt);
    vprint_with_color(CLR_CYAN, "DEBUG", fmt, args, ON);
    va_end(args);
}

void infoln(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprint_with_color(CLR_GREEN, "INFO", fmt, args, ON);
    va_end(args);
}

void warnln(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprint_with_color(CLR_YELLOW, "WARN", fmt, args, ON);
    va_end(args);
}

void errorln(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprint_with_color(CLR_RED, "ERROR", fmt, args, ON);
    va_end(args);
}