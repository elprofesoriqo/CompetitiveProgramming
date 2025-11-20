#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Book;

void swap(Book *a, Book *b) {
    Book temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Book *heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].value > heap[largest].value) {
        largest = left;
    }
    if (right < n && heap[right].value > heap[largest].value) {
        largest = right;
    }

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(heap, n, largest);
    }
}

void buildHeap(Book *heap, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(heap, n, i);
    }
}

Book extractMax(Book *heap, int *size) {
    Book root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify(heap, *size, 0);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int *books = (int *)malloc(n * sizeof(int));
    int *k_values = (int *)malloc(n * sizeof(int));
    int *checkpoints = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &books[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &k_values[i]);
    }

    int checkpoints_count = 0;
    int checkpoint;

    while (scanf("%d", &checkpoint) == 1) {
        checkpoints[checkpoints_count++] = checkpoint;
        if (checkpoint == n) break;
    }

    for (int i = 0; i < n; ++i) {
        Book *heap = (Book *)malloc((n - i) * sizeof(Book));
        int heap_size = n - i;

        for (int j = 0; j < heap_size; j++) {
            heap[j].value = books[j];
            heap[j].index = j;
        }

        buildHeap(heap, heap_size);

        int k = k_values[i];
        Book selected_book;

        for (int j = 0; j < k; j++) {
            selected_book = extractMax(heap, &heap_size);
        }

        int selected_index = selected_book.index;
        int temp = books[selected_index];
        books[selected_index] = books[n - i - 1];
        books[n - i - 1] = temp;

        free(heap);

        for (int j = 0; j < checkpoints_count; ++j) {
            if (checkpoints[j] == i + 1) {
                for (int l = 0; l < n; ++l) {
                    printf("%d ", books[l]);
                }
                printf("\n");
                break;
            }
        }
    }

    free(books);
    free(k_values);
    free(checkpoints);

    return 0;
}
