/*88. 合并两个有序数组
题目描述：
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:
初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

示例:
	输入:
	nums1 = [1,2,3,0,0,0], m = 3
	nums2 = [2,5,6],       n = 3

	输出: [1,2,2,3,5,6]



*/
/*
	正序思路就是新建一个数组然后循环对比大小填到新数组里
	最后判断i j的值，如果超过m n的那个就是已经赋值完毕
	把另一个剩余的值赋值
*/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int* nums = (int* )malloc(sizeof(int) * (m+n)); 
    int i ,j ,p ;
    i = j = p = 0; 
    while(i < m || j < n)/* 这里有问题，报错，测试了好久应该是i < m || j < n 条件的原因 */
    {					/* ||换成&&就不会报错 */
        
        if(i > m)//说明nums1赋值完
            nums[p++] = nums2[j++];
        else if(j > n)//说明nums2赋值完
            nums[p++] = nums1[i++];
        
        
        if(nums1[i] >= nums2[j])
            nums[p++] = nums2[j++];
        else 
            nums[p++] = nums1[i++];
    }
    
    
    for(int i = 0; i < p; i++)
    {
        nums1[i] = nums[i];
    }
}

/* 这样就可以了 */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int* nums = (int* )malloc(sizeof(int) * (m+n)); 
    int i ,j ,p ;
    i = j = p = 0; 
    while(i < m && j < n)/* 这里有问题，报错，测试了好久应该是i < m || j < n 条件的原因 */
    {					/* ||换成&&就不会报错 */
        /*
        if(i > m)//说明nums1赋值完
            nums[p++] = nums2[j++];
        else if(j > n)//说明nums2赋值完
            nums[p++] = nums1[i++];
        */
        
        if(nums1[i] >= nums2[j])
            nums[p++] = nums2[j++];
        else 
            nums[p++] = nums1[i++];
    }
    
    while(i < m)
    {
        nums[p++] = nums1[i++];
    }
    
    while(j < n)
    {
        nums[p++] = nums2[j++];
    }
    
    for(int i = 0; i < m+n; i++)
    {
        nums1[i] = nums[i];
    }
}


/* 反序 */
/* 这个一直输出nums1？？为什么啊 你有毒吧 艹忘了函数是自动返回nums1，加一个for赋值就行了*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int* nums = (int* )malloc(sizeof(int) * (m+n)); 
    int i = m - 1;
    int j = n - 1;
    int p = m + n -1;

    
    while(i >= 0 && j >= 0)
    {
        if(nums1[i] < nums2[j])
            nums[p--] = nums2[j--];
        else 
            nums[p--] = nums1[i--];
    }
    
    if(j >= 0)
    {
        for(int k = 0; k <= j; k++)
        {
            nums[k] = nums2[k];
        }
    }
    if(i >= 0)
    {
        for(int k = 0; k <= i; k++)
        {
            nums[k] = nums1[k];
        }
    }
	
	for(int i = 0; i < m+n; i++)
    {
        nums1[i] = nums[i];
    }
}


/* 这个通过 */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
  
    int i = m - 1;
    int j = n - 1;
    int p = m + n -1;

    
    while(i >= 0 && j >= 0)
    {
      /*  
        if(i > m)//说明nums1赋值完
            nums[p++] = nums2[j++];
        else if(j > n)//说明nums2赋值完
            nums[p++] = nums1[i++];
      */  
        
        if(nums1[i] < nums2[j])
            nums1[p--] = nums2[j--];
        else 
            nums1[p--] = nums1[i--];
    }
    
    if(j >= 0)
    {
        for(int k = 0; k <= j; k++)
        {
            nums1[k] = nums2[k];
        }
    }
}


