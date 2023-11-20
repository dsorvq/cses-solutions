CC := g++
CFLAGS := -Wall -std=c++20 -fsanitize=address -fno-omit-frame-pointer
TARGETS := main 

$(TARGETS): %: %.cpp
	$(CC) $(CFLAGS) -o $@.out $<

.PHONY: all clean

all: $(TARGETS)

clean:
	rm -f $(TARGETS)
