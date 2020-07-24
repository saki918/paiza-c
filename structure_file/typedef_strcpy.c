// 構造体を扱うときに便利な機能を使ってみよう
#include <stdio.h>
// strcpyを使用するためのライブラリ
#include <string.h>

// typedef で宣言すると構造体タグを省略できる。
typedef struct {
  char name[20];
  int hp;
  int power;
} Player;

// typedef を使うとデータ型に名前をつけることができます。名前の先頭は大文字。
// typedef struct player Player;

int main(void)
{
  // struct player hero;
  // typedefを使うと下のように省略できる。
  Player hero;

  // このhero.nameはエラーになる。＝でそのまま代入できない。
  // すでに宣言された変数に文字列を代入するにはstrcpy関数を使う。
  strcpy(hero.name, "勇者");
  hero.hp = 100;
  hero.power = 100;

  printf("%s：HP %d, 攻撃力 %d\n", hero.name, hero.hp, hero.power);
}