all:
	gcc -O0 -lc -g -Wall main.c dict.c parser.c word_counter.c word.c word_node.c -o wcounter
