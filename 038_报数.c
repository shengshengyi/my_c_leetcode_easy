c/*38.报数
题目描述：
	报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
	1.     1
	2.     11
	3.     21
	4.     1211
	5.     111221

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。

示例1：
	输入: 1
	输出: "1"

示例2：
	输入: 4
	输出: "1211"

我的理解就是下一行把上行的数字描述出来
比如上行是23332
那么下行就是1个2，3个3，1个2:
123312

*/
/*	首先需要两个for循环，外面的用于不同行，里面的用于同一行
	里for	对比逐次两个数，相等count++(初值1)，知道出现不等的情况，赋值
	怎么赋值：表示出现次数的count放到前面,temp[j++] = count，然后是那个数出现了count，就是当下对比的两个数的前者,temp[j++] = cur[i-1]。并且count回1
	对比到最后我们发现，出现两种情况
	1、最后两个数相同，count > 1，最后一项还未赋值
	2、最后两个数不用，count = 1，最后一项同样未赋值
	所以需要在里for外面，也就是外for赋值，怎么赋值？和里for差不多，表示次数的count放到前面,temp[j++] = count，
	最后一位表示是哪个数出现count次，和里for不同的是，这里直接取上个数组最后一位就行了：temp[j] = cur[len - 1];

*/
char* countAndSay(int n)
{

    if(n == 1) return "1";

    char * cur = malloc(2);
    char * temp;
    cur[0] = '1';
    cur[1] = 0;

    int len, idx, j, count;
    for(int i = 2; i <= n; i++)//不同行
    {
        len = strlen(cur);
        temp = malloc(3 * len);
        memset(temp, 0, 3 * len);
        count = 1;
        for(idx = 1, j = 0; idx < len; idx++)//同一行
        {
            if(cur[idx] == cur[idx - 1]) count++;
            else 
            {
                temp[j++] = '0' + count;
                temp[j++] = cur[icdx - 1];
                count = 1;
            }
        }
        temp[j++] = '0' + count;
        temp[j] = cur[len - 1];
        free(cur);
        cur = temp;
    }
    return cur;
}

