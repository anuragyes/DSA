 // Calculate the expected sum of all numbers from 1 to n
    int expectedSum = n * (n + 1) / 2;

    // Calculate the actual sum of elements in the array
    int actualSum = 0;
    for (int num : arr) {
        actualSum += num;
    }

    // The missing element is the difference between expectedSum and actualSum
    return expectedSum - actualSum;