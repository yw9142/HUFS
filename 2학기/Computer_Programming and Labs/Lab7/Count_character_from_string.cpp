#include <iostream>

using namespace std;

int Count_character_from_string(char m, char n[]);

int main() {
    char m;
    char n[8];
    cin >> m >> n;

    cout << Count_character_from_string(m, n) << endl;

    return (0);
}

int Count_character_from_string(char m, char n[]) {
    int count = 0;
    for (int i = 0; i < sizeof(n) / (sizeof(char)); i++) {
        if (n[i] == m)
            count += 1;
    }

    return (count);
}