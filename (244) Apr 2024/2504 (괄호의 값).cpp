#include<bits/stdc++.h>
using namespace std;
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);
	string q;
	cin>>q;
	stack<int> s;
	int pf=0;
	bool can=1;
	for(int i=0;i<q.size()&&can;++i){
		int p=q[i];
		if(p=='(') s.push(-1);
		else if(p=='[') s.push(-2);
		else{
			int req,c=0;
			if(p==')') req=-1;
			else req=-2;
			while(!s.empty()){
				int p=s.top();
				s.pop();
				if(p>0) c+=p;
				else{
					if(p==req){
						if(c) s.push(c*(req*-1+1));
						else s.push(req*-1+1);
						req=0;
						break;
					}else{
						can=0;
						break;
					}
				}
			}if(req) can=0;
		}
	}while(!s.empty()&&can){
		if(s.top()>0) pf+=s.top();
		else can=0;
		s.pop();
	}if(can) cout<<pf;
	else cout<<0;
}
