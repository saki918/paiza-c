// queue_enqueue_dequeue.c ファイルでは、tail、head の値が enqueue、dequeue を実行するごとに増えていってしまいます。
// そのため、enqueue と dequeue を使うごとに、キューの容量が小さくなっていってしまいます。

// キューを実装しよう(3)
#include <stdio.h>

#define N 4
typedef int data_t;

data_t queue[N];
int head;
int tail;

void init(void)
{
  head = 0;
  tail = 0;
}

void enqueue(data_t x)
{
  // 格納できるデータ数はN - 1個
  // つまり tail = N だとすでにキューオーバーフローしている。
  // この条件はキュー配列の空きが残り１つしかない場合、
  // キューオーバーフローを出力
  if (head == (tail + 1) % N) {
    printf("queue overflow\n");
    return;
  }

  queue[tail] = x;
  // 下の計算式で tail = 0 になるということは配列の最後まで値が入ったということになる。
  // tail = N-1 になるまで配列にデータが加わったらtail[0](データが入っていない場合)からデータを加えられるようにする計算式
  tail = (tail + 1) % N;
}

void dequeue(data_t *x)
{
  // head == tail のときは何も変更せず、キューオーバーフローを出力
  if (head == tail) {
    printf("queue underflow\n");
    return;
  }

  *x = queue[head];
  head = (head + 1) % N;
}

void printQueue() {
  for (int i = 0; i < N; i++)
  {
    printf("%d\n", queue[i]);
  }
  printf("\n");
}
int main(void)
{
  // キューの初期化
  init();

  // キューに値を追加
  enqueue(10);
  enqueue(20);
  enqueue(30);

  printf("値を３つ追加したときのキューの中身\n");
  printQueue();

  // キューから値を取り出す
  int x;
  dequeue(&x);
  printf("%d\n", x);
  printf("値を1つ取り出したときのデータの中身\n");
  dequeue(&x);
  printf("値を1つ取り出したときのデータの中身\n");
  printf("%d\n", x);
  printf("\n");
  // どうしてここで二つのデータを取り出しているはずなのに下の配列で10,20が配列の中に入っているのか？
  printf("値を2つ取り出したときのキューの中身\n");
  printQueue();

  // キューに値を追加
  enqueue(40);
  printf("値40を追加したときのキューの中身\n");
  printQueue();

  enqueue(50);
  printf("値50を追加したときのキューの中身\n");
  printQueue();

  // 今回の場合キューの空きが残り一つしかない場合処理が実行されないのでキューオーバーフローと出力される。
  enqueue(60);
  printf("値60を追加したときのキューの中身\n");
  printQueue();
}

/* % は余りを求める計算式
   tail = (tail + 1) % N;
   tail = 1 N = 4の場合
   tail = 2 % 4 = 0余り2
   tail = 2 */