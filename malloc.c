// malloc について理解しよう
#include <stdio.h>
// ライブラリの追加
#include <stdlib.h>

int main(void)
{
    char buf[100];
    int n;
    
    // 標準入力からデータを受け取る
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);
    printf("データの個数 : %d\n", n);

    /* ・領域の大きさは、「sizeof(型名) * 要素数」 で指定します。
    ・malloc で返される値は、確保された領域の先頭のアドレスです。
    (ただし、領域の確保に失敗したときには NULL が返されます) */
    int *p;
    p = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("p[%d] : %d\n", i, p[i]);
    }

    // malloc で確保された領域は、free で解放することができます。
    free(p);
}