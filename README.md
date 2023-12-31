# csapp-self-learning
including the practice and homework as well as notes in the lesson learning process

#### 整数运算:
在计算一个补码表示的负数,即求补码的非时,我们可以将位向量拆分为两部分:
从$x_{w-1},x_{w-2},...,x_{k+1},1,0,0,...,0$

以x的位级表示中最右边一位1为分割点,假设其位置为k
从而$-x = ~x_{w-1},~x_{w-2},...,~x_{k+1},1,0,0,...,0$ 
我们只需要将位k左边的所有位取反就得到了结果

SF标志是CPU对==有符号数==运算结果的一种记录,SF为1时,标志着运算结果为负

无符号乘法是将产生的2w位的结果截断为w位
补码乘法:需要知道无符号和补码两种乘法乘积的真正2w位表示是不同的,
但截断为w位后,乘法的位级便具有了等价性

无符号整数左移一个数值等价于执行一个与2的幂相乘的无符号乘法

#### machine-level programming

##### basics
为了简化对指令功能的说明,有时采用寄存器传送语言说明 RTL

如将寄存器EBP中的内容与4相加得到的地址对应的两个连续存储单元的内容送入AX寄存器中
每条机器指令由若干字段组成,机器指令的实质是位串
将其分为不同字段 
```mov D<表示reg字段给出的是源操作数还是目的操作数> W<长度> mod reg r/m disp8``` 其中mov等都是==汇编助记符==


对于shark machine,我们有四核shared L3 cache共享的缓存
对于machine programmer来说，可视化的有：
1. 程序计数器（%rip）：下一条指令在内存中的地址
==机器级程序使用的内存地址是虚拟地址==
2. Condition codes(条件码寄存器)
Store status information about most recent arithmetic or logical operation，
用于conditional branching
3. 寄存器文件...
4. 程序内存(memory)
很大的字节数组中记录
   1. 程序的可执行机器代码
   2. 基本信息
   3. 管理过程调用和返回的运行时栈runtime stack

cache是不可见的，programmer无法直接操作或访问cache

##### 程序的编码过程

考虑大型程序的编译 
-Og优化的原因：较高级别优化产生的代码会严重变形
对.o文件的理解：目标代码是机器代码的一种形式，其包含所有指令的二进制表示，只是还没有填入全局值的地址
在链接时，导入的库是static libraries
汇编指令只有字节大小方面的区分，1，2，4，8bytes...

得到汇编指令通过：1. objdump 2. gdb
%e版本只是%r版本的低32位

操作数指示符
立即数 + 寄存器 + 内存引用
##### 寻址模式
针对不同形式的memory 操作数引用
$Imm(r_b,r_i,s)$是最常用的比例变址寻址
其中的比例因子必须是1，2，4或者8
进行的是pointer dereferencing
而displacement 中R 表示的是the start of memory region