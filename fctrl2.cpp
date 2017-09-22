#include<bits/stdc++.h> 
using namespace std;
 int main(){ 
 int t, count=1, prev, temp, carry, ans, size; string sec; 
vector<vector<int> >vect;
 vector<int>  :: iterator itv; 
 vector<int>:: reverse_iterator itrv; 
 vector<vector<int> >:: iterator it;
  vector<int>tvect; tvect.push_back(0); 
  vect.push_back(tvect); tvect.clear(); 
  tvect.push_back(1); vect.push_back(tvect); 
  tvect.clear(); 
  cin>>t; 
  while(t--) 
  { int n; 
  scanf("%d", &n);
   if(n<=count){ 
   for(itrv=vect[n].rbegin(); itrv!=vect[n].rend(); itrv++) 
   { printf("%d", *itrv); } cout<<endl; } 
   else{
    for(int i=count+1; i<=n;i++){ 
    sec=to_string(i); 
    vector<vector<int> > partial; 
    int count2=0; 
    for(int j=sec.length()-1;j>=0;j--) 
    { 
    for(int k=0; k<count2; k++) 
    { tvect.push_back(0); } 
    
    count2++; carry=0;
     for(itv=vect[i-1].begin(); itv!=vect[i-1].end(); itv++) 
     {temp=sec[j]-'0'; 
     ans=(*itv)*temp+carry;	
     tvect.push_back(ans%10); 
     if(itv!=vect[i-1].end()-1) 
     carry=ans/10; 
     else { 
     int q=ans/10;
      if(q) tvect.push_back(q); 
      }
      } 
      partial.push_back(tvect); 
      size=tvect.size(); 
      tvect.clear();  
      } int carry=0; 
      for(int j=0;j<size; j++)
       { int sum=0;
        for(it=partial.begin(); it!=partial.end(); it++)
         { if((*it).size()>j) 
         { sum+=(*it).at(j); } 
         } 
         sum+=carry;	
         tvect.push_back(sum%10); 
         if(j==size-1) 
         { int q=sum/10;
          if(q) 
          tvect.push_back(q);
         } 
         else 
         carry=sum/10; 
        } 
        vect.push_back(tvect); 
        tvect.clear(); 
       } 
       count=n; 
       for(itrv=vect[n].rbegin(); itrv!=vect[n].rend(); itrv++) 
       { 
       printf("%d", *itrv); 
       } 
       cout<<endl; 
       } } return 0; }
