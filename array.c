// 配列に要素を追加しよう
#include <stdio.h>

// memcpyを使用するのに必要（配列のコピー）
#include <string.h>

int main(void)
{
  // この配列に 123, 456, 789 の値を代入する
  int a[] = {123,456,789};

  printf("a[0] = %d\n", a[0]);
  printf("a[1] = %d\n", a[1]);
  printf("a[2] = %d\n", a[2]);

  // 配列から特定の要素を取り出してみよう
  int idx;
  char buf[10];
  int data[] = {111, 222, 333, 444, 555};

  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d", &idx);

  // ここで、data のインデックスが idx の要素を出力する
  printf("%d\n", data[idx]);

  int copy[3];
    copy[0] = 100;
    copy[1] = 200;
    copy[2] = 300;

    int number = 0;
    printf("%d\n", copy[number]);
    
    int b[3];
    // b = copy; //これはエラーになる
    
    // ループで配列をコピーする場合
    // for (int i = 0; i < 3; i++) {
    //     b[i] = copy[i];
    // }
    
    // memcpy の
    // ・1 つ目の引数にコピー先の配列、
    // ・2 つ目の引数にコピー元の配列、
    // ・3 つ目の引数にコピーするサイズ (バイト数)
    // を指定します。
    // 配列 b のサイズは sizeof(b) で取得できます。
    memcpy(b,copy,sizeof(b));
    
    for (int i = 0; i < 3; i++) {
        printf("%d\n", b[i]);
    }
}