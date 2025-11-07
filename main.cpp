#include <iostream>

using namespace std;

 // Data array karakter, artefak, dan item
string list_karakter_S[5] = {"Argon", "Alexandria", "Prostius", "Dularia", "Golaria"};
string list_karakter_A[10]= {"Stella", "Warden", "Dargon", "Boravia", "Twilight Lich", "The Forgotten", "Gorgon", "Harbinger", "Kranvagn", "Stridsvan"};

string list_artefak_S[5] = {"Heart of the deep", "Skull of the deep", "Withering neckless", "Amulet of sturm", ".Glove of the ancient"};
string list_artefak_A[5] = {"Deck of ages", "Divine sharpness scroll", "Book of utheric", "Bone of the sea", "Corus Dram"};
string list_artefak_B[10] = {"Vibranium of ages", "The silenced note", "Dune of smith", "Smite Of dawn", "Mob masher", "Cursium of Ender", "Charm of mortal", "Charm of fire", "Charm of hydro", "Chains of borivia"};

string list_item_S[5] = {"Gem of the blood lord", "Gem of the mageslayer", "Godforged pearl", "Demonforged pearl", "Eye of hydra"};
string list_item_A[10] = {"Mortalforged pearl", "Demiforged pearl", "Luminous crystal shard", "Flawless gem", "Giga gem", "Andesite gem", "Zinc", "Coil", "Steel Malice", "Sheetmet"};
string list_item_B[20] = {"Brawler's gem", "Breach Gem", "Guardian Gem", "Witherbone", "Utheric Shard", "Cinder", "Salpeter", "Artisan", "Celestigem", "Dimerald", "Cytrine", "Iolite", "Alexandrite", "Theodrite", "Kyanite", "Tanzanite", "Alchemical Niter", "Diga Shard", "Lostrite Shard", "Diorite shard"};

// fungsi prototype
int main_menu(char menu);
void list_menu();
void list_template();
void listing(char list);

void test();

// fungsi utama
int main() {

    char menu, list;
    int role;

    main_menu(menu);

    cin >> menu;

    if (menu == '1') {
        cout << "menu gacha" << endl;
    } else if (menu == '2') {
        cout << "list item karakter" << endl;

        list_menu();
        cout << "________________________________________\n";
        cout << "Pilih opsi dengan angka : ";
        cin >> list;
        switch (list) {
            case '1':
                cout << "< karakter list >" << endl;
                listing(list); break;
            case '2':
                cout << "< Artefak List >" << endl;
                listing(list); break;
            case '3':
                cout << "< Item >" << endl;
                listing(list); break;
        }


        // for (int i = 0; i < 5; i++) {
        //     cout << "[" << i << "] : " << list_karakter_S[i] << endl;
        // }

        
    }

    test();

    return 0;
}

// fungsi main menu ketika awal menjalankan program
int main_menu(char menu) {
    cout << "\n<====================> RANDOM ITEM AND CHARACTER <====================>\n\n";
    cout << "Random item and character adalah sebuah program untuk mendapatkan item dan karakter secara random" << endl << endl;
    cout << "       [1] : MAIN" << endl;
    cout << "       [2] : LIST ITEM DAN KARAKTER" << endl << endl;

    cout << "Pilih dengan angka : ";

    return 0;
}

// fungsi untuk melihat list karakter, artefak, dan item
void list_menu() {
    cout << "\n<====================> LIST ITEM AND CHARACTER <====================>\n\n";
    cout << "Lihat daftar rangking " << endl << endl;
    cout << "       [1] : Character" << endl;
    cout << "       [2] : Artefak" << endl;
    cout << "       [3] : Item" << endl;
    cout << "       [X] : Kembali" << endl;
}

// fungsi looping dari array agar bisa tampil ke fungsi utama
void listing(char list) {
    
    if (list == '1') {
        cout << "\n==========> RANK S" << endl;
    
        for (int i = 0; i < 5; i++) {
        cout << "[" << i+1 << "] : " << list_karakter_S[i] << endl;
        }
        cout << endl;

        cout << "\n==========> RANK A" << endl;
        for (int i = 0; i < 10; i++) {
            cout << "[" << i+1 << "] : " << list_karakter_A[i] << endl;
        }
    } else if (list == '2') {
        cout << "\n==========> RANK S" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "[" << i+1 << "] : " << list_artefak_S[i] << endl; 
        }

        
        cout << "\n==========> RANK A" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "[" << i+1 << "] : " << list_artefak_A[i] << endl;
        }

        cout << "\n==========> RANK B" << endl;
        for (int i = 0; i < 10; i++) {
            cout << "[" << i+i << "] : " << list_artefak_B[i] << endl;
        }
    } else if (list == '3') {
        cout << "\n==========> RANK S" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "[" << i+1 << "] : " << list_item_S[i] << endl;
        }

        cout << "\n==========> RANK A" << endl;
        for (int i = 0; i < 10; i++) {
            cout << "[" << i+1 << "] : " << list_item_A[i] << endl;
        }

        cout << "\n==========> RANK B" << endl;
        for (int i = 0; i < 20; i++) {
            cout << "[" << i+1 << "] : " << list_item_B[i] << endl;
        }
    }
}

void list_template() {
  
}

// fungsi tes untuk debug
void test() {
    cout << endl << "ini tes apakah melanjutkan atau tidak" << endl;
}