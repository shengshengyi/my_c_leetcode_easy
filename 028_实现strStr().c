/*28. ʵ��strStr()
��Ŀ������
	ʵ�� strStr() ������

	����һ�� haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)����������ڣ��򷵻�  -1��

ʾ��1��
	����: haystack = "hello", needle = "ll"
	���: 2

ʾ�� 2:
	����: haystack = "aaaaa", needle = "bba"
	���: -1

˵��:
	�� needle �ǿ��ַ���ʱ������Ӧ������ʲôֵ�أ�����һ���������кܺõ����⡣

	���ڱ�����ԣ��� needle �ǿ��ַ���ʱ����Ӧ������ 0 ������C���Ե� strstr() �Լ� Java�� indexOf() ���������
	
*/

/*˫ָ�룬iָ��haystack��jָ��needle����λ�Աȣ�
 *����ȷ����������
 * 	1��һֱ����ȣ�����Ҳ����ȣ�jͣ�ڵ�0λ��iָ����һλ
 * 	2��ǰ����ȣ�ͻȻ����ȣ�jָ�����ص�0λ��iָ���ϴο�ʼ���ʱ��λ������һλ
 * 		����dbaba��baa�� haystack[3] != needle[2],���ʱ��j���ص�0λ��i�ص�haystack[2]�������λ�ÿ�ʼ���±Ƚ�
 *	���Զ��ڵڶ��������i = i - j + 1��
 *	���������������ڵ�һ������ʲ����ã�
 *	��Ϊ��һ���������һֱ����Ȼ����ǵ�һ�β���ȵ��������ʱ��j = 0��i = i + 1;
 *	��������õ�
 *���j��iͬʱָ����һλ
 *������needle == NULL˵�����ظ��ģ����ص�һ�γ��ֵ�λ�ã�i = i - j
 */
int strStr(char* haystack, char* needle) {

	int i = 0,j = 0, len_haystack = 0,len_needle = 0;
//	while(*(haystack + len_haystack))	len_haystack++;
//	while(*(needle + len_needle))		len_needle++;
//	���ﲻ��forѭ��

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
			//i�Ȼ�ȥ��j���ܻ�0
		}
	}
	
	if(needle[j] == NULL)
		return i - j;
	else
		return -1;
	
}



