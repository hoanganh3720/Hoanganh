#include<iostream>

using namespace std;

void inPut(int arr[][100], int n, int m){
    for ( int i=0; i<n; i++){
        for ( int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
}

int main() {
    int arr[100][100];
    int n,m;
    cin >> n >> m;
    inPut( arr, n, m);
    return 0;
}
