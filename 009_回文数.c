/*009������



��Ŀ������

����һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��



ʾ����
����: 121
���: true

����: -121
���: false
����: �������Ҷ�, Ϊ -121 �� ���������, Ϊ 121- �����������һ����������


����: 10
���: false
����: ���������, Ϊ 01 �����������һ����������


*/


/* ��ʱ */

bool isPalindrome(int x) {
	int result = 0,temp ;
	temp = x;
	if(x < 0)
		return false;
	while(temp)
	{
		result = result*10 + x%10;
		x /= 10;
	}
	if(result == x)
		return true;
	else
		return false;
}



/* ֻȡһ�� */
bool isPalindrome(int x) {
    int result = 0;

    if(x < 0 || (x%10 == 0 && x!=0))
        return false;
    
    while(x > result)
    {
        result = result*10 + x%10;
        x /= 10;
    }

   /* 
   	return x==result || x ==result/10;
	return a && b ���a��true�Ļ�������b�����򷵻�a
	return a || b ���a��true�Ļ�������a�����򷵻�b 
	*/

	//�������λ���Ļ���12321����ʱresult=123��x=12��
    if(x==result || x ==result/10)
        return true;
    else
        return false;
}

