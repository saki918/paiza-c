// 構造体を作成しよう
#include <stdio.h>

// 構造体の宣言 struct を記述
// 今回の場合のplayerを構造体タグという。
struct player {
  // 構造体の中の変数をメンバという。
  char name[20];
  int hp;
  int power;
};
// 構造体の宣言の最後にはセミコロンが必要。

int main(void)
{
  // 構造体を使うには、struct 構造体タグ 変数名 = {};
  // {}内の変数は定義したメンバの順番に記述する。
  struct player hero = {"勇者", 100, 100};
  struct player wizard = {"魔法使い", 80, 120};

  // 変数のメンバの表示は、変数.メンバ
  printf("%s：HP %d, 攻撃力 %d\n", hero.name, hero.hp, hero.power);
  printf("%s：HP %d, 攻撃力 %d\n", wizard.name, wizard.hp, wizard.power);
}
