progs = $(patsubst %.c,%,$(wildcard *.c))
winprogs = $(patsubst %.c,%.exe,$(wildcard *.c))

questions = $(patsubst %.c,%.html,$(wildcard *.c))
answers = $(patsubst %.c,%.txt,$(wildcard *.c))

current_progs = $(foreach prog,$(progs) $(winprogs),$(wildcard $(prog)))
CLEAN = $(foreach prog,$(current_progs),rm $(prog);)

CC ?= gcc
CFLAGS += -std=c99 -Wall -Wextra -Werror -Ofast
LD_LIBS += -lm

WINCC ?= x86_64-w64-mingw32-gcc
WINCFLAGS += $(CFLAGS) -D__USE_MINGW_ANSI_STDIO=1

CURL ?= curl

$(progs) : % : %.c
	$(CC) $(CFLAGS) $< -o $@ $(LD_LIBS)

$(winprogs) : %.exe : %.c
	$(WINCC) $(WINCFLAGS) $< -o $@ $(LD_LIBS)

$(questions) : %.html :
	$(CURL) https://projecteuler.net/minimal=$* > $@

$(answers) : %.txt : %
	./$< > $@

.DEFAULT_GOAL = all
.PHONY : all all-win run clean

all : $(progs) $(questions) $(answers)

all-win : $(all) $(winprogs)

clean : 
	$(CLEAN)