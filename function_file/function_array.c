// 関数の引数で配列を受け取ろう
#include <stdio.h>

/* a 変数を渡しただけで配列の要素を書き換えられた理由は、a 変数が「配列の先頭の要素のポインタ」に読み替えられるためです。
   add_one 関数は、渡されたポインタをもとに、配列の要素の値を書き換えることができます。
   *a のようにa[]は「配列の先頭の要素のポインタ」を持っているため値を書き換えられる。*/
void print(int a[]) {
  for (int i = 0; i < 5; i++) {
      printf("%d\n", a[i]);
  }
}

void add_one(int a[]) {
  for (int i = 0; i < 5; i++) {
      a[i]++;
  }
}

int main(void)
{
  int a[] = {1, 2, 3, 4, 5};
  
  // add_oneを記述した分だけ配列の値が１ずつ増えていく。
  add_one(a);
  add_one(a);
  print(a);
}
