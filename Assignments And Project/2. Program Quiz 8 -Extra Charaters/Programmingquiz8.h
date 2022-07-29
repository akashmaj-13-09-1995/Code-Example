#include <utility>
#include <iostream>
#include <map>
//#include <bits/stdc++.h>

using namespace std;

string findTheDigits(string x, string y) {
    map<char, int> data1, data2;
    for (int i = 0; i < x.size(); i++) {
        char str = x[i];
        map<char, int>::iterator itr = data1.find(str);
        if (itr != data1.end()) {
            data1[str] = data1[str] + 1;
        } else
        { data1[str] = 1; 
	}
    }
    //cout<<endl;
    for (int i = 0; i < y.size(); i++) {
        char str = y[i];
        map<char, int>::iterator itr = data2.find(str);
        if (itr != data2.end()) {
            data2[str] = data2[str] + 1;
        } else
		{data2[str] = 1;
	}
    }
    string ans = "";
   // for (int i = 0; i < y.size(); i++) {
        map<char, int>::iterator itr;
        for (itr = data2.begin(); itr != data2.end(); itr++) {
			char c= itr->first;
            map<char, int>::iterator itr2 = data1.find(c);
            if (itr2 == data1.end()) {
                int num = itr->second;
                while (num--) {
                    ans += itr->first;
                }
            } else {
                int num = itr->second - itr2->second;
                while (num--) {
                    ans += itr->first;
                }
            }
        }
   // }

    return ans;
}

int main(int argc, char** argv) {

    string s1, s2, s3;
    cin >> s1>>s2;

    s3 = findTheDigits(s1, s2);
    cout << s3;
    return 0;
}

