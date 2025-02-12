#include "word_node.h"
#include "word.h"
#include "dict.h"

struct dictionary {
    struct word_node *word_node;
};

struct dictionary *dictionary_create()
{
    struct dictionary *dict = (struct dictionary *) malloc(sizeof(struct dictionary));

    if (dict == NULL) {
        perror("failed to alloc");
        return NULL;
    }

    dict->word_node = NULL;

    return dict;
}

void dictionary_set_word_list_head(struct dictionary *d, struct word_node *new_head)
{
    d->word_node = new_head;
}

int dictionary_add_word(struct dictionary *d, const char *s)
{
    struct word_node *cur_node = d->word_node;

    while (cur_node != NULL) {
        if (strcmp(s, word_get_str(word_node_get_word(cur_node))) == 0) {
            word_increment_counter(word_node_get_word(cur_node));
            return 0;
        }

        cur_node = word_node_get_next(cur_node);
    }

    struct word_node *new_head = word_node_create(word_create(s));

    word_node_set_next(new_head, dictionary_get_word_list(d));

    dictionary_set_word_list_head(d, new_head);

    return 0;
}

void dictionary_print(struct dictionary *d)
{
    struct word_node *cur_node = dictionary_get_word_list(d);

    while (cur_node != NULL) {
        printf("%d - %s\n", word_get_counter(word_node_get_word(cur_node)),
                            word_get_str(word_node_get_word(cur_node)));

        cur_node = word_node_get_next(cur_node);
    }
}

struct word_node *dictionary_get_word_list(struct dictionary *d)
{
    return d->word_node;
}

int dictionary_destroy(struct dictionary *d)
{
    return 0;
}

