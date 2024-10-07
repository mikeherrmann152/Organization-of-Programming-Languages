typedef enum {t_read, t_write, t_id, t_literal, t_gets, t_add, t_sub, t_mul,t_dic, t_lparen, t_rparen, t_eof} token;

#define MAX_TOENLEN 128

extern char token_image[MAX_TOKEN_LEN];

extern token scan();
