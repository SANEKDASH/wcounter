#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

struct file_parser {
    int fd;

    size_t read_size;

    char *buf;
    char *cur_string;
    char *split_string;

    int split_word_flag;
};

struct file_parser *file_parser_create(int fd)
{
    struct file_parser *fp = (struct file_parser *) malloc(sizeof(struct file_parser));

    fp->fd = fd;
    fp->buf = (char *) malloc(sizeof(char) * (MAX_BUF_SIZE + 1));

    fp->buf[MAX_BUF_SIZE] = '\0';

    if (fp->buf == NULL) {
        perror("file_parser: failed to allocate memory");
        return NULL;
    }

    fp->cur_string   = NULL;
    fp->split_string = NULL;

    fp->read_size = 0;
    fp->split_word_flag = 0;

    return fp;
}

char *file_parser_get_string(struct file_parser *fp)
{
    char *new_string = fp->cur_string;

    fp->cur_string = strtok(NULL, DELIM_STR);
/*
    if (fp->split_word_flag) {
        if (fp->cur_string == NULL) {
            fp->split_string = (char *) malloc(strlen(new_string));
            strcpy(fp->split_string, new_string);

            return NULL;
        }
        else {
            if (fp->split_string != NULL) {
                char *old_split_string = fp->split_string;

                fp->split_string = strcat(fp->split_string, fp->cur_string);

                fp->cur_string = strtok(NULL, DELIM_STR);

                if (fp->cur_string != NULL) {
                    return new_string;
                }
            }
        }
    }
    else {
        if (fp->split_string != NULL) {
            if (new_string != NULL) {
                new_string = strcat(fp->split_string, new_string);

                free(fp->split_string);
                fp->split_string = NULL;

                fp->cur_string = strtok(NULL, DELIM_STR);
            }
        }
    }
*/
    return new_string;
}

int file_parser_destroy(struct file_parser *fp)
{
    fp->fd = -1;

    free(fp->buf);

    fp->buf = NULL;
    fp->cur_string = NULL;

    return 0;
}

int file_parser_read(struct file_parser *fp)
{
    fp->read_size = read(fp->fd, fp->buf, MAX_BUF_SIZE);

    fp->buf[fp->read_size] = '\0';

    if (!strchr(DELIM_STR, fp->buf[fp->read_size - 1])) {
        fp->split_word_flag = 1;
    }
    else {
        fp->split_word_flag = 0;
    }

    return fp->read_size;
}

int file_parser_parse(struct file_parser *fp)
{
    char *new_word = strtok(fp->buf, DELIM_STR);

    if (new_word == NULL) {
        return -1;
    }

    fp->cur_string = new_word;

    return 0;
}
