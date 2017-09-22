#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	double u, ua , v, va, w, wa, U, Ua, V, Va, W, Wa, a;
	double  Volume,  b=12;
	cin>>t;
	while(t--)
	{
		cin>>u;
		cin>>v;
		cin>>w;
		cin>>W;
		cin>>V;
		cin>>U;
		
        a=4*(pow(u,2)*pow(v,2)*pow(w,2)) - pow(u,2)*pow((pow(v,2)+pow(w,2)-pow(U,2)),2) - pow(v,2)*pow((pow(w,2)+pow(u,2)-pow(V,2)),2) - pow(w,2)*pow((pow(u,2)+pow(v,2)-pow(W,2)),2) + (pow(v,2)+pow(w,2)-pow(U,2))*(pow(w,2)+pow(u,2)-pow(V,2))*(pow(u,2)+pow(v,2)-pow(W,2));
        Volume=sqrt(a);
        Volume/=b;
				cout<<std::fixed<<std::setprecision(4)<<Volume<<endl;	
	}
	return 0;
}
