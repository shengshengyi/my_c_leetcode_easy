/*
001. 两数之和

题目描述：

	给定一个整数数组 nums 和一个目标值 target，
	请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。

	你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例：

	给定 nums = [2, 7, 11, 15], target = 9

	因为 nums[0] + nums[1] = 2 + 7 = 9
	所以返回 [0, 1]


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
构造结构体，将数字与其原始位置关联起来。
然后对结构体数组进行排序，从小到大的顺序，这里采用qsort()函数。
利用两个下标begin和end，begin指向于开始的位置，end指向结束的位置，
判断nums[begin] + nums[end]与target的关系，
如果相等，则直接返回索引；
如果比target大，则说明需要减小两数之和，即end--，来减小后者数字；
如果比target大，则说明需要增大两数之和，即begin++来增大前者数字。
通过这种方式逐渐逼近target，运行时间0ms，代码如下。
--------------------- 
原文：https://blog.csdn.net/hang404/article/details/84764531 
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
