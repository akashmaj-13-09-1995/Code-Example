#include <iostream>
#include<cstring>
#include <bits/stdc++.h>

using namespace std;

typedef map<string, int> web_ID_Map1;        

int main()
{
    int num1 , num2;  			//Initial input i.e. number of input and number of power iteration
    web_ID_Map1 dataMap1;       //Map to store the Web link and map that link with a unique id
    int id = 1;					//Use to initialize web link with this id and later we have incremented this id when ever we got a new web link 
    cin>>num1>>num2;
    num2--;						//For expected output, we reduce it to one less power iteration
    int a[2*num1][2*num1];   		//Adjacency Matrix
    float r[num1];				//Value to store power iteration
    float r2[num1];				//temp storage of power iteration
    float sum = 0;				//Use this in various places for different purpose like calculating individual out degree
    float M[2*num1][2*num1];		//Store the required matrix which need for doing power iteration
    memset(&M, 0, sizeof (M));
    memset(&a, 0, sizeof (a));
    memset(&r2, 0, sizeof (r2));
  
  memset(&r, 0, sizeof (r));

	//Making an Adjacency matrix and creating a map which will map each web link with a unique id 
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
    }
    
     //Calculating the out degree from each node
     for (int i = 0; i < dataMap1.size(); i++) {
        sum = 0;
        for (int j = 0; j < dataMap1.size(); j++) {
            sum += a[i][j];
        }
        r[i] = sum;
    }

    //Matrix with out degree value
    for (int i = 0; i < dataMap1.size(); i++) {
        for (int j = 0; j < dataMap1.size(); j++)
            if (a[j][i] == 1)
                if (r[j])
                    M[i][j] = 1 / r[j];
                else
                    M[i][j] = 0;
    }
   
    //Power column matrix
    for (int i = 0; i < dataMap1.size(); i++) {
        r[i] = dataMap1.size();
        r[i] = 1 / r[i];
    }

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
    web_ID_Map1::iterator itr = dataMap1.begin();
    for (; itr != dataMap1.end(); itr++) {
        cout << itr->first << " " << fixed << setprecision(2)<<r[itr->second - 1] << endl;
    }
    return 0;
}

