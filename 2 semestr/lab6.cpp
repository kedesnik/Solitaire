#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <regex>
#include <clocale>
#include <locale>
#include <codecvt>
using namespace std;


char* stroka(char* name);
void con(char* word);
bool pal(char* str);
void funck3(string t[], int& count, const string& line);
void alphabet(string words[], int count);
void noreg(const string& filename, int n);
void withreg(const string& filename, int n);

 int main() {
    setlocale(LC_CTYPE, "");
    setlocale(LC_ALL, "C");

    //1
    //char name[61];
    //cin.getline(name, 60);
    //cout << stroka(name) << endl;
    

    //2
   /*char str[100];

    cin.getline(str, 99);

    if (pal(str)) {
        cout << "Yes." << endl;
    }
    else {
        cout << "No." << endl;
    }
    return 0;*/

    //3
    /*ifstream fin("input.txt");
    ofstream fout("output.txt");
    string words[1000];
    int count = 0;

    string line; 
    while (getline(fin, line)) {
        funck3(words, count, line);
    }

    alphabet(words, count);
    for (int i = 0; i < count; i++) { 
        fout << words[i] << endl;
    }

    fin.close();
    fout.close();
    cout << "Success." << endl;
    return 0;*/
    
    //4
    string filename = "test1.txt";
    int n;
    cout << "max lenght (n): ";
    cin >> n;
    noreg(filename, n);
    withreg(filename, n);
    return 0;
}
    


char* stroka(char* name) {
    static char word[61];
    word[0] = '\0';

    char* token = strtok(name, " ");
    if (token != NULL) {
        strcpy(word, token);
        token = strtok(NULL, " ");
    }

    for (int count = 0; token != NULL && count < 2; count++) {
        strcat(word, " ");
        strncat(word, &token[0], 1);
        strcat(word, ".");
        token = strtok(NULL, " ");
    }

    return word;
}

//2
void con(char* word) {
    for (int i = 0; word[i] != '\0'; i++) {
            word[i] = tolower(word[i]); 
    }
}
bool pal(char* str) {
    char filter[100];
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            filter[j++] = str[i];
        }
    }
    filter[j] = '\0';

    con(filter);

    for (int i = 0; i < j / 2; i++) {
        if (filter[i] != filter[j - 1 - i]) {
            return false;
        }
    }
    return true;
}



//3
void funck3(string t[], int& count, const string& line) {
    regex re(R"(\b([a-zA-Z]+)\b)"); 
    smatch parts; 
    string cleanW = line; 

    while (regex_search(cleanW, parts, re)) { 
        string word = parts.str(0);

        for (int i = 0; i < word.length(); ++i) { 
            word[i] = tolower(word[i]);
        }
        bool unical = true;
        for (int i = count - 1; i >= 0; --i) { 
            if (t[i] == word) {
                unical = false;
                break;
            }
        }
        
        if (unical) {
            t[count] = word;
            count++;
        }
        cleanW = parts.suffix().str(); 
    }
}

void alphabet(string words[], int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (words[j] > words[j + 1]) {
                swap(words[j], words[j + 1]);
            }
        }
    }
}
//4
void noreg(const string& filename, int n) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) { 
        if (line.length() < n) { 
            cout << line << endl;
        }
    }
    file.close();
}

void withreg(const string& filename, int n) {
    ifstream file(filename);
    regex pattern("^.{0," + to_string(n - 1) + "}$"); 
    string line;
    while (getline(file, line)) { 
        if (regex_match(line, pattern)) { 
            cout << line << endl;
        }
    }
    file.close();
}
