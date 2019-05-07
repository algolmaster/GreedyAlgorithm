//
//  eBookstore.cpp
//  GreedyAlgorithm
//
//  Created by 신예지 on 01/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    for(int l=0; l<tc; l++) {
        int n, m;
        cin >> n >> m;
        
        int** menu = new int*[n];
        for(int i=0; i<n; i++) {
            menu[i] = new int[2*m];
            for(int j=0; j<2*m; j++) cin >> menu[i][j];
        }
        
        vector<int> finalPay;
        for(int i=0; i<m; i++) {
            vector<pair<int, int>> vec;
            int min =0;
            for(int k=0; k<n; k++) {
                vec.push_back(pair<int, int>(menu[k][2*i+1],menu[k][2*i]));
                min += menu[k][2*i];
            }
            sort(vec.begin(),vec.end(), greater<pair<int, int>>());
            
            int pay = vec[0].second;
            int rest = vec[0].first;
            for(int j=1; j<n; j++) {
                if(vec[j].second <= rest) {
                    rest -= vec[j].second;
                    rest += vec[j].first;
                }
                else {
                    pay += vec[j].second-rest;
                    rest = vec[j].first;
                }
            }
            finalPay.push_back(pay);
        }
        
        cout << *min_element(finalPay.begin(), finalPay.end());
    }
}
