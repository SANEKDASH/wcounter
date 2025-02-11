#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "dict.h"

int main(int argc, char **argv)
{
    struct dictionary *dict = dictionary_create();

    if (argc < 2) {
        dictionary_add_words_from_file(STDIN_FILENO, dict);
    }
    else {
        for (int i = 1; i < argc; i++) {
            int fd = open(argv[i], O_RDONLY);

            if (fd < 0) {
                perror("failed to open file");

                return -1;
            }

            dictionary_add_words_from_file(fd, dict);

            close(fd);
        }
    }

    dictionary_print(dict);

    dictionary_destroy(dict);

    return 0;
}
