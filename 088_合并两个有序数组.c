/*88. �ϲ�������������
��Ŀ������
�������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣

˵��:
��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n��
����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�

ʾ��:
	����:
	nums1 = [1,2,3,0,0,0], m = 3
	nums2 = [2,5,6],       n = 3

	���: [1,2,2,3,5,6]



*/
/*
	����˼·�����½�һ������Ȼ��ѭ���Աȴ�С���������
	����ж�i j��ֵ���������m n���Ǹ������Ѿ���ֵ���
	����һ��ʣ���ֵ��ֵ
*/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int* nums = (int* )malloc(sizeof(int) * (m+n)); 
    int i ,j ,p ;
    i = j = p = 0; 
    while(i < m || j < n)/* ���������⣬���������˺þ�Ӧ����i < m || j < n ������ԭ�� */
    {					/* ||����&&�Ͳ��ᱨ�� */
        
        if(i > m)//˵��nums1��ֵ��
            nums[p++] = nums2[j++];
        else if(j > n)//˵��nums2��ֵ��
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

/* �����Ϳ����� */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int* nums = (int* )malloc(sizeof(int) * (m+n)); 
    int i ,j ,p ;
    i = j = p = 0; 
    while(i < m && j < n)/* ���������⣬���������˺þ�Ӧ����i < m || j < n ������ԭ�� */
    {					/* ||����&&�Ͳ��ᱨ�� */
        /*
        if(i > m)//˵��nums1��ֵ��
            nums[p++] = nums2[j++];
        else if(j > n)//˵��nums2��ֵ��
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


/* ���� */
/* ���һֱ���nums1����Ϊʲô�� ���ж��� ܳ���˺������Զ�����nums1����һ��for��ֵ������*/
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


/* ���ͨ�� */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
  
    int i = m - 1;
    int j = n - 1;
    int p = m + n -1;

    
    while(i >= 0 && j >= 0)
    {
      /*  
        if(i > m)//˵��nums1��ֵ��
            nums[p++] = nums2[j++];
        else if(j > n)//˵��nums2��ֵ��
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


