#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int counts[1001][1001];
    string a,b;
    cin>>a>>b;
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1]) counts[i][j]=counts[i-1][j-1]+1;
            else{
                counts[i][j]=max(counts[i-1][j],counts[i][j-1]);
            }
        }
    }
    cout<<counts[a.size()][b.size()];
}