# csapp-self-learning
including the practice and homework as well as notes in the lesson learning process

在计算一个补码表示的负数,即求补码的非时,我们可以将位向量拆分为两部分:
从$x_{w-1},x_{w-2},...,x_{k+1},1,0,0,...,0$

以x的位级表示中最右边一位1为分割点,假设其位置为k
从而$-x = ~x_{w-1},~x_{w-2},...,~x_{k+1},1,0,0,...,0$ 
我们只需要将位k左边的所有位取反就得到了结果