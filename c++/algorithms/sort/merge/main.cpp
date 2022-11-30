// Merge Sort Algorithm

// Complexity Analysis
// O(n * log(n))

#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSort(vector<int> unsortedList);
void display(vector<int> sortedList);

int main()
{
    vector<int> unsortedList = {21, 2, 7, 19, 13};
    vector<int> sortedList = mergeSort(unsortedList);

    display(sortedList);
}

vector<int> mergeSort(vector<int> unsortedList)
{
    if (unsortedList.size() > 1)
    {

        // Calculate midpoint
        int midpoint = unsortedList.size() / 2;

        // C++ equivalent to using JavaScript slices
        // Divide vector into halves
        vector<int> left(unsortedList.begin(), unsortedList.begin() + midpoint);
        vector<int> right(unsortedList.begin() + midpoint, unsortedList.begin() + unsortedList.size());

        // Sort halves using recursion
        left = mergeSort(left);
        right = mergeSort(right);

        // Merge the halves
        int i = 0, j = 0, k = 0;

        while (i < left.size() && j < right.size())
        {
            if (left[i] < right[j])
            {
                unsortedList[k] = left[i];
                i++;
            }
            else
            {
                unsortedList[k] = right[j];
                j++;
            }

            k++;
        }

        while (i < left.size())
        {
            unsortedList[k] = left[i];
            i++;
            k++;
        }

        while (j < right.size())
        {
            unsortedList[k] = right[j];
            j++;
            k++;
        }
    }

    return unsortedList;
}

void display(vector<int> sortedList)
{
    cout << "Sorted vector: " << endl;
    for (int i = 0; i < sortedList.size(); i++)
    {
        cout << sortedList[i] << "\t";
    }
}
