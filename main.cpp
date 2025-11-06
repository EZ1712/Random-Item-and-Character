#include <iostream>

using namespace std;

string list_karakter_S[4] = {"skibidi", "george", "hitler", "icikiwir"};

int main_menu(char menu);


int main() {
    char menu;

    main_menu(menu);

    return 0;
}

int main_menu(char menu) {
    cout << "\n<====================> RANDOM ITEM AND CHARACTER <====================>\n\n";
    cout << "Random item and character adalah sebuah program untuk mendapatkan item dan karakter secara random" << endl << endl;
    cout << "       [1] : MAIN" << endl;
    cout << "       [2] : LIST ITEM DAN KARAKTER" << endl << endl;

    cout << "Pilih dengan angka : ";
    cin >> menu;

    if (menu == '1') {
        cout << "menu gacha" << endl;
    } else if (menu == '2') {
        cout << "list item karakter" << endl;

        for (int i = 0; i < 4; i++) {
            cout << list_karakter_S[i] << endl;
        }

        
    }

    return 0;
}