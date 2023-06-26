#include <iostream>

using namespace std;

int main()
{
    int choice;
    double val1, val2;
    double somme=0, produit = 1, difference = 0, rapport=0;

    cout<<"Programme calculatrice\n"<<endl;
    cout<<"Nommbre\tOperation\n\n";
    cout<<"1:\tSomme\n2:\tProduit\n3:\tdifference\n4:\tRapport";
    cout<<"\n\nEnter your choice : ";

    cin>>choice;
    switch(choice){
        case 1:
            cout<<"\nEntrez un  nombre : ";
            cin>>val1;
            cout<<"Entrez un nombre : ";
            cin>>val2;
            cout<<val1<<" + "<<val2<<" = "<<val1+val2<<endl;
            break;
        case 2:
            cout<<"\nEntrez un  nombre : ";
            cin>>val1;
            cout<<"Entrez un nombre : ";
            cin>>val2;
            cout<<val1<<" + "<<val2<<" = "<<val1-val2<<endl;
            break;
        case 3:
            cout<<"\nEntrez un  nombre : ";
            cin>>val1;
            cout<<"Entrez un nombre : ";
            cin>>val2;
            cout<<val1<<" + "<<val2<<" * "<<val1-val2<<endl;
            break;
        case 4:
            cout<<"\nEntrez un  nombre : ";
            cin>>val1;
            cout<<"Entrez un nombre : ";
            cin>>val2;
            if(val2==0)
                cout<<"\nVotre valeur est nulle. Il y aura division par 0\n";
            cout<<val1<<" / "<<val2<<" = "<<val1/val2<<endl;
            break;
    }

    return 0;
}
