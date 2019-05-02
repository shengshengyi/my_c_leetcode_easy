/*67. ���������
��Ŀ������
	���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����

	����Ϊ�ǿ��ַ�����ֻ�������� 1 �� 0��

ʾ��1��
	����: a = "11", b = "1"
	���: "100"

ʾ��2��
	����: a = "1010", b = "1011"
	���: "10101"
111
111

*/

#define max(a,b)((a) > (b) ? (a) : (b))
char * addBinary(char * a, char * b)
{
	if(a == NULL || *a == NULL)
		return b;
	if(b == NULL || *b == NULL)
		return a;	

	int flag = 0;
	int len_a = strlen(a),len_b = strlen(b);
	int len = max(len_a,len_b) + 2;
	char * result = (char *)malloc(sizeof(char) * (len));
	result[len - 1] = '\0';
	int i = 0,j = 0,index = len - 2 ;

	while(len_a || len_b || flag)
	{
		int t = flag;
		if(len_a)
			t += (a[--len_a] - '0');
		if(len_b)
			t += (b[--len_b] - '0');
		flag = t/2;

		result[index--] = '0' + t % 2;
	}

	/* "0" "0" ��һ�β��Ǻܶ�*/
	if(index == 0)
	{
		char * temp = (char *)malloc(sizeof(char) * (len - 1));
		memcpy(temp,result + 1,(len - 1) * sizeof(char));
		free(result);
		return temp;
	}
	
	return result;
}


