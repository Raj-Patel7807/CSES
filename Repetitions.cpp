#include <iostream>
using namespace std;

int main() {
    
    string dna;
    int count = 1, maxCount = 1;

    cin >> dna;

    for(int i=0; dna[i]!='\0'; i++) {
        if(dna[i] == dna[i-1]) {
            count++;
            maxCount = max(maxCount, count);
        } else {
            count = 1;
        }
    }

    cout << maxCount << endl;

    return 0;
}