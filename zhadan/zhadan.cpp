#include <iostream>
#include <climits>
using namespace std;

void findMinSumRows(double a[15][2], int& imin, int& jmin, double& minSum) {
    minSum = a[0][0] + a[0][1];
    imin = 0;
    jmin = 1;

    for (int i = 0; i < 14; i++) {
        double currentSum = a[i][0] + a[i][1] + a[i + 1][0] + a[i + 1][1];
        if (currentSum < minSum) {
            minSum = currentSum;
            imin = i;
            jmin = i + 1;
        }
    }
}
void sortRow(double row[2]) {
    if (row[0] > row[1]) {
        double temp = row[0];
        row[0] = row[1];
        row[1] = temp;
    }
}

int main() {
    setlocale(LC_ALL, "ukrainian");

    double a[15][2];
    int imin, jmin;
    double minSum;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }
    findMinSumRows(a, imin, jmin, minSum);
    for (int i = 0; i < 15; i++) {
        sortRow(a[i]);
    }
    cout << "Вiдсортований масив:" << endl;
    for (int i = 0; i < 15; i++) {
        cout << " " << a[i][0] << " " << a[i][1] << " ";
        if (i < 14) {
            cout << endl;
        }
    }
    cout << "Номер 1 рядка: " << imin << endl;
    cout << "Номер 2 рядка: " << jmin << endl;
    cout << "Мiнiмальна сума елементiв: " << minSum << endl;

    return 0;

}

