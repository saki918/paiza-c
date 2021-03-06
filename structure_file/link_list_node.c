// 連結リストを実装しよう (2)
#include <stdio.h>

typedef struct node {
  int num;
  struct node *next;
} Node;

void print_list(Node *top)
{
  Node *p = top;
  while (p != NULL) {
    printf("%d\n", p->num);
    p = p->next;
  }
  printf("\n");
}
int main(void)
{
  Node node1 = {5, NULL};
  Node node2 = {9, NULL};
  Node node3 = {3, NULL};
  Node node4 = {7, NULL};

  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;

  print_list(&node1);
  
  // ノードを追加する
  Node node5 = {2, NULL};
  node5.next = &node2;
  node1.next = &node5;
  
  print_list(&node1);
  
  // ノードを削除する
  node3.next = NULL;
  node2.next = &node4;
  
  print_list(&node1);
}

/* 連結リストを関数を通して操作する場合、例えば以下のようになります。

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int num;
  struct node *next;
} Node;

// リストを初期化
Node* init()
{
  // ダミーノードを用意
  Node *dummy = malloc(sizeof(Node));
  dummy->next = NULL;
  return dummy;
}

// p の後ろにノードを追加
void insert_after(Node *p, int num)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->num = num;

  if (p == NULL) {
    printf("エラー：追加する位置にノードが存在しません\n");
    return;
  }

  new_node->next = p->next;
  p->next = new_node;
}

// p の後ろのノードを削除
void delete_after(Node *p)
{
  if (p == NULL || p->next == NULL) {
    printf("エラー：削除するノードが存在しません\n");
    return;
  }

  Node *tmp = p->next->next;
  free(p->next);
  p->next = tmp;
}

// top の後ろのノードを出力
void print_list(Node *top)
{
  if (top == NULL) {
    printf("エラー：リストが初期化されていません\n");
    return;
  }

  Node *p = top->next; // ダミーノードの次のノードから出力する
  while (p != NULL) {
    printf("%d\n", p->num);
    p = p->next;
  }
  printf("\n");
}

int main(void)
{
  // リストを初期化
  Node *top = init();

  // 5 => 9 => 3 => 7 の順番でノードを追加
  Node *p = top;
  insert_after(p, 5);
  p = p->next;
  insert_after(p, 9);
  p = p->next;
  insert_after(p, 3);
  p = p->next;
  insert_after(p, 7);

  print_list(top);

  // ノードを追加する
  p = top->next;
  insert_after(p, 2); // p の後ろの 2 の値を持つノードを追加する

  print_list(top);

  // ノードを削除する
  p = top->next->next->next;
  delete_after(p); // p の後ろにノードがあれば、そのノードを削除する

  print_list(top);
}

main 関数では、リストの操作を、p 変数と関数を使っておこなっています。

以下のような関数が新たに追加されています。

○ init() : 「ダミーノード」と呼ばれるデータを持たないノードを用意する関数です。
・連結リストを、ダミーノードが 1 つだけ存在する状態にすることで、初期化しています。
・ダミーノードをリストの先頭に配置することで、リストの先頭にデータを追加しやすくなります。

○ insert_after(Node *p, int num) : p 変数が指し示すノードの後ろに、num の値を持つノードを追加する関数です。

○ delete_after(Node *p) : p 変数が指し示すノードの 1 つあとのノードを削除する関数です。 */