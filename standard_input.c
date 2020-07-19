// 標準入力
#include <stdio.h>

// defineマクロを使うと、文字列の長さなどを後から変更するときなどに便利です。
// Nなどのマクロ名は見分けがつきやすいように、大文字を使うのが一般的です。
#define N 10

int main(void)
{
  /* 【 sscanf で使う変換指定 】
  %d : 整数を受け取ります
  %s : 改行や空白(スペース)を含まない文字列を受け取ります */
  
  char buf[100];
  // fgets(エフゲッツ)で標準入力からデータを読み込む １行分
  // stdin 標準入力のこと
  fgets(buf, sizeof(buf), stdin);
  
  // 文字列
  char str[N];
  // sscanf(エススキャンエフ)をつかって、データを変換する
  // %s : 改行や空白(スペース)を含まない文字列を受け取ります
  sscanf(buf, "%s", str);
  printf("hello %s\n", str);
  
  fgets(buf, sizeof(buf), stdin);
  
  // 数値
  int n;
  // sscanfで数値を読み込む場合、変数の前に＆をつける。３つめの変数にはアドレスをつける必要がある。
  //  sscanfの中ではnに&(アンド)をつけます。
  sscanf(buf, "%d", &n);
  printf("hello %d\n", n * 2);

  // 同じテキストを指定回数出力する
  int num;
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d", &num);
  
  for (int i = 0; i < num; i++) {
      printf("スライムがあらわれた\n");
  }

  // 標準入力で2つの自然数n1、n2が、改行区切りで与えられます。
  // n1からn2まで、1ずつ増加させながら、順番に1行ずつ出力するプログラムを作成してください。

  int n1;
  int n2;
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d", &n1);
  // printf("%d", n1);
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d", &n2);
  // printf("%d", n2);
  for (int i = n1; i <= n2; i++) {
    printf("%d\n", i);
  }

  // 指定した行数だけデータを取得する
  int number;
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d", &number);
  for (int i = 0; i < number; i++) {
      int number1;
      fgets(buf, sizeof(buf), stdin);
      sscanf(buf, "%d", &number1);
      printf("%d\n", number1 * 2);
  }

  // 西暦年と昭和年の対応表 自分の解答
  // int seireki = 1926;
  // int showa = seireki - 1925;
  // for (int i = seireki; i <= 1988; i++) {
  //     printf("西暦%d年 昭和%2d年\n", i,i - 1925);
  // }

  // 模範解答
  int seireki;
  int showa;
  for (seireki = 1926; seireki <= 1988; seireki++) {
      showa = seireki - 1925;
      printf("西暦%d年 昭和%2d年\n", seireki, showa);
  }

  // 特定期間の西暦年と令和年の対応表を作る
  // char buf[100];
  int start, term;
  int seireki1, reiwa;
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d", &start);
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d", &term);
  for (seireki1 = start; seireki1 < start + term; seireki1++) {
    reiwa = seireki1 - 2018;
    printf("西暦%d年 令和%2d年\n", seireki1, reiwa);
  }
}
