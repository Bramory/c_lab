# learn effective address leaq
# rdi 
# -save-temps nstructs the compiler to generate intermediate assembly files 
# -fverbose-asm Produces an assembly listing with compiler comments + etc
# -c Prevents linking.
# -S compile to an assembly file only and not link.

TARGET=main
DEPS=tools
DEPS:= $(addsuffix .o, $(DEPS))
CC=gcc
CFLAGS=-lrt -save-temps -fverbose-asm -O2 #  -Wall -v
	
.PHONY: all clean install

all: $(TARGET)

#$(TARGET): $(DEPS) $(addsuffix .o, $(TARGET))
#	$(CC) $(CFLAGS) $(DEPS) $(addsuffix .o, $(TARGET)) -o $@

$(TARGET): $(DEPS)
	$(CC) $(CFLAGS) $(DEPS) $(addsuffix .c, $(TARGET)) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o *.i *.s $(TARGET) Primes.txt

install:
	