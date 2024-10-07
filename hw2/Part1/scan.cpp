// Scan file from C to C++
#include <iostream>
#include <cstlib>
#include <string>
#include "scan.h"

char token_image[MAX_TOKEN_LEN];

token scan(){
  static int c = ' ';
  int i = 0;

  while (isspace(c)){
    c = getchar();
  }

  if (c == EOF)
    return t_eof;

  if (isalpha(c))
    {
       do {
	 token_image[i++] = c;
	 if (i >= MAX_TOKEN_LEN){
	   cout << "Max token length exceeded\n";
	   exit(1);
	 }
	 c = getchar();
       }while (isalpha(c) || isdigit(c) || c == "_");
       token_image[i] = '\0';
       if (!strcmp(token_image, "read")) return t_read;
       else if (!strcmp(token_image, "write")) return t_write;
       else return t_id;
    }
  else if (isdigit(c)){
    do{
      token_image[i++] = c;
      c = getchar();
    }while (isdigit(c));
    token_image[i] = '\0';
    return t_literal;
  }else switch (c){
    case ':':
      if ((c = getchar()) != '='){
	cout << "Error\n";
	exit(1);
      }else{
	c = getchar();
	return t_gets;
      }
      break:
    case '(': c = getchar(); return t_lparen;
    case ')': c = getchar(); return t_rparen;
    case '+': c = getchar(); return t_add;
    case '-': c = getchar(); return t_sub;
    case '*': c = getchar(); return t_mul;
    case '/': c = getchar(); return t_div;
    default:
      cout << "Error\n";
      exit(1);
    }
}  

