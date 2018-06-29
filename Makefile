CC := gcc
SRCDIR := src
BUILDDIR := build
TARGET := lib/libcstruct.a

SRCEXT := c
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall -Werror
LIB :=
INC := -I include

$(TARGET): $(OBJECTS)
	@echo "Linking $(TARGET)"
	@mkdir -p $(shell dirname "$(TARGET)")
	@mkdir -p log
	@ar rcs $(TARGET) $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo "Compiling $<"
	@mkdir -p $(shell dirname "$@")
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<

test: $(TARGET) test/test.c
	gcc -o test/test test/test.c -Llib -lcstruct -I include

clean:
	@echo Removing generated file
	@$(RM) -rf $(BUILDDIR) $(TARGET) test/test

.PHONY: clean
