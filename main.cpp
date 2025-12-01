#include <iostream>
#include <string>
#include <array>
#include <random>
#include <cctype>
#include <stdlib.h>

using namespace std;

// Data struct
// Karakter Data
struct karakter {
    string nama;
    char rank;
    string elemental;
    string type;
};

// Artefak Data
struct artefak {
    string nama;
    char rank;
    string elemental;
    float crit_rate;
    float crit_damage;
}; 

// Item Data
struct item {
    string nama;
    char rank;
    string element;
    string buffs;
    string status_effect;    

};

// Data Prototype
array<karakter, 5> data_karakter_S();
array<karakter, 10> data_karakter_A();

array<artefak, 5> data_artefak_S();
array<artefak, 5> data_artefak_A();
array<artefak, 10> data_artefak_B();

array<item, 5> data_item_S();
array<item, 10> data_item_A();
array<item, 20> data_item_B();

// fungsi prototype
void main_menu();
void play_menu();
void list_menu();
void info();

void list_karakter();
void list_artefak();
void list_item();

void gacha_karakter_menu();
void gacha_karakter_1();
void gacha_karakter_10();

void gacha_artefak_menu();
void gacha_artefak_1();
void gacha_artefak_10();

void gacha_item_menu();
void gacha_item_1();
void gacha_item_10();

void card(char rank);

// Fungsi Random Number
int random_value() {
    random_device rd;
    uniform_int_distribution distribution(1 ,100);

    // cout << distribution(rd) << endl;
    return distribution(rd);
};

int gacha_value(int max_size);
int pity = 80;

// fungsi utama
int main() {

    main_menu();

    return 0;
}

// Data Karakter, Artefak, dam Item

// Karakter Data / Karakter Data / Karakter Data / Karakter Data / Karakter Data 
array<karakter, 5> data_karakter_S() {
    array<karakter, 5> karakter_S; 

    karakter_S[0] = {"Argon", 'S', "Electro", "Human"};
    karakter_S[1] = {"Alexandria", 'S', "Ice", "Demon"};
    karakter_S[2] = {"Prostius", 'S', "Fire", "Demigod"};
    karakter_S[3] = {"Dularia", 'S' , "Hydro", "Demon"};
    karakter_S[4] = {"Golaria", 'S', "Fire", "Human"};

    return karakter_S;
}

array<karakter, 10> data_karakter_A() {
    array<karakter, 10> karakter_A;

    karakter_A[0] = {"Boravia", 'A', "Ice", "Human"};
    karakter_A[1] = {"Twilight Lich", 'A', "Fire", "Demon"};
    karakter_A[2] = {"The Forgotten", 'A', "Hydro", "Demigod"};
    karakter_A[3] = {"stella", 'A', "Fire", "Human"};
    karakter_A[4] = {"Warden", 'A', "Ice", "Human"};
    karakter_A[5] = {"Gorgon", 'A', "Hydro", "Demon"};
    karakter_A[6] = {"Dargon", 'A', "Elektro", "Demigod"};
    karakter_A[7] = {"Harbinger", 'A', "Fire", "Demon"};
    karakter_A[8] = {"Kranvagn", 'A', "Ice", "Human"};
    karakter_A[9] = {"Stridsvan", 'A', "Hydro", "Demigod"};

    return karakter_A;
}

// Artefak Data / Artefak Data / Artefak Data / Artefak Data / Artefak Data  
array<artefak, 5> data_artefak_S() {
    array<artefak, 5> artefak_S; 

    artefak_S[0] = {"Heart of the deep", 'S', "Fire", 36, 74};
    artefak_S[1] = {"Skull of the deep", 'S', "Hydro", 33, 68};
    artefak_S[2] = {"Withering neckless", 'S', "Elektro", 38, 77};
    artefak_S[3] = {"Amulet of sturm", 'S', "Ice", 31, 63};
    artefak_S[4] = {"Glove of the ancient", 'S', "Hydro", 40, 80};

    return artefak_S;
}

array<artefak, 5> data_artefak_A() {
    array<artefak, 5> artefak_A;

    artefak_A[0] = {"Deck of ages", 'A', "Fire", 22, 45};
    artefak_A[1] = {"Divine sharpness scroll", 'A', "Ice", 17, 33};
    artefak_A[2] = {"Book of utheric", 'A', "Elektro", 19, 39};
    artefak_A[3] = {"Bone of the sea", 'A', "Ice", 15, 30};
    artefak_A[4] = {"Corus Dram", 'A', "Fire", 24, 48};

    return artefak_A;
}

array<artefak, 10> data_artefak_B() {
    array<artefak, 10> artefak_B;
    
    artefak_B[0] = {"Vibranium of ages", 'B', "Hydro", 9, 21};
    artefak_B[1] = {"The silenced note", 'B', "Fire", 6, 14};
    artefak_B[2] = {"Dune of smith", 'B', "Electro", 5, 10};
    artefak_B[3] = {"Smite Of dawn", 'B', "Hydro", 7, 18};
    artefak_B[4] = {"Mob masher", 'B', "Ice", 10, 25};
    artefak_B[5] = {"Cursium of Ender", 'B', "Wind", 8, 19};
    artefak_B[6] = {"Charm of mortal", 'B', "Earth", 5, 11};
    artefak_B[7] = {"Charm of fire", 'B', "Shadow", 6, 13};
    artefak_B[8] = {"Charm of hydro", 'B', "Light", 7, 17};
    artefak_B[9] = {"Chains of borivia", 'B', "Toxin", 9, 12};

    return artefak_B; 
}

// Item Data / Item Data / Item Data / Item Data / Item Data 
array<item, 5> data_item_S() {
    array<item, 5> item_S;

    item_S[0] = {"Gem of the blood lord", 'S', "Hydro", "30% Life Steal", "Bleed on Hit"};
    item_S[1] = {"Gem of the mageslayer", 'S', "Fire", "25% Magic Resist", "Silence on Hit"};
    item_S[2] = {"Godforged pearl", 'S', "Ice", "20% All Stats", "Burn Aura"};
    item_S[3] = {"Demonforged pearl", 'S', "Elektro", "40% Fire Damage", "Poison"};
    item_S[4] = {"Eye of hydra", 'S', "Shadow", "20% Multi-hit Chance", "Slow on Hit"};

    return item_S;
}

array<item, 10> data_item_A() {
    array<item, 10> item_A;

    item_A[0] = {"Mortalforged pearl", 'A', "Wind", "15% Physical Damage", "Minor Blind Aura"};
    item_A[1] = {"Demiforged pearl", 'A', "Earth", "10% Elemental Resist", "Bleed Chance"};
    item_A[2] = {"Luminous crystal shard", 'A', "Fire", "10% Mana Regen", "Daze"};
    item_A[3] = {"Flawless gem", 'A', "Toxin", "10% To two random Stats", "Weaken Armor"};
    item_A[4] = {"Giga gem", 'A', "Light", "20% Max HP", "Disorient"};
    item_A[5] = {"Andesite gem", 'A', "Hydro", "10% Defense", "Mark Target"};
    item_A[6] = {"Zinc", 'A', "Ice", "5% Attack Speed", "chill"};
    item_A[7] = {"Coil", 'A', "Elektro", "10% Energy Regen", "Sap Energy"};
    item_A[8] = {"Steel Malice", 'A', "Fire", "10% Damage", "Interrup Casting"};
    item_A[9] = {"Sheetmet", 'A', "Shadow", "10% Block Chance", "Cripple Movement"};

    return item_A; 
}

array<item, 20> data_item_B() {
    array<item, 20> item_B;

    item_B[0] = {"Brawler's gem", 'B', "Earth", "5% melee Damage", "Stun" };
    item_B[1] = {"Breach Gem", 'B', "Wind", "3% Armor Penetration", "Weakness"};
    item_B[2] = {"Guardian Gem", 'B', "Toxin", "5% HP", "Burn on Attacker"};
    item_B[3] = {"Witherbone", 'B', "Ice", "3% Magic Resist", "Slow Duration"};
    item_B[4] = {"Utheric Shard", 'B', "Light", "5% Fire Resist", "Silence Resist"};
    item_B[5] = {"Cinder", 'B', "Fire", "3% Explosion Radius", "Blind"};
    item_B[6] = {"Salpeter", 'B', "Hydro", "5% Crafting Speed", "Fear"};
    item_B[7] = {"Artisan", 'B', "Elektro", "3% Light Damage", "Root"};
    item_B[8] = {"Celestigem", 'B', "Shadow", "3% Poison Resist", "Curse"};
    item_B[9] = {"Dimerald", 'B', "Earth", "2% Crit Chance", "Confuse"};
    item_B[10] = {"Cytrine", 'B', "Fire", "Spell Haste", "Sap Mana"};
    item_B[11] = {"Iolite", 'B', "Ice", "2% Luck", "Chill"};
    item_B[12] = {"Alexandrite", 'B', "Wind", "3% Earth Resist", "Cripple"};
    item_B[13] = {"Theodrite", 'B', "Toxin", "2% Ice Resist", "Mark"};
    item_B[14] = {"Kyanite", 'B', "Light", "2% Magic Damage", "Disorient"};
    item_B[15] = {"Tanzanite", 'B', "Hydro", "2% Potion Effectiveness", "Interrupt"};
    item_B[16] = {"Alchemical Niter", 'B', "Fire", "2% Dig Speed", "Daze"};               
    item_B[17] = {"Diga Shard", 'B', "Electro", "2% Evasion", "Sap Energy"};
    item_B[18] = {"Lostrite Shard", 'B', "Ice", "2% Knockbck Resist", "Weaken Armor"};
    item_B[19] = {"Diorite shard", 'B', "Shadow", "2% Fire Resist", "Bleed"};


    return item_B;
}




// fungsi main menu ketika awal menjalankan program
void main_menu() {
    system("cls");
    char pilih;
    int alret = 0;

    do {
        cout << "\n<====================> RANDOM ITEM AND CHARACTER <====================>\n\n";
        cout << "Random item and character adalah sebuah program untuk mendapatkan item dan karakter secara random" << endl << endl;
        cout << "       [1] : Play" << endl;
        cout << "       [2] : List" << endl;
        cout << "       [3] : Info" << endl;
        cout << "       [X] : Exit" << endl;

        cout << "-------------------------------------" << endl;
        if (alret > 0) {
            cout << "Pilih dengan angka [Input Invalid] : ";
        } else {
            cout << "Pilih dengan angka : ";
        }
        alret++;
        cin >> pilih;

        switch (toupper(pilih)) {
            case '1':
                play_menu(); break;
            case '2':
                list_menu(); break;
            case '3':
                info(); break;
            case 'X':
                exit(0);
                break;
        }


    } while (pilih != 'X');

}

// Play Menu Funtion
void play_menu() {
    system("cls");

    char pilih;
    // int alret = 0;

    // do {    
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " | [1] : RANDOM CHARACTER |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "     " << "  ____ _           _            ____                 _                 " << endl;
        cout << " |                        |" << " | " << "     " << " / ___| |__   ___ (_) ___ ___  |  _ \\ __ _ _ __   __| | ___  _ __ ___  " << endl;
        cout << " | [2] : RANDOM ARTEFAK   |" << " | " << "     " << "| |   | '_ \\ / _ \\| |/ __/ _ \\ | |_) / _` | '_ \\ / _` |/ _ \\| '_ ` _ \\ " << endl;
        cout << " |                        |" << " | " << "     " << "| |___| | | | (_) | | (_|  __/ |  _ < (_| | | | | (_| | (_) | | | | | |" << endl;
        cout << " |                        |" << " | " << "     " << " \\____|_| |_|\\___/|_|\\___\\___| |_| \\_\\__,_|_| |_|\\__,_|\\___/|_| |_| |_|" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " | [3] : RANDOM ITEM      |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << " |   [X] : Kembali   |   ";
        cin >> pilih;


        switch (toupper(pilih)) {
            case '1':
                gacha_karakter_menu(); break;
            case '2':
                gacha_artefak_menu(); break;
            case '3':
                gacha_item_menu(); break;
            case 'X':
                main_menu();
        };

    //  } while (alret != 0);
}

int gacha_value(int max_size) {
    random_device rd;
    uniform_int_distribution distribution(0 ,(max_size-1));

    // cout << distribution(rd) << endl;
    return distribution(rd);
}


// Gacha Karakter // Gacha Karakter // Gacha Karakter // Gacha Karakter // Gacha Karakter // Gacha Karakter // Gacha Karakter // Gacha Karakter // Gacha Karakter // Gacha Karakter // Gacha Karakter 
void gacha_karakter_menu() {
    system("cls");

    char pilih,gacha;
    // int alret = 0;

    // do {    
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |    RANDOM CHARACTER    |" << " | " << "" << endl;
        cout << " |       [SELECTED]       |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "     " << " ____                 _                   _  __               _    _            " << endl;
        cout << " |                        |" << " | " << "     " << "|  _ \\ __ _ _ __   __| | ___  _ __ ___   | |/ /__ _ _ __ __ _| | _| |_ ___ _ __ " << endl;
        cout << " |     RANDOM ARTEFAK     |" << " | " << "     " << "| |_) / _` | '_ \\ / _` |/ _ \\| '_ ` _ \\  | ' // _` | '__/ _` | |/ / __/ _ \\ '__|" << endl;
        cout << " |                        |" << " | " << "     " << "|  _ < (_| | | | | (_| | (_) | | | | | | | . \\ (_| | | | (_| |   <| ||  __/ |   " << endl;
        cout << " |                        |" << " | " << "     " << "|_| \\_\\__,_|_| |_|\\__,_|\\___/|_| |_| |_| |_|\\_\\__,_|_|  \\__,_|_|\\_\\__\\___|_|   " << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |      RANDOM ITEM       |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << " |   [1] : Random 1x   |   [2] : Ramdom 10x   |   [X] : Kembali   |   Pity : "<< pity << "   |" << endl;
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
       

        // cout << "Pilih opsi dengan angka : ";
        cin >> pilih;

        switch (toupper(pilih)) {
            case '1':
                gacha_karakter_1(); break;
            case '2':
                gacha_karakter_10(); break;
            case 'X':
                play_menu();
        };

}

void gacha_karakter_1() {
    system("cls");

    char pilih;

    auto karakter_S = data_karakter_S();
    auto karakter_A = data_karakter_A();

    cout << " ";
    if (random_value() <= 70) {

        int value = gacha_value(karakter_A.size());

        cout << "----------------------------------------------" << endl;
        cout << "|           | " << endl;
        cout << "|    AAA    | " << endl;
        cout << "|   A   A   | " << "Nama       : " << karakter_A[value].nama << endl;
        cout << "|   A   A   | " << "Rank       : " << karakter_A[value].rank << endl;
        cout << "|   AAAAA   | " << "Elemental  : " << karakter_A[value].elemental << endl;
        cout << "|   A   A   | " << "Type       : " << karakter_A[value].type << endl;
        cout << "|           | " << endl;
        cout << "----------------------------------------------" << endl;


        // cout << karakter_A[gacha_value(karakter_A.size())].rank << endl;
        // cout << karakter_A[gacha_value(karakter_A.size())].nama << endl;
        pity--;
    } else if (random_value() >70 ) {

        int value = gacha_value(karakter_S.size());

        cout << "----------------------------------------------" << endl;
        cout << "|           | " << endl;
        cout << "|   SSSSS   | " << endl;
        cout << "|   S       | " << "Nama       : " << karakter_S[value].nama << endl;
        cout << "|   SSSSS   | " << "Rank       : " << karakter_S[value].rank << endl;
        cout << "|       S   | " << "Elemental  : " << karakter_S[value].elemental << endl;
        cout << "|   SSSSS   | " << "Type       : " << karakter_S[value].type << endl;
        cout << "|           | " << endl;
        cout << "----------------------------------------------" << endl;

        // cout << karakter_S[gacha_value(karakter_S.size())].rank << endl;
        // cout << karakter_S[gacha_value(karakter_S.size())].nama << endl;
        pity--;
    }

    if (pity <= 0) {
        pity = 80;
    }

    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << " |   [1] : Random 1x   |   [2] : Ramdom 10x   |   [X] : Kembali   |   Pity : "<< pity << "   |" << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cin >> pilih;

    switch (toupper(pilih)) {
        case '1':
            gacha_karakter_1(); break;
        case '2':
            gacha_karakter_10(); break;
        case 'X':
            play_menu();
    };
    
}

void gacha_karakter_10() {
    system("cls");

    char pilih;

    int gacha = random_value();

    auto karakter_S = data_karakter_S();
    auto karakter_A = data_karakter_A();

    for (int i = 0; i <= 10;i++) {
    if (random_value() <= 70) {
        int value = gacha_value(karakter_A.size());

        cout << "----------------------------------------------" << endl;
        cout << "|           | " << endl;
        cout << "|    AAA    | " << endl;
        cout << "|   A   A   | " << "Nama       : " << karakter_A[value].nama << endl;
        cout << "|   A   A   | " << "Rank       : " << karakter_A[value].rank << endl;
        cout << "|   AAAAA   | " << "Elemental  : " << karakter_A[value].elemental << endl;
        cout << "|   A   A   | " << "Type       : " << karakter_A[value].type << endl;
        cout << "|           | " << endl;
        cout << "----------------------------------------------" << endl;
    } else if (random_value() >70 ) {
        int value = gacha_value(karakter_S.size());

        cout << "----------------------------------------------" << endl;
        cout << "|           | " << endl;
        cout << "|   SSSSS   | " << endl;
        cout << "|   S       | " << "Nama       : " << karakter_S[value].nama << endl;
        cout << "|   SSSSS   | " << "Rank       : " << karakter_S[value].rank << endl;
        cout << "|       S   | " << "Elemental  : " << karakter_S[value].elemental << endl;
        cout << "|   SSSSS   | " << "Type       : " << karakter_S[value].type << endl;
        cout << "|           | " << endl;
        cout << "----------------------------------------------" << endl;
    }
    pity--;
    }

    if (pity <= 0) {
        pity = 80;
    }

    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << " |   [1] : Random 1x   |   [2] : Ramdom 10x   |   [X] : Kembali   |   Pity : "<< pity << "   |" << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cin >> pilih;

    switch (toupper(pilih)) {
        case '1':
            gacha_karakter_1(); break;
        case '2':
            gacha_karakter_10(); break;
        case 'X':
            play_menu();
    };
    
}


// Gacha Artefak // Gacha Artefak // Gacha Artefak // Gacha Artefak // Gacha Artefak // Gacha Artefak // Gacha Artefak // Gacha Artefak // Gacha Artefak // Gacha Artefak // Gacha Artefak //
void gacha_artefak_menu() {
    system("cls");

    char pilih,gacha;
    // int alret = 0;

    // do {    
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |    RANDOM CHARACTER    |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "     " << " ____                 _                      _         _        __       _    " << endl;
        cout << " |                        |" << " | " << "     " << "|  _ \\ __ _ _ __   __| | ___  _ __ ___      / \\   _ __| |_ ___ / _| __ _| | __" << endl;
        cout << " |     RANDOM ARTEFAK     |" << " | " << "     " << "| |_) / _` | '_ \\ / _` |/ _ \\| '_ ` _ \\    / _ \\ | '__| __/ _ \\ |_ / _` | |/ /" << endl;
        cout << " |       [SELECTED]       |" << " | " << "     " << "|  _ < (_| | | | | (_| | (_) | | | | | |  / ___ \\| |  | ||  __/  _| (_| |   < " << endl;
        cout << " |                        |" << " | " << "     " << "|_| \\_\\__,_|_| |_|\\__,_|\\___/|_| |_| |_| /_/   \\_\\_|   \\__\\___|_|  \\__,_|_|\\_\\ " << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |      RANDOM ITEM       |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << " |   [1] : Random 1x   |   [2] : Ramdom 10x   |   [X] : Kembali   |   Pity : "<< pity << "   |" << endl;
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
       

        // cout << "Pilih opsi dengan angka : ";
        cin >> pilih;

        switch (toupper(pilih)) {
            case '1':
                gacha_artefak_1(); break;
            case '2':
                gacha_artefak_10(); break;
            case 'X':
                play_menu();
        };

}

void gacha_artefak_1() {
    system("cls");

    char pilih;

    auto artefak_S = data_artefak_S();
    auto artefak_A = data_artefak_A();
    auto artefak_B = data_artefak_B();

    cout << " ";
     if (random_value() <= 50) {

        int value = gacha_value(artefak_B.size());

        cout << "----------------------------------------------" << endl;
        cout << "|           | " << endl;
        cout << "|   BBBB    | " << "Nama       : " << artefak_B[value].nama << endl;
        cout << "|   B   B   | " << "Rank       : " << artefak_B[value].rank << endl;
        cout << "|   BBBB    | " << "Elemental  : " << artefak_B[value].elemental << endl;
        cout << "|   B   B   | " << "Crit_rate  : " << artefak_B[value].crit_rate << "%" << endl;
        cout << "|   BBBB    | " << "Crit_damage: " << artefak_B[value].crit_damage<< "%" << endl;
        cout << "|           | " << endl;
        cout << "----------------------------------------------" << endl;

        // cout << artefak_B[gacha_value(artefak_B.size())].rank << endl;
        // cout << artefak_B[gacha_value(artefak_B.size())].nama << endl;
        // cout << "-----" << endl;
        pity--;
    } else if (random_value() <= 80 ) {

        int value = gacha_value(artefak_A.size());

        cout << "----------------------------------------------" << endl;
        cout << "|           | " << endl;
        cout << "|    AAA    | " << "Nama       : " << artefak_A[value].nama << endl;
        cout << "|   A   A   | " << "Rank       : " << artefak_A[value].rank << endl;
        cout << "|   A   A   | " << "Elemental  : " << artefak_A[value].elemental << endl;
        cout << "|   AAAAA   | " << "Crit_rate  : " << artefak_A[value].crit_rate << "%" << endl;
        cout << "|   A   A   | " << "Crit_damage: " << artefak_A[value].crit_damage<< "%" << endl;
        cout << "|           | " << endl;
        cout << "----------------------------------------------" << endl;

        // cout << artefak_A[gacha_value(artefak_A.size())].rank << endl;
        // cout << artefak_A[gacha_value(artefak_A.size())].nama << endl;
        // cout << "-----" << endl;
        pity--;
    } else if (random_value() > 80) {

        int value = gacha_value(artefak_S.size());

        cout << "----------------------------------------------" << endl;
        cout << "|           | " << endl;
        cout << "|   SSSSS   | " << "Nama       : " << artefak_S[value].nama << endl;
        cout << "|   S       | " << "Rank       : " << artefak_S[value].rank << endl;
        cout << "|   SSSSS   | " << "Elemental  : " << artefak_S[value].elemental << endl;
        cout << "|       S   | " << "Crit_rate  : " << artefak_S[value].crit_rate << "%" << endl;
        cout << "|   SSSSS   | " << "Crit_damage: " << artefak_S[value].crit_damage<< "%" << endl;
        cout << "|           | " << endl;
        cout << "----------------------------------------------" << endl;

        // cout << artefak_S[gacha_value(artefak_S.size())].rank << endl;
        // cout << artefak_S[gacha_value(artefak_S.size())].nama << endl;
        // cout << "-----" << endl;
        pity--;
    }

    if (pity <= 0) {
        pity = 80;
    }

    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << " |   [1] : Random 1x   |   [2] : Ramdom 10x   |   [X] : Kembali   |   Pity : "<< pity << "   |" << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cin >> pilih;

    switch (toupper(pilih)) {
        case '1':
            gacha_artefak_1(); break;
        case '2':
            gacha_artefak_10(); break;
        case 'X':
            play_menu();
    };
    
}

void gacha_artefak_10() {
    system("cls");

    char pilih;

    int gacha = random_value();

    auto artefak_S = data_artefak_S();
    auto artefak_A = data_artefak_A();
    auto artefak_B = data_artefak_B();

    for (int i = 0; i <= 10;i++) {
    if (random_value() <= 50) {
        int value = gacha_value(artefak_B.size());

        cout << "----------------------------------------------" << endl;
        cout << "|           | " << endl;
        cout << "|   BBBB    | " << "Nama       : " << artefak_B[value].nama << endl;
        cout << "|   B   B   | " << "Rank       : " << artefak_B[value].rank << endl;
        cout << "|   BBBB    | " << "Elemental  : " << artefak_B[value].elemental << endl;
        cout << "|   B   B   | " << "Crit_rate  : " << artefak_B[value].crit_rate << "%" << endl;
        cout << "|   BBBB    | " << "Crit_damage: " << artefak_B[value].crit_damage<< "%" << endl;
        cout << "|           | " << endl;
        cout << "----------------------------------------------" << endl;
    } else if (random_value() <= 80 ) {
        int value = gacha_value(artefak_A.size());

        cout << "----------------------------------------------" << endl;
        cout << "|           | " << endl;
        cout << "|    AAA    | " << "Nama       : " << artefak_A[value].nama << endl;
        cout << "|   A   A   | " << "Rank       : " << artefak_A[value].rank << endl;
        cout << "|   A   A   | " << "Elemental  : " << artefak_A[value].elemental << endl;
        cout << "|   AAAAA   | " << "Crit_rate  : " << artefak_A[value].crit_rate << "%" << endl;
        cout << "|   A   A   | " << "Crit_damage: " << artefak_A[value].crit_damage<< "%" << endl;
        cout << "|           | " << endl;
        cout << "----------------------------------------------" << endl;
    } else if (random_value() > 80) {
        int value = gacha_value(artefak_S.size());

        cout << "----------------------------------------------" << endl;
        cout << "|           | " << endl;
        cout << "|   SSSSS   | " << "Nama       : " << artefak_S[value].nama << endl;
        cout << "|   S       | " << "Rank       : " << artefak_S[value].rank << endl;
        cout << "|   SSSSS   | " << "Elemental  : " << artefak_S[value].elemental << endl;
        cout << "|       S   | " << "Crit_rate  : " << artefak_S[value].crit_rate << "%" << endl;
        cout << "|   SSSSS   | " << "Crit_damage: " << artefak_S[value].crit_damage<< "%" << endl;
        cout << "|           | " << endl;
        cout << "----------------------------------------------" << endl;
    }
        pity--;
    }

    if (pity <= 0) {
        pity = 80;
    }

    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << " |   [1] : Random 1x   |   [2] : Ramdom 10x   |   [X] : Kembali   |   Pity : "<< pity << "   |" << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cin >> pilih;

    switch (toupper(pilih)) {
        case '1':
            gacha_artefak_1(); break;
        case '2':
            gacha_artefak_10(); break;
        case 'X':
            play_menu();
    };
    
}


// Gacha Item // Gacha item // Gacha item // Gacha item // Gacha item // Gacha item // Gacha item // Gacha item // Gacha item // Gacha item // Gacha item //
void gacha_item_menu() {
    system("cls");

    char pilih,gacha;
    // int alret = 0;

    // do {    
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |    RANDOM CHARACTER    |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "     " << " ____                 _                   ___ _                 " << endl;
        cout << " |                        |" << " | " << "     " << "|  _ \\ __ _ _ __   __| | ___  _ __ ___   |_ _| |_ ___ _ __ ___  " << endl;
        cout << " |     RANDOM ARTEFAK     |" << " | " << "     " << "| |_) / _` | '_ \\ / _` |/ _ \\| '_ ` _ \\   | || __/ _ \\ '_ ` _ \\ " << endl;
        cout << " |                        |" << " | " << "     " << "|  _ < (_| | | | | (_| | (_) | | | | | |  | || ||  __/ | | | | |" << endl;
        cout << " |                        |" << " | " << "     " << "|_| \\_\\__,_|_| |_|\\__,_|\\___/|_| |_| |_| |___|\\__\\___|_| |_| |_|" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |      RANDOM ITEM       |" << " | " << "" << endl;
        cout << " |      [SELECTED]        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " |                        |" << " | " << "" << endl;
        cout << " --------------------------" << " | " << "" << endl;
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << " |   [1] : Random 1x   |   [2] : Ramdom 10x   |   [X] : Kembali   |   Pity : "<< pity << "   |" << endl;
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
       
        cin >> pilih;

        switch (toupper(pilih)) {
            case '1':
                gacha_item_1(); break;
            case '2':
                gacha_item_10(); break;
            case 'X':
                play_menu();
        };

}

void gacha_item_1() {
    system("cls");

    char pilih;

    auto item_S = data_item_S();
    auto item_A = data_item_A();
    auto item_B = data_item_B();

    cout << " ";
     if (random_value() <= 50) {
        int value = gacha_value(item_B.size());

        cout << "----------------------------------------------" << endl;
        cout << "|           | " << ""  << endl;
        cout << "|   BBBB    | " << "Nama          : " << item_B[value].nama << endl;
        cout << "|   B   B   | " << "Rank          : " << item_B[value].rank << endl;
        cout << "|   BBBB    | " << "Elemental     : " << item_B[value].element << endl;
        cout << "|   B   B   | " << "Buffs         : " << item_B[value].buffs << endl;
        cout << "|   BBBB    | " << "Status Effect : " << item_B[value].status_effect<< endl;
        cout << "|           | " << endl;
        cout << "----------------------------------------------" << endl;
        pity--;
    } else if (random_value() <= 80 ) {
        int value = gacha_value(item_A.size());

        cout << "----------------------------------------------" << endl;
        cout << "|           | " << ""  << endl;
        cout << "|    AAA    | " << "Nama          : " << item_A[value].nama << endl;
        cout << "|   A   A   | " << "Rank          : " << item_A[value].rank << endl;
        cout << "|   A   A   | " << "Elemental     : " << item_A[value].element << endl;
        cout << "|   AAAAA   | " << "Buffs         : " << item_A[value].buffs << endl;
        cout << "|   A   A   | " << "Status Effect : " << item_A[value].status_effect<< endl;
        cout << "|           | " << endl;
        cout << "----------------------------------------------" << endl;
        pity--;
    } else if (random_value() > 80) {
        int value = gacha_value(item_S.size());

        cout << "----------------------------------------------" << endl;
        cout << "|           | " << ""  << endl;
        cout << "|   SSSSS   | " << "Nama          : " << item_S[value].nama << endl;
        cout << "|   S       | " << "Rank          : " << item_S[value].rank << endl;
        cout << "|   SSSSS   | " << "Elemental     : " << item_S[value].element << endl;
        cout << "|       S   | " << "Buffs         : " << item_S[value].buffs << endl;
        cout << "|   SSSSS   | " << "Status Effect : " << item_S[value].status_effect<< endl;
        cout << "|           | " << endl;
        cout << "----------------------------------------------" << endl;
        pity--;
    }

    if (pity <= 0) {
        pity = 80;
    }

    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << " |   [1] : Random 1x   |   [2] : Ramdom 10x   |   [X] : Kembali   |   Pity : "<< pity << "   |" << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cin >> pilih;

    switch (toupper(pilih)) {
        case '1':
            gacha_item_1(); break;
        case '2':
            gacha_item_10(); break;
        case 'X':
            play_menu();
    };
    
}

void gacha_item_10() {
    system("cls");

    char pilih;

    int gacha = random_value();

    auto item_S = data_item_S();
    auto item_A = data_item_A();
    auto item_B = data_item_B();

    for (int i = 0; i <= 10;i++) {
    if (random_value() <= 50) {

        int value = gacha_value(item_B.size());

        cout << "----------------------------------------------" << endl;
        cout << "|           | " << ""  << endl;
        cout << "|   BBBB    | " << "Nama          : " << item_B[value].nama << endl;
        cout << "|   B   B   | " << "Rank          : " << item_B[value].rank << endl;
        cout << "|   BBBB    | " << "Elemental     : " << item_B[value].element << endl;
        cout << "|   B   B   | " << "Buffs         : " << item_B[value].buffs << endl;
        cout << "|   BBBB    | " << "Status Effect : " << item_B[value].status_effect<< endl;
        cout << "|           | " << endl;
        cout << "----------------------------------------------" << endl;

    } else if (random_value() <= 80 ) {
        int value = gacha_value(item_A.size());

        cout << "----------------------------------------------" << endl;
        cout << "|           | " << ""  << endl;
        cout << "|    AAA    | " << "Nama          : " << item_A[value].nama << endl;
        cout << "|   A   A   | " << "Rank          : " << item_A[value].rank << endl;
        cout << "|   A   A   | " << "Elemental     : " << item_A[value].element << endl;
        cout << "|   AAAAA   | " << "Buffs         : " << item_A[value].buffs << endl;
        cout << "|   A   A   | " << "Status Effect : " << item_A[value].status_effect<< endl;
        cout << "|           | " << endl;
        cout << "----------------------------------------------" << endl;
    } else if (random_value() > 80) {
        int value = gacha_value(item_S.size());

        cout << "----------------------------------------------" << endl;
        cout << "|           | " << ""  << endl;
        cout << "|   SSSSS   | " << "Nama          : " << item_S[value].nama << endl;
        cout << "|   S       | " << "Rank          : " << item_S[value].rank << endl;
        cout << "|   SSSSS   | " << "Elemental     : " << item_S[value].element << endl;
        cout << "|       S   | " << "Buffs         : " << item_S[value].buffs << endl;
        cout << "|   SSSSS   | " << "Status Effect : " << item_S[value].status_effect<< endl;
        cout << "|           | " << endl;
        cout << "----------------------------------------------" << endl;
    }
    pity--;
    }

    if (pity <= 0) {
        pity = 80;
    }

    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << " |   [1] : Random 1x   |   [2] : Ramdom 10x   |   [X] : Kembali   |   Pity : "<< pity << "   |" << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cin >> pilih;

    switch (toupper(pilih)) {
        case '1':
            gacha_item_1(); break;
        case '2':
            gacha_item_10(); break;
        case 'X':
            play_menu();
    };
    
}





// fungsi untuk melihat list karakter, artefak, dan item
void list_menu() {
    system("cls");

    char pilih;
    int alret = 0;

    do {
        cout << "\n<====================> LIST ITEM AND CHARACTER <====================>\n\n";
        cout << "Lihat daftar rangking " << endl << endl;
        cout << "       [1] : Character" << endl;
        cout << "       [2] : Artefak" << endl;
        cout << "       [3] : Item" << endl;
        cout << "       [X] : Kembali" << endl;

        cout << "\n--------------------------------------------------\n";

        if (alret > 0) {
            cout << "Pilih dengan angka [Input Invalid] : ";
        } else {
            cout << "Pilih dengan angka : ";
        }
        alret++;

        cin >> pilih;

        switch (toupper(pilih)) {
            case '1':
                list_karakter(); break;
            case '2':
                list_artefak(); break;
            case '3':
                list_item(); break;
            case 'X':
                main_menu();
            };

    } while (pilih != 'X');

}

void list_karakter() {
    system("cls");

    char pilih;
    int count = 0;
    int alret = 0;

    auto karakter_S = data_karakter_S();
    auto karakter_A = data_karakter_A();

        cout << "\n====================> List Karakter <====================\n\n";

        
    do {
        for (int i = 0; i < karakter_S.size(); i++ ) {
            count++;

            cout << "----------------------------------------------" << endl;
            cout << "|           | " << endl;
            cout << "|   SSSSS   | " << "[ " << count << " ]" << endl;
            cout << "|   S       | " << "Nama       : " << karakter_S[i].nama << endl;
            cout << "|   SSSSS   | " << "Rank       : " << karakter_S[i].rank << endl;
            cout << "|       S   | " << "Elemental  : " << karakter_S[i].elemental << endl;
            cout << "|   SSSSS   | " << "Type       : " << karakter_S[i].type << endl;
            cout << "|           | " << endl;
            cout << "----------------------------------------------" << endl;

        }

        for (int i = 0; i < karakter_A.size(); i++ ) {
            count++;

            cout << "----------------------------------------------" << endl;
            cout << "|           | " << endl;
            cout << "|    AAA    | " << "[ " << count << " ]" << endl;
            cout << "|   A   A   | " << "Nama       : " << karakter_A[i].nama << endl;
            cout << "|   A   A   | " << "Rank       : " << karakter_A[i].rank << endl;
            cout << "|   AAAAA   | " << "Elemental  : " << karakter_A[i].elemental << endl;
            cout << "|   A   A   | " << "Type       : " << karakter_A[i].type << endl;
            cout << "|           | " << endl;
            cout << "----------------------------------------------" << endl;
        }

        if (alret > 0) {
            cout << " |   [X] : Kembali   |    [Input Invalid] : ";
        } else {
            cout << " |   [X] : Kembali   |    : ";
        }
        alret++;

        cin >> pilih;

        switch (toupper(pilih)) {
            case 'X':
                list_menu();
        }

        count = 0;

    } while (pilih != 'X'); 
}

void list_artefak() {
    system("cls");

    char pilih;
    int count = 0;
    int alret = 0;

    auto artefak_S = data_artefak_S();
    auto artefak_A = data_artefak_A();
    auto artefak_B = data_artefak_B();

    do {

        cout << "\n====================> List artefak <====================\n\n";
        for (int i = 0; i < artefak_S.size(); i++ ) {
            count++;
            
            cout << "----------------------------------------------" << endl;
            cout << "|           | " << "[ " << count << " ]"  << endl;
            cout << "|   SSSSS   | " << "Nama       : " << artefak_S[i].nama << endl;
            cout << "|   S       | " << "Rank       : " << artefak_S[i].rank << endl;
            cout << "|   SSSSS   | " << "Elemental  : " << artefak_S[i].elemental << endl;
            cout << "|       S   | " << "Crit_rate  : " << artefak_S[i].crit_rate << "%" << endl;
            cout << "|   SSSSS   | " << "Crit_damage: " << artefak_S[i].crit_damage<< "%" << endl;
            cout << "|           | " << endl;
            cout << "----------------------------------------------" << endl;
        }

        for (int i = 0; i < artefak_A.size(); i++ ) {
            count++;

            cout << "----------------------------------------------" << endl;
            cout << "|           | " << "[ " << count << " ]"  << endl;
            cout << "|    AAA    | " << "Nama       : " << artefak_A[i].nama << endl;
            cout << "|   A   A   | " << "Rank       : " << artefak_A[i].rank << endl;
            cout << "|   A   A   | " << "Elemental  : " << artefak_A[i].elemental << endl;
            cout << "|   AAAAA   | " << "Crit_rate  : " << artefak_A[i].crit_rate << "%" << endl;
            cout << "|   A   A   | " << "Crit_damage: " << artefak_A[i].crit_damage<< "%" << endl;
            cout << "|           | " << endl;
            cout << "----------------------------------------------" << endl;
        }

        for (int i = 0; i < artefak_B.size(); i++ ) {
            count++;
         
            cout << "----------------------------------------------" << endl;
            cout << "|           | " << "[ " << count << " ]"  << endl;
            cout << "|   BBBB    | " << "Nama       : " << artefak_B[i].nama << endl;
            cout << "|   B   B   | " << "Rank       : " << artefak_B[i].rank << endl;
            cout << "|   BBBB    | " << "Elemental  : " << artefak_B[i].elemental << endl;
            cout << "|   B   B   | " << "Crit_rate  : " << artefak_B[i].crit_rate << "%" << endl;
            cout << "|   BBBB    | " << "Crit_damage: " << artefak_B[i].crit_damage<< "%" << endl;
            cout << "|           | " << endl;
            cout << "----------------------------------------------" << endl;
        }

        if (alret > 0) {
            cout << " |   [X] : Kembali   |   [Input Invalid] : ";
        } else {
            cout << " |   [X] : Kembali   |   : ";
        }
        alret++;

        cin >> pilih;

        switch (toupper(pilih)) {
            case 'X':
                list_menu();
        }

        count = 0;

    } while (pilih != 'X');

}

void list_item() {
    system("cls");

    char pilih;
    int count = 0;
    int alret = 0;

    auto item_S = data_item_S();
    auto item_A = data_item_A();
    auto item_B = data_item_B();

    do {

        cout << "\n====================> List Item <====================\n\n";
        for (int i = 0; i < item_S.size(); i++ ) {
            count++;

            cout << "----------------------------------------------" << endl;
            cout << "|           | " << "[ " << count << " ]"  << endl;
            cout << "|   SSSSS   | " << "Nama          : " << item_S[i].nama << endl;
            cout << "|   S       | " << "Rank          : " << item_S[i].rank << endl;
            cout << "|   SSSSS   | " << "Elemental     : " << item_S[i].element << endl;
            cout << "|       S   | " << "Buffs         : " << item_S[i].buffs << endl;
            cout << "|   SSSSS   | " << "Status Effect : " << item_S[i].status_effect<< endl;
            cout << "|           | " << endl;
            cout << "----------------------------------------------" << endl;
        }

            for (int i = 0; i < item_A.size(); i++ ) {
            count++;

            cout << "----------------------------------------------" << endl;
            cout << "|           | " << "[ " << count << " ]"  << endl;
            cout << "|    AAA    | " << "Nama          : " << item_A[i].nama << endl;
            cout << "|   A   A   | " << "Rank          : " << item_A[i].rank << endl;
            cout << "|   A   A   | " << "Elemental     : " << item_A[i].element << endl;
            cout << "|   AAAAA   | " << "Buffs         : " << item_A[i].buffs << endl;
            cout << "|   A   A   | " << "Status Effect : " << item_A[i].status_effect<< endl;
            cout << "|           | " << endl;
            cout << "----------------------------------------------" << endl;
        }

            for (int i = 0; i < item_B.size(); i++ ) {
            count++;

            cout << "----------------------------------------------" << endl;
            cout << "|           | " << "[ " << count << " ]"  << endl;
            cout << "|   BBBB    | " << "Nama          : " << item_B[i].nama << endl;
            cout << "|   B   B   | " << "Rank          : " << item_B[i].rank << endl;
            cout << "|   ABBB    | " << "Elemental     : " << item_B[i].element << endl;
            cout << "|   B   B   | " << "Buffs         : " << item_B[i].buffs << endl;
            cout << "|   BBBB    | " << "Status Effect : " << item_B[i].status_effect<< endl;
            cout << "|           | " << endl;
            cout << "----------------------------------------------" << endl;

        }

        if (alret > 0) {
            cout << " |   [X] : Kembali   :   [Input Invalid] : ";
        } else {
            cout << " |   [X] : Kembali   |   : ";
        }
        alret++;

        cin >> pilih;

        switch (toupper(pilih)) {
            case 'X':
                list_menu();
        }

        count = 0;

    } while (pilih != 'X');

}

// fungsi looping dari array agar bisa tampil ke fungsi utama


void info() {
    system("cls");

    char pilih;
    int alret = 0;

    do {

        cout << endl;
        cout << "                                            -<><><><><>-" << endl;
        cout << "                                            |INFORMASI!|" << endl;
        cout << "                                            -<><><><><>-" << endl;
        cout << "<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>" << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "            > PROGRAM INI MENGGUNAKAN FUNGSI RANDOM YANG ADA DI STANDART LIBRARY C++." << endl;
        cout << "              -----------------------------------------------------------------------" << endl;
        cout << "          >  BERTUJUAN UNTUK MEREPLIKA SISTEM GACHA DALAM GAME YANG BEREDAR SAAT INI." << endl;
        cout << "             ------------------------------------------------------------------------" << endl;
        cout << "                         > PROGRAM INI DIKEMBANGKAN OLEH =" << endl;
        cout << "                            -> ENZA." << endl;
        cout << "                            -> STEVANUS." << endl;
        cout << "                            -> FAKHRI." << endl;
        cout << "<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>" << endl;

        cout << "\n------------------------------------------------\n";

        if (alret > 0) {
            cout << " |   [X] : Kembali   |   [Input Invalid] : ";
        } else {
            cout << " |   [X] : Kembali   |   :";
        }
        alret++;
        cin >> pilih;
        
        switch (toupper(pilih)) {
            case 'X':
                main_menu();
        }
            
        

    } while (pilih != 'X');
}
                                                                                         