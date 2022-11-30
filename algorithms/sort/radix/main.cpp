// Radix Sort Algorithm

// Complexity Analysis
// O((n + k) / d)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> countingSort(vector<int> &unsortedList, int size, int place);
vector<int> radixSort(vector<int> &unsortedList);
void display(vector<int> sortedList);

int main()
{
    vector<int> unsortedList = {21, 2, 7, 19, 13};
    vector<int> sortedList = radixSort(unsortedList);

    display(sortedList);

    return 0;
}

vector<int> countingSort(vector<int> &unsortedList, int size, int place)
{
    int max = 10;
    int output[size];
    int count[max];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    // Calculate count of elements
    for (int i = 0; i < size; i++)
        count[(unsortedList[i] / place) % 10]++;

    // Calculate cumulative count
    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    // Place the elements in sorted order
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(unsortedList[i] / place) % 10] - 1] = unsortedList[i];
        count[(unsortedList[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        unsortedList[i] = output[i];

    return unsortedList;
}

vector<int> radixSort(vector<int> &unsortedList)
{
    vector<int> sortedList;

    // Find the element with the max value
    int max = *max_element(unsortedList.begin(), unsortedList.end());

    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
        sortedList = countingSort(unsortedList, unsortedList.size(), place);

    return sortedList;
}

void display(vector<int> sortedList)
{
    cout << "Sorted vector: " << endl;
    for (int i = 0; i < sortedList.size(); i++)
    {
        cout << sortedList[i] << "\t";
    }
}
