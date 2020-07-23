// if文による条件分岐
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
  srand((unsigned int)time(NULL));
  int number = (rand() % 3 + 1) * 100;
  printf("あなたの得点は%dポイントです\n", number);
  // ここにif文を追加する
  if (number == 300) {
      printf("おめでとう\n");
  } else {
      printf("ざんねん\n");
  }

  int num = rand() % 5 + 1;
  printf("あなたの順位は%d位です\n", num);
  // ここにif文を追加する
  if (num == 1) {
      printf("おめでとう！\n");
  } else if (num == 2) {
      printf("あと少し！\n");
  } else {
      printf("よくがんばったね\n");
  }

  // 西暦年から昭和年を求める
  int seireki = rand() % 63 + 1926;
  printf("西暦%d年は、\n", seireki);

  // 昭和年を計算
  int showa = seireki - 1925;
  printf("昭和%d年です\n", showa);
}
