#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // ポインタの配列を理解しよう
  char slime[] = "スライム";
  char dragon[] = "ドラゴン";
  char satan[] = "魔王";
  
  char *enemies[3];
  
  enemies[0] = slime;
  enemies[1] = dragon;
  enemies[2] = satan;
  
  // char *p;
  // p = &slime[0];と同様
  // p = slime;

  // printf("%s\n", slime);
  // ランダムな数を初期化するための関数 time(NULL)で現在の時刻を指定
  srand((unsigned int)time(NULL));
  // 0~2のランダムな数
  int target = rand() % 3;
  printf("%s\n", enemies[0]);

  printf("%sに会心の一撃！ モンスターを倒した！\n", enemies[target]);
}