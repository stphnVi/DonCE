CC = gcc
CFLAGS = -Isrc/include
LDFLAGS = -Lsrc/lib
LDLIBS = -lmingw32 -lSDL2main -lSDL2

SRCS = main.c
OBJS = $(SRCS:.c=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
