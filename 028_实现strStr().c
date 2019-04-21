/*28. 实现strStr()
题目描述：
	实现 strStr() 函数。

	给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例1：
	输入: haystack = "hello", needle = "ll"
	输出: 2

示例 2:
	输入: haystack = "aaaaa", needle = "bba"
	输出: -1

说明:
	当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

	对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
	
*/

/*双指针，i指向haystack，j指向needle，逐位对比，
 *不相等分两种情况：
 * 	1、一直不相等，现在也不相等，j停在第0位，i指向下一位
 * 	2、前面相等，突然不相等，j指针跳回第0位，i指向上次开始相等时的位数的下一位
 * 		比如dbaba和baa， haystack[3] != needle[2],这个时候，j跳回第0位，i回到haystack[2]，从这个位置开始重新比较
 *	所以对于第二种情况，i = i - j + 1；
 *	现在来看这样对于第一种情况适不适用，
 *	因为第一种情况处于一直不相等或者是第一次不相等的情况，这时候j = 0；i = i + 1;
 *	因此是适用的
 *相等j，i同时指向下一位
 *最后如果needle == NULL说明有重复的，返回第一次出现的位置，i = i - j
 */
int strStr(char* haystack, char* needle) {

	int i = 0,j = 0, len_haystack = 0,len_needle = 0;
//	while(*(haystack + len_haystack))	len_haystack++;
//	while(*(needle + len_needle))		len_needle++;
//	这里不用for循环

	if(needle == NULL)	return 0;

	while (haystack[i] && needle[j])
	{
		if(haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
			//i = i - j + 1;
			//i先回去，j才能回0
		}
	}
	
	if(needle[j] == NULL)
		return i - j;
	else
		return -1;
	
}



