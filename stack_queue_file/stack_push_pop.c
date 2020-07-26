// スタックを実装しよう push,pop
#include <stdio.h>

// マクロを定義
#define N 4
typedef int data_t;

data_t stack[N];
int size;

void init(void)
{
  size = 0;
}

// スタックにデータを追加する push 関数は、次のように定義
void push(data_t x)
{
  // sizeがN以上だったら
  if (size >= N) {
    // スタックオーバーフローと出力
    printf("stack overflow\n");
    return;
  }
  stack[size] = x;
  size++;
}

// スタックからデータを取り出す pop 関数は、次のように定義
void pop(data_t *x)
{
  // sizeが0以下だったら
  if (size <= 0) {
    // スタックアンダーフローと出力
    printf("stack underflow\n");
    return;
  }
  // スタックからデータが取り出されたら格納するアドレスを変更する必要があるので
  // *x = stack[size - 1]とする ※ stack[2] = 3 から stack[1] = 3 になる為
  *x = stack[size - 1];
  size--;
}

void printStack() {
  for (int i = 0; i < N; i++)
  {
    printf("%d\n", stack[i]);
  }
  printf("\n");
}

int main(void)
{
  // スタックの初期化
  init();

  // スタックに値を追加
  push(10);
  push(20);

  printf("スタックにデータを２つ追加したときの中身\n");
  printStack();

  // スタックから値を取り出す
  int x;
  pop(&x);
  printf("%d\n", x);
  pop(&x);
  printf("%d\n", x);
  pop(&x);
  printf("%d\n", x);
  printf("\n");

  printf("スタックにデータを３つ取り出したときの中身\n");
  printStack();

  push(40);
  push(50);
  push(60);
  push(70);
  push(80);
  push(90);
  printf("\n");

  printf("スタックにデータをたくさん追加したときの中身\n");
  printStack();
}
