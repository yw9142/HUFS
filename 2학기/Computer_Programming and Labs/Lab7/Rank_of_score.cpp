#include <iostream>

using namespace std;

void Rank_of_score(int score[], int rank[]);

int main() {
    int numbers[10];
    int rank[10];

    for (int i = 0; i < 10; i++) {
        cin >> numbers[i];
    }

    Rank_of_score(numbers, rank);

    return (0);
}

void Rank_of_score(int score[], int rank[]) {
    int count;

    for (int i = 0; i < 10; i++) {
        count = 0;
        for (int j = 0; j < 10; j++) {
            if (score[i] > score[j])
                count++;
        }
        rank[i] = 10 - count;
    }

    for (int i = 0; i < 10; i++) {
        cout << "Input " << i + 1 << " : " << score[i] << " // Rank : " << rank[i] << endl;
    }
}
