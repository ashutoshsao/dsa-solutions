//this code is for strongs no. in range 1->N (N being the input value)
#include<stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	if(N==0){
		printf("no\n");
	}	
	else {
		int i=1;
		while(i<=N){
			int sum=0,temp=i;
			while(temp>0){
				int x=temp%10;
				int fact=1,j=1;
				while(j<=x){
					fact*=j;
					j++;
				}
				sum+=fact;
				temp/=10;
			}
			if(sum == i){
				printf("%d ",i);
			}
			i++;
		}
		printf("\n");
	}
return 0;
}