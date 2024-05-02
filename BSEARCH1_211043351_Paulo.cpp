#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>* numbers, int target) {
    int initial = 0;
    int final = numbers->size() - 1;

    while (initial <= final) {
        int mid = initial + (final - initial) / 2;

        if ((*numbers)[mid] == target) {
            while (true) {
                if ((*numbers)[mid - 1] == target) {
                    mid--;
                } else {
                    break;
                }
            }
            return mid;
        } else if ((*numbers)[mid] < target) {
            initial = mid + 1;
        } else {
            final = mid - 1;
        }
    }

    return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,Q;
    cin >> N;
    cin >> Q;

    int input;

    vector<int> numbers;
    for (int i = 0; i < N; i++) {
        cin >> input;
        numbers.push_back(input);
    }
    for (int i = 0; i < Q; i++) {
        cin >> input;
        cout << binarySearch(&numbers, input) << '\n';
    }


    return 0;
}