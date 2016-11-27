// Simple short/long args parsing library
char* argv0;

#define ARGBEGIN for(argv0=argv[0],argv++,argc--;                       \
                     argv[0] && argv[0][0] == '-' && argv[0][1];        \
                     argc--, argv++) {                                  \
    if(argv[0][1] == '-' && !argv[0][2]) { argc--, argv++; break; }     \
        switch(argv[0][1]) {                                            \
        default:                                                        \
        if(0) {

// Arg values
#define ARGS (argc == 1 ? (fprintf(stderr,"%s: argument expected after %s\n", argv0, argv[0]),exit(-1),"") : (argc--, argv++, argv[0]))
#define ARGI (argc == 1 ? (fprintf(stderr,"%s: argument expected after %s\n", argv0, argv[0]),exit(-1),0) : (argc--, argv++, atoll(argv[0])))
#define ARGF (argc == 1 ? (fprintf(stderr,"%s: argument expected after %s\n", argv0, argv[0]),exit(-1),0.0) : (argc--, argv++, atof(argv[0])))

// Short arg only
#define ARG_CASE(chr) } else if(0) { case chr:
// Long arg only
#define LARG_CASE(str) } else if(strcmp((argv[0] + 2), str) == 0) {
// Equivalent short/long args
#define LSARG_CASE(chr, str) } else if(strcmp(argv[0] + 2, str) == 0) { case chr:

// Facultative WRONG_ARG handling, default is to ignore the arg
#define WRONG_ARG } else {

#define ARGEND }}}
