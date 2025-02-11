#ifndef WORD_HEADER
#define WORD_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word;

struct word *word_create(const char *s);

int word_increment_counter(struct word *w);

char *word_get_str(struct word *w);

int word_get_counter(struct word *w);

int word_destroy(struct word *w);

#endif /* WORD_HEADER */
