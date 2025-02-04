{{ self.title() }}

{{ s('background') }}

小Y喜欢喝可乐。

{{ s('description') }}

一天，小 L 送给了小 Y 一箱可乐，这项可乐一共有 $K$ 瓶，每瓶可乐有一个口感值 $a_i=C-(2i-1)$（其中 $C$ 为给定的一个偶数，$i$ 为可乐的序号）。

小 Y 非常喜欢喝冰可乐，于是她去商店购买了$K$ 个冰块，每个冰块的大小为 $b_i=C+(2i-1)$（$i$ 为冰块的序号）。

作为喝冰可乐的专家，小 Y 也十分讲究冰块与可乐的搭配。由她的经验，往可乐中放入大小与其口感值互质的冰块可以让该可乐拥有最佳的味道。

现在小 Y 想知道如何搭配可乐与冰块才能最大化达到最佳味道的可乐数量，但送她可乐的小L忙着去看《すずめの戸締まり》去了，所以请你代替小 L 回答这个问题。

{{ s('input format') }}

共一行，输入两个整数 $C,K$ 含义如体面所示

{{ self.input_file() }}

{{ s('output format') }}

共 $K+1$ 行。

第一行一个整数，代表最大的达到最佳味道的可乐数量。

第 $2$ 到 $K+1$ 行，顺序输出当前情况下每瓶可乐中放入的冰块的编号（若有多种方案，则任意输出一种即可）。

{{ self.output_file() }}

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('sample', 2) }}

{{ self.sample_file() }}

{{ s('sample', 3) }}

{{ self.sample_file() }}

{{ s('subtasks') }}

特殊性质：$C=2K$.

{{ tbl('data') }}

{{ s('scoring') }}

本题开启 SPJ，若第一行正确但后续的方案错误，将会得到 10% 的分数。

{{ s('hint') }}

本题下发了 checker.exe，请按照以下方式使用：

`checker.exe [输入文件的路径] [输出文件的路径] [答案文件的路径]`