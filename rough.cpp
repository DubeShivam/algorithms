#include <iostream>
#include <vector>
#include <string>
using namespace std;

int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);

        for(int i = 0; i < ratings.size(); i++) {
            if(i-1 > -1 && i+1 < ratings.size()) {
                if(ratings[i] > ratings[i-1] || ratings[i] > ratings[i+1]) 
                    candies[i] += 1;
            } else if(i-1 > -1) {
                if(ratings[i] > ratings[i-1]) 
                    candies[i] += 1;
            } else if(i+1 < ratings.size()) {
                if(ratings[i] > ratings[i+1])
                    candies[i] += 1; 
            }
        }

        for(int i = 0; i < candies.size()-1; i++) {
            if(candies[i] == candies[i+1]) {
                if(ratings[i] > ratings[i+1]) {
                    candies[i] += 1;
                } else {
                    candies[i+1] +=1;
                }
            }
        }

        for(int x: ratings) 
            cout << x << " ";
        cout << endl;

        for(int x: candies) 
            cout << x << " ";
        cout << endl;

        int sum = 0;

        for(int i = 0; i < candies.size(); i++) {
            sum += candies[i];
        }
        return sum;
}

int main() {
    
    vector<int> v = {1,2,87,87,87,2,1};

    cout << candy(v);

    return 0;
}