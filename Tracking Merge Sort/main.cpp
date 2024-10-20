#include <iostream>

using namespace std;

void MergeSort(int* A, int L, int R) {
    if (L < R - 1) {
        int M = (L + R) / 2;

        MergeSort(A, L, M);
        MergeSort(A, M, R);

        cout << "[" << L << ":" << M << ":" << R << "] "
             << A[M] << " ["
             << (L < M ? A[L] : 0) << " "
             << (M < R ? A[M] : 0)
             << "]" << endl;

        int leftSize = M - L;
        int rightSize = R - M;

        int* left = new int[leftSize];
        int* right = new int[rightSize];

        for (int i = 0; i < leftSize; i++)
            left[i] = A[L + i];
        for (int j = 0; j < rightSize; j++)
            right[j] = A[M + j];

        int i = 0, j = 0, k = L;

        while (i < leftSize && j < rightSize) {
            if (left[i] <= right[j]) {
                A[k++] = left[i++];
            } else {
                A[k++] = right[j++];
            }
        }

        while (i < leftSize) {
            A[k++] = left[i++];
        }

        while (j < rightSize) {
            A[k++] = right[j++];
        }

        delete[] left;
        delete[] right;
    }
}

int main() {
    int n;
    cin >> n;

    int* sequence = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    for (int i = 0; i < n; i++) {
        cout << sequence[i] << " ";
    }
    cout << endl;

    MergeSort(sequence, 0, n);

    for (int i = 0; i < n; i++) {
        cout << sequence[i] << " ";
    }
    cout << endl;

    delete[] sequence;

    return 0;
}
