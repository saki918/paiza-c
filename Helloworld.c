#include<stdio.h>

// ライブラリの指定
#include <stdlib.h>

// time関数 
#include <time.h>

// プログラムの実行ファイル作成 実行したいファイルがあるフォルダまで移動
// gcc -o 実行ファイル名 Helloworld.c
// 例1 gcc -o program Helloworld.c

// 実行ファイルを実行 実行したいファイルがあるフォルダまで移動
// ./実行ファイル名
// 上記の例1で作成した場合 ./program

int main (void){
  // (\)の出力の仕方 optionキー + ¥キー
  printf("Helloworld\n");
  printf("%d円\n",100);

  // HTMLの表示
  printf("<h1>HTML</h1>\n");

  // 文字列の変数の宣言 []は長さの範囲を指定
  char player[100] = "勇者";
  // printf("%s", player);
  printf("%sは、荒野を歩いていた\n", player);
  printf("%sは、モンスターと戦った\n", player);
  printf("%sは、モンスターをたおした\n", player);

  //値段を計算する
  srand((unsigned int)time(NULL));
  // apple_price	リンゴの単価 100,200,300の中でランダム表示
  // apple_num	リンゴを買う数 1 ~ 10 でランダム表示
  int apple_price = (rand() % 3 + 1) * 100;
  int apple_num = rand() % 10 + 1;
  printf("リンゴの単価：%d円\n",apple_price);
  printf("リンゴを買う数：%d個\n", apple_num);
  int total = apple_price * apple_num;
  printf("合計金額：%d円\n", total);
  // C 言語の main 関数で return 0; を最後に書くことで、プログラムが正常に終了したことをシェルに伝えます
  return 0;
}