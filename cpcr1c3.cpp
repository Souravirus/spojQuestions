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
				//cout<<"s.length"<<s.length()<<endl;
				length=s.length()-1-i;
				//cout<<"length"<<length<<endl;
				mul=pow(10, length);
				//cout<<"mul"<<mul<<endl;
				anum=((add_number1*10)+s[i]-48)*mul;
				//cout<<"anum"<<anum<<endl;
					diff=a-1-anum;
				//cout<<"diff"<<diff<<endl;
				//cout<<"s[i]"<<s[i]<<endl;
				ulli mid=0;
				if(s[i]-48!=0)
				{
					mid=s[i]-48-1;
				}
				sum1=sum1+((add_number1*arr[9]*mul)+(arr[mid]*mul)+((s[i]-48)*(diff+1)));
				//cout<<"inside"<<sum1<<endl;
				add_number1=(add_number1*10)+s[i]-48;
				//cout<<"add_number1:"<<add_number1<<endl;
			}
		}
		else
			sum1=0;
		//cout<<sum1<<endl;
		s=std::to_string(b);
		ulli sum2=0, add_number2=0;
		if(b!=0)
		{
			for(ulli i=0; i<s.length(); i++)
			{
				length=s.length()-1-i;
			//	cout<<"length2:"<<length<<endl;
				mul=pow(10, length);
			//	cout<<"mul2:"<<mul<<endl;
				anum=((add_number2*10)+s[i]-48)*mul;
				diff=b-anum;
			//	cout<<"diff2:"<<diff<<endl;
				ulli mid=0;
				if(s[i]-48!=0)
					mid=s[i]-48-1;
			//	cout<<"mid2:"<<mid<<endl;
			//	cout<<"s[i]b"<<s[i]<<endl;
				sum2=sum2+(add_number2*arr[9]*mul+arr[mid]*mul+(s[i]-48)*(diff+1));
				add_number2=(add_number2*10)+s[i]-48;
		//	cout<<"inside sum2:"<<sum2<<endl;
		//	cout<<"add_number2:"<<add_number2<<endl;
			}
		}
		else 
			sum2=0;
		//cout<<sum2<<endl;
	return sum2-sum1;
}

int main(){
	//memset(ans, -1, sizeof(ans));
	ulli arr[10];
	for(int i=0; i<10; i++)
	{
		if(i==0)
		{
			arr[i]=0;
		}
		else
			arr[i]=arr[i-1]+i;
	//	cout<<arr[i]<<endl;
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
