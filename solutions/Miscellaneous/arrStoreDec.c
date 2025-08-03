#include <stdio.h>
int main() {
    char x[7];
    int idx,carry=0,i;
    scanf("%s",x);
    for(int i = 0; i != '\0' ; i++){
        if(x[i]=='.'){
            idx = i;
            break;
        }
    }
    if(x[idx+1]>'5')
        carry = 1;
    else if(x[idx+1] == '5'){
        if(x[idx+2] != '0' || x[idx+3] != '0')
            carry = 1;
        else if((x[idx-1]-'0')%2 != 0)
            carry = 1;
    }
    if(carry == 1){
        if(idx == 2){
            if(x[idx-1]==9 && x[idx-2]==9)
                printf("100\n");
            else if(x[idx-1]==9){
                x[idx-2]++;
                x[idx-1]=0;
                printf("%c0\n",x[idx-2]);
            }
            else {
                x[idx-1]++;
                printf("%c%c\n",x[idx-2],x[idx-1]);
            }
        }
        else{
            if(x[idx-1]==9)
                printf("10\n");
            else
                printf("%c",x[idx-1]);
        }
    }
    else {
        if(idx == 2){
            printf("%c%c\n",x[idx-2],x[idx-1]);
        }
        else
            printf("%c",x[idx-1]);
    }
    return 0;
}
