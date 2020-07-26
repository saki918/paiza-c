// スタックを実装しよう(1)
/* スタックとは
   後入れ先出しのデータ構造
   LIFO(Last In, First Out)
   例 積み重ねたお皿*/
#include <stdio.h>

#define N 10

// グローバル変数
typedef int data_t;

// int型の配列
data_t stack[N];
int size;

// stuckを初期化するinit関数の作成
void init(void)
{
  size = 0;
}

int main(void)
{

}
