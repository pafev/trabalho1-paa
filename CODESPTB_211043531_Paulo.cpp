#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int countSwaps(vector<int> array) {
    int swapCount = 0;
    int n = array.size();

    function<void(int, int)> merge = [&](int initial, int final) {
        if (initial >= final) return;
        int mid = initial + (final - initial) / 2;
        merge(initial, mid);
        merge(mid + 1, final);

        vector<int> merged(final - initial + 1);
        int i = initial, j = mid + 1, k = 0;

        while (i <= mid && j <= final) {
            if (array[i] <= array[j]) {
                merged[k++] = array[i++];
            } else {
                merged[k++] = array[j++];
                swapCount += (mid - i + 1); // Conta os elementos restantes na primeira metade que são maiores que array[j]
            }
        }

        while (i <= mid) {
            merged[k++] = array[i++];
        }

        while (j <= final) {
            merged[k++] = array[j++];
        }

        for (int p = 0; p < merged.size(); p++) {
            array[initial + p] = merged[p];
        }
    };

    merge(0, n - 1);
    return swapCount;
}



int main() {
    int T;
    cin >> T;

    int N;
    for (int i=0; i < T; i++) {
        cin >> N;

        int number;
        vector<int> numbers;
        for (int j=0; j < N; j++) {
            cin >> number;
            numbers.push_back(number);
        }

        cout << countSwaps(numbers) << endl;
    }


    return 0;
}