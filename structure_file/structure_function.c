// 構造体を使った関数をつくろう
#include <stdio.h>
#include <string.h>

typedef struct {
  char name[20];
  int hp;
  int power;
} Player;

// 構造体を作成して返す関数
/* 構造体は、直接代入ができるデータ型なので、関数の戻り値にすることができます。
   一方で**配列**は、値を**直接代入できず**、関数の戻り値にすることができません。 */
/* "勇者" や "魔法使い" のようなダブルクォーテーションで囲った文字列は「文字列リテラル」と呼ばれます。
   文字列リテラルには、原則として「実行時に書き換えることができない」という特徴があります。
   ・init 関数を呼び出すときに、引数に文字列リテラルを指定する 例 Player init(char name) {}
   ・init 関数の中で、引数で受け取った文字列リテラルを書き換える
   ということをしてしまうと、エラーになってしまいます。
   これを防ぐには、init 関数の引数で、書き換えができないことを表す const キーワードをつける必要があります。 
   ⬇︎ Player init(char name)とするとエラーになる。*/
Player init(char *name)
{
  Player player;

  strcpy(player.name, name);
  player.hp = 100;
  player.power = 100;

  return player;
}

// 構造体を引数として受け取る関数
/* ※ 関数の引数で構造体を渡す場合、値のコピーが渡されます。
   そのため、構造体のサイズが大きいと (構造体のメンバにある配列が大きいなど) コピーに時間がかかってしまいます。
   ○ そのようなときに、構造体へのポインタを渡す方法が推奨されることがあります。*/
void walk(Player player)
{
  printf("%sは荒野を歩いていた\n", player.name);
}

int main(void)
{
  Player hero = init("勇者");
  Player wizard = init("魔法使い");

  walk(hero);
  walk(wizard);
}
