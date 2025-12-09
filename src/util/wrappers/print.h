#ifndef PRINT_H
#define PRINT_H

#define CLR_RESET   "\x1b[0m"
#define CLR_RED     "\x1b[31m"
#define CLR_GREEN   "\x1b[32m"
#define CLR_YELLOW  "\x1b[33m"
#define CLR_BLUE    "\x1b[34m"
#define CLR_MAGENTA "\x1b[35m"
#define CLR_CYAN    "\x1b[36m"

void println(const char *fmt, ...);

void debugln(const char *fmt, ...);
void infoln(const char *fmt, ...);
void warnln(const char *fmt, ...);
void errorln(const char *fmt, ...);

void set_debug_enabled(int enabled);

#endif