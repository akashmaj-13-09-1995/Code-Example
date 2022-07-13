#include <iostream>
#include<cstring>
#include <bits/stdc++.h>
using namespace std;
typedef map<string, int> web_ID_Map1;;        

int main()
{
    int num1 , num2;
    web_ID_Map1 dataMap1;
    int id = 1;
    cin>>num1>>num2;
    num2--;
    int a[num1][num1];
    float r[num1];
    float r2[num1];
    float sum = 0;
    float M[num1][num1];
    memset(&M, 0, sizeof (M));
    memset(&a, 0, sizeof (a));
    
    for (int i = 0; i < num1; i++) {
        int ii, jj;
        string str1 ;
        string str2 ;
        cin>>str1>>str2;
        web_ID_Map1::iterator ele1 = dataMap1.find(str1);
        if (ele1 == dataMap1.end()) {
            dataMap1.insert(make_pair(str1, id));
            ii = id;
            id++;
        } else {
            ii = dataMap1[str1];
        }

        web_ID_Map1::iterator ele2 = dataMap1.find(str2);
        if (ele2 == dataMap1.end()) {
            dataMap1.insert(make_pair(str2, id));
            jj = id;
            id++;
        } else {
            jj = dataMap1[str2];
        }
        a[ii - 1][jj - 1] = 1;
 //       cout << ii << " " << jj << endl;
    }
    
     for (int i = 0; i < dataMap1.size(); i++) {
        sum = 0;
        for (int j = 0; j < dataMap1.size(); j++) {
            sum += a[i][j];
        }
        r[i] = sum;
 //       cout << sum << endl;
    }
    
    
 //   cout << "Out Degree" << endl;
 //   for (int j = 0; j < dataMap1.size(); j++)
 //       cout << r[j] << " ";
  //  cout << endl;
 //   cout << endl;
  //  cout << endl;
    //Matrix with outdegree value
    for (int i = 0; i < dataMap1.size(); i++) {
        for (int j = 0; j < dataMap1.size(); j++)
            if (a[j][i] == 1)
                if (r[j])
                    M[i][j] = 1 / r[j];
                else
                    M[i][j] = 0;
    }
    
//          for (int i = 0; i < dataMap1.size(); i++) {
 //           for (int j = 0; j < dataMap1.size(); j++)
 //               cout << a[i][j] << " ";
  //          cout << endl;
  //      }

   // cout << endl;

    //Power colum matrix
    for (int i = 0; i < dataMap1.size(); i++) {
        r[i] = dataMap1.size();
        r[i] = 1 / r[i];
 //       for (int j = 0; j < dataMap1.size(); j++)
  //          cout << M[i][j] << " ";
  //      cout << endl;
    }


//    cout << endl;
 //   for (int j = 0; j < dataMap1.size(); j++)
 //       cout << r[j] << " ";
 //   cout << endl;
    
    //Power Iterations
    while (num2--) {
        for (int i = 0; i < dataMap1.size(); i++) {
            sum = 0;
            for (int j = 0; j < dataMap1.size(); j++)
                sum += (M[i][j] * r[j]);
            r2[i] = sum;
        }
        for (int j = 0; j < dataMap1.size(); j++)
            r[j] = r2[j];
    }

 //   cout << endl;
 //   for (int j = 0; j < dataMap1.size(); j++)
 //       cout << r[j] << " ";

 //   cout << endl;
 //   cout << endl;

  //  for (int i = 0; i < dataMap1.size(); i++) {
  //      for (int j = 0; j < dataMap1.size(); j++)
  //          cout << M[i][j] << " ";
  //      cout << endl;
  //  }
    
    
    web_ID_Map1::iterator itr = dataMap1.begin();
    for (; itr != dataMap1.end(); itr++) {
        cout << itr->first << " " << fixed << setprecision(2)<<r[itr->second - 1] << endl;
    }

    return 0;
}