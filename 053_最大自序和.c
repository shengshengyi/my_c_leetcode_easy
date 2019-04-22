/*53. ��������
��Ŀ������
	����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

ʾ����
	����: [-2,1,-3,4,-1,2,1,-5,4],
	���: 6
	����: ���������� [4,-1,2,1] �ĺ����Ϊ 6��


*/
int maxSubArray(int* nums, int numsSize) {
	int sum = 0,max = nums[0];
	for(int i = 0;i < numsSize;i++)
	{
		sum += nums[i];
		if(sum > max)
			max = sum;
		if(sum < 0)
			sum = 0;
	}
	return max;
}


