#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &vector, int firstIndex, int secondIndex);
int partition(vector<int> &vector, int startIndex, int endIndex);
void quickSort(vector<int> &unsortedList, int startIndex, int endIndex);
vector<int> sort(vector<int> &vector);
void display(vector<int> &sortedList);

int main()
{
    cout << "Yooo" << endl;

    vector<int> unsortedList = {21, 2, 7, 19, 13};
    vector<int> sortedList = sort(unsortedList);
    display(sortedList);

    return 0;
}

void swap(vector<int> &vector, int firstIndex, int secondIndex)
{
    int temp = vector[firstIndex];
    vector[firstIndex] = vector[secondIndex];
    vector[secondIndex] = temp;
}

int partition(vector<int> &vector, int startIndex, int endIndex)
{
    int pivot = endIndex;
    int boundary = startIndex - 1;

    for (int i = startIndex; i <= endIndex; i++)
    {
        if (vector[i] <= vector[pivot])
        {
            boundary++;
            swap(vector, i, boundary);
        }
    }

    return boundary;
}

// 0, 9
// 4 pivot
// 0, 3 (left)
// 5, 9 (right)

void quickSort(vector<int> &unsortedList, int startIndex, int endIndex)
{
    if (startIndex >= endIndex)
    {
        return;
    }

    // Partition the vector and get the boundary (which is now the pivot)
    int boundary = partition(unsortedList, startIndex, endIndex);

    // Sort the left side of the boundary
    quickSort(unsortedList, startIndex, boundary - 1);

    // Sort the right side of the boundary
    quickSort(unsortedList, boundary + 1, endIndex);
}

vector<int> sort(vector<int> &vector)
{
    quickSort(vector, 0, vector.size() - 1);

    return vector;
}

void display(vector<int> &sortedList)
{
    cout << "Sorted vector: " << endl;
    for (int i = 0; i < sortedList.size(); i++)
    {
        cout << sortedList[i] << "\t";
    }
}
