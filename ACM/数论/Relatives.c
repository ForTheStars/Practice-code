/*
 *@author Wang1997
 *2016年04月08日
 *
 *                       欧拉函数
 *             求1..n-1中与n互质的数的个数
 *	 将X分解为如下形式，其中p1,p2...pk皆为素数
 *	 X=pow(p1,n1)*pow(p2,n2)*....*pow(pk,nk)  
 *	 则X的欧拉函数为
 *	 Φ(X)=pow(p1,n1-1)*pow(p2,n2-1)*....*pow(pk,nk)*(p1-1)*(p2-1)*....*(pk-1);
 *   例如：Φ(12)= Φ(2^2 * 3^1)=(2-1)*2^(2-1) * (3-1)*3^(1-1) = 2 * 2 = 4
 *   写代码时若是遇到素数p1的话，先乘p1-1，再算p1的几次幂，然后乘起来
 *   欧拉函数是积性函数——若m,n互质，φ(mn)=φ(m)φ(n)。 
 */ 
#include<stdio.h>
void ola(int su)
{//感觉就是在分解质因数公式的基础上，算出p-1 和 p^(n-1) 
	int i,sum=1;//sum存放结果 
	for(i=2;i<=su;i++)
	{
		if(su % i == 0)//此步求公式中的p1,p2... 
		{//也就是分解质因数，将su一直除以i，直到不能整除 
			su/=i;
			sum*=i-1;//乘以p-1
			while(su % i == 0)
			{
				su/=i;
				sum*=i;// 乘以p^(n-1)  上面略过了一次p^1
			}
		}
		
	}
	if(su > 1)//大于1，说明此时su还是个素数 
      sum*=su-1;//继续带公式 
    printf("%d\n",sum);//输出结果 
}
int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{//以0结束输入 
		if(n == 0)
		   break;
        ola(n);//欧拉函数调用 
	}
}
