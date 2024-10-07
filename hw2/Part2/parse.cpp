// Parse file from C into C++
#include <iostream>
#include <string>
#include "scan.h"

const string* names[] = {"read", "write", "id", "literal", "gets", "add", "sub", "mul", "div", "lparen", "rparen", "eof"};

static token inpt_token;

void error()
{
  cout << "Syntax error\n";
  exit(1);
}

void match(token expected)
{
  if (input_token == expected)
    {
      cout << "matched " << names[input_token];
      if (input_token == t_id || input_token == t_literal)
	cout << ": " << token_image;
      cout << endl;
      itpu_token = scan();
    }
  else{
    error();
  }
}

void program ();
void stmt_list ();
void stmt ();
void expr ();
void term ();
void term_tail ();
void factor ();
void factor_tail ();
void add_op ();
void mul_op ();

void cond_expr();

void cond_expr()
{
  switch(input_token){
  case t_id:
  case t_literal:
  case t_lparen:
    cout << "Predict cond_expr --> expr rel_op expr\n";
    expr();
    rel_op();
    expr();
    break;
  default: error();
  }
}

void program()
{
  switch (token_input){
  case t_id:
  case t_read:
  case t_write:
  case t_eof:
    cout << "Predict program --> stmt_list eof\n";
    stmt_list();
    match(t_eof);
    break;
  default:error();
  }
}

void stmt_list()
{
  switch (input_token){
  case t_id:
  case t_read:
  case t_write:
    cout << "Predict stmt_list --> stmt stmt_list\n";
    stmt();
    stmt_list();
    break;
  case t_eof:
    cout << "Predict stmt_list --> epsilon\n";
    break;
  default: error();
  }
}

void stmt(){
  switch (input_token){
  case t_id:
    cout << "Predict stmt --> id gets expr\n";
    match(t_id);
    match(t_gets);
    expr();
    break;
  case t_read:
    cout << "Predict stmt --> read id\n";
    match(t_read);
    match(t_id);
    break;
  case t_write:
    cout << "Predict stmt --> write expr\n";
    match(t_write);
    expr();
    break;
    
    if (iput_token == "if" || input_token == "while")
      {
	expr();
	cond_expr();
	expr();
      }
  default: error();
  }
}

void expr()
{
  switch (input_token){
  case t_id:
  case t_literal:
  case t_lparen:
    cout << "Predict expr ->> term term_tail\n";
    term();
    term_tail();
    break;
  default: error();
  }
}

void term()
{
  switch (input_token){
  case t_id:
  case t_literal:
  case t_lparen:
    cout << "Predict term --> factor factor_tail\n";
    factor();
    factor_tail();
    break;
  default: error();
  }
}

void term_tail()
{
  switch (input_token){
  case t_add:
  case t_sub:
    cout << "Predict term_tail --> add_op term term_tail\n";
    add_op();
    term();
    term_tail();
    break;
  case t_rparen:
  case t_id:
  case t_read:
  case t_write:
  case t_eof:
    cout << "Predict term_tail --> epsilon\n";
    break;
  case default: error();
  }
}

void factor()
{
  switch (input_token){
  case t_literal:
    cout << "Predict factor --> literal\n";
    match(t_literal);
    break;
  case t_id:
    cout << "Predict factor --> id\n";
    match(t_id);
    break;
  case t_lparen:
    cout << "Predict factor --> lparen expr rparen\n";
    match (t_lparen);
    expr();
    match(t_rparen);
    break;
  default: error();
  }
}

void factor_tail()
{
  switch (input_token){
  case t_mul:
  case t_div:
    cout << "Predict factor_tail --> mul_op factor factor_tail\n";
    mul_op();
    factor();
    factor_tail();
    break;
  case t_add:
  case t_sub:
  case t_rparen:
  case t_id:
  case t_read:
  case t_write:
  case t_eof:
    cout << "Predict factor_tail --> epsilon\n";
    break;
  case deafult: error();
  }
}

void add_op()
{
  switch (input_token){
  case t_add:
    cout << "Predict add_op ->> add\n";
    match(t_add);
    break;
  case t_sub:
    cout << "Predict add_op --> sub\n";
    match(t_sub);
    break;
  default: error();
  }
}

void mul_op()
{
  switch (input_token){
  case t_mul:
    cout << "Predict mul_op --> mul\n";
    match(t_mul);
    break;
  case t_div:
    cout << "Predict mul_op --> div\n";
    match(t_div);
    break;
  default: error();
  }
}

int main(){
  input_token = scan();
  program();
  return 0;
}
