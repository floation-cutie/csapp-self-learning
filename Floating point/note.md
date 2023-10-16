1. Background : the fractional binary numbers… the properties and limitations

2. the normalized form uses the ==implied leading 1== as the interpretation of the frac section. And when we talk about the topic of denormalized form of floating point,the encoding scheme has changed… E = 1 - Bias Frac = f = M (which without the implied leading 1 instead) This situation comes with a desire for representing the number closer to zero,
   **gradual underflow** 
   For the **special value**,the exp is 1111…111 ,the frac is 0,means INFINITY.
   所有的数字溢出后都会到达INFINITY.之后对于其的任何运算都还是INFINITY….
   If the frac is not 0,`NaN`(not a number)..
   在浮点数的表示中,可表示的数并不是均匀分布在数轴上的,越靠近原点处它们越稠密

3. try a visualization and build a small floating system where we can enumerate all the possibilities..

   The interesting is that denormalized numbers are **evenly distributed** surrounding 0…

   And why we use E = 1 - Bias???  We can get a smooth transition from `denom` to norm by keeping the exponent unchanged….

4. SPEICAL properties of the IEEE encoding
   By treating it like a unsigned comparison,即解释为无符号整数,我们可以用整数排序函数来对浮点数进行排序

   1. First,must compare sign bits
   2. Must consider  -0 = 0
   3. with the exception of Not a Number circumstances…