#include "word_counter.h"

int dictionary_add_words_from_file(int fd, struct dictionary *d)
{
    struct file_parser *fp = file_parser_create(fd);

    while (file_parser_read(fp) > 0) {
        file_parser_parse(fp);

        char *new_word = NULL;

        while((new_word = file_parser_get_string(fp)) != NULL) {
            dictionary_add_word(d, new_word);
        }
    }

    file_parser_destroy(fp);

    return 0;
}
