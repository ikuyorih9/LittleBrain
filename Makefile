CC=gcc
CFLAGS=-I./includes -g3
BINDIR=bin

# Encontra todos os arquivos .c na pasta sources
SOURCES=$(wildcard sources/*.c)
# Substitui a extensão .c por .o e adiciona o prefixo bin/ para todos os arquivos encontrados
OBJECTS=$(patsubst sources/%.c,$(BINDIR)/%.o,$(SOURCES))

# Nome do executável
EXECUTABLE=$(BINDIR)/programa

all: $(BINDIR) $(EXECUTABLE) run

hugo: compile roda

roda:
	./bin/programa

compile:
	gcc -I./includes -o ./bin/programa ./sources/main.c ./sources/filtros.c ./sources/matrix.c

$(BINDIR):
	mkdir -p $(BINDIR)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

$(BINDIR)/%.o: sources/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./$(EXECUTABLE)

clean:
	rm -f $(BINDIR)/*.o $(EXECUTABLE)
	rm -d $(BINDIR)
