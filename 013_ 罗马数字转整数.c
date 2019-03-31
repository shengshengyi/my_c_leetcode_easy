
/* 
�������ְ������������ַ�: I�� V�� X�� L��C��D �� M��

�ַ�          ��ֵ
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

���磬 �������� 2 д�� II ����Ϊ�������е� 1��12 д�� XII ����Ϊ X + II ��
				27 д��  XXVII, ��Ϊ XX + V + II ��

				
ͨ������£�����������С�������ڴ�����ֵ��ұߡ�
��Ҳ�������������� 4 ��д�� IIII������ IV��
���� 1 ������ 5 ����ߣ�����ʾ�������ڴ��� 5 ��С�� 1 �õ�����ֵ 4 ��
ͬ���أ����� 9 ��ʾΪ IX���������Ĺ���ֻ�������������������

I ���Է��� V (5) �� X (10) ����ߣ�����ʾ 4 �� 9��
X ���Է��� L (50) �� C (100) ����ߣ�����ʾ 40 �� 90�� 
C ���Է��� D (500) �� M (1000) ����ߣ�����ʾ 400 �� 900��


����һ���������֣�����ת��������������ȷ���� 1 �� 3999 �ķ�Χ�ڡ�

ʾ�� 1:
	����: "III"
	���: 3

ʾ�� 2:
	����: "IV"
	���: 4

ʾ�� 3:
	����: "IX"
	���: 9

ʾ�� 4:
	����: "LVIII"
	���: 58
	����: L = 50, V= 5, III = 3.

ʾ�� 5:
	����: "MCMXCIV"
	���: 1994
	����: M = 1000, CM = 900, XC = 90, IV = 4.

*/
#define num_I	1
#define num_V	5
#define num_X	10
#define num_L	50
#define num_C	100
#define num_D 	500
#define num_M 	1000



/* ��Ϊ�����������������Ҫ�����ó���(s+2)��ʣ������(s+1)������ж϶�Ӧֵ���� */
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

