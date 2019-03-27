/*007整数反转

题目描述：给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例：
	输入: 123
	输出: 321

	输入: -123
	输出: -321


	输入: 120
	输出: 21

*/


int reverse(int x) {
	
	long rev = 0;

	while(x)
	{
		rev = 10*rev + x%10;
		x /= 10;		
	}
	  return (rev > INT_MAX || rev < INT_MIN) ? 0 : (int)rev ;
}


