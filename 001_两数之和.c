/*
001. ����֮��

��Ŀ������

	����һ���������� nums ��һ��Ŀ��ֵ target��
	�����ڸ��������ҳ���ΪĿ��ֵ�����������������������ǵ������±ꡣ

	����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ��㲻���ظ��������������ͬ����Ԫ�ء�

ʾ����

	���� nums = [2, 7, 11, 15], target = 9

	��Ϊ nums[0] + nums[1] = 2 + 7 = 9
	���Է��� [0, 1]


*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target)
{
     int *result = (int *)malloc(sizeof(int) * 2); 
	 
    for(int i = 0; i < numsSize - 1; i++)
    {
        for(int j = i+1; j < numsSize; j++)
        {
            if( nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}



/*
����ṹ�壬����������ԭʼλ�ù���������
Ȼ��Խṹ������������򣬴�С�����˳���������qsort()������
���������±�begin��end��beginָ���ڿ�ʼ��λ�ã�endָ�������λ�ã�
�ж�nums[begin] + nums[end]��target�Ĺ�ϵ��
�����ȣ���ֱ�ӷ���������
�����target����˵����Ҫ��С����֮�ͣ���end--������С�������֣�
�����target����˵����Ҫ��������֮�ͣ���begin++������ǰ�����֡�
ͨ�����ַ�ʽ�𽥱ƽ�target������ʱ��0ms���������¡�
--------------------- 
ԭ�ģ�https://blog.csdn.net/hang404/article/details/84764531 
*/



struct node{
	int val;
	int index;
};

int cmp(const void* a,const void* b)
{
	return (((struct node*)a)->val > ((struct node*)b)->val ? 1 : -1); 
}

int* twoSum(int* nums,int numsSize,int target)
{
	int i = 0;
	int begin = 0, end = numsSize - 1;
	int* result = (int*)malloc(2*sizeof(int));
	struct node* nodes = (struct node*)malloc(numsSize * sizeof(struct node));

	//init nodes
	for(i = 0; i < numsSize; i++)
	{
		nodes[i].val = nums[i];
		nodes[i].index = i;
	}

	qsort(nodes,numsSize,sizeof(struct node),cmp);

	while(begin < end)
	{
		if(nodes[begin].val + nodes[end].val == target)
		{
			result[0] = nodes[begin].index;
			result[1] = nodes[end].index;
			free(nodes);
			return result;
		}
		else if(nodes[begin].val + nodes[end].val > target)
			end--;
		else
			begin++;
	}
	free(nodes);
	return result;
}
