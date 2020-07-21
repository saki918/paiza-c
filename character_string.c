// C言語には文字列型がありません。
// 文字列は文字 (char 型) の配列になります。

// ・最後の文字の次の要素にはヌル文字 '\0' が必要です。

/* 文字にはシングルクオート (' ') を使います。

char c = 'a';

文字列にはダブルクオート (" ") を使います。
char str[] = "paiza";

※ダブルクオートを使う場合は、ヌル文字を書く必要はありません

文字列は char 型の配列なので、次のように書くこともできます。
char str[] = {'p', 'a', 'i', 'z', 'a', '\0'};

・文字列の最後には必ずヌル文字 '\0' が必要です
・配列の大きさは、改行文字やヌル文字を含めたサイズが必要です
(たとえば、"a,b,c,\n,\0" という文字列では、5文字分の配列が必要になります。)*/

// 文字列の長さを求めよう
#include <stdio.h>

// strtok で文字列を分割しよう
#include <string.h>
/* string.h には、以下のような関数が定義されています。
・ strlen : 文字列の長さを求める string + length
・ strcmp : 文字列を比較する
・ strcpy : 文字列をコピーする
・ strtok : 文字列を区切り文字で分割する
・ memcpy : オブジェクトを指定したサイズだけコピーする */

// マクロで定義
#define N 20

int main(void)
{
  // 文字列
  char str[] = "paiza";
  printf("hello %s\n", str);
  
  int i;
  
  i = 0;
  // 文字列の[i]がヌル文字であるか判定 whileの場合
  // while (str[i] != '\0') {
  //     i++;
  // }
  
  // 文字列の[i]がヌル文字であるか判定 forの場合
  // for (i = 0; str[i] != '\0'; i++);
  
  // int length = i;
  // printf("%d\n", length);
  
  // #include <string.h>を用いた場合
  int length = strlen(str); 
  printf("%d\n", length);

  char buf[100];
  int n;
  
  // 標準入力から１行分のデータをbuf変数に読み込ませる
  fgets(buf, sizeof(buf), stdin);
  // buf変数を%dでint型に変換してnに代入
  // int型の時にはアドレスを措定するので&をつける
  sscanf(buf, "%d", &n);
  printf("データ数 : %d\n", n);

  // データ配列の作成 data[20]と同じ意味上のマクロを用いて
  int data[N];
  for (int i = 0; i < n; i++) {
      int x;
      fgets(buf, sizeof(buf), stdin);
      sscanf(buf, "%d", &x);
      data[i] = x;
  }

  for (int i = 0; i < n; i++) {
      printf("%d\n", data[i]);
  }

  // sscanf で文字列を分割しよう
  char buf[100];
  char s1[10];
  char s2[10];
  char s3[10];
  fgets(buf, sizeof(buf), stdin);
  // スペース（空白文字）で区切られている場合使える。,は不可能。
  // あらかじめ決められた個数しか分割できない
  sscanf(buf, "%s %s %s", s1, s2, s3);

  printf("%s\n", s1);
  printf("%s\n", s2);
  printf("%s\n", s3);

  // 文字列の分割（,などで分割させた場合） #include <string.h>
  fgets(buf, sizeof(buf), stdin);
    // sscanf で %s を使うと、空白文字以外では分割できません。

    // *tp ポインタ変数はアドレスを保持するための変数
    // 文字列の先頭を指し示す変数 変数の前に*をつける
    char *tp;
    /* strtok を使うと、空白文字以外でも文字列を分割できます。

    strtok の 1 つ目の引数は、
    1 回目の呼び出しでは、文字列を格納した変数、
    2 回目以降の呼び出しでは、NULL
    を指定します。

    ※strtokを使うと、もとの文字列 (ここでは str) は書き換わってしまいます
    
    strtok の 2 つ目の引数は、区切りたい文字を文字列として指定（今回は(,)）
    文字列を表示させたい回数分記述する。strtok printf
    区切りたい文字までいくとその文字が\0(ヌル文字)と変換される
    ヌル文字を読むとそこまでが文字列だと判断されて、
    また別の文字列として表示する。その繰り返しがされて分割していく*/
    tp = strtok(buf, " ,\n");
    printf("%s\n", tp);

    tp = strtok(NULL, " ,\n");
    printf("%s\n", tp);

    tp = strtok(NULL, " ,\n");
    printf("%s\n", tp);
}