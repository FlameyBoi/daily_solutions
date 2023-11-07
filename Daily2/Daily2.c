#include <stdlib.h>

typedef struct {
    double* arr;
    int size;
} minHeap;

void upHeapify(minHeap* heap);
void downHeapify(minHeap* heap, int node);
void buildHeap(minHeap* heap);
double pop(minHeap* heap);

int eliminateMaximum(int* dist, int distSize, int* speed, int speedSize) {
    minHeap heap;
    int i, time = 0, count = 0;
    heap.arr = (double*)malloc(distSize * sizeof(double));
    heap.size = distSize;
    for (i = 0; i < distSize; i++)
        heap.arr[i] = (dist[i] / (double)speed[i]);
    buildHeap(&heap);
    while (count < distSize)
    {
        double cur = pop(&heap);
        if (cur > time)
        {
            count++;
            time++;
        }
        else
            break;
    }
    free(heap.arr);
    return count;
}

void upHeapify(minHeap* heap)
{
    int cur = heap->size;
    int parent = (cur - 1) / 2;
    while (cur && heap->arr[cur] < heap->arr[parent])
    {
        int temp = heap->arr[parent];
        heap->arr[parent] = heap->arr[cur];
        heap->arr[cur] = temp;
        cur = parent;
        parent = (cur - 1) / 2;
    }
}

void downHeapify(minHeap* heap, int node)
{
    int cur = node;
    while (cur < heap->size)
    {
        int min;
        int left = (cur * 2) + 1, right = (cur * 2) + 2;
        if (left >= heap->size)
            break;
        else if (right < heap->size)
            min = (heap->arr[left] < heap->arr[right]) ? left : right;
        else
            min = left;

        if (heap->arr[cur] > heap->arr[min])
        {
            double temp = heap->arr[min];
            heap->arr[min] = heap->arr[cur];
            heap->arr[cur] = temp;
            cur = min;
        }
        else
            break;
    }
}

void buildHeap(minHeap* heap) // heapify array in O(n)
{
    int i;
    for (i = heap->size - 1; i >= 0; i--)
        downHeapify(heap, i);
}

double pop(minHeap* heap)
{
    double ret = heap->arr[0];
    heap->size--;
    if (heap->size)
    {
        heap->arr[0] = heap->arr[heap->size];
        downHeapify(heap, 0);
    }
    return ret;
}