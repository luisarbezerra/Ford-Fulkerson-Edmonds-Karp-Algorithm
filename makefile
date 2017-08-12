CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -std=c99 -pedantic
DEPS = buscaLargura.h ff.h fila.h
OBJ = main.o buscaLargura.o ff.o fila.o
%.o: %.c $(DEPS)
				$(CC) -c -o $@ $< $(CFLAGS)

exec: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

	rm -rf *.o
