/*009回文数



题目描述：

给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。



示例：
输入: 121
输出: true

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。


输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。


*/


/* 超时 */

bool isPalindrome(int x) {
	int result = 0,temp ;
	temp = x;
	if(x < 0)
		return false;
	while(temp)
	{
		result = result*10 + x%10;
		x /= 10;
	}
	if(result == x)
		return true;
	else
		return false;
}



/* 只取一半 */
bool isPalindrome(int x) {
    int result = 0;

    if(x < 0 || (x%10 == 0 && x!=0))
        return false;
    
    while(x > result)
    {
        result = result*10 + x%10;
        x /= 10;
    }

   /* 
   	return x==result || x ==result/10;
	return a && b 如果a是true的话，返回b，否则返回a
	return a || b 如果a是true的话，返回a，否则返回b 
	*/

	//如果是奇位数的话，12321，此时result=123，x=12，
    if(x==result || x ==result/10)
        return true;
    else
        return false;
}

