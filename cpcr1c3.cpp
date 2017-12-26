#include<bits/stdc++.h>
typedef  unsigned long long int ulli;
using namespace std;


ulli ans_query(int a, int b, ulli *arr)
{
		string s=std::to_string(a-1);
		ulli sum1=0, add_number1=0;
		ulli length=0;
		ulli mul=0;
		ulli anum=0, diff=0;
		if(a!=0)
		{
			for(ulli i=0; i<s.length(); i++)
			{
				length=s.length()-1-i;
				mul=pow(10, length);
				anum=((add_number1*10)+s[i]-48)*mul;
				diff=a-1-anum;
				ulli mid=0;
				if(s[i]-48!=0)
				{
					mid=s[i]-48-1;
				}
				sum1=sum1+((add_number1*arr[9]*mul)+(arr[mid]*mul)+((s[i]-48)*(diff+1)));
				add_number1=(add_number1*10)+s[i]-48;
			}
		}
		else
			sum1=0;
		s=std::to_string(b);
		ulli sum2=0, add_number2=0;
		if(b!=0)
		{
			for(ulli i=0; i<s.length(); i++)
			{
				length=s.length()-1-i;
				mul=pow(10, length);
				anum=((add_number2*10)+s[i]-48)*mul;
				diff=b-anum;
				ulli mid=0;
				if(s[i]-48!=0)
					mid=s[i]-48-1;
				sum2=sum2+(add_number2*arr[9]*mul+arr[mid]*mul+(s[i]-48)*(diff+1));
				add_number2=(add_number2*10)+s[i]-48;
			}
		}
		else 
			sum2=0;
	return sum2-sum1;
}

int main(){
	ulli arr[10];
	for(int i=0; i<10; i++)
	{
		if(i==0)
		{
			arr[i]=0;
		}
		else
			arr[i]=arr[i-1]+i;
	}
	ulli a, b;
	cin>>a>>b;
	while(a!=-1 && b!=-1)
	{
		ulli sum=ans_query(a, b, arr);					
		cout<<sum<<endl;
		cin>>a>>b;	
	}
	return 0;
}
