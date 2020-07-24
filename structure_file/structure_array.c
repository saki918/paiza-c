// 構造体の配列をつくろう
#include <stdio.h>

typedef struct {
  char name[20];
  int attack;
} Enemy;

int main(void)
{
  Enemy slime = {"スライム", 10};
  Enemy monster = {"モンスター", 20};
  Enemy dragon = {"ドラゴン", 30};

  // 構造体の配列
  Enemy enemies[3];
  enemies[0] = slime;
  enemies[1] = monster;
  enemies[2] = dragon;

  for (int i = 0; i < 3; i++) {
    // 構造体の配列の要素からでもメンバにアクセスできる。
    printf("%sは勇者を攻撃した！%dのイメージ！\n", enemies[i].name, enemies[i].attack);
  }
}
