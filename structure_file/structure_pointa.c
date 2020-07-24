// 構造体とポインタ
#include <stdio.h>

typedef struct {
  char name[20];
  int hp;
  int power;
} Player;

// 引数をポインタで設定
void heal(Player *player)
{
  // 構造体へのポインタを使ってメンバを書き換えるには、次のように記述します。
  // *playerは()で囲む
  // (*player).hp += 100;
  
  // (*player).hp += 100;の代わりに、「アロー演算子」を使って以下のように書くことができます。
  // データ型 -> メンバ = oo;
  player -> hp += 100;
}
int main(void)
{
  Player hero = {"勇者", 100, 100};
  
  printf("%sのHPは%dです\n", hero.name, hero.hp);
  
  // heal関数の引数をポインタで設定しているので、アドレス(&変数)で設定する。
  heal(&hero);
  heal(&hero);
  printf("%sのHPは%dです\n", hero.name, hero.hp);
}
