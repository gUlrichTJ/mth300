#include <iostream>
#include <vector>

using namespace std;

// Average
double averages(int tab[], int N) {
    double average = 0;
    for (int i = 0; i < N; i++) {
        cout << "Mark " << i + 1 << " : ";
        cin >> tab[i];
        average += tab[i];
    }
    return average / N;
}
/// Function that will return the second smallest element
void secondSmallestElement() {
    int N = 10;
    int i = 0, j = 0, index = 0;
    int help = 0;
    int helps[N];
    vector<int> elements(N);

    //
    for (i = 0; i < N; i++) {
        cout << "Element " << i + 1 << " : ";
        cin >> elements[i];
    }

    // Display
    cout << "\nElements entered \n";

    for (i = 0; i < N; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;

    // We are gonna range them in croissant order
    for (i = 0; i < N; i++) {
        help = elements[i];
        for (j = 0; j < N - i; j++) {
            // We see if help is greater than this number
            if (help > elements[j]) {
                help  = elements[j];
                index = j;
            }
        }
        for (j = index; j < N; j++) {
            elements[j] = elements[j + 1];
        }

        helps[i] = help;
    }

    for (i = 0; i < 10; i++) {
        cout << helps[i] << " ";
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
