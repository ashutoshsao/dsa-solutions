#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int r,c,k,ct=0;
        scanf("%d %d %d",&r,&c,&k);
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(pow(abs(i-r),2) + pow(abs(j-r),2) <= pow(k,2))
                ct++;
            }
        }
        printf("%d",ct);
    }
    return 0;
}
