// スタックを使った宝箱
#include <stdio.h>

#define N 10
// 文字列を扱う場合は、char*
typedef char* data_t;

data_t stack[N];
int size;

void init(void)
{
  size = 0;
}

void push(data_t x)
{
  if (size >= N) {
    // N以上のデータが格納されそうになるとスタックオーバーフローを出力
    printf("stack overflow\n");
    return;
  }

  stack[size] = x;
  size++;
}

/* push関数も下の関数と同じようにreturnで返しても良い 戻り値を int にする
int push(data_t x)
{
  if (size >= N) {
    return 1;
    return;
  }

  stack[size] = x;
  size++;
  return 0;
}*/

int pop(data_t *x)
{
  if (size <= 0) {
    // stack配列の中は何も無いのでエラーを意味する1を出力
    return 1;
  }

  *x = stack[size - 1];
  size--;
  return 0;
}

int main(void)
{
  init();

  char item1[] = "鋼鉄の剣";
  char item2[] = "木の盾";
  char item3[] = "回復薬";
  char item4[] = "クリスタル";

  // data_tはcharのポインタ変数
  push(item1);
  push(item2);
  push(item3);
  push(item4);

  char *p;
  printf("宝箱を開けた！\n");

  while (pop(&p) == 0) {
    printf("%sを手に入れた！\n", p);
  }
  // ここの時点だとstack配列の中は何も無いのでエラーを意味する1を出力する。
  printf("%d\n", pop(&p));
}
