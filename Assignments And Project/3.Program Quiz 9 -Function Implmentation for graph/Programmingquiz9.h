#include <vector> 
#include <utility>
#include <iostream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PAIR;
typedef pair<PAIR, int> PAIR_WEIGHT;

typedef vector<PAIR_WEIGHT> ALL_DATA;
ALL_DATA allData;

void insertEdge(int from, int to, int weight) {
    PAIR tempPair;
    tempPair.first = from;
    tempPair.second = to;
    allData.push_back(make_pair(tempPair, weight));

    //    vector<int>::iterator it;
    //    it= std::find(allNodes.begin(), allNodes.end(), from);
    //    if (it == allNodes.end()) 
    //    allNodes.push_back(from);
    //    
    //    it= std::find(allNodes.begin(), allNodes.end(), to);
    //    if (it == allNodes.end()) 
    //    allNodes.push_back(to);
}

bool isEdge(int from, int to) {
    PAIR tempPair;
    tempPair.first = from;
    tempPair.second = to;
    ALL_DATA::iterator itr;
    for (itr = allData.begin(); itr != allData.end(); itr++) {
        PAIR_WEIGHT tempPairWeight = *itr;
        if ((tempPair.first == tempPairWeight.first.first)&&(tempPair.second == tempPairWeight.first.second))
            return true;
        else
            return false;
    }
    return false;
}

int sumEdge(int from, int to) {
    int sum = 0;
    PAIR tempPair;
    tempPair.first = from;
    tempPair.second = to;
    ALL_DATA::iterator itr;
    for (itr = allData.begin(); itr != allData.end(); itr++) {
        PAIR_WEIGHT tempPairWeight = *itr;
        if ((tempPair.first == tempPairWeight.first.first)&&(tempPair.second == tempPairWeight.first.second))
            sum += tempPairWeight.second;
    }
    return sum;
}

vector<int> getWeight(int from, int to) {
    vector<int> temVec;
    PAIR tempPair;
    tempPair.first = from;
    tempPair.second = to;
    ALL_DATA::iterator itr;
    for (itr = allData.begin(); itr != allData.end(); itr++) {
        PAIR_WEIGHT tempPairWeight = *itr;
        if ((tempPair.first == tempPairWeight.first.first)&&(tempPair.second == tempPairWeight.first.second))
            temVec.push_back(tempPairWeight.second);
    }
    sort(temVec.begin(), temVec.end());
    return temVec;
}

vector<int> getAdjacent(int vertex) {
    vector<int> temVec;
    ALL_DATA::iterator itr;
    for (itr = allData.begin(); itr != allData.end(); itr++) {
        PAIR_WEIGHT tempPairWeight = *itr;
        if ((vertex == tempPairWeight.first.first)) {
            vector<int>::iterator itr = std::find(temVec.begin(), temVec.end(), tempPairWeight.first.second);
            if (itr == temVec.end())
                temVec.push_back(tempPairWeight.first.second);
        }
    }
    sort(temVec.begin(), temVec.end());
    return temVec;
}

int main(int argc, char** argv) {

    int num_of_operation;
    int operation, firstNode, secondNode, weight;
    vector<int> temVec2;
    cin>>num_of_operation;

    while (num_of_operation--) {
        cin >> operation;
        switch (operation) {
            case 1: cin >> firstNode>>secondNode;
                cin>>weight;
                insertEdge(firstNode, secondNode, weight);
                break;
            case 2:cin >> firstNode>>secondNode;
                cout << isEdge(firstNode, secondNode)<<endl;
                break;
            case 3:cin >> firstNode>>secondNode;
                cout << sumEdge(firstNode, secondNode)<<endl;
                break;
            case 4:cin >> firstNode>>secondNode;
                temVec2.clear();
                temVec2 = getWeight(firstNode, secondNode);
                for (int i = 0; i < temVec2.size(); i++) {
                    cout << temVec2[i] << " ";
					
                }cout<<endl;
                break;
            case 5: cin>>firstNode;
                temVec2.clear();
                temVec2 = getAdjacent(firstNode);
                for (int i = 0; i < temVec2.size(); i++) {
                    cout << temVec2[i] << " ";
                }	cout<<endl;
                break;
        }
    }
    return 0;
}

