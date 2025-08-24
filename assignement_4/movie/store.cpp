#include "store.h"
#include "movieFactory.h"      // assumes you have MovieFactory::createFromLine
#include "customer.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>

using namespace std;


void Store::loadMovies(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cout << "ERROR: cannot open movies file: " << filename << "\n";
        return;
    }

    string line;
    size_t lineNo = 0, ok = 0, bad = 0;

    while (getline(in, line)) {
        ++lineNo;

        auto trimBoth = [](string s) {
            size_t b = 0, e = s.size();
            while (b < e && isspace((unsigned char)s[b])) ++b;
            while (e > b && isspace((unsigned char)s[e - 1])) --e;
            return s.substr(b, e - b);
        };
        string raw = trimBoth(line);

        if (raw.empty() || raw[0] == '#') continue;

        MovieFactory factory;
        Movie* m = factory.createFromLine(raw);  
        if (!m) {
            cout << "ERROR: bad movie line (" << lineNo << "): " << raw << "\n";
            ++bad;
            continue;
        }

        inventory.addMovie(m);
        ++ok;
    }

    cout << "Loaded movies: " << ok << " ok, " << bad << " bad\n";
}

string Store::trim(string s) {
    while (!s.empty() && isspace((unsigned char)s.back())) s.pop_back();
    size_t i = 0; while (i < s.size() && isspace((unsigned char)s[i])) ++i;
    return s.substr(i);
}

bool Store::readLine(istream& in, string& line) {
    while (getline(in, line)) {
        if (!line.empty()) return true;  
    }
    return false;
}

// --------------------- key builders ---------------------

// Comedy: expect rest like " Title, 1994"
bool Store::buildComedyKey(const  string& rest, string& outKey) {
    istringstream parts(rest);
    if (parts.peek() == ',') parts.get();

    string title, yearStr;
    if (!getline(parts, title, ',')) return false;
    if (!getline(parts, yearStr))    return false;

    title   = trim(title);
    yearStr = trim(yearStr);
    if (title.empty() || yearStr.empty()) return false;

    outKey = title + "|" + yearStr;   // EXACT: Title|Year
    return true;
}

// Drama: expect rest like " Director Name, Movie Title"
bool Store::buildDramaKey(const string& rest, string& outKey) {
    istringstream parts(rest);
    if (parts.peek() == ',') parts.get();

    string director, title;
    if (!getline(parts, director, ',')) return false;
    if (!getline(parts, title))         return false;

    director = trim(director);
    title    = trim(title);
    if (director.empty() || title.empty()) return false;

    outKey = director + "|" + title;   // EXACT: Director|Title
    return true;
}

// Classic: after "... D C", remaining tokens: " month year First Last"
bool Store::buildClassicKey(istream& ss, string& outKey) {
    int month, year;
    string first, last;
    if (!(ss >> month >> year >> first >> last)) return false;
    outKey = to_string(year) + "|" + to_string(month) + "|" + (first + " " + last);
    return true;
}

// --------------------- command handlers ---------------------

// bool Store::handleBorrow(istream& ss) {
//     int customerId; char media; char type;
//     if (!(ss >> customerId >> media >> type)) { cout << "ERROR: bad B header\n"; return false; }
//     if (!customers.has(customerId)) { cout << "ERROR: unknown customer " << customerId << "\n"; return false; }
//     if (media != 'D') { cout << "ERROR: unsupported media '" << media << "'\n"; return false; }

//     Customer* cust = customers.get(customerId);
//     string key;

//     if (type == 'F') {
//         string rest; getline(ss, rest);
//         if (!buildComedyKey(rest, key)) { cout << "ERROR: bad Comedy fields\n"; return false; }
//         Movie* m = inventory.findComedy(key);
//         if (!m) { cout << "ERROR: movie not found: " << key << "\n"; return false; }
//         if (!m->borrow()) { cout << "ERROR: out of stock: " << m->display() << "\n"; return false; }
//         cust->record(new Borrow(m, ""));
//         return true;
//     } else if (type == 'D') {
//         string rest; getline(ss, rest);
//         if (!buildDramaKey(rest, key)) { cout << "ERROR: bad Drama fields\n"; return false; }
//         Movie* m = inventory.findDrama(key);
//         if (!m) { cout << "ERROR: movie not found: " << key << "\n"; return false; }
//         if (!m->borrow()) { cout << "ERROR: out of stock: " << m->display() << "\n"; return false; }
//         cust->record(new Borrow(m, ""));
//         return true;
//     } else if (type == 'C') {
//         if (!buildClassicKey(ss, key)) { cout << "ERROR: bad Classic fields\n"; return false; }
//         Movie* m = inventory.findClassic(key);
//         if (!m) { cout << "ERROR: movie not found: " << key << "\n"; return false; }
//         if (!m->borrow()) { cout << "ERROR: out of stock: " << m->display() << "\n"; return false; }
//         cust->record(new Borrow(m, ""));
//         return true;
//     }

//     cout << "ERROR: invalid movie type '" << type << "'\n";
//     return false;
// }

// bool Store::handleReturn(istream& ss) {
//     int customerId; char media; char type;
//     if (!(ss >> customerId >> media >> type)) { cout << "ERROR: bad R header\n"; return false; }
//     if (!customers.has(customerId)) { cout << "ERROR: unknown customer " << customerId << "\n"; return false; }
//     if (media != 'D') { cout << "ERROR: unsupported media '" << media << "'\n"; return false; }

//     Customer* cust = customers.get(customerId);
//     string key;

//     if (type == 'F') {
//         string rest; getline(ss, rest);
//         if (!buildComedyKey(rest, key)) { cout << "ERROR: bad Comedy fields\n"; return false; }
//         Movie* m = inventory.findComedy(key);
//         if (!m) { cout << "ERROR: movie not found: " << key << "\n"; return false; }
//         m->returnMovie();
//         cust->record(new Return(m, ""));
//         return true;
//     } else if (type == 'D') {
//         string rest; getline(ss, rest);
//         if (!buildDramaKey(rest, key)) { cout << "ERROR: bad Drama fields\n"; return false; }
//         Movie* m = inventory.findDrama(key);
//         if (!m) { cout << "ERROR: movie not found: " << key << "\n"; return false; }
//         m->returnMovie();
//         cust->record(new Return(m, ""));
//         return true;
//     } else if (type == 'C') {
//         if (!buildClassicKey(ss, key)) { cout << "ERROR: bad Classic fields\n"; return false; }
//         Movie* m = inventory.findClassic(key);
//         if (!m) { cout << "ERROR: movie not found: " << key << "\n"; return false; }
//         m->returnMovie();
//         cust->record(new Return(m, ""));
//         return true;
//     }

//     cout << "ERROR: invalid movie type '" << type << "'\n";
//     return false;
// }

// bool Store::handleHistory(istream& ss) {
//     int customerId;
//     if (!(ss >> customerId)) { cout << "ERROR: bad H line\n"; return false; }
//     Customer* cust = customers.get(customerId);
//     if (!cust) { cout << "ERROR: unknown customer " << customerId << "\n"; return false; }
//     cout << "History for " << cust->getName() << " (ID " << cust->getId() << "):\n";
//     cust->printHistory();
//     return true;
// }

bool Store::handleInventory() {
    inventory.printAll();
    return true;
}

// --------------------- public API ---------------------


// void Store::loadCustomers(const string& filename) {
//     ifstream file(filename);
//     if (!file) { cout << "ERROR: cannot open customers file: " << filename << "\n"; return; }

//     // Expected line format (typical): ID Last First
//     int id; string last, first;
//     while (file >> id >> last >> first) {
//         Customer* c = new Customer(id, first, last);
//         customers.put(c);
//     }
// }

// void Store::processCommands(const string& filename) {
//     ifstream file(filename);
//     if (!file) { cout << "ERROR: cannot open commands file: " << filename << "\n"; return; }

//     string line;
//     while (readLine(file, line)) {
//         istringstream ss(line);
//         char cmd; ss >> cmd;

//         switch (cmd) {
//             case 'B': if (!handleBorrow(ss))   cout << ">> BAD BORROW: "   << line << "\n"; break;
//             case 'R': if (!handleReturn(ss))   cout << ">> BAD RETURN: "   << line << "\n"; break;
//             case 'H': if (!handleHistory(ss))  cout << ">> BAD HISTORY: "  << line << "\n"; break;
//             case 'I': if (!handleInventory())  cout << ">> BAD INVENTORY\n";                break;
//             default:
//                 cout << "ERROR: unknown command: " << cmd << " in line: " << line << "\n";
//                 break;
//         }
//     }
// }

void Store::printInventory() const {
    inventory.printAll();
}

// void Store::printHistory(int customerId) const {
//     Customer* cust = customers.get(customerId);
//     if (!cust) {
//         cout << "ERROR: unknown customer " << customerId << "\n";
//         return;
//     }
//     cout << "History for " << cust->getName() << " (ID " << cust->getId() << "):\n";
//     cust->printHistory();
// }
