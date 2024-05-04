CFLAGS = -Wall -Iinclude -Itest/unity
LDFLAGS=-lreadline
OBJDIR = obj/
SRC = src/main.c src/parser.c src/autocomplete.c
OBJ = $(SRC:src/%.c=$(OBJDIR)%.o)
# match each file in src against 'src/%.c'
# % captures the filename without directory and extentsion
# replace with $(OBJDIR)%.o
TARGET = bin/shell

TEST_SRC = $(wildcard test/*.c)
UNITY_SRC = test/unity/unity.c
TEST_OBJ = $(TEST_SRC:.c=.o) $(UNITY_SRC:.c=.o)
TEST_TARGET = bin/test_shell

SRC_TEST_OBJS = $(filter-out $(OBJDIR)main.o, $(SRC:src/%.c=$(OBJDIR)%.o))

all: $(TARGET)

$(TARGET):	$(OBJ)
	gcc -o $@ $^ $(LDFLAGS)
# $@ is replaced by $(TARGET)
# $^ is replaced by all prereqs of target i.e. obj files in $(OBJ)

$(OBJDIR)%.o: src/%.c
	gcc $(CFLAGS) -c $< -o $@
# $< is a special automatic variable in Makefiles that represents
# the first prerequisite of a rule i.e. the corresponding .c file in src 

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJ) $(SRC_TEST_OBJS)
	gcc -o $@ $^ $(CFLAGS) $(LDFLAGS)



clean:
	rm -f $(OBJDIR)*.o $(TARGET) $(TEST_OBJ) $(TEST_TARGET)

.PHONY: all clean test
