//
//  participateOrder.cpp
//  GreedyAlgorithm
//
//  Created by 신예지 on 30/04/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    for(int k=0; k<tc; k++) {
        int n;
        cin >> n;
        
        vector<int> teamA;
        vector<int> teamB;
        
        int maxCompetiton = 0;
        
        int num;
        for(int i=0; i<n; i++) {
            cin >> num;
            teamA.push_back(num);
        }
        for(int i=0; i<n; i++) {
            cin >> num;
            teamB.push_back(num);
        }
        sort(teamA.begin(), teamA.end());
        sort(teamB.begin(), teamB.end());
        
        for(int i=0; i<n; i++) {
            
            if(teamA[i]<teamB[0]) {
                maxCompetiton++;
                i++;
            }
            for(vector<int>::iterator iter=teamB.begin(); iter!=teamB.end(); iter++) {
                if(teamA[i]<=*iter) {
                    teamB.erase(iter);
                    maxCompetiton++;
                    break;
                }
            }
        }
        cout << maxCompetiton << endl;
    }
}
