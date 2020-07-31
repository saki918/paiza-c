// 引数と戻り値を理解しよう
#include <stdio.h>

/* 関数の定義は、原則として main 関数の上に書く必要があります。
   main 関数の下に関数定義を書きたい場合には、
   次のようにプロトタイプ宣言を記述する必要があります。*/

// 戻り値がなく、引数のある関数のプロトタイプ宣言
void sum(int, int);

// 戻り値、引数のある関数のプロトタイプ宣言
int plus(int, int);

// 戻り値、引数のない関数のプロトタイプ宣言
void say_hello(void);

// main関数では戻り値を省略できる
// returnを記述しなかった場合自動的にreturn0が行われる
int main(void)
{
  say_hello();
  sum(3, 5);
  int c = plus(45,918);
  printf("%d\n", c);
}

// 関数に引数を設定
void sum(int x, int y) {
  printf("%d\n", x + y);
}

// main関数で値を使いたい場合、戻り値を使う。
/* 関数の戻り値は、次のように設定できます。
   ・関数名の前に、戻り値のデータ型を記述する。
   ・関数の中で「return ...」で値を返す。*/
int plus(int a, int b) {
  return a + b;
}

void say_hello(void)
{
  printf("Hello paiza\n");
}