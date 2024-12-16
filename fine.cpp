#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Data barang
struct Barang {
    int kode;
    string nama;
    double harga;
};

// Daftar barang
const Barang daftarBarang[] = {
    {1001, "Ayam Goreng", 18750},
    {1002, "Lotek", 12190},
    {1003, "Gado-gado", 10680},
    {1004, "Wagyu A5", 767250},
    {1005, "Gurame Bakar", 45328},
    {1006, "Bebek Peking", 31313},
    {1007, "Telur Triceratops", 56570},
    {1008, "Daging Zombie", 123456},
    {1009, "Magelangan Mba Lis", 12100},
    {1010, "Babi Guling", 27894},
    {1011, "Unagi", 60456}
};

// Akun
const int MAX_AKUN = 10; // Maksimum jumlah akun
string akun[MAX_AKUN][3]; // Kolom 0: Nama, Kolom 1: Username, Kolom 2: Password
int jumlahAkun = 0;

// Pesanan
struct Pesanan {
    string namaCustomer;
    int kodeBarang;
    int jumlah;
    double hargaSatuan;
    double subtotal;
    double total;
};

Pesanan pesanan[100]; // Array untuk menyimpan pesanan
int jumlahPesanan = 0;

// Fungsi untuk menampilkan menu login dan registrasi
void menuLogin(bool& isLoggedIn) {
    int pilihan;
    string username, password;

    cout << "Menu: " << endl;
    cout << "1.Login " << endl; 
    cout << "2.Register " << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    if (pilihan == 1) {
        int attempts = 3;
        while (attempts--) {
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            for (int i = 0; i < jumlahAkun; ++i) {
                if (akun[i][1] == username && akun[i][2] == password) {
                    cout << "Login berhasil!\n";
                    isLoggedIn = true;
                    return;
                }
            }
            cout << "Username atau password salah. Sisa kesempatan: " << attempts << "\n";
        }
        cout << "Kesempatan habis! Program berhenti.\n";
        exit(0);
    } else if (pilihan == 2) {
        if (jumlahAkun < MAX_AKUN) {
            cout << "Nama: ";
            cin.ignore();
            getline(cin, akun[jumlahAkun][0]);
            cout << "Username: ";
            cin >> akun[jumlahAkun][1];
            cout << "Password: ";
            cin >> akun[jumlahAkun][2];
            ++jumlahAkun;
            cout << "Akun berhasil dibuat!\n";
        } else {
            cout << "Jumlah akun maksimum tercapai.\n";
        }
    } else {
        cout << "Pilihan tidak valid.\n";
    }
}

// Fungsi untuk mencari barang berdasarkan kode
bool cariBarang(int kode, Barang& barang) {
    for (const auto& b : daftarBarang) {
        if (b.kode == kode) {
            barang = b;
            return true;
        }
    }
    return false;
}

// Fungsi untuk menampilkan daftar pesanan
void lihatPesanan() {
    if (jumlahPesanan == 0) {
        // Peringatan jika tidak ada pesanan
        cout << "Error: Belum ada pesanan yang masuk.\n";
        return;
    }

    // Header tabel
    cout << left << setw(15) << "Customer"
         << setw(10) << "Kode"
         << setw(20) << "Nama Barang"
         << setw(10) << "Jumlah"
         << setw(15) << "Harga Satuan"
         << setw(15) << "Subtotal"
         << setw(15) << "Total (incl. 10%)" << "\n";

    // Menampilkan data pesanan
    for (int i = 0; i < jumlahPesanan; ++i) {
        double pajak = pesanan[i].subtotal * 0.1; // Hitung pajak 10%
        double total = pesanan[i].subtotal + pajak; // Harga total

        cout << left << setw(15) << pesanan[i].namaCustomer
             << setw(10) << pesanan[i].kodeBarang;

        // Mencari nama barang berdasarkan kode
        for (const auto& barang : daftarBarang) {
            if (barang.kode == pesanan[i].kodeBarang) {
                cout << setw(20) << barang.nama;
                break;
            }
        }

        cout << setw(10) << pesanan[i].jumlah
             << setw(15) << fixed << setprecision(2) << pesanan[i].hargaSatuan
             << setw(15) << pesanan[i].subtotal
             << setw(15) << total << "\n"; // Tampilkan total
    }
}

// Fungsi untuk menambah pesanan
void tambahPesanan() {
    Pesanan p;
    Barang barang;

    cout << "Nama Customer: ";
    cin.ignore();
    getline(cin, p.namaCustomer);

    while (true) {
        cout << "Masukkan kode barang: ";
        cin >> p.kodeBarang;

        if (cariBarang(p.kodeBarang, barang)) {
            cout << "Barang ditemukan: " << barang.nama << ", Harga: " << barang.harga << "\n";
            p.hargaSatuan = barang.harga;
            break;
        } else {
            cout << "Kode barang tidak ditemukan. Coba lagi.\n";
        }
    }

    cout << "Masukkan jumlah barang: ";
    cin >> p.jumlah;

    p.subtotal = p.hargaSatuan * p.jumlah;
    p.total = p.subtotal + (p.subtotal * 0.1); // Harga total dengan pajak

    pesanan[jumlahPesanan++] = p;

    cout << "Pesanan berhasil ditambahkan.\n";
}

// Fungsi utama
int main() {
    bool isLoggedIn = false;

    while (!isLoggedIn) {
        menuLogin(isLoggedIn);
    }

    int pilihan;
    while (true) {
        cout << "Menu Utama:\n1. Tambah Pesanan\n2. Lihat Daftar Pesanan\n3. Keluar\nPilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            tambahPesanan();
        } else if (pilihan == 2) {
            lihatPesanan();
        } else if (pilihan == 3) {
            cout << "Keluar dari program. Terima kasih!\n";
            break;
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}
