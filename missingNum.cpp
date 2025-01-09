#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    cin >> n;

    int arr[n-1];

    for(int i=0; i<n-1; i++) {
        cin >> arr[i];
    }

    int Xor = 1;
    for(int i=1; i<=n; i++) {
        Xor ^= i;
    }

    int missing = 1;
    for(int i=0; i<n-1; i++) {
        missing ^= arr[i]; 
    }

    cout << (Xor^missing) << "\n";

    return 0;
}