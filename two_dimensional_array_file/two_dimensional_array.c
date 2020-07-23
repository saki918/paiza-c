// 2 次元配列を作成しよう
#include <stdio.h>

int main(void)
{
  // int data[] = {1, 2, 3, 4, 5};

  // for (int i = 0; i < 5; i++) {
  //     printf("%d\n", data[i]);
  // }
  
  // 多次元配列の場合要素数を省略して書けない。 例 data[][] = { {1,2,3,4,5}, {6,7,8,9,10} };は エラーになる。
  int data[2][5] = { {1,2,3,4,5}, {6,7,8,9,10} };
  
  // 出力結果 1
  printf("%d\n",data[0][0]);
  // 出力結果 9
  printf("%d\n",data[1][3]);

  // 2次元配列の要素を変更する
  // ここで data 配列の 1 行目の値を 100 に書き換える
  data[0][0] = 100;
  data[0][1] = 100;
  data[0][2] = 100;

  printf("%d %d %d\n", data[0][0], data[0][1], data[0][2]);
  printf("%d %d %d\n", data[1][0], data[1][1], data[1][2]);

  // 2 次元配列をループで処理しよう
  int data1[3][3];

  for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
          data1[i][j] = i * 3 + j + 1;
      }
  }
  for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
          printf("%d",data1[i][j]);
      }
      // data[][]の最初の[]の配列の出力が終わったら改行する
      printf("\n");
  }

  int a[3][4] = { {10, 11, 12, 13}, {14, 15, 16, 17}, {18, 19, 20, 21} };

  // ここで、a の各要素を出力する
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
        if (j != 0) {
            printf(" ");
        }
        printf("%d", a[i][j]);
    }
      printf("\n");
  }
}