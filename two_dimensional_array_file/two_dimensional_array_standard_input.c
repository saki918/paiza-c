// 標準入力から 2 次元配列のデータを読み込もう
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char buf[100];
  fgets(buf, sizeof(buf), stdin);

  int n, m;
  // データ型 int のときはアドレスを示す&を変数の前につける
  sscanf(buf, "%d %d", &n,  &m);
  // printf("ドット絵の大きさ： %d × %d\n", n, m);

  // 2 次元配列のように使える領域 (n × m の領域) は次のように確保できます。
  int **enemy_image;
  enemy_image = malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
      enemy_image[i] = malloc(sizeof(int) * m);
  }
  /* 1. はじめに、「int へのポインタへのポインタ」の enemy_image 変数を宣言しています。

  2. 次に、enemy_image = malloc(sizeof(int ∗) ∗ n); としています。
  これによって、enemy_image には、「int ∗」型の値を n 個格納できる領域の先頭のアドレスが代入されます。
  よって、enemy_image は「int ∗ 型の値を要素としてもつ配列」のように使うことができます。

  3. その後で、ループ処理で、enemy_image[i] = malloc(sizeof(int) ∗ m); としています。
  これによって、各 enemy_image[i] には、int 型の値を m 個格納できる領域の先頭のアドレスが代入されます。
  よって、各 enemy_image[i] は「int 型の値を要素として持つ配列」のように使うことができます。

  つまり、enemy_image は「m 個の int を格納できる領域へのポインタ」を n 個格納する配列のように使うことができます。 */

  for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
          int x;
          /* scanf に変換指定子の「%s」や「%d」を使うと、標準入力から空白文字で区切られたデータを 1 つずつ読み込むことができます。
             空白文字とは、タブ、スペース、改行などを指します。 */
          scanf("%d", &x);
          enemy_image[i][j] = x;
      }
  }

  for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
          if (enemy_image[i][j] == 1) {
              printf("#");
          } else {
              printf(" ");
          }
      }
      printf("\n");
  }

  // malloc で以下のように領域を取得したとき、次のようにして領域を開放します。
  for (int i = 0; i < n; i++) {
      free(enemy_image[i]);
  }
  free(enemy_image);
  /* 先に「free(enemy_image);」を実行すると、各 enemy_image[i] にアクセスできなくなってしまうので、
     この順番で開放をおこなう必要があります。 */
}