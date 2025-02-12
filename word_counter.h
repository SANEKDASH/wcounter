#ifndef WORD_COUNTER_HEADER
#define WORD_COUNTER_HEADER

#include "dict.h"

int dictionary_add_words_from_file(int fd, struct dictionary *d);

#endif /* WORD_COUNTER_HEADER */
