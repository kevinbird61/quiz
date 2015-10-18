CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative recursive
all: $(EXEC)

iterative: iterative.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

recursive: recursive.c
	$(CC) $(CFLAGS_common) -o $@ $@.c

DoItLoop:iterative
	 @num=1 ; while [ $$num -le 50 ] ; do \
        echo "Times of $$num" ; \
        ./iterative $$num; \
        num=`expr $$num + 1` ; \
    done
    
DoReLoop:recursive
	@num=1 ; while [ $$num -le 50 ] ; do \
        echo "Times of $$num" ; \
        ./recursive $$num; \
        num=`expr $$num + 1` ; \
    done

clean:
	$(RM) $(EXEC) *.o perf.*
