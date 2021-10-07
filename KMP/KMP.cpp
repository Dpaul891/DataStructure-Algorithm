#include <iostream>
#include <vector>
#include <string>
using namespace std;

void builMatch(string& needle, vector<int>& match){
    int m = needle.size();
    match[0] = -1;
    for(int j=1; j<m; j++){
        int pre = match[j-1];
        while(pre>=0 && needle[j] != needle[pre+1]){
            pre = match[pre];
        }
        if(needle[j] == needle[pre+1])
            match[j] = pre + 1;
        else 
            match[j] = -1;
    }
}
int KMP(string& haystack, string& needle, vector<int>& match){
    int n = haystack.size();
    int m = needle.size();
    int s=0, p=0;
    while(s<n && p<m){
        if(haystack[s] == needle[p]) {s++; p++;}
        else if(p>0) {p = match[p-1]+1;}
        else {s++;}
    }
    if(p == m)  return s-m;
    else return -1;

}
int main()
{
    string haystack = "hello";
    string needle = "ll";
    int m = needle.size();
    if(m == 0) return 0;
    vector<int> match(m);
    builMatch(needle, match);
    cout << KMP(haystack, needle, match) << endl;
    return 0;
}