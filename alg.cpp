#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;
#define ok1 printf("ok1\n");
#define ok2 printf("ok2\n");


int main(){
    int n;
    cin >> n;
    vector<vector<int> > v, w;
    //動的2次元配列作成(&要素すべてを10000で初期化)
    v = vector<vector<int> >(n+1, vector<int>(n+1, 10000));
    //サイズ確認用デバッグ
    /*
    cout << v.size() << endl;
    cout << v.front().size() << endl;
    */

    //入力(v0を入れる)
    for(int i = 1; i < n; ++i){
        for(int j = i+1; j < n+1; ++j){
            //cout << j << endl;
            int num;
            cin >> num;
            v[i][j] = num;
            v[j][i] = num;
        }
    }
    
    //計算
    for(int k = 1;k < n+1; ++k){
        w = v;
        
        for(int i = 1; i < n; ++i){
            for(int j = i+1; j < n+1; ++j){
                //デバッグ用出力
                //cout << w[i][j] <<" " << w[i][k] << " " << w[k][j] << endl;
                v[i][j] = min(w[i][j], w[i][k] + w[k][j]);
            }
        }
    }

    //結果の出力
    for(int i = 1; i < n; ++i){
        for(int j = i+1; j < n+1; ++j){
            cout << v[i][j] << " ";
        }
    }
    cout << endl;    
    return 0;
}