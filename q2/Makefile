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

DoItLoop:iterative
	@num=1 ; while [ $$num -le 1000 ] ; do \
        echo "Times of $$num" ; \
        ./iterative 'm' $$num; \
        num=`expr $$num + 1` ; \
    done	

DoReLoop:recursive
	@num=1 ; while [ $$num -le 1000 ] ; do \
        echo "Times of $$num" ; \
        ./recursive 'm' $$num; \
        num=`expr $$num + 1` ; \
    done

clean:
	$(RM) $(EXEC) *.o perf.*
