// 何もしないプログラム

/* では、C言語の構造とは、一体どのような構造なのでしょうか？
機械を作るときは、様々な部品を組み合わせて作ります。
同じように、プログラミングでも部品を組み合わせます。この部品のことを**関数**と呼びます。
つまり、C言語のプログラムは、関数が集まって作られているのです。 */

/* 関数の構造
型名 関数名(引数)｛処理｝ */

/* 引数とは、関数に渡す数値の種類のことです。
関数は、渡された数値を元に計算を行って結果を返すことが出来ます。
しかし、始めに述べたように、今回の目的は、何もしないプログラムを作ることです。
何もしないプログラムに、情報を渡す必要はないでしょう。
そこで、情報がないことを表す、void(ボイド)を使用することにします。 */

/* 処理とは、その名の通りの処理のことです。
始めに述べたように、今回の目的は、何もしないプログラムを作ることなのですが、
今回、唯一しなくてはならない処理として、関数を終了させる処理があります。
関数を終了させるには、return(リターン)文を使用します。
なお、return文には計算結果の数値を返す機能があるのですが、
今回は何もしないプログラムなので、とりあえず0にしておきます。 */

int main(void) {return 0;}

/* コンパイルの流れ
Ｃ言語のプログラム、ソースコード
  Ｖ
プリプロセス（文字列の調整）
まず、始めにプリプロセッサというソフトにより、文字列の調整が行われます。
空白や改行の結合、記号の置き換えなどを行いプログラムを解析しやすくします。
また、後述する#define疑似命令などもここで処理されています。
  Ｖ
コンパイル（翻訳）
  Ｖ
リンク（結合）
翻訳した機械語プログラムが、リンカというソフトによって結合されます。
リンカで結合することを、リンクと呼びます。
リンクされることで、マシン語のデータが、実行可能ファイルになります。
  Ｖ
実行可能なソフトウェア、実行可能ファイル

※プリプロセス、コンパイル、リンクをまとめてコンパイルと呼ぶことがある。
  また、実行可能ファイルを作成することまでまとめてビルドと呼ぶことがある。 */