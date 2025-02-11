#ifndef WORD_NODE_HEADER
#define WORD_NODE_HEADER

#include "word.h"

struct word_node;

struct word_node *word_node_create(struct word *w);

int word_node_set_next(struct word_node *cur_node,
                       struct word_node *next_node);

struct word_node *word_node_get_next(struct word_node *n);

struct word *word_node_get_word(struct word_node *n);

int word_node_destroy(struct word_node *n);

#endif /* WORD_NODE_HEADER */
