CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

CHARACTERS = 'a' 'e' 'g' 'h' 'b' 'z' 'x' 'r' 'l' 'q'
EXEC = iterative recursive
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

DoIter:
	$(foreach var,$(CHARACTERS),./iterative $(var) ;)

DoRecu:
	$(foreach var,$(CHARACTERS),./recursive $(var) ;)

clean:
	$(RM) $(EXEC) *.o perf.*
