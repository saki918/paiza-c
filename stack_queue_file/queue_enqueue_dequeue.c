// キューを実装しよう(2) 配列
// このキューには、繰り返し使うごとに容量が小さくなってしまう、という問題点があります。
// queue_enqueue_dequeue_fix.c ファイルで⬆︎の問題を修正済
#include <stdio.h>

#define N 10
typedef int data_t;

data_t queue[N];
int head;
int tail;

void init(void)
{
  head = 0;
  tail = 0;
}

// キューにデータを追加する enqueue 関数は、次のように定義
void enqueue(data_t x)
{
  if (tail >= N) {
    printf("queue overflow\n");
    return;
  }

  queue[tail] = x;
  tail++;
}

// キューからデータを取り出す dequeue 関数は、次のように定義
void dequeue(data_t *x)
{
  /* head と tail が等しいときは、それ以上データを取り出せない(データがない)ので、
    「queue underflow」と出力して、return で処理を終了させます。 */
  if (head == tail) {
    printf("queue underflow\n");
    return;
  }
  *x = queue[head];
  head++;
}

int main(void)
{
  // キューの初期化
  init();

  // キューに値を追加
  enqueue(10);
  enqueue(20);

  // キューから値を取り出す
  int x;
  dequeue(&x);
  printf("%d\n", x);
  dequeue(&x);
  printf("%d\n", x);
  // 取り出せるデータが無いのでqueue underflowと出力
  dequeue(&x);
}
