template <typename T>
class Heap {
    vector<T> data; // The heap is stored as a vector

    // Returns the index of the parent of the node at index i
    int parent(int i) { return (i - 1) / 2; }

    // Returns the index of the left child of the node at index i
    int left(int i) { return (2 * i + 1); }

    // Returns the index of the right child of the node at index i
    int right(int i) { return (2 * i + 2); }

    // Returns the item at the nth index in the heap
    T getItem(int n) { return data[n]; }

    // Maintains the max heap property, assuming the subtrees are already max heaps
    void maxHeapify(int i, int n) {
        int largest = i; // Initialize largest as root
        int l = left(i); // left child
        int r = right(i); // right child

        // If the left child is larger than the root
        if (l < n && data[l] > data[largest])
            largest = l;

        // If the right child is larger than the largest so far
        if (r < n && data[r] > data[largest])
            largest = r;

        // If the largest is not the root
        if (largest != i) {
            swap(data[i], data[largest]); // Swap the root with the largest
            maxHeapify(largest, n); // Recursively heapify the affected sub-tree
        }
    }

    // Builds a max heap from an unsorted vector
    void buildMaxHeap() {
        int n = data.size();
        // Start from the last non-leaf node and heapify each node
        for (int i = n / 2 - 1; i >= 0; i--)
            maxHeapify(i, n);
    }

public:
    // Constructor to initialize the heap with a given vector
    Heap(const vector<T>& v) : data(v) {}

    // Sorts the elements in the heap
    void heapsort() {
        buildMaxHeap(); // First build a max heap
        // One by one extract elements from the heap
        for (int i = data.size() - 1; i > 0; i--) {
            swap(data[0], data[i]); // Move the current root to the end
            maxHeapify(0, i); // Call maxHeapify on the reduced heap
        }
    }

    // Returns the sorted data
    vector<T> getSortedData() {
        return data;
    }
};
