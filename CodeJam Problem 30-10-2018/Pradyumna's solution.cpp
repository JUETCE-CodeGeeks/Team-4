#include<bits/stdc++.h>
using namespace std;
int calsum(vector<int> v,int i,int j){
	int sum=0;
	for(int k=i;k<=j;k++){
		sum+=v[k];
	}
	return(sum);
}
int countodd(vector<int> v,int i, int j){
	int odd=0;
	for(int k=i;k<=j;k++){
		if(abs(v[k]%2)==1) odd++;
	}
	return(odd);
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int N,O,D;
		cin>>N>>O>>D;
		int X1,X2,A,B,C,M,L;
		cin>>X1>>X2>>A>>B>>C>>M>>L;
		vector<int> v;
		vector<int> sum;
		vector<int> i_index;
		vector<int> j_index;
		v.push_back(X1+L);
		v.push_back(X2+L);
		for(int i=2;i<N;i++){
			int k=((A*(v[i-1]-L))+(B*(v[i-2]-L))+C)%M;
			int m=k+L;
			v.push_back(m);
		}
	/*	for(int i=0;i<N;i++){
			cout<<v[i]<<" ";
		}*/
		cout<<"\n";
		for(int i=0;i<N-1;i++){
			
			for(int j=N-1;j>i;j--){
				int s1=calsum(v,i,j);
				
				if(s1<=D && countodd(v,i,j)<=O){
					sum.push_back(s1);
					i_index.push_back(i);
					j_index.push_back(j);
				}
				
			}
		}
	
		
	/*	for(int i=0;i<sum.size();i++){
			for(int j=0;j<sum.size();j++){
			
				int t=countodd(v,i_index[i],j_index[j]);
				
				if(t>O){
					vector<int>:: iterator i1,i2,i3;
					i1=sum.begin()+i;
					i2=i_index.begin()+i;
					i3=j_index.begin()+i;
					sum.erase(i1);
					i_index.erase(i2);
					j_index.erase(i3);
			}
		}*
	}*/
		if(sum.empty()) cout<<"IMPOSSIBLE";
		else{
		
			sort(sum.begin(),sum.end());
			if(sum[0]>D) cout<<"IMPOSSIBLE";
			else{
				int max=sum[sum.size()-1];
				for(int i=0;i<v.size();i++){
					if(v[i]>max) max=v[i];
				}
				cout<<max<<"\n";
			}
		}
		
}
}
	



