# codexion

## Status
Early work. The argument parser (src/parse.c) checks the 8 arguments: the count, that they are digits, and it prints errors to stderr. main.c calls it. The parser doesn't store the values in the struct yet, and the signature still needs to match the header. The Makefile is empty, so nothing builds yet.