#include <iostream>
#include <string>
#include <vector>
using namespace std;

void split(vector<int> *array, const string *str, const char delimiter) {
    string temp = "";
    int lenStr = str->length();

    for (int i=0; i <= lenStr; i++) {
        if ((*str)[i] == delimiter || i == lenStr) {
            array->push_back(stoi(temp));
            temp = "";
        } else {
            temp += (*str)[i];
        }
    }

}

void merge(vector<int> *array, int initial, int mid, int final) {
    int sizeLeftArray = mid - initial + 1;
    int sizeRightArray = final - mid;

    vector<int> L(sizeLeftArray), R(sizeRightArray);

    for (int i = 0; i < sizeLeftArray; i++)
        L[i] = (*array)[initial + i];
    for (int j = 0; j < sizeRightArray; j++)
        R[j] = (*array)[mid + 1 + j];

    int i = 0, j = 0, k = initial;

    while (i < sizeLeftArray && j < sizeRightArray) {
        if (L[i] <= R[j]) {
            (*array)[k] = L[i];
            i++;
        } else {
            (*array)[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < sizeLeftArray) {
        (*array)[k] = L[i];
        i++;
        k++;
    }

    while (j < sizeRightArray) {
        (*array)[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> *array, int initial, int final) {
    if (initial < final) {
        int mid = initial + (final - initial) / 2;

        mergeSort(array, initial, mid);
        mergeSort(array, mid + 1, final);

        merge(array, initial, mid, final);
    }
}


int main() {
    vector<int> arrayToSort;
    string input;

    getline(cin, input);
    split(&arrayToSort, &input, ' ');

    int sizeArray = arrayToSort.size();

    mergeSort(&arrayToSort, 0, sizeArray - 1);

    for (int i = 0; i < sizeArray; i++) {
        if (i ==  sizeArray - 1) {
            cout << arrayToSort[i] << endl;
        } else {
            cout << arrayToSort [i] << " ";
        }
    }

    return 0;
}