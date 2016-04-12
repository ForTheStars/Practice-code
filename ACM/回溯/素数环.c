/*
 *@author Wang1997
 *2015年04月12号 
 * 
 *
 *素数环
 *把1-20个数摆成一个环，要求相邻的两个数的和是一个素数,给定第一个数m 
 *
 *输入        输出 
 *  5         5 2 1 4 3 8 9 10 7 6 11 20 17 12 19 18 13 16 15 14
 */
#include<stdio.h>
#include<math.h>
int tryput(int);
int isprime(int);
int sumisprime(int,int);
int a[20+1],used[20+1];
//a数组存放已得到的序列，usd[k] 表示值是否被使用 
int main()
{
	int k,m;
	while(1)
	{
		for(k=1;k<=20;k++) 
		{//初始化
			a[k]=0;
			used[k]=0;
		}
		scanf("%d",&m);
		if(m == 0)//输入 0 结束 
		   break;
        a[1]=m;
        used[m]=1;//第一个数为m，且标记被使用 
        tryput(2);
        for(k=1;k<=20;k++)
           printf("%d ",a[k]);
        printf("\n");
	} 
} 
int isprime(int x)//判断x是否为素数，是返回1，否返回0 
{
	int k,m;
	m=(int)(sqrt(x));
	for(k=2;k<=m;k++)
	   if(x%k == 0)
	     break;
    if(k>m)  
	   return 1;
    else
       return 0;
}
//判断第i项存入n是否满足条件，是返回1，否返回0 
int sumisprime(int n,int i)
{
	int rtn;
	if(i == 1)//第一项直接返回1 
	   return 1;
    rtn=isprime(n+a[i-1]);//判断n与前一项的和是否为素数 
    if(rtn == 0)
      return 0;
    if(i<20)//如果不是最后一项，返回1 
      return 1;
    rtn=isprime(n+a[1]);//是最后一项，判断与第一项的和是否为素数 
      return rtn;
}
int tryput(int i)//搜索第i项的数 
{
	int j;
	for(j=1;j<=20;j++)//1~20项中查找 
	{
		if(used[j])//如果被使用，查找下一个 
		  continue;
        if(sumisprime(j,i))//是否满足条件 
        {
        	a[i]=j;
        	used[j]=1;//若满足，则保留此数并标记 
        	if(i==20)
        	  return 1;//20项查找完，正确返回 
      	    if(tryput(i+1) != 1)//若第i+1项查找不成功，回溯 
      	    {
    	      	a[i]=0;
    	      	used[j]=0;
  	        }
  	        else
  	          return 1;//若成功，则返回1 
        }
	}
	return 0;
}