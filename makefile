lib: stcsearch.c stcsearch.h
	gcc -c -Wall -Werror -Wextra *stcsearch.c stcsearch.h
	ar -rc libstcsearch.a *.o
	ranlib libstcsearch.a
find: main.c
	gcc main.c -L . -l stcsearch -o find