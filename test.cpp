#include <iostream>
using namespace std;
int main() {
    int x,y;
    cin >> x >> y;
    while(x!=0 && y!=0){
        if(x>y){
            x = x-y;
        }else if(x<y){
            y = y-x;
        }else y=0;
    }
    cout << x+y << endl;
  return 0;
}