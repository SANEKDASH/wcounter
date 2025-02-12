#ifndef DICTIONARY_HEADER
#define DICTIONARY_HEADER

#include <stdio.h>
#include <unistd.h>

#include "parser.h"

struct dictionary;

struct dictionary *dictionary_create();

/*
 * Copies word 's' and adds it to dictionary.
 * (Allocates memory)
 */
int dictionary_add_word(struct dictionary *d, const char *s);

int dictionary_destroy(struct dictionary *d);

struct word_node *dictionary_get_word_list(struct dictionary *d);

void dictionary_set_word_list_head(struct dictionary *d, struct word_node *new_head);

void dictionary_print(struct dictionary *d);

#endif /* DICTIONARY_HEADER */
