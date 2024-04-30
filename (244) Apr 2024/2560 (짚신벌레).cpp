#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct xy{ll x,y,p;};
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int a,b,d,n;
	cin>>a>>b>>d>>n;
	vector<xy> k(n+1);
	k[0]=xy{0,1,1};
	for(int i=1;i<=n;++i){
		k[i]=k[i-1];
		if(i>=a){
			k[i].y-=k[i-a].p;
			k[i].x+=k[i-a].p;
		}if(i>=d) k[i].y-=k[i-d].p;
		if(i>=b){
			k[i].y+=k[i-b].p;
			k[i].x-=k[i-b].p;
		}
		if(k[i].x<0) k[i].x+=1000;
		if(k[i].y<0) k[i].y+=1000;
		k[i].x%=1000;
		k[i].y%=1000;
		k[i].p%=1000;
		k[i].p=k[i].x;
		k[i].y+=k[i].x;
	}cout<<(k[n].x+k[n].y)%1000;
}
