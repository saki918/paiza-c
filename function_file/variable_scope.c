// スコープを理解しよう
#include <stdio.h>

/* 関数の外側で宣言された変数は「グローバル変数 (大域変数)」と呼ばれます。
   グローバル変数は、複数の関数から直接アクセスできます。 */
int count = 0;

int sum(int x, int y)
{
  count++;
  // a = 3; main関数で定義された変数はsum関数内では使えない。
  return x + y;
}

int main(void)
{
  // main関数で定義された変数はsum関数内では使えない。
  /* スコープが関数の中に限られている変数は「ローカル変数 (局所変数)」と呼ばれます。
      関数の中で宣言した変数はローカル変数です。
      ローカル変数は、その関数の中でだけ使うことができます。
      他の関数からは直接アクセスできません。 */
  int a = 10;
  int b = 20;
  printf("%d\n", sum(3, 2));
  printf("%d\n", sum(a, b));
  printf("sum が呼び出された回数 : %d 回\n", count);
  printf("%d\n", sum(a, b));
  printf("sum が呼び出された回数 : %d 回\n", count);
  printf("%d\n", sum(a, b));
  printf("sum が呼び出された回数 : %d 回\n", count);

  char message[] = "paiza";
  for (int i = 0; i < 5; i++) {
      // ブロック」とは、コードを波カッコ { } で囲ってひとまとまりにしたもののことです。
      // ブロックの内側で宣言した変数は、ブロックの外側では利用できません。
      // ブロック内に変数を宣言した場合、一番下のブロック外、40行目のprintfがエラーになる。
      // char message[] = "paiza";
      printf("%s %d\n", message, i);
  }
  printf("%s\n", message);
}
