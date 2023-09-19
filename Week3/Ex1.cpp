#include<iostream>
#include<map>
using namespace std;

int main (){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    map <int, int> cnt;
    for(int j = 0; j < n; j++){
        cnt[a[j]]++;
    }
    for(auto it : cnt){
        if(it.second == 1){
            cout << it.first << endl;
        }
    }
}