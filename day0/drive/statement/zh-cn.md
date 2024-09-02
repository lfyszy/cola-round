{{ self.title() }}

{{ s('background') }}

> Yeah, I can’t do these long drives sitting in the back seat.
> 
> 
> Thinking’bout that one night when the world caught fire.
> 
> Baby, and your eyes brightened up this dark scene.
> 
> You told me I would be fine, I called you a liar.
> 

{{ s('description') }}

小 L 正准备去找小 Y 玩，但路途遥远，小L准备开着他自己研发的汽车去找小Y。

小 L 的汽车由一种神奇的魔法驱动，它是依赖一个特殊的信号序列运行。

在操作前，小 L 已经拥有了一个速度值为一的魔法球。

这种魔法会从头到尾读取信号序列中的每一个数，并且根据以下序列做出相应操作：

1. 若该项为 $1$，则生成一个速度值为一的魔法球。
2. 若该项为 $-1$，则将已有的两个魔法球合并，其速度值为原先两个球速度值之和（如果无法进行此操作，则小L的汽车无法启动）。
3. 若该项为 $0$，则可以自由决定进行以上两个操作之一。

在操作完之后，汽车的速度即为所有魔法球速度的平均值。

小 L 害怕像贵树君那样迟到太久，所以他想尽可能地提高汽车的速度，但他还在看《秒速5センチメートル》，所以请你帮他规划操作 3 的选取，使得汽车的速度最大。

{{ s('input format') }}

{{ self.input_file() }}

本题有多组测试数据。

第一行一个整数 $T$，代表数据的组数。

对于每一组数据：

第一行一个整数 $N$，表示信号串的长度。

第二行输入一个由 $N$ 个在 $-1$ 到 $1$ 之间的整数组成的信号序列，含义如题面所示。

{{ s('output format') }}

{{ self.output_file() }}

对于每组数据：

输出一行，如果汽车无法启动，输出 $-1$；否则输出两个整数，代表汽车速度在分数表示下的分子与分母，**注意该分数需要化成最简形式**

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

对于第一组数据，按题意模拟即可。

对于第二组数据，两个三操作依次为生成一个魔法球与合并两个魔法球。

对于第三组数据，不存在可行的解。

对于第四组数据，操作为添加一个魔法球。

对于第五组数据，操作依次为生成一个魔法球与合并两个魔法球。

对于第六组数据，操作为添加一个魔法球。

{{ s('sample', 2) }}

{{ self.sample_file() }}

{{ s('subtasks') }}

保证信号序列中不存在 $0$。

{{ tbl('data') }}
