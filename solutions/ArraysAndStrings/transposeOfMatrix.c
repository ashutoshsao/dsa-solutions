/*
Problem: Transpose of a Square Matrix
Link: None
Problem Statement: Given a square matrix, transpose it in-place. The transpose of a matrix is the matrix flipped over its main diagonal, switching the row and column indices of the matrix.
Approach: To transpose the matrix in-place, we can iterate through the upper triangle of the matrix (where row index `i` is less than column index `j`) and swap the element `arr[i][j]` with `arr[j][i]`. This avoids swapping elements twice. The provided code iterates through the lower triangle, which also works.
Time Complexity: O(n^2), where n is the number of rows (or columns) in the matrix, because we iterate through all the elements of the matrix.
Space Complexity: O(1), as the transpose is done in-place without using any extra space.
*/
#include<stdio.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    int arr[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            if(i!=j){
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
    }
    printf("\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}