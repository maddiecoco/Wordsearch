void search(int algorithm) {
    Dictionary dict;
    // Load words into dict
    // Load grid from file

    if (algorithm == 1) {
        dict.sortUsingQuicksort();
    } else if (algorithm == 2) {
        dict.sortUsingHeapsort();
    }

    // Perform the search in the grid using dict.binarySearch
    // Print found words
}
