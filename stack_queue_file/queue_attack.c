// RPGの攻撃シーンをつくろう 構造体を用いたキュー
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
// 構造体を用いたキュー
typedef struct {
  char name[20];
  int hp;
} data_t;

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
  if (head == (tail + 1) % N) {
    printf("queue overflow\n");
    return;
  }

  queue[tail] = x;
  tail = (tail + 1) % N;
}

int dequeue(data_t *x)
{
  if (head == tail) {
    return 1;
  }

  *x = queue[head];
  head = (head + 1) % N;
  return 0;
}

int main(void)
{
  init();

  // 敵の構造体
  data_t slime = {"スライム", 5};
  data_t monster = {"モンスター", 10};
  data_t dragon = {"ドラゴン", 20};

  // 作った敵をキューに追加
  enqueue(slime);
  enqueue(monster);
  enqueue(dragon);

  srand(time(NULL));
  data_t target;
  // 配列に値（敵）が存在している間
  while (dequeue(&target) == 0) {
    // 敵のHPが0になるまでランダムな数値で攻撃する
    while (target.hp > 0) {
      int hit = rand() % 10 + 1;
      printf("%sを攻撃した。%dのダメージ！\n", target.name, hit);
      target.hp -= hit;
    }
    printf("%sを倒した！\n", target.name);
  }
}