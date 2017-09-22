#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	vector<int>nums;
	for(int i=2; i<=100000; i++)
			nums.push_back(i);
	int count=1;
	int countpr=nums[0];
	int lucky[3050];
	while(1){
		cin>>n;
		if(n==0)
			break;
		int sum;		
		while(count<=n)
		{
			lucky[count]=nums[0];
			countpr=nums[0];
			sum=0;
			int cnt=0;
			int size=nums.size();
			while((sum-cnt)<nums.size())
			{
				//cout<<"cnt"<<cnt<<endl;
				nums.erase(nums.begin()+(sum-cnt));	
				sum+=countpr;
				cnt++;
			}
			count++;
		}
		cout<<lucky[n]<<endl;
	}
	return 0;
}
