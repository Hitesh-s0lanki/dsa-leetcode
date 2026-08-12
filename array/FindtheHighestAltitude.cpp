#include <iostream>
#include <vector>

using namespace std;

int largestAltitude(vector<int>& gain) {
    int highestPeak = 0;
    int dist = 0;

    for(int i = 0; i < gain.size(); i++){
        dist = gain[i] + dist; 
        highestPeak = max(dist, highestPeak);
    }

    return highestPeak;
}

int main() {

    vector<int> gain = {-5,1,5,0,-7};

    cout<<"Higheest peak is this  : "<<largestAltitude(gain) << endl;

    return 0;
}