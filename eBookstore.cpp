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
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int** menu = new int*[n];
    for(int i=0; i<n; i++) {
        menu[i] = new int[2*m];
        for(int j=0; j<2*m; j++) cin >> menu[i][j];
    }
    
    int* price = new int[m];
    for(int i=0; i<m; i++) {
        vector<pair<int, int>> vec;
        int book=0, point=0;
        
        for(int k=0; k<n; k++)
            vec.push_back(pair<int, int>(menu[k][2*i+1],menu[k][2*i]));
        sort(vec.begin(),vec.end(), greater<pair<int, int>>());
        
        for(int k=0; k<n-1; k++) point += vec[k].first;
        for(int k=0; k<n; k++) book += vec[k].second;
        price[i] = book-point;
    }
    
    int smallPrice = price[0];
    for(int i=1; i<m; i++) if(smallPrice>price[i]) smallPrice=price[i];
    
    cout << smallPrice;
}
