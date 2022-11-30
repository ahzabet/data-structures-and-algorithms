// Insertion Sort Algorithm

// Complexity Analysis
// O(n^2)

#include <iostream>
#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> unsortedList);
void display(vector<int> sortedList);

int main()
{
    vector<int> unsortedList = {21, 2, 7, 19, 13};
    vector<int> sortedList = insertionSort(unsortedList);
    display(sortedList);

    return 0;
}

vector<int> insertionSort(vector<int> unsortedList)
{
    for (int i = 1; i < unsortedList.size(); i++)
    {
        int current = unsortedList[i];
        int previous = i - 1;

        while (previous >= 0 && unsortedList[previous] > current)
        {
            unsortedList[previous + 1] = unsortedList[previous];

            previous--;
        }

        unsortedList[previous + 1] = current;
    }

    return unsortedList;
};

void display(vector<int> sortedList)
{
    cout << "Sorted vector: " << endl;
    for (int i = 0; i < sortedList.size(); i++)
    {
        cout << sortedList[i] << "\t";
    }
}
