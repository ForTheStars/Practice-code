/*
 *@author Wang1997
 *2015��04��12�� 
 * 
 *
 *������
 *��1-20�����ڳ�һ������Ҫ�����ڵ��������ĺ���һ������,������һ����m 
 *
 *����        ��� 
 *  5         5 2 1 4 3 8 9 10 7 6 11 20 17 12 19 18 13 16 15 14
 */
#include<stdio.h>
#include<math.h>
int tryput(int);
int isprime(int);
int sumisprime(int,int);
int a[20+1],used[20+1];
//a�������ѵõ������У�usd[k] ��ʾֵ�Ƿ�ʹ�� 
int main()
{
	int k,m;
	while(1)
	{
		for(k=1;k<=20;k++) 
		{//��ʼ��
			a[k]=0;
			used[k]=0;
		}
		scanf("%d",&m);
		if(m == 0)//���� 0 ���� 
		   break;
        a[1]=m;
        used[m]=1;//��һ����Ϊm���ұ�Ǳ�ʹ�� 
        tryput(2);
        for(k=1;k<=20;k++)
           printf("%d ",a[k]);
        printf("\n");
	} 
} 
int isprime(int x)//�ж�x�Ƿ�Ϊ�������Ƿ���1���񷵻�0 
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
//�жϵ�i�����n�Ƿ������������Ƿ���1���񷵻�0 
int sumisprime(int n,int i)
{
	int rtn;
	if(i == 1)//��һ��ֱ�ӷ���1 
	   return 1;
    rtn=isprime(n+a[i-1]);//�ж�n��ǰһ��ĺ��Ƿ�Ϊ���� 
    if(rtn == 0)
      return 0;
    if(i<20)//����������һ�����1 
      return 1;
    rtn=isprime(n+a[1]);//�����һ��ж����һ��ĺ��Ƿ�Ϊ���� 
      return rtn;
}
int tryput(int i)//������i����� 
{
	int j;
	for(j=1;j<=20;j++)//1~20���в��� 
	{
		if(used[j])//�����ʹ�ã�������һ�� 
		  continue;
        if(sumisprime(j,i))//�Ƿ��������� 
        {
        	a[i]=j;
        	used[j]=1;//�����㣬������������� 
        	if(i==20)
        	  return 1;//20������꣬��ȷ���� 
      	    if(tryput(i+1) != 1)//����i+1����Ҳ��ɹ������� 
      	    {
    	      	a[i]=0;
    	      	used[j]=0;
  	        }
  	        else
  	          return 1;//���ɹ����򷵻�1 
        }
	}
	return 0;
}