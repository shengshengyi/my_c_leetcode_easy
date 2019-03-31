
/* 
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。
				27 写做  XXVII, 即为 XX + V + II 。

				
通常情况下，罗马数字中小的数字在大的数字的右边。
但也存在特例，例如 4 不写做 IIII，而是 IV。
数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。
同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。


给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

示例 1:
	输入: "III"
	输出: 3

示例 2:
	输入: "IV"
	输出: 4

示例 3:
	输入: "IX"
	输出: 9

示例 4:
	输入: "LVIII"
	输出: 58
	解释: L = 50, V= 5, III = 3.

示例 5:
	输入: "MCMXCIV"
	输出: 1994
	解释: M = 1000, CM = 900, XC = 90, IV = 4.

*/
#define num_I	1
#define num_V	5
#define num_X	10
#define num_L	50
#define num_C	100
#define num_D 	500
#define num_M 	1000



/* 因为有六种特殊情况，需要单独拿出来(s+2)，剩余的情况(s+1)就逐个判断对应值就行 */
int romanToInt(char* s) {
	int num = 0;
	while(*s != NULL)
	{
		if((*s == 'I' ) && (*(s + 1) == 'V' ))
		{
			num +=	(num_V - num_I);
			s 	+= 2;
		}
		
		else if((*s == 'I' ) && (*(s + 1) == 'X' ))
		{
			num +=	(num_X - num_I);
			s 	+= 2;
		}

		else if((*s == 'X' ) && (*(s + 1) == 'L' ))
		{
			num +=	(num_L - num_X);
			s 	+= 2;
		}
		
		else if((*s == 'X' ) && (*(s + 1) == 'C' ))
		{	
			num +=	(num_C - num_X);
			s 	+= 2;
		}
		
		else if((*s == 'C' ) && (*(s + 1) == 'D' ))
		{
			num +=	(num_D - num_C);
			s 	+= 2;
		}
		
		else if((*s == 'C' ) && (*(s + 1) == 'M' ))
		{
			num +=	(num_M - num_C);
			s 	+= 2;
			
		}
		else
		{
			switch (*s)
			{
				case 'I':	
					num +=num_I;
					s += 1;
					break;
				
				case 'V':	
					num +=num_V;
					s += 1;
					break;
				
				case 'X':	
					num +=num_X;
					s += 1;
					break;

				case 'L':	
					num +=num_L;
					s += 1;
					break;

				case 'C':	
					num +=num_C;
					s += 1;
					break;

				case 'D':	
					num +=num_D;
					s += 1;
					break;
				
				case 'M':	
					num +=num_M;
					s += 1;
					break;
			}
		}
	}
	return num;
}

