#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "args.h"

int main(int argc, char** argv) {

    printf("Initial argc=%d\n", argc);

    ARGBEGIN

    LSARG_CASE('s', "string")
        printf("  str: %s\n", ARGS);

    LARG_CASE("decimal")
        printf("  int: %d\n", ARGI);

    ARG_CASE('f')
        printf("  float: %f\n", ARGF);

    WRONG_ARG
        fprintf(stderr, "%s: wrong argument: %s\n", argv0, argv[0]);
        exit(1);

    ARGEND;

    printf("Final argc=%d\nNew args :\n", argc);

    for(int i=0; i<argc; i++) {
        printf("  %d: %s\n", i, argv[i]);
    }

    return EXIT_SUCCESS;
}
