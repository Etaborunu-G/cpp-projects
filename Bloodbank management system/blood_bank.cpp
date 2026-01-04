#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int k = 1, l = 1;

class hospital {
public:
    int HPID;
    char contactno[15];
    char rhesius;
    char type;

    void h_register() {
        HPID = k;
        cout << "Enter contact number: ";
        cin >> contactno;
        cout << "Your hospital ID is: " << HPID << endl;
    }

    void payment_check() {
        char ch;
        cout << "Has the payment been made? (y/n): ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y') {
            cout << "Transaction successful." << endl;
        } else {
            cout << "Transaction failed. Please try again." << endl;
        }
    }
};

class donor {
public:
    int fitness;
    char name[20];
    char contact[15];
    int DNR;
    char r; // rhesius
    char t; // type ('A','B','O','X' for AB)

    void d_register() {
        char str[5];

        cout << "Enter your name: ";
        cin >> name;

        cout << "Enter contact number: ";
        cin >> contact;

        cout << "\nEnter fitness level (1-fit, 0-unfit): ";
        cin >> fitness;

        // Blood Type
        while (1) {
            cout << "\nEnter Bloodtype (A/B/AB/O): ";
            cin >> str;

            if (strcmp(str, "A") == 0 || strcmp(str, "a") == 0) {
                t = 'A';
                break;
            } else if (strcmp(str, "B") == 0 || strcmp(str, "b") == 0) {
                t = 'B';
                break;
            } else if (strcmp(str, "O") == 0 || strcmp(str, "o") == 0) {
                t = 'O';
                break;
            } else if (strcmp(str, "AB") == 0 || strcmp(str, "ab") == 0 || strcmp(str, "Ab") == 0 || strcmp(str, "aB") == 0) {
                t = 'X'; // AB stored as X
                break;
            } else {
                cout << "Invalid Bloodtype. Please enter again." << endl;
            }
        }

        // Rhesius
        while (1) {
            cout << "\nEnter Rhesius factor (+/-): ";
            cin >> str;
            r = str[0];
            if (r == '+' || r == '-') {
                break;
            } else {
                cout << "Invalid Rhesius factor. Please enter again." << endl;
            }
        }

        DNR = l;
        cout << "Your Donor ID is: " << DNR << endl;
    }

    void d_updation() {
        int choice;
        cout << "\nEnter Choice: \n1. Update fitness status\n2. Update contact number\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nEnter updated fitness level (1-fit, 0-unfit): ";
            cin >> fitness;
            break;
        case 2:
            cout << "Enter updated contact number: ";
            cin >> contact;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    }
};

class bloodpacket {
public:
    char t_1; // type
    char r_1; // rhesius
    int expiry;
};

class bloodbank {
public:
    int z = 0, x = 0, c = 0, v = 0, w = 0, n = 0, m = 0, q = 0;

    int username;
    int password;

    donor d[50];
    hospital h[50];
    bloodpacket bp[24];

    bloodbank(int user, int pass) {
        username = user;
        password = pass;

        // initialize blood packets as "empty"
        for (int i = 0; i < 24; i++) {
            bp[i].t_1 = '0';
            bp[i].r_1 = '0';
            bp[i].expiry = 2017; // sentinel for empty
        }
    }

    int authenticate() {
        int y, z;
        cout << "Enter username: ";
        cin >> y;
        cout << "Enter password: ";
        cin >> z;

        if (y == username && z == password) return 1;
        return 0;
    }

    void b_register() {
        d[l].d_register(); // store at donor ID index
        l++;
    }

    void update() {
        int id;
        cout << "Enter Donor ID to update details: ";
        cin >> id;

        if (id <= 0 || id >= l) {
            cout << "Donor does not exist." << endl;
            return;
        }

        d[id].d_updation();
    }

    void h_register() {
        h[k].h_register();
        k++;
    }

    void accept() {
        int hid, flag = 0, i;
        char req_t;
        char req_r;

        cout << "Enter Hospital ID: ";
        cin >> hid;

        if (hid <= 0 || hid >= k) {
            cout << "Hospital ID does not exist." << endl;
            return;
        }

        cout << "Enter required Bloodtype (A/B/AB/O): ";
        cin >> req_t;

        if (req_t == 'a') req_t = 'A';
        if (req_t == 'b') req_t = 'B';
        if (req_t == 'o') req_t = 'O';

        // If they type "AB" they can't fit in char. So instruct use X or handle separately (simple approach):
        if (req_t == 'X') { /* AB already */ }

        cout << "Enter required Rhesius factor (+/-): ";
        cin >> req_r;

        // AB stored as X
        if (req_t == 'A') {
            if (req_r == '+') {
                for (i = 0; i < 3; i++) if (bp[i].expiry > 2017) { flag = 300; bp[i].expiry = 2017; break; }
            } else {
                for (i = 3; i < 6; i++) if (bp[i].expiry > 2017) { flag = 1000; bp[i].expiry = 2017; break; }
            }
        } else if (req_t == 'B') {
            if (req_r == '+') {
                for (i = 6; i < 9; i++) if (bp[i].expiry > 2017) { flag = 300; bp[i].expiry = 2017; break; }
            } else {
                for (i = 9; i < 12; i++) if (bp[i].expiry > 2017) { flag = 800; bp[i].expiry = 2017; break; }
            }
        } else if (req_t == 'O') {
            if (req_r == '+') {
                for (i = 12; i < 15; i++) if (bp[i].expiry > 2017) { flag = 300; bp[i].expiry = 2017; break; }
            } else {
                for (i = 15; i < 18; i++) if (bp[i].expiry > 2017) { flag = 2000; bp[i].expiry = 2017; break; }
            }
        } else if (req_t == 'X') {
            if (req_r == '+') {
                for (i = 18; i < 21; i++) if (bp[i].expiry > 2017) { flag = 500; bp[i].expiry = 2017; break; }
            } else {
                for (i = 21; i < 24; i++) if (bp[i].expiry > 2017) { flag = 2000; bp[i].expiry = 2017; break; }
            }
        }

        if (flag != 0) {
            cout << "Cost of the required blood packet is: " << flag << endl;
            h[hid].payment_check();
        } else {
            cout << "Required blood packet is not available." << endl;
        }
    }

    void donate() {
        int id, i;
        cout << "Enter Donor ID: ";
        cin >> id;

        if (id <= 0 || id >= l) {
            cout << "Donor ID does not exist." << endl;
            return;
        }

        if (d[id].fitness == 0) {
            cout << "Donor is unfit to donate blood." << endl;
            return;
        }

        char t = d[id].t;
        char r = d[id].r;

        auto storePacket = [&](int start, int end, int &counter) {
            for (int j = start; j < end; j++) {
                if (bp[j].expiry == 2017) { // empty slot
                    bp[j].t_1 = t;
                    bp[j].r_1 = r;
                    cout << "Enter Expiry year (>2017): ";
                    cin >> bp[j].expiry;
                    counter++;
                    return true;
                }
            }
            return false;
        };

        bool ok = false;

        if (t == 'A') ok = (r == '+') ? storePacket(0, 3, z) : storePacket(3, 6, x);
        else if (t == 'B') ok = (r == '+') ? storePacket(6, 9, c) : storePacket(9, 12, v);
        else if (t == 'O') ok = (r == '+') ? storePacket(12, 15, w) : storePacket(15, 18, n);
        else if (t == 'X') ok = (r == '+') ? storePacket(18, 21, m) : storePacket(21, 24, q);

        if (!ok) cout << "No storage space available for that blood type." << endl;
    }

    void show() {
        cout << "\nBLOOD BANK DETAILS\n";
        cout << "Available Blood packets:\n";
        cout << "Total blood packets available: " << (z + x + c + v + w + n + m + q) << endl;
        cout << "A+ : " << z << endl;
        cout << "A- : " << x << endl;
        cout << "B+ : " << c << endl;
        cout << "B- : " << v << endl;
        cout << "O+ : " << w << endl;
        cout << "O- : " << n << endl;
        cout << "AB+ : " << m << endl;
        cout << "AB- : " << q << endl;
    }
};

int main() {
cout << " ____   _       ____   ____   ____ " << endl;
cout << "| __ ) | |     / __ \\ / __ \\ |  _ \\" << endl;
cout << "|  _ \\ | |    | |  | | |  | || | | |" << endl;
cout << "| |_) || |___ | |__| | |__| || |_| |" << endl;
cout << "|____/ |_____| \\____/ \\____/ |____/ " << endl;
cout << endl;
cout << " ____    _      _   _   _  __" << endl;
cout << "| __ )  / \\    | \\ | | | |/ /" << endl;
cout << "|  _ \\ / _ \\   |  \\| | | ' / " << endl;
cout << "| |_) / ___ \\  | |\\  | | . \\ " << endl;
cout << "|____/_/   \\_\\ |_| \\_| |_|\\_\\ " << endl;


    int ch, count = 0;
    bloodbank b(123, 123);

    while (count < 3) {
        if (b.authenticate() == 0) {
            cout << "Invalid credentials. Please try again." << endl;
            count++;
        } else break;
    }

    if (count == 3) {
        cout << "Maximum login attempts exceeded. Exiting program." << endl;
        return 1;
    }

    while (1) {
        cout << "\nEnter choice";
        cout << "\n1. Add Donor\n2. Update donor details\n3. Add Hospital\n4. Donate\n5. Request Blood\n6. Display available Blood packets\n7. Exit\n";
        cin >> ch;

        switch (ch) {
        case 1: b.b_register(); break;
        case 2: b.update(); break;
        case 3: b.h_register(); break;
        case 4: b.donate(); break;
        case 5: b.accept(); break;
        case 6: b.show(); break;
        case 7: return 0;
        default: cout << "Invalid choice. Please try again." << endl;
        }
    }
}
