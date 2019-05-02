/*66. 加一
题目描述：
	给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

	最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

	你可以假设除了整数 0 之外，这个整数不会以零开头。


示例1：
	输入: [1,2,3]
	输出: [1,2,4]
	解释: 输入数组表示数字 123。


示例2：
	输入: [4,3,2,1]
	输出: [4,3,2,2]
	解释: 输入数组表示数字 4321。

示例3：
	输入: [9]
	输出: [1,0]


示例4：
	输入: [1,9]
	输出: [2,0]


*/

/* 其实总体上分三种情况：无进位，数组长度不变的进位，数组长度加1的进位
 */

int* plusOne(int* digits, int digitsSize, int* returnSize) {

	int * result = (int *)malloc(sizeof(int) * (digitsSize + 1));
	int i;
	/* 首先判断是否进位，有进位则 */
	for(i = 0;i < digitsSize;i++)
	{
		if(digits[i] != 9)
			break;
	}


	/* 全遍历完，证明数组全为9 */
	if(i == digitsSize)
	{
		*returnSize = digitsSize + 1 ;
		result[0] = 1;
		for(int j = 1;j < digitsSize + 1;j++)
		{
			result[j] = 0;
		}
		return result;
	}

	/* 遍历到一半，或者一开始就break, 要从后面开始赋值 */
	i = digitsSize - 1;
	result[i] = digits[i] + 1;
	for(i;i > 0;i--)
	{
		if(result[i] == 10)//有进位
		{
			result[i] = 0;
			result[i - 1] = digits[i - 1] + 1;
		}
		else
			result[i - 1] = digits[i - 1];
	}
	
	*returnSize =digitsSize;

	return result;
}


