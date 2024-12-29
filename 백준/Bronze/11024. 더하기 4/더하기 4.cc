#include <iostream>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    //cin의 입력버퍼에는 정수 t와 \n이 들어간다 이 새퀴는 안 없어진다 따라서 getline()에서
    //인자입력을 default로는 \n으로 구분하기 때문에 cin의 입력버퍼를 비워줘야 된다.
    cin.ignore();//cin의 입력버퍼를 비워주는 함수이다.
    while (t--)
    {
        string n;
        int sum = 0;
        getline(cin, n);
        string tmp = "" ;
        int nlen = n.size();
        for (int i = 0; i < nlen; i++) {
            tmp += n[i];
            if(n[i]==' '|| i==nlen-1)
            {
                sum += stoi(tmp); 
                tmp = "";
            }
        }
        cout << sum << '\n';
    }
}