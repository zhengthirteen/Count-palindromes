#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int judge(char *x,int y)//�жϻ����� 
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
int compare(char* x,char* y)//�Ƚ��ַ���С��λ���ߵĴ� 
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
	while((ch=getchar())!=EOF)//д���ı� 
	{
		if(ch>='0'&&ch<='9')//���������ַ� 
		x[a][b++]=ch;
		else if((ch<'0'||ch>'9')&&b>0) 
		{
			x[a][b]='\0';//��'\0' 
			b=0;
			if(x[a][0]!='0')//�ų���0��ͷ�������ַ� 
			a++;
		}
	}
	if(a==0)//���޺Ϸ��������룬��ǰ���� 
	{
		printf("None\n");
		return 0;
	}
	for(int i=0;i<a;i++)//��������д���µ����� 
	{
		d=strlen(x[i]);
		if(d>=2&&judge(x[i],d))
		strcpy(y[c++],x[i]);
	}
	if(c==0)//���޻���������ǰ���� 
	{
		printf("None\n");
		return 0;
	}
	for(int j=0;j<c;j++)//�ж�ÿ�����������ֵĴ���������������������ͬ��ŵ����������� 
	{
		strcpy(ch1,y[j]);
		for(int i=0;i<c;i++)
		{
			if((compare(ch1,y[i]))==0)
			n[j]++;
		}
	}
	int max=n[0];
	for(int i=0;i<c;i++)//�ҵ��������Ļ���������� 
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
				if((compare(y[i],y[j]))==0)//�˺���ͬ������������Ϊһλ 
				n[j]=0;
			}
			n[i]=max;
			m[e++]=i;
		}
	}
	if(e==1)//���������Ļ���������һ�֣���ǰ���� 
	{
		printf("%s %d\n",y[m[0]],max);
		return 0;
	}
	for(int i=0;i<e-1;i++)//Ϊ��������Ļ��������� 
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
	for(int i=0;i<e;i++)//����С������� 
	{
		printf("%s %d\n",y[m[i]],max);
	}
	return 0;
}
