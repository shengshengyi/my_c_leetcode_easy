
/* 20. 有效的括号
题目描述：
	给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

	有效字符串需满足：

	1、左括号必须用相同类型的右括号闭合。
	2、左括号必须以正确的顺序闭合。

	注意空字符串可被认为是有效字符串。

示例 1:
	输入: "()"
	输出: true

示例 2:
	输入: "()[]{}"
	输出: true

示例 3:
	输入: "(]"
	输出: false

示例 4:
	输入: "([)]"
	输出: false

示例 5:
	输入: "{[]}"
	输出: true


*/
/* ([{])这种也是错的！！ */
/* 这样就好解决了      ， 把所有 左括号入栈，遇到右括号与栈顶相比
	相对应就出栈，
	不对应false
	最后检查栈是否为空，空true，不空false
*/

bool isValid(char* s) 
{
    int length = 0;
    while(*(s + length)) length++;
	char* temp = (char*)malloc(sizeof(char) *length);//这里的长度最好为(length+1)/2的，但总是报错所以就取length

	/* 发现空字符串也为true */
    if(*s == '\0')	//if(strlen(s)==0);
    	return true;
	
	for(int i = 0;i < length;i++)
	{
		/* 左括号入栈 */
		if(s[i]=='(' || s[i]=='[' || s[i]=='{')
		{
			temp[k] = s[i];
			k++;
		}
		/* 右括号与栈顶对比，不对应出错，对应出栈 */
		else
		{
            if(k == 0)
                return false;           
			else 
            {   
                if((s[i] == ')' && temp[k-1] != '(' ) || (s[i] == '}' && temp[k-1] != '{' ) || (s[i] == ']' && temp[k-1] != '[' ))
                return false;				    
            }
            temp[k-1] = '\0';
		    k--;
        }
	}
    return strlen(temp)==0;
}

