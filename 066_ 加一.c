/*66. ��һ
��Ŀ������
	����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��

	���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢һ�����֡�

	����Լ���������� 0 ֮�⣬��������������㿪ͷ��


ʾ��1��
	����: [1,2,3]
	���: [1,2,4]
	����: ���������ʾ���� 123��


ʾ��2��
	����: [4,3,2,1]
	���: [4,3,2,2]
	����: ���������ʾ���� 4321��

ʾ��3��
	����: [9]
	���: [1,0]


ʾ��4��
	����: [1,9]
	���: [2,0]


*/

/* ��ʵ�����Ϸ�����������޽�λ�����鳤�Ȳ���Ľ�λ�����鳤�ȼ�1�Ľ�λ
 */

int* plusOne(int* digits, int digitsSize, int* returnSize) {

	int * result = (int *)malloc(sizeof(int) * (digitsSize + 1));
	int i;
	/* �����ж��Ƿ��λ���н�λ�� */
	for(i = 0;i < digitsSize;i++)
	{
		if(digits[i] != 9)
			break;
	}


	/* ȫ�����֤꣬������ȫΪ9 */
	if(i == digitsSize)
	{
		*returnSize = digitsSize + 1 ;
		result[0] = 1;
		for(int j = 1;j < digitsSize + 1;j++)
		{
			result[j] = 0;
		}
		return result;
	}

	/* ������һ�룬����һ��ʼ��break, Ҫ�Ӻ��濪ʼ��ֵ */
	i = digitsSize - 1;
	result[i] = digits[i] + 1;
	for(i;i > 0;i--)
	{
		if(result[i] == 10)//�н�λ
		{
			result[i] = 0;
			result[i - 1] = digits[i - 1] + 1;
		}
		else
			result[i - 1] = digits[i - 1];
	}
	
	*returnSize =digitsSize;

	return result;
}


