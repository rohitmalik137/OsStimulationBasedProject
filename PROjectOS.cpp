#include <iostream> 
#include<vector>
using namespace std;
int main() 
{ 
	// P0, P1, P2, P3, P4 are the Process names here 

	int p,r;
	cout<<"Enter the number of process: ";
	cin>>p;		 	// Number of processes
	cout<<endl;
	cout<<"Enter no. of resources: ";
	cin>>r;			// Number of resources
	cout<<endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////////
	int ** alloc = new int* [p];
	for(int i=0;i<p;i++){								//For Declaration
		alloc[i]= new int [r];
	}
	for(int i=0;i<p;i++){
		cout<<"Enter allocation Resources for P"<<i<<": ";
		for(int j=0;j<r;j++){
			cin>>alloc[i][j];
		}
	}
	cout<<endl;
//	cout<<"Avail Matrix";
//	for(int i=0;i<p;i++){
//		for(int j=0;j<r;j++){
//			cout<<alloc[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
	int ** max_need = new int* [p];
	for(int i=0;i<p;i++){								//For Declaration
		max_need[i]= new int [r];
	}
	for(int i=0;i<p;i++){
		cout<<"Enter max need resources for P"<<i<<": ";
		for(int j=0;j<r;j++){
			cin>>max_need[i][j];		//Max Need Matrix
		}
	}
	cout<<endl;
//	cout<<"Avail Matrix";
//	for(int i=0;i<p;i++){
//		for(int j=0;j<r;j++){
//			cout<<max_need[i][j]<<" ";
//		}
//		cout<<endl;
//	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int ** avail = new int* [p];
	for(int i=0;i<p;i++){								//For Declaration
		avail[i]= new int [r];
	}
	cout<<"Enter the available resources: ";
	for(int i=0;i<1;i++){	
		for(int j=0;j<r;j++){
			cin>>avail[i][j];					// Available Resources 
		}
	}
	for(int i=1;i<p;i++){	
		for(int j=0;j<r;j++){
			avail[i][r]=0;					// Available Resources 
		}
	}
	cout<<endl;
///////////////////////////////////////////////////////////////////////////////////////////////////////////
	int ** rem_need = new int* [p];
	for(int i=0;i<p;i++){								//For Declaration
		rem_need[i]= new int [r];
	}
	for (int i = 0; i < p; i++) { 
		for (int j = 0; j < r; j++){
			rem_need[i][j] = max_need[i][j] - alloc[i][j];		//Remaining Need Matrix
		}
	}
////////////////////////////////////////////////////////////////////////////////////////////////////
	int ** rem_need1 = new int* [p];
	for(int i=0;i<p;i++){								//For Declaration
		rem_need1[i]= new int [r];
	}
	for(int i=0;i<p;i++){
		for(int j=0;j<r;j++){
			rem_need1[i][j] = rem_need[i][j];			//Copying rem_need Matrix into rem_need1
		}
	}
	cout<<endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////////
	int result,count = 0,fi = 0;
	for(int i=0;i<p;i++){
		for(int j=0;j<r;j++){
			result = 0;
			cout<<"avail[fi][j]->"<<avail[fi][j]<<endl;
			result = avail[fi][j]-rem_need[i][j];
			if(result <0){
				break;
			}else{
				count++;
			}
		}
		cout<<count<<" <-count\n";
		if(count == r){
			for(int j=0;j<r;j++){
				avail[fi+1][j] = avail[fi][j] + alloc[i][j];
				cout<<avail[fi][j]<<" / ";
			}
			fi++;
			count = 0;
		}
	}
	cout<<endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////
	cout<<"Avail matrix\n";
	for(int i=0;i<p;i++){
		for(int j=0;j<r;j++){
			cout<<avail[i][j]<<" ";
		}
		cout<<endl;
	}
		return (0); 
} 

