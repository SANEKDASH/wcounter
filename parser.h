#ifndef PARSER_HEADER
#define PARSER_HEADER

#define MAX_BUF_SIZE 256

static const char *DELIM_STR = " \n,\\\t\r<>#*\"();{}=";

struct file_parser;

struct file_parser *file_parser_create(int fd);

char *file_parser_get_string(struct file_parser *fp);

int file_parser_parse(struct file_parser *fp);

int file_parser_read(struct file_parser *fp);

int file_parser_destroy(struct file_parser *fp);

#endif /*PARSER_HEADER*/
