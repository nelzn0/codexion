# codexion

## Status
Early work. The argument parser (src/parse.c) checks the 8 arguments: the count, that they are digits, the number limits, the zero rules, and the scheduler name. It fills the t_args struct and compiles on its own. It isn't tested yet, and main.c doesn't pass it a struct yet. The Makefile is empty, so nothing builds yet.