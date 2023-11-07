//
// Created by renec on 6/4/2023.
//
#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool inLanguage(char* theString)
{
    string testS = theString;
    stack<char> ab;
    bool abst = false;

    for(int i = 0; i < testS.length(); i++){
        if(abst){
            if(!ab.empty()){
                ab.pop();
                abst = false;
            }
        }
        else if(theString[i] == 'A' || theString[i] =='B' ) {
            ab.push(theString[i]);
            abst = true;
            continue;
        }
        else if(theString[i] != 'A' && theString[i] != 'B'){
            return false;
        }
    }

    if(ab.empty()){
        return true;
    }
    else{
        return false;
    }

}

int main(){
    char* test = "A";
    bool result = inLanguage(test);
    cout << "1 means true, 0 means false: " << result;
}