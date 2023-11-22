template <typename T>
class Heap {
    vector<T> data;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    T getItem(int n) { return data[n]; }

    void maxHeapify(int i, int n) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < n && data[l] > data[largest])
            largest = l;
        if (r < n && data[r] > data[largest])
            largest = r;

        if (largest != i) {
            swap(data[i], data[largest]);
            maxHeapify(largest, n);
        }
    }

    void buildMaxHeap() {
        int n = data.size();
        for (int i = n / 2 - 1; i >= 0; i--)
            maxHeapify(i, n);
    }

public:
    Heap(const vector<T>& v) : data(v) {}

    void heapsort() {
        buildMaxHeap();
        for (int i = data.size() - 1; i > 0; i--) {
            swap(data[0], data[i]);
            maxHeapify(0, i);
        }
    }

    vector<T> getSortedData() {
        return data;
    }
};
