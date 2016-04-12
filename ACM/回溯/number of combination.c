/*
 *@author Wang1997
 *2015年04月12号 
 *
 *找组合数   
 *从自然数1,2，...n中任取r个数的所有组合数 
 *输入     输出 
 *3 3      1 2 3
 *         1
 */
#include<stdio.h>
int main()
{
	int x[25],fg,k,i,s,n,j,r;
	scanf("%d%d",&n,&r);
	i=1;
	x[i]=1;
	s=0;
	while(1)
	{
		fg=1;//假设路径成立 
		for(k=i-1;k>=1;k--)//检查x[i]是否比它的前每一项都大 
		   if(x[k] >= x[i])
            {
            	fg=0;
            	break; 
			} 
        if(fg==1 && i==r)//当i等于r时，得到一个解 
        {
        	s++;
        	for(j=1;j<=r;j++)
        	{
	        	printf("%d ",x[j]);
	        }
	        printf("\n");
        }
        if(fg == 1 && i<n)//如果此路径通，且i没有达到最大规模 
        {
        	i++;
        	x[i]=1;
        	continue;
        }
        while(x[i]==n && i>1)//如果第i个元素已经到达了最大值n，那么回溯 
           i--;
        if(i==1 && x[i]==n)//第一个元素已经取到了n，试探结束 
           break;
        else
           x[i]=x[i]+1;//否则继续取下一个 
	}
	printf("%d\n",s);//s为方案数 
} 