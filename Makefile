TARGET ?= prob_1

CXX = clang++
CC = clang
CFLAGS = -pedantic -pedantic-errors -Wall -Werror -Wextra
CXXFLAGS = -std=c++17
LDFLAGS = -lm
STYLE = Google

SOURCES := $(wildcard *.c *.cpp)
EXECS_ = $(SOURCES:.c=.out)
EXECS = $(EXECS_:.cpp=.out)

.PHONY: all
all: $(EXECS)

.PHONY: test
test:
	@echo $(EXECS)

.PHONY: reformat
reformat:
	clang-format -i --style=$(STYLE) $(SOURCES)

%.out: %.c
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $<

%.out: %.cpp
	$(CXX) $(CFLAGS) $(CXXFLAGS) $(LFLAGS) -o $@ $<

.PHONY: run_%
run_%: %.out
	./$<

.PHONY: clean
clean:
	$(RM) $(EXECS)