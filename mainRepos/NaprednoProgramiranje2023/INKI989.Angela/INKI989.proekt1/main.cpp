#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// kreirame struktura Profil
struct Profil {
    int IDbroj;
    string Nickname;
    float nivo;


    Profil(int IDbroj, string Nickname, float nivo) {
        this->IDbroj = IDbroj;
        this->Nickname = Nickname;
        this->nivo = nivo;
    }

    // funkcija za sortiranje na strukturata po Nickname
    bool operator<(const Profil& other) const {
        return this->Nickname < other.Nickname;
    }
};

int main() {
    // vektor za smestuvanje na strukturata Profil
    vector<Profil> profili;

    // zapisi vo vektorot
    profili.push_back(Profil(1, "Petar", 3.2));
    profili.push_back(Profil(2, "Viktor", 2.8));
    profili.push_back(Profil(3, "Jovan", 4.5));
    profili.push_back(Profil(4, "Ana", 3.9));
    profili.push_back(Profil(5, "Nikola", 4.1));

    // go pecati vektorot na konzola, kako sto e vnesen
    cout << "Sodrzinata na vektorot kako sto e vnesen: " << endl;
    for (const auto& profil : profili) {
        cout << profil.IDbroj << " " << profil.Nickname << " " << profil.nivo << endl;
    }

    // go sortira vektorot po Nickname
    sort(profili.begin(), profili.end());

    // go pecati vektorot na konzola podreden
    cout << "Sodrzinata na vektorot sortirana po Nickname: " << endl;
    for (const auto& profil : profili) {
        cout << profil.IDbroj << " " << profil.Nickname << " " << profil.nivo << endl;
    }

    // go zapisuva vektorot vo izleznata datoteka
    ofstream outFile("INKI989.Angela");
    if (outFile.is_open()) {
        for (const auto& profil : profili) {
            outFile << profil.IDbroj << " " << profil.Nickname << " " << profil.nivo << endl;
        }
        outFile.close();
    }
    else {
        cout << "Ne moze da se otvori datotekata!" << endl;
    }

    return 0;
}
