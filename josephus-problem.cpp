#include <iostream>
#include <cmath>
using namespace std;

int find_a(int n) {
    int a = 1;
    while(pow(2, a) <= n) {
        a++;
    }
    return a - 1;
}

int find_l(int n) {
    if(n == 1) {
        return 1;
    }
    return n - pow(2, find_a(n));
}

int josephus_solution(int n) {
    if(find_l(n) == 0 || n == 1) {
        return 1;
    } else {
        return (2 * find_l(n)) + 1;
    }
}

int main() {
  
    for(int i = 1; i <= 20; i++) {
        cout << josephus_solution(i) << "   ";
    }
    return 0;
}