#include <iostream>

using namespace std;

void printArray(const int* A, int n) {
    for (int i = 0; i < n; ++i) {
        cout << A[i] << (i < n - 1 ? " " : "\n");
    }
}



int findMin(const int* A, int start, int end) {
    int minVal = A[start];
    for (int i = start + 1; i <= end; ++i) {
        if (A[i] < minVal) {
            minVal = A[i];
        }
    }
    return minVal;
}

void merge(int *A, int L, int M, int R, const int *original) {
    int leftSize = M - L + 1;
    int rightSize = R - M;

    int* left = new int[leftSize];
    int* right = new int[rightSize];

    for (int i = 0; i < leftSize; ++i)
        left[i] = A[L + i];
    for (int i = 0; i < rightSize; ++i)
        right[i] = A[M + 1 + i];

    int Mval = original[M];
    int leftMin = findMin(original, L, M);
    int rightMin = findMin(original, M + 1, R);

    if (R - L + 1 >= 3) {
        cout << "[" << L << ":" << M << ":" << R << "] " << Mval
             << " [" << leftMin << " " << rightMin << "]" << endl;
    }

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

void mergeSort(int* A, int L, int R, const int* original) {
    if (L < R) {
        int M = L + (R - L) / 2;

        if (L < M) {
            mergeSort(A, L, M, original);
        }
        if (M + 1 < R) {
            mergeSort(A, M + 1, R, original);
        }

        merge(A, L, M, R, original);
    }
}

int main() {
    int n;
    cin >> n;

    int* A = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    printArray(A, n);

    int* original = new int[n];
    for (int i = 0; i < n; ++i) {
        original[i] = A[i];
    }

    mergeSort(A, 0, n - 1, original);

    printArray(A, n);

    delete[] A;
    delete[] original;

    return 0;
}
