#include <stdio.h>
#include "util/wrappers/print.h"

int main() {
    debugln("Oh No, Something is Fishy");
    errorln("Oh NO, Something DIED");
    println("This is fine I guess");

    return 0;
}