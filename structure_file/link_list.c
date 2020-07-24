// 連結リストを実装しよう (1)
#include <stdio.h>

typedef struct node {
  int num;
  // struct node へのポインタ型 *next変数
  // 構造体が自分自身のポインタを持っている。
  // このような構造体を自己参照構造体という。
  // 連結リストのデータ構造を定義するときに使う。
  // typedef で定義した Node 型をその場で使うとエラーになる
  // Node *next; だとエラーになる。
  struct node *next;
} Node;

int main(void)
{
  // ノードを宣言する
  Node node1 = {5, NULL};
  Node node2 = {9, NULL};
  Node node3 = {3, NULL};
  Node node4 = {7, NULL};
  
  // ノードをつなげる
  // 構造体のメンバの next に、次のノードのアドレスを代入しています。
  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;

  // 各ノードのデータを出力するには、次のように記述します。
  // *p に &node1 を代入
  Node *p = &node1;
  while (p != NULL) {
    // 一番初めの処理の時には p変数には、node1のポインタになっている。
    // p->num は node1.num と同じように使える。
    printf("%d\n", p->num);
    // ⬇︎は最初の処理の時には p->next は node1.next = &node2; と同じ動きをする。
    p = p->next;
  }
}
/* 上のwhileの流れ
  node1 = {5, &node2}; ➡︎ node2 = {9, &node3}; ➡︎ node3 = {3, &node4}; ➡︎ node4 = {7, NULL}; */
