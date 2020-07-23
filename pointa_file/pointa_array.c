#include <stdio.h>

int main(void) {
  // 配列に対してポインタを使ってみよう
  int data[] = {1, 2, 3, 4, 5};

  int *p3, *p4;
  p3 = &data[2];
  p4 = &data[4];
  
  // そのポインタが指し示す値を参照したり書き換えたりできる
  *p3 = 30;
  *p4 = 50; 
  
  for (int i = 0; i < 5; i++) {
      printf("%d\n", data[i]);
  }
}