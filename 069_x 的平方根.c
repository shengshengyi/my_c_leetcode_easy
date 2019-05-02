/*69. x 的平方根
题目描述：
	实现 int sqrt(int x) 函数。

	计算并返回 x 的平方根，其中 x 是非负整数。

	由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。


示例1：
	输入: 4
	输出: 2

示例2：
	输入: 8
	输出: 2
	说明: 8 的平方根是 2.82842..., 
	     由于返回类型是整数，小数部分将被舍去。
*/

/*
	直接return INT_MAX;得到2 147 483 647，开方 46340
	Line 7: Char 34: runtime error: signed integer overflow: 46341 * 46341 cannot be represented in type 'int' (solution.c)
	??46341 * 46341 = 2 147 395 600没超出啊
	哦因为下面有i + 1超出了
	那就只能单独设置这种特殊情况
	  if(x>=46340*46340)
            return 46340;

执行用时 : 56 ms, 在Sqrt(x)的C提交中击败了26.72% 的用户
内存消耗 : 6.8 MB, 在Sqrt(x)的C提交中击败了70.32% 的用户
太慢了

*/
int mySqrt(int x)
{
	if(x>=46340*46340)
		return 46340;

	for(int i = 0;i <= 46340;i++)
	{
		if(((i * i) <= x) && (((i + 1) * (i + 1)) > x))
			return i;
	}

}


