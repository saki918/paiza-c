#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// int main(void)
// {
//   srand(time(NULL));
//   int random = rand() % 10 + 1;

//   printf("スライムが%d匹現れた", random);
//   /* このコードでは、次のような関数が使用されています。
//     ・time ：現在の時刻を取得する関数です。
//     ・srand：引数の値をもとに、ランダムな数を初期化する関数です。
//     ・rand ：ランダムな数を生成する関数です。
//     ・printf：値を出力する関数です。 */
// }

// 関数をつくろう
void say_hello(void)
{
    printf("Hello paiza\n");
}
    /* void は「何もない」ということを表しています。

    この関数では void を 2 回使っていますが、
    ・先頭の void：この関数は値を返さない
    ・引数の void：この関数は引数がない
    ということを表しています。 */

int main(void)
{
    say_hello();
    say_hello();
}