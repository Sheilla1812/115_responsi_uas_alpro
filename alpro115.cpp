#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAKS = 100;

struct Mahasiswa {
    string nama;
    string nim;
    int uas;
    int uts;
    float rataRata;
};

Mahasiswa data[MAKS];
int jumlahData = 0;

void inputData() {
    ofstream file("115.txt", ios::app);
    int jumlahInput;
    cout << "banyak data yang ingin dimasukkan : ";
    cin >> jumlahInput;
    cin.ignore();

    for (int i = 0; i < jumlahInput; i++) {
        string nama, nim;
        int uas, uts;
        cout << "\nData ke-" << (i + 1) << endl;
        cout << "Nama mahasiswa   : ";
        getline(cin, nama);
        cout << "NIM mahasiswa    : ";
        getline(cin, nim);
        cout << "Nilai UAS        : ";
        cin >> uas;
        cout << "Nilai UTS        : ";
        cin >> uts;
        cin.ignore();

        file << nama << "|" << nim << "|" << uts << "|" << uas << "\n";
    }
    file.close();
    cout << "Data berhasil disimpan ke '115.txt'.\n";
}

void bacaDataDariFile(string namaFile) {
    ifstream file(namaFile);
    if (!file.is_open()) {
        cout << "Gagal membuka file: " << namaFile << endl;
        return;
    }

    string baris;
    jumlahData = 0;
    while (getline(file, baris) && jumlahData < MAKS) {
        stringstream ss(baris);
        string nama, nim, utsStr, uasStr;

        getline(ss, nama, '|');
        getline(ss, nim, '|');
        getline(ss, utsStr, '|');
        getline(ss, uasStr, '|');

        if (nama.empty() || nim.empty() || utsStr.empty() || uasStr.empty()) continue;

        data[jumlahData].nama = nama;
        data[jumlahData].nim = nim;
        data[jumlahData].uts = stoi(utsStr);
        data[jumlahData].uas = stoi(uasStr);
        data[jumlahData].rataRata = (data[jumlahData].uts + data[jumlahData].uas) / 2.0;
        jumlahData++;
    }
    file.close();
    cout << "Data berhasil dibaca dari file.\n";
}

void tampilkanRataRata() {
    bacaDataDariFile("115.txt");
    cout << "\nDaftar Nilai Rata-rata Mahasiswa:\n";
    for (int i = 0; i < jumlahData; i++) {
        cout << data[i].nama << " (" << data[i].nim << ") - Rata-rata: " << fixed << setprecision(2) << data[i].rataRata << endl;
    }
}

void datalulus(){
	bacaDataDariFile("115.txt");
	cout << "\nmahasiswa yang lulus :\n";
	  for (int i = 0; i < jumlahData; i++) {
        cout << data[i].nama << " (" << data[i].nim << ") - Rata-rata: " << fixed << setprecision(2) << data[i].rataRata << endl;
    if (data[i].rataRata< 75) {
    	cout<<data[i].nama<<" TIDAK LULUS!";
    } else if (data[i].rataRata> 75){
    	cout<<data[i].nama <<" LULUS!";
    }cout<<endl;
}
}

void nama(){
	bacaDataDariFile("115.txt");
	cout << "\nmasukkan nama mahasiswa :\n";
	//cin>>data[i].nama;	
}

int main() {
    int pilih;

    do {
        	cout<<"======MENU======\n";
	cout<<"1. masukkan data.\n";
	cout<<"2. menghitung nilai akhir (Rata rata UAS & UTS).\n";
	cout<<"3. data kelulusan.\n";
	cout<<"4. cari nilai berdasarkan nama mahasiswa.\n";
	cout<<"5. mengurutkan nilai dari besar ke kecil.\n";
	cout<<"5. bisa mengurutkan nilai dari kecil ke besar.\n";
	cout<<"0. program selesai.\n";
	cout<<"masukkan pilihan anda : ";
	cin>>pilih;
	 cin.ignore();

        switch (pilih) {
            case 1:
                inputData();
                break;
            case 2:
                tampilkanRataRata();
                break;
            case 3:
            	datalulus();
            	break;
            case 4:
            	nama();
            	break;
            case 0:
                cout << "Program selesai, terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 0);

    return 0;
}