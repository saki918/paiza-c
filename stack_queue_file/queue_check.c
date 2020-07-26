#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* キューに入るデータの上限 */
#define MAX_QUEUE_NUM 3

/* キュー構造体 */
typedef struct QUEUE {
  /* エンキューされているデータの数 */
  int num;
  /* エンキューされているデータ */
  int data[MAX_QUEUE_NUM];
} QUEUE_T;

void initQueue(QUEUE_T*);
void printQueue(QUEUE_T*);
void enqueue(QUEUE_T*, int);
int deqeueue(QUEUE_T*);

/* キューを初期化する関数 */
void initQueue(QUEUE_T *queue){
  int i = 0;
  queue->num = 0;
  for(i = 0; i < MAX_QUEUE_NUM; i++){
    queue->data[i] = 0;
  }
}

/* エンキューする関数 */
void enqueue(QUEUE_T *queue, int input){

  /* キューが満杯なら何もせず関数終了 */
  if(queue->num >= MAX_QUEUE_NUM){
    printf("キューが満杯でエンキューできません\n");
    return;
  }

  /* データをキューの最後に追加 */
  queue->data[queue->num] = input;

  /* データの数もカウントアップ */
  queue->num++;
}

/* デキューする関数 */
int dequeue(QUEUE_T *queue){
  int i = 0;
  int ret = 0;

  /* キューが空なら何もせずに関数終了 */
  if(queue->num == 0){
    printf("キューが空です\n");
    return -1;
  }

  /* デキューした数を取得 */
  ret = queue->data[0];

  /* キューのデータを一つずつ先頭側に移動 */
  for(i = 0; i < queue->num-1; i++){
    queue->data[i] = queue->data[i+1];
  }

  /* キューの最後のデータは不要になるので0で初期化 */
  queue->data[queue->num-1] = 0;

  /* デキューしたのでキューのデータの数を１つ減らす */
  queue->num--;

  return ret;
}

/* キューの中身を表示 */
void printQueue(QUEUE_T *queue){
  int i = 0;

  for(i = 0; i < queue->num; i++){
    printf("%d,", queue->data[i]);
  }
  printf("\n");
}

int main(void){

  int m;
  int input;
  int output;
  QUEUE_T queue;

  /* キューを初期化 */
  initQueue(&queue);

  while(1){
    /* ユーザからメニューを選んでもらう */
    printf("メニュー\n 1:エンキュー\n 2:デキュー\n 3:キュー表示\n それ以外:終了\n");
    scanf("%d", &m);

    /* 選ばれたメニューに応じて処理を分岐 */
    if(m == 1){
      printf("エンキューする数は？（0以上の整数のみ可）");
      scanf("%d", &input);
      if(input < 0){
        printf("負の数は受け付けていません\n");
        continue;
      }
      printf("%dをエンキューします\n", input);
      enqueue(&queue, input);
    }else if(m == 2){
      printf("デキューします\n");
      output = dequeue(&queue);
      if(output != -1){
        printf("%dをデキューしました\n", output);
      }
    } else if(m == 3){
      printf("キューの中身を表示します\n");
      printQueue(&queue);
    } else {
      /* 1, 2, 3以外の場合はwhile文を抜け出すためにbreakを実行 */
      printf("終了します\n");
      break;
    }
  }
  return 0;
}