### CSAPP-self-learning

including the practice and homework as well as notes in the lesson learning process

#### 数据存储
位向量一个很有效的应用就是==表示有限集合的编码==
如使用[01101001]表示集合$${0,3,5,6}$$
注意位向量的$a_0$写在最右边

掩码的概念:用于产生特定选出的位的集合 要注意掩码的可移植性
如~0 掩码和oxFFFFFFFF本质上还是不同的

#### 整数表示
关于two's complement的encoding,我们将字的最高有效位解释为negative weight,即负权重
这对帮助理解补码的T2B和表示范围有很大的帮助

对于非负数x,求解-x的补码表示 是通过$2^w - x$实现的
而求解-x的反码表示是通过$[111...1] - x$实现的 
对于32位机器,由八个16进制数字组成的num的最高位
==若为8~f之间的任何值都表示其为一个负数==

expand && truncate
size_t在stdio.h文件中定义为unsigned int的

#### 整数运算
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

##### IA32的体系结构

由于ISA是计算机组成的抽象,对于特定的ISA,需知:
1. 寄存器的个数及其功能
2. 寄存器宽度
3. 存储空间大小
4. 编址单位
5. 大端小端存放立即数?
6. 寻址方式
7. PC位数??


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

###### 程序的编码过程

考虑大型程序的编译 
-Og优化的原因：较高级别优化产生的代码会严重变形
对.o文件的理解：目标代码是机器代码的一种形式，其包含所有指令的二进制表示，只是还没有填入全局值的地址
在链接时，导入的库是static libraries
汇编指令只有字节大小方面的区分，1，2，4，8bytes...

得到汇编指令通过：1. objdump 2. gdb
%e版本只是%r版本的低32位

操作数指示符
立即数 + 寄存器 + 内存引用
###### 寻址模式
针对不同形式的memory 操作数引用
$Imm(r_b,r_i,s)$是最常用的比例变址寻址
其中的比例因子必须是1，2，4或者8
进行的是pointer dereferencing
而displacement 中R 表示的是the start of memory region

由于64位机器上称64位数为"quad word" 且大部分代码示例都使用了指针和long数据类型,所以都是四字操作,如movq

在进行寄存器与内存之间的数据传送时,需要通过总线传送

##### control
control the flow of execution of instructions 
可以根据条件码的某种组合,将一个字节设置为0或者1 set指令的目的操作数是==低位单字节寄存器元素==
`setg D` ~ZF&&~(SF^OF)  此时SF为0且OF为0 或者 如正数减去负数 得到正溢出OF为1,且SF为1 这两个情形不同时成立

`seta D`  当a > b时,CF为0,说明无借位
并且ZF标志不为0,说明a!=b
由于许多算术运算对无符号和补码算术都有相同的位级行为,所以机器代码如何区分有符号和无符号值是很重要的

###### 跳转指令的编码
无论是汇编器还是链接器产生的结果
PC相对寻址 看指令的字节编码
用数据的条件转移来代替控制的条件转移
即用条件传送指令实现条件分支

执行开关语句的时间与开关情况的数量无关

##### procedures

过程,方法,子例程,处理函数这些都是过程在软件中的抽象
提供对过程的机器级支持
1. passing control: 通过程序计数器设置被调用函数的起始地址以及返回后原函数应当指向的下一条指令的地址
2. passing data: 参数与返回值
3. memory management:针对局部变量的空间分配与释放

第七个或以上的参数放入调用函数P的栈帧中
当前正在执行的过程的帧总是在栈顶

##### data
Besides manipulating integers or long integers or pointers,which are all ==scaler data==,即标量数据，we can aggregate them into a bigger form,聚集成更大的数据类型。

###### 数组分配和访问

C语言可以产生指向数组中元素的指针，并对这些指针进行运算，也即通过array identifier 操作指针

###### 指针运算

需要注意的是，我们不能改变标识符A的大小，since it’s a const value.可以进行

```c
val+1;//可以
val++;//非法
```

```c
int E[5];
&E[i] - E;//结果是i，且类型为long，为两个地址之差除以该数据类型的大小
*(type) //the type is T*,为指针类型
```

需要注意的是，对于不同的操作对象，`int or int*` 汇编层面的效果是不同的，涉及四字节的`movl %eax`

涉及八字节的`leaq %rax` 

###### Pointers & Arrays

数组在进行声明时，除了为数组名分配了对应的地址空间用于索引，同时分配了实际大小的数组元素空间，这些是在内存中可以被实际访问到的

Bad 表示空指针引用 `sizeof(A1)==12 sizeof(A2)== 8`

![image-20231114180707849](C:\Users\WESLEY\AppData\Roaming\Typora\typora-user-images\image-20231114180707849.png)

对非指针类型的数组名进行连续两次解引用是不会通过编译的
指针数组or 指向数组的指针 在没有括号时，数组[]的优先级是高于*指针命名的优先级的
`int *(A3) [3]` :声明一个指针，指向一个int[3]的数组
==但这个数组并没有实际被分配内存空间，可能造成空指针引用==

###### nested arrays
Row-major Ordering 嵌套数组和定长数组的汇编引用会产生不同

###### 异质的数据结构
Fields ordered according to declaration,不同的字段之间可以被编译器明确地区分
determined at compile time
注意数组的索引查询时要将4字节的eax寄存器符号位扩展到八字节 movslq
现代操作系统每次取字节都是一次性取出多个(如64)字节，防止其在访问同一数据结构时出现多次重新取值的麻烦
we need Alignment!
通过末尾  0 的个数判断对齐方式

考虑the largest Alignment we need to satisfy,我们要保证整体的地址对齐满足K的倍数
==对于arrays of Structure== 这样的处理是很有效的

将大数据优先声明在前面，是一种最大化节省空间的贪心算法

###### 缓冲区溢出
允许使用47位地址 已被使用的地址有48位
128T的内核空间 与 128T的用户空间
分析7fffffffffff的来源 就是指128T的用户空间
在linux中，栈就是从最高端向下延展的，共有8MB runtime stack
也就是==栈溢出的核心矛盾==

descriptor table && file table && v-node table
从Exception Control Flows 出发,理解进程与fork的概念
the nested Fork matters!

How to implement I/O redirection???

#### Linking
加载器负责复制入内存
实现separate compilation 分离编译
符号解析用于关联符号引用和符号定义