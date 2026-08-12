#include <iostream>
#include <vector>

using namespace std;

int maxNumberOfBalloons(string text) {
    vector<int> freq(26, 0);

    for (char ch : text) {
        freq[ch - 'a']++;
    }

    return min({
        freq['b' - 'a'],
        freq['a' - 'a'],
        freq['l' - 'a'] / 2,
        freq['o' - 'a'] / 2,
        freq['n' - 'a']
    });
}

int maxNumberOfBalloonsBrute(string text) {

    string finalText = "balloon";

    vector<int> freq(26, 0);
    int ans = 0;


    // increase all the lettere frequency 
    for(char ch:text){
        freq[ch - 'a']++;
    }

    bool canCheck = true;
    //check the freq for the balloon
    while(canCheck){
        for(char ch:finalText){
            if(freq[ch - 'a'] > 0){
                freq[ch - 'a']--;
            } else {
                canCheck = false;
                break;
            }
        }
        if(canCheck)
            ans++;
    }

    return ans;
}

int main() {

    string text = "nlaebolko";

    cout<<"Number of the instanse = "<<maxNumberOfBalloons(text)<<endl;

    return 0;
}