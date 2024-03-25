#include<bits/stdc++.h>
using namespace std;


void generateBinaryStringsHelper(int N, string crntStr, vector<string>& result) {
    if (crntStr.length() == N) {
        result.push_back(crntStr);
        return;
    }

    if (crntStr.empty() || crntStr[crntStr.length() - 1] == '0') {
        generateBinaryStringsHelper(N, crntStr + '0', result);
        generateBinaryStringsHelper(N, crntStr + '1', result);
    } else {
        generateBinaryStringsHelper(N, crntStr + '0', result);
    }
}



vector<string> generateString(int N) {
     vector<string> result;
    generateBinaryStringsHelper(N, "", result);
    return result;
}