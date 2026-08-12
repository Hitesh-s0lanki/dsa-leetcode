#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> sequentialDigits(int low, int high) {
    
    // using the bfs approach 
    queue<int> que;

    for(int i = 1; i < 9; i++)
        que.push(i);
    
    // result 
    vector<int> result;

    while(!que.empty()){
        int front = que.front();
        que.pop();

        if(front >= low && front <= high)
            result.push_back(front);

        // get the last digit 
        int last_digit = front % 10;
        
        if (last_digit + 1 <= 9){
            int nextNum = (front * 10) + (last_digit + 1);
            if (nextNum <= high)
                que.push(nextNum);
        }

    }
    
    return result;
}

int main() {

    vector<int> ans = sequentialDigits(100, 300);

    for(int i:ans)
        cout<<i<<", ";
    cout<<endl;

    return 0;
}