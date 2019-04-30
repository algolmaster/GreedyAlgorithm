//
//  rope.cpp
//  GreedyAlgorithm
//
//  Created by 신예지 on 01/05/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> rope;
    int num;
    for(int i=0; i<n; i++) {
        cin >> num;
        rope.push_back(num);
    }
    sort(rope.begin(), rope.end(), greater<int>());
    
    int max = rope[0];
    int cnt = 1;
    for(int i=1; i<n; i++) {
        int temp = ++cnt*rope[i];
        if(max<temp) max=temp;
    }
    cout << max;
}
