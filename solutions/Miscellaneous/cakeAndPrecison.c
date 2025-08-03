#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char arr[130];
        int i=0,len=0;
        scanf("%s",arr);
        while(arr[i] !='\0'){
            len++;
            i++;
        }
        int carry =1;
        for(i=len-1;i>=0;i--){
            if(carry ==1){
                if(arr[i] == '9'){
                    arr[i] = '0';
                }
                else{
                    arr[i]++;
                    carry=0;
                }
            }
        }
        if(carry == 1){
            arr[len]='0';
            for(i=len;i>0;i--){
                arr[i] = arr[i-1]; //arr[i] = arr[i-1] works fine
            }
            arr[0]='1';
            arr [len+1] = '\0';
        }
        printf("%s\n",arr);
    }
    return 0;
}

