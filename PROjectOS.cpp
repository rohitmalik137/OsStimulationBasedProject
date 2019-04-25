#include <iostream>
#include<windows.h>
using namespace std;

int deleteElement(int trash[], int n, int x) 
{
   // Search x in array 
   int i; 
   for (i=0; i<n; i++) 
      if (trash[i] == x) 
         break; 
  
   // If x found in array 
   if (i < n) 
   { 
     // reduce size of array and move all 
     // elements on space ahead 
     n = n - 1; 
     for (int j=i; j<n; j++) 
        trash[j] = trash[j+1]; 
   }
   return n; 
} 

int main() 
{
	// P0, P1, P2, P3, P4 are the Process names here 
	printf("======================================================================================================\n						BANKER'S ALGORITHM\n====================================================================================================== \n\n");
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int ** avail = new int* [p+1];
	for(int i=0;i<p+1;i++){								//For Declaration
		avail[i]= new int [r];
	}
	cout<<"Enter the available resources: ";
	for(int i=0;i<1;i++){	
		for(int j=0;j<r;j++){
			cin>>avail[i][j];					// Available Resources 
		}
	}
	for(int i=1;i<=p;i++){	
		for(int j=0;j<r;j++){
			avail[i][r]=0;					// Available Resources 
		}
	}
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////
	int result,n,count = 0,count1=0,l=0,fi = 0,trash[p];
	for(int i=0;i<p;i++){
		trash[i] = i+1;
	}
	int i=0,q=0;
	while(1){
		for(int j=0;j<r;j++){
			result = 0;
			result = avail[fi][j]-rem_need[i][j];
			if(result <0){
				break;
			}else{
				count++;
			}
		}
		if(count == r){
			for(int j=0;j<r;j++){
				avail[fi+1][j] = avail[fi][j] + alloc[i][j];
				count1++;  
			}
			if(count1>0){
				n = sizeof(trash)/sizeof(trash[0])-q;
			    n = deleteElement(trash, n, trash[i-l]);
			    l++;
			    q++;
			}
			fi++;
		}
			count = 0;
			if(i==4){
				i=0;
				l=0;
			}else{
				i++;
			}
			if(n == 1){
				break;
			}
	}
	
	int final = trash[0]-1;
		for(int j=0;j<r;j++){
				avail[fi+1][j] = avail[fi][j] + alloc[final][j];
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////
//Displaying The Content
	printf("\n _______________________________________________________________________________________");
	printf("\n|  Process\t|  Allocation\t|  Max_Ne3d\t|  Available\t|  Remaining_Need\t|\n");
	printf("|_______________|_______________|_______________|_______________|_______________________|\n");
	
	 for(int i=0;i<p;i++){
	 	printf("|  P%d\t\t|",i);
	 	for(int j=0;j<r;j++){
			 	printf("%d ",alloc[i][j]);			
			 }
		if(r<=3){
			printf("\t");
		}
		printf("\t|");
		for(int j=0;j<r;j++){
			 	printf("%d ",max_need[i][j]);			
			 }
		if(r<=3){
			printf("\t");
		}
		printf("\t|");
		for(int j=0;j<r;j++){
//			Sleep(1000);
			 	printf("%d ",avail[i][j]);			
			 }
		if(r<=3){
			printf("\t");
		}
		printf("\t|");
		for(int j=0;j<r;j++){
			 	printf("%d ",rem_need[i][j]);			
			 }
		if(r<=3){
			printf("\t");
		}
		printf("\t\t|\n");
		printf("|_______________|_______________|_______________|_______________|_______________________|\n");
	 }
	 i=5;
	 int sum[r];
	 for(int i=0;i<r;i++){
	 	sum[i] = 0;
	 }
	 for(int j=0;j<r;j++){
	 	for(int i=0;i<p;i++){
	 		sum[j] += alloc[i][j];
		 }
	 }
	 	printf("|\t\t|");
	 	for(int j=0;j<r;j++){
	 		Sleep(1000);
			 	printf("%d ",sum[j]);			
			 }
		if(r<=3){
			printf("\t");
		}
		printf("\t|\t\t|");
		for(int j=0;j<r;j++){
			 	printf("%d ",avail[i][j]);			
			 }
		if(r<3){
			printf("\t");
		}
		printf("\t|\t\t\t|\n");
		printf("|_______________|_______________|_______________|_______________|_______________________|\n");
		return (0); 
} 
