COMPILER = gcc
CFLAGS = -g -Wall
SRCSDIR = $(PWD)
INCSDIR = $(SRCSDIR)/../common
SRCS = $(wildcard $(SRCSDIR)/*.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))

EXEC = alg_heap_main
all: $(EXEC)
$(EXEC) : $(OBJS)
	$(COMPILER) $(CFLAGS) -o $(EXEC) $(OBJS)

%.o : %.c
	-@echo -e "\033[33mnow compling $<...\033[0m"
	$(COMPILER) $(CFLAGS) -o $@ -c $< -I$(INCSDIR)

.PHONY: all clean
clean:
	-@echo -e "\033[31mcleaning $(OBJS) $(EXEC)...\033[0m"
	-@rm -rf $(OBJS) $(EXEC)
	-@echo -e "\033[31mclean done!\033[0m"
