#include <iostream>
#include <math.h>
#include <list>

using namespace std;

int N;
int licznik;
std::list<int>ilosc;
int main()
{
    cout << "Ile zestawow chcesz wpisac (od 1 do 20k) : ?" << endl;
    cin >> N;
    while (N < 1 || N > 20000)
    {
        cout << "Ilosc zestawow jest za mala lub za duza!\n";
        cin >> N;
    }
    int *a = new int[N];
    int *b = new int[N];
    for (int i = 0; i<N; i++)
    {
        cout << "Podaj pierwsza liczbe otwierajaca przedzial (od 2)\n";
        cin >> a[i];
        while (a[i] < 2)
        {
            cout << "Liczba jest za mala!\n";
            cin >> a[i];
        }
        cout << "Podaj druga liczbe zamykajaca przedzial (wieksza niz a)\n";
        cin >> b[i];
        while (b[i] < a[i] || b[i] > pow(10,6))
        {
            cout << "Druga liczba jest za duza lub za mala!\n";
            cin >> b[i];
        }
    }
    for (int i = 0; i<N; i++)
    {
        for (int j =a[i]; j < b[i]; j++)
            for (int k=2; k*k<=j; k++)
            {
                if (j == 2) {
                    ilosc.push_front(j);
                }
                if (j % k == 0) {
                    break;
                }
                else if (k+1 > sqrt(j))
                {
                    ilosc.push_front(j);
                }
            }
        cout << a[i] << " " << b[i] << "\n";
        cout << ilosc.size() << endl;
        ilosc.resize(0);
    }
    delete [] a;
    delete [] b ;

        return 0;
}
