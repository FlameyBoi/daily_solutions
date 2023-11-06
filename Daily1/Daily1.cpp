
using namespace std;

class minHeap {
private:
    int* arr;
    int size = 0;
    void upHeapify()
    {
        int cur = size;
        int parent = (cur - 1) / 2;
        while (cur && arr[cur] < arr[parent])
        {
            int temp = arr[parent];
            arr[parent] = arr[cur];
            arr[cur] = temp;
            cur = parent;
            parent = (cur - 1) / 2;
        }
    }

    void downHeapify()
    {
        int cur = 0;
        while (cur < size)
        {
            int min;
            int left = (cur * 2) + 1, right = (cur * 2) + 2;
            if (left >= size)
                break;
            else if (right < size)
                min = (arr[left] < arr[right]) ? left : right;
            else
                min = left;

            if (arr[cur] > arr[min])
            {
                int temp = arr[min];
                arr[min] = arr[cur];
                arr[cur] = temp;
                cur = min;
            }
            else
                break;
        }
    }

public:
    minHeap(int n)
    {
        arr = new int[n];
    }

    int pop()
    {
        int ret = arr[0];
        size--;
        if (size)
        {
            arr[0] = arr[size];
            downHeapify();
        }
        return ret;
    }

    void push(int n)
    {
        arr[size] = n;
        upHeapify();
        size++;
    }
};

class SeatManager {
private:
    minHeap seats;
public:
    SeatManager(int n) : seats(n) {
        for (int i = 1; i <= n; i++)
            seats.push(i);
    }

    int reserve() {
        return seats.pop();
    }

    void unreserve(int seatNumber) {
        seats.push(seatNumber);
    }
};

