
/*14. �����ǰ׺
��Ŀ������
��дһ�������������ַ��������е������ǰ׺��

��������ڹ���ǰ׺�����ؿ��ַ��� ""��

ʾ�� 1:
	����: ["flower","flow","flight"]
	���: "fl"

ʾ�� 2:
	����: ["dog","racecar","car"]
	���: ""
	����: ���벻���ڹ���ǰ׺��

˵��:
��������ֻ����Сд��ĸ a-z 

*/
/* ˼·�ǣ��õ�һλ�������λ�Ƚϣ��ַ�һ����һ���ͽ�ֹ */
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
		while(temp[j] && strs[i][j] && (temp[j] == strs[i][j]) )//ǰ�����ֹ["",""]
		{
			j++;
		}
		temp[j] = '\0';
	}
	return temp;
}


