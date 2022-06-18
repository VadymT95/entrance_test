#include "stcsearch.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    char* dirname = "/";

    if (argc < 1) return 0;
    find_file(argv[1], dirname);

    return 0;
}