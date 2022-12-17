#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int judge(char *x,int y)//判断回文数 
{
	if(y==1||y==0)
	return 1;
	else
	{
		if(*x==*(x+y-1))
		return judge(x+1,y-2);
		else
		return 0;
	}
}
int compare(char* x,char* y)//比较字符大小（位数高的大） 
{
	if(strlen(x)!=strlen(y))
	return strlen(x)-strlen(y);
	else
	return strcmp(x,y);
}
int main(void)
{
	char x[30][100],y[30][100],ch,ch1[100],ch2[100],ch3[100];
	int a=0,b=0,c=0,d=0,e=0,n[10]={0},m[10]={0};
	while((ch=getchar())!=EOF)//写入文本 
	{
		if(ch>='0'&&ch<='9')//储存数字字符 
		x[a][b++]=ch;
		else if((ch<'0'||ch>'9')&&b>0) 
		{
			x[a][b]='\0';//补'\0' 
			b=0;
			if(x[a][0]!='0')//排除以0开头的数字字符 
			a++;
		}
	}
	if(a==0)//若无合法数字输入，提前结束 
	{
		printf("None\n");
		return 0;
	}
	for(int i=0;i<a;i++)//将回文数写入新的数组 
	{
		d=strlen(x[i]);
		if(d>=2&&judge(x[i],d))
		strcpy(y[c++],x[i]);
	}
	if(c==0)//若无回文数，提前结束 
	{
		printf("None\n");
		return 0;
	}
	for(int j=0;j<c;j++)//判断每个回文数出现的次数，并将次数储存在相同序号的数字数组中 
	{
		strcpy(ch1,y[j]);
		for(int i=0;i<c;i++)
		{
			if((compare(ch1,y[i]))==0)
			n[j]++;
		}
	}
	int max=n[0];
	for(int i=0;i<c;i++)//找到次数最多的回文数的序号 
	{
		if(max<n[i])
		{
			max=n[i];
		}
	}
	for(int i=0;i<c;i++)
	{
		if(max==n[i])
		{
			for(int j=0;j<c;j++)
			{
				if((compare(y[i],y[j]))==0)//此后相同回文数仅保留为一位 
				n[j]=0;
			}
			n[i]=max;
			m[e++]=i;
		}
	}
	if(e==1)//若最大次数的回文数仅有一种，提前结束 
	{
		printf("%s %d\n",y[m[0]],max);
		return 0;
	}
	for(int i=0;i<e-1;i++)//为最大字数的回文数排序 
	{
		for(int j=i+1;j<e;j++)
		if((compare(y[m[i]],y[m[j]]))>0)
		{
			int temp;
			temp=m[i];
			m[i]=m[j];
			m[j]=temp;
		}
	}
	for(int i=0;i<e;i++)//按由小到大输出 
	{
		printf("%s %d\n",y[m[i]],max);
	}
	return 0;
}
