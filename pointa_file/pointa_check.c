#include <stdio.h>

int main(void) {
  // ポインタの間違えやすいところ
  int s = 10;
  int t = 20;

  char *p7;

  // ポインタの型は、アドレスを代入する変数の型に
  // 合わせて適切に選ぶ必要があります。
  // p6 = &s;
  // char型のポインタ変数にint型の変数を入れているので
  // コンパイルエラーが起きる。
  // p7 = &x;

  // 下の２行をまとめて書くとこうなる。
  int *p6 = &s;
  // int *p6; 本当はこのように動作している
  // p6 = &x;

  // &で参照しているものに代入で書き換えることはできない。
  // 変える場合はポインタ変数を使う。
  // &x = &y; （できない）

  // ・ヌル文字 ('\0') : 文字列の最後に使われる char 型の文字
  char str[] = {'a','b','c','\0'};

  // ・ヌルポインタ (NULL) : 何も指し示さないことを表す特別なポインタ
  int *p8 = NULL;

  /* ヌル文字とヌルポインタは違うものです。
  ・ヌル文字 ('\0') : 文字列の最後に使われる char 型の文字
  ・ヌルポインタ (NULL) : 何も指し示さないことを表す特別なポインタ

  文字列で、ヌル文字の代わりにヌルポインタを
  使ってしまう間違いがよくあるので、注意!! */
}