
/*
qsort����C�����еĿ��ź�����������stdlib.hͷ�ļ��У�����һ�����ĸ�������û�з���ֵ��
���е�һ������s��һ����ַ��������������׵�ַ��
n����Ҫ�����������
sizeof(s[0])����ÿһ��Ԫ��ռ�õĿռ��С��
ָ������ָ�룬����ȷ�������˳��
�򵥵�˵����һ����Ϊ1000�������������ʱ��int a[1000];


qsort(a, 1000, sizeof(int), cmp); 
//����cmp����ӦдΪ��
int cmp(const void *a, const void *b) { 
return *(int*)a - *(int*)b; //��С�������� 
//return *(int *)b - *(int *)a; �ɴ�С���� 
} 

cmp�����ķ���ֵ��<0(�������û�)��>0(�����û�)��0(�������û�)

?
��int��������п���
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int s[10000], n, i;

int cmp(const void *a, const void *b)
{
     return (*(int *)a - *(int *)b);
}

int main()
{
     scanf("%d", &n);
     for(i = 0; i < n; i++) 
         scanf("%d", &s[i]);

     qsort(s, n, sizeof(s[0]), cmp);

     for(i = 0; i < n; i++) 
         printf("%d ", s[i]);

     return 0;
}?

double��
#include <stdio.h>
#include <stdlib.h>
double s[1000];
int i, n;

int cmp(const void * a, const void * b)
{
     return((*(double*)a - *(double*)b>0)?1:-1);
}

int main()
{
     scanf("%d", &n);
     for(i = 0; i < n; i++) 
         scanf("%lf", &s[i]);

     qsort(s, n, sizeof(s[0]), cmp);

     for(i = 0; i < n; i++) 
         printf("%lf ", s[i]);

     return 0;
}
?
char��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[10000], i, n;
int cmp(const void *a,const void *b)
{
     return (*(char *)a - *(char *)b);
}

int main()
{
     scanf("%s", s);
     n = strlen(s);
     qsort(s, n, sizeof(s[0]), cmp);

     printf("%s", s);
     return(0);
}?
struct��
#include <stdio.h>
#include <stdlib.h>
struct node
{
     double date1;
     int no;
} s[100];
int i, n;
int cmp(const void *a,const void *b)
{
     struct node *aa = (struct node *)a;
     struct node *bb = (struct node *)b;
     return (((aa->date1) > (bb->date1)) ? 1 : -1);
}

int main()
{
     scanf("%d", &n);
     for(i = 0; i < n; i++)
     {
         s[i].no = i + 1;
         scanf("%lf", &s[i].date1);
     }
     qsort(s, n, sizeof(s[0]), cmp);

     for(i = 0; i < n; i++)
         printf("%d   %lf\n", s[i].no, s[i].date1);

     return(0);
}
?
�ṹ�����򣬼���no��ʹ���ȶ�(��dataֵ��ȵ�����°�ԭ����˳����)
#include <stdio.h>
#include <stdlib.h>
struct node
{
     double date1;
     int no;
} s[100];

int i, n;
int cmp(const void *a, const void *b)
{
     struct node *aa = (struct node *)a;
     struct node *bb = (struct node *)b;
     if(aa->date1 != bb->date1)
         return(((aa->date1) > (bb->date1)) ? 1 : -1);
     else
         return((aa->no) - (bb->no));
}
int main()
{
     scanf("%d", &n);
     for(i = 0; i < n; i++)
     {
         s[i].no = i + 1;
         scanf("%lf", &s[i].date1);
     }
     qsort(s, n, sizeof(s[0]), cmp);
     for(i = 0; i < n; i++) 
         printf("%d   %lf\n", s[i].no, s[i].date1);
     return 0;
}
?
���ַ������������(char s[][]��)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[100][100];
int i, n;
int cmp(const void *a, const void *b)
{
     return (strcmp((char*)a, (char*)b));
}

int main()
{
     scanf("%d", &n);
     for(i = 0; i < n; i++) 
         scanf("%s", s[i]);

     qsort(s, n, sizeof(s[0]), cmp);

     for(i = 0; i < n; i++)
         printf("%s\n", s[i]);

     return 0;
}
?
���ַ�����������(char *s[]��)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *s[100];
int i, n;
int cmp(const void *a, const void *b)
{
     return (strcmp(*(char**)a, *(char**)b));
}

int main()
{
     scanf("%d", &n);
     for(i = 0; i < n; i++)
     {
         s[i] = (char*)malloc(sizeof(char*));
         scanf("%s", s[i]);
     }
     qsort(s, n, sizeof(s[0]), cmp);
     for(i = 0; i < n; i++) 
         printf("%s\n", s[i]);
     return 0;
}



*/

