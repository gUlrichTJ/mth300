#include <iostream>

using namespace std;

int main()
{
    int ageUtilisateur(24);
    int& maReference(ageUtilisateur);
    cout<<"\nFelicitation Monsieur. Vous avez "<<maReference<<" ans\n";
    cout << "Hello world!" << endl;

    return 0;
}
