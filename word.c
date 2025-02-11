#include "word.h"

struct word {
    char *str;

    size_t counter;
};

struct word *word_create(const char *s)
{
    struct word *new_word = (struct word *) malloc(sizeof(struct word));
    if (new_word == NULL) {
        perror("failed to alloc memory");
        return NULL;
    }

    new_word->str = strdup(s);

    new_word->counter = 1;

    return new_word;
}

int word_get_counter(struct word *w)
{
    return w->counter;
}

int word_increment_counter(struct word *w)
{
    w->counter++;

    return 0;
}

char *word_get_str(struct word *w)
{
    return w->str;
}

int word_destroy(struct word *w)
{
    free(w->str);

    return 0;
}


