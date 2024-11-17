#include <iostream>
#include <cstring>
using namespace std;

void up(int *rlt, int idx){
    if(rlt[idx] > 9){
        rlt[idx-1] += rlt[idx]/10;
        rlt[idx] = rlt[idx]%10;
    }
}

int main(){
    char a[10001]={0}, b[10001]={0};
    cin>>a>>b;
    int n = strlen(a), m = strlen(b), temp, i, result[10002]={0,}, sml, big;
    if(m > n){ sml = n; big = m;}
    else{ sml = m; big = n; }

    for(i = 0 ; i < sml; i++){
        temp = (a[n-1-i]-'0') + (b[m-1-i]-'0'); //문자에서 '0'을 빼면 숫자와 동일
        result[big+1-i] += temp;
        up(result, big+1-i);
    }
    temp = i;
    for(i = temp; i < big; i++){
        if(big == n){
            result[big+1-i] += a[big-1-i]-'0';
            up(result, big+1-i);
        }
        else{
            result[big+1-i] += b[big-1-i]-'0';
            up(result, big+1-i);
        }
    }

    int flag = 0;
    for(i = 0 ; i < big+2; i++){
        if (flag == 0) {
            if (result[i] != 0)
                flag = 1;
            else if (i == big+1)
                cout<<"0";
        }
        if (flag != 0)
            cout<<result[i];
    }
    return 0;
}