// RPGの攻撃シーンをつくろう
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void attack(char target[]) {
    // 1~10のランダムな数
    int hit = rand() % 10 + 1;
    if (hit > 6) {
        printf("クリティカルヒット！ %sに100のダメージを与えた！\n",target);
        // 関数を定義するときのテクニックの 1 つに「早期リターン」があります。
        // 関数内にreturnを記述するとそこで関数の処理が終了する。
        // void を指定した関数は、単に「return;」と記述するだけで処理を終了できます。
        return;
    }
    printf("%sに%dのダメージを与えた\n", target,hit);
}

int main(void)
{
    char slime[] = "スライム";
    char monster[] = "モンスター";
    char dragon[] = "ドラゴン";

    // srand で引数の値をもとにランダムな数を初期化しています。
    srand(time(NULL));

    attack(slime);
    attack(monster);
    attack(dragon);
}
