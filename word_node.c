#include "word_node.h"

struct word_node {
    struct word *word;

    struct word_node *next;
};

int word_node_set_next(struct word_node *cur_node,
                       struct word_node *next_node)
{
    cur_node->next = next_node;

    return 0;
}

struct word_node *word_node_get_next(struct word_node *n)
{
    return n->next;
}

struct word *word_node_get_word(struct word_node *n)
{
    return n->word;
}

struct word_node *word_node_create(struct word *w)
{
    struct word_node *new_node = malloc(sizeof(struct word_node));

    if (new_node == NULL) {
        perror("failed to alloc mem");
        return NULL;
    }

    new_node->word = w;
    new_node->next = NULL;

    return new_node;
}

int word_node_destroy(struct word_node *n)
{
    return 0;
}
