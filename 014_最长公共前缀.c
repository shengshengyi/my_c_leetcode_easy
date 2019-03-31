
/*14. 最长公共前缀
题目描述：
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:
	输入: ["flower","flow","flight"]
	输出: "fl"

示例 2:
	输入: ["dog","racecar","car"]
	输出: ""
	解释: 输入不存在公共前缀。

说明:
所有输入只包含小写字母 a-z 

*/
/* 思路是，用第一位与后续逐位比较，字符一旦不一样就截止 */
char* longestCommonPrefix(char** strs, int strsSize)
{
	int i,j;
	char* temp;
	temp = strs[0];
	
	if(strsSize <= 0)
		return "";	  
	
	
	for(i  = 1;i < strsSize;i++)
	{
		j = 0;
		while(temp[j] && strs[i][j] && (temp[j] == strs[i][j]) )//前两项防止["",""]
		{
			j++;
		}
		temp[j] = '\0';
	}
	return temp;
}


