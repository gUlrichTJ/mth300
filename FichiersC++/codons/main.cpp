#include <iostream>
#include <vector>

using namespace std;

/// Function that will return the second smallest element
void secondSmallestElement() {
    int const N = 10;
    int i = 0;
    vector<int> elements(N);

    //
    for (i = 0; i < N; i++) {
        cout << "Element " << i + 1 << " : ";
        cin >> elements[i];
    }

    // Display
    for (i = 0; i < N; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;
   // return 0;
}

int main()
{
    secondSmallestElement();
    cout << "Hello world!" << endl;
    return 0;
}
