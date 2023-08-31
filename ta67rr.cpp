#include<iostream>
#include <queue>
using namespace std;

struct Process{
	int id;
	int at;
	int bt;
	int wt;
	int tat;
};

/*    p1 p2 p3 
   at 5  4  7
   bt 0  4  5 
*/
int main(){
	int n , tq;
	int i = 0;
	int count = 0;
	Process p[10];
	
	
	cout<<"enter number of processes"<<endl;
	cin>>n;
	cout<<"enter time quantum"<<endl;
	cin>>tq;
	for(int j = 0; j<n ; j++){
		p[j].id = j;
		cout<<"enter arrival time of processes"<<endl;
		cin>>p[j].at;
		cout<<"enter burst time of process"<<endl;
		cin>>p[j].bt;
	}
	queue<Process> q;
	q.push(p[i]);
	
	while(!q.empty()){
		Process exe = q.front();
		if(exe.bt > tq){
			exe.bt-=tq;
			count+= tq;
		}else{
			count+= exe.bt;
			exe.bt= 0;
			
			cout<<"process "<<exe.id<<"ended at : "<<count<<endl;
		}
		if(p[i+1].at <= count){
			for(int x = i+1 ; x < n ; x++){
				if(p[x].at<=count){
					q.push(p[x]);
					i++;
					cout<<"inceamented\n";
				}
			}
		}
		if(exe.bt>0){
			q.push(exe);
			q.pop();
		}else{
		
			q.pop();
			
		}
	
		
	}
	
	return 0;
	
}
