// 2 次元配列で地図をつくろう １
#include <stdio.h>

int main(void)
{
    char world_map[9][19];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 19; j++) {
          if (i % 2 == 0 || j % 3 == 0) {
                world_map[i][j] = '.';
            } else {
                world_map[i][j] = '#';
            }
        }
    }

    world_map[0][0] = 'S';
    world_map[0][18] = '@';
    world_map[8][18] = 'G';

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 19; j++) {
            // char 型の文字は printf の変換指定子に %c を使うことで出力できます
            printf("%c", world_map[i][j]);
        }
        printf("\n");
    }
}