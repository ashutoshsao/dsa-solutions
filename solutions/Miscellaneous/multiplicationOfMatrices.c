#include<stdio.h>
int main(){
    int m,n,o,i,j,k;
    scanf("%d %d %d",&m,&n,&o);
    int mata[m][n],matb[n][o],matc[m][o];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&mata[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<o;j++){
            scanf("%d",&matb[i][j]);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<o;j++){
            matc[i][j]=0;
            for(k=0;k<n;k++){
                matc[i][j] += mata[i][k] * matb[k][j];
            }
        }
    }
    printf("\n");
    for(i=0;i<m;i++){
        for(j=0;j<o;j++){
            printf("%d ",matc[i][j]); 
        }
        printf("\n");
    }    
}
