#include <stdio.h>
#include <stdlib.h>

// Structure for intervals
typedef struct {
    int start;
    int end;
} Interval;

// Comparator for sorting by start time
int compare(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

// Min-heap functions
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(int heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

// Insert into heap
void insertHeap(int heap[], int *size, int value) {
    heap[*size] = value;
    heapifyUp(heap, *size);
    (*size)++;
}

// Remove min (root)
void removeMin(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

int minMeetingRooms(Interval arr[], int n) {
    qsort(arr, n, sizeof(Interval), compare);

    int *heap = (int *)malloc(n * sizeof(int));
    int size = 0;

    // Add first meeting
    insertHeap(heap, &size, arr[0].end);

    for (int i = 1; i < n; i++) {
        // If current meeting starts after earliest ending
        if (arr[i].start >= heap[0]) {
            removeMin(heap, &size); // reuse room
        }
        insertHeap(heap, &size, arr[i].end);
    }

    int result = size;
    free(heap);
    return result;
}

int main() {
    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    Interval *arr = (Interval *)malloc(n * sizeof(Interval));

    printf("Enter start and end times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    int rooms = minMeetingRooms(arr, n);

    printf("Minimum number of rooms required: %d\n", rooms);

    free(arr);
    return 0;
}