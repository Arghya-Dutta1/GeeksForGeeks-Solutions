#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >> a;
    if(a==0){
        cout<<0<<endl;
        return 0;
    }

    string bin="", ans="";
    while(a>0){
        bin=(char)('0'+(a%2)) + bin;
        a/=2;
    }
    // cout<<bin<<endl;
    // printing hexadecimal value of a.
    map<string, char> hx={{"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'},
        {"0100", '4'}, {"0101", '5'}, {"0110", '6'}, {"0111", '7'},
        {"1000", '8'}, {"1001", '9'}, {"1010", 'a'}, {"1011", 'b'},
        {"1100", 'c'}, {"1101", 'd'}, {"1110", 'e'}, {"1111", 'f'}
    };
    int s=bin.size();
    if(s%4!=0){
        int r=4-(s%4);
        while(r--)
            bin='0'+bin;
    }
    for(int i=0;i<bin.size();i+=4)
        ans+=hx[bin.substr(i,4)];
    cout<<ans<<endl;
    return 0;
}