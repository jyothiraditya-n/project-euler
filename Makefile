progs = $(patsubst %.c,%,$(wildcard *.c))
winprogs = $(patsubst %.c,%.exe,$(wildcard *.c))

current_progs = $(foreach prog,$(progs) $(winprogs),$(wildcard $(prog)))
CLEAN = $(foreach prog,$(current_progs),rm $(prog);)

CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -O2

WINCC = x86_64-w64-mingw32-gcc-win32
WINCFLAGS = $(CFLAGS) -D__USE_MINGW_ANSI_STDIO=1

$(progs) : % : %.c
	$(CC) $(CFLAGS) $< -o $@

$(winprogs) : %.exe : %.c
	$(WINCC) $(WINCFLAGS) $< -o $@

.DEFAULT_GOAL = all

.PHONY: all clean

all: $(progs) $(winprogs)

clean: 
	$(CLEAN)
