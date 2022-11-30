// Heap Sort Algorithm

// Complexity Analysis
// O(n * log(n))

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &v, int i, int size);
void buildHeap(vector<int> &v);
vector<int> heapSort(vector<int> &v);
void display(vector<int> sortedList);

int main()
{
    vector<int> unsortedList = {21, 2, 7, 19, 13};
    vector<int> sortedList = heapSort(unsortedList);
    display(sortedList);

    return 0;
}

// Working with a max-heap tree
void heapify(vector<int> &v, int i, int size)
{
    int largest = i;       // Gets the largest node
    int left = 2 * i + 1;  // Gets the left child node
    int right = 2 * i + 2; // Gets the right child node

    if (left < size && v[left] > v[largest])
        largest = left;

    if (right < size && v[right] > v[largest])
        largest = right;

    if (largest != i)
    {
        // If i is larger than largest, set i to largest
        swap(v[i], v[largest]);

        // Heapify with new largest
        heapify(v, largest, size);
    }
}

void buildHeap(vector<int> &v)
{
    for (int j = v.size() / 2 - 1; j >= 0; j--)
        heapify(v, j, v.size());
}

vector<int> heapSort(vector<int> &v)
{
    buildHeap(v);

    int currentSize = v.size();

    for (int i = 0; i < v.size(); i++)
    {
        swap(v[0], v[currentSize - 1]);
        heapify(v, 0, --currentSize);
    }

    return v;
}

void display(vector<int> sortedList)
{
    cout << "Sorted vector: " << endl;
    for (int i = 0; i < sortedList.size(); i++)
    {
        cout << sortedList[i] << "\t";
    }
}
