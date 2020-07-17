// 数の表示
#include <stdio.h>

// ライブラリの指定
#include <stdlib.h>

// time関数
#include <time.h>

int main(void){
    srand((unsigned int)time(NULL));
    // rand() % 何通り + 指定した数値からランダムで表示
    // 下記の場合 1 〜 100 の間でランダムで表示
    int randnum = rand() % 100 + 1;
    // printf("%d", randnum);
    // 数値の変数 は下記のように int で表示
    // int number = 100;
    // printf("%d", number);
    printf("スライムが%d匹あらわれた\n", randnum);
}