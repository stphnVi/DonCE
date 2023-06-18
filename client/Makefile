CC = gcc
CFLAGS = -Isrc/include
LDFLAGS = -Lsrc/lib
LDLIBS = -lmingw32 -lwsock32 -lSDL2main -lSDL2 -lSDL2_image

SRCS = main.c screen.c load_texture.c user.c fruits.c cocodriles.c network.c
OBJS = $(SRCS:.c=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)


