#include <iostream>
#include <vector>
using namespace std;

class Sorting
{

public:
    void selectionSort(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }

    void merge(vector<int> &arr, int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
                arr[k++] = L[i++];
            else
                arr[k++] = R[j++];
        }

        while (i < n1)
            arr[k++] = L[i++];
        while (j < n2)
            arr[k++] = R[j++];
    }

    void mergeSort(vector<int> &arr, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    int linearSearch(vector<int> &arr, int target)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == target)
            {
                return i;
            }
        }
        return -1;
    }

    int binarySearch(vector<int> &arr, int target)
    {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target)
            {
                return mid;
            }

            else if (arr[mid] < target)
            {
                left = mid + 1;
            }

            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};

void printArray(vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
        cout << endl;
    }
}
int main()
{
    Sorting sort;
    vector<int> data;
    int choice, val, result, size;

    do
    {
        cout<<endl;
        cout << "*** Menu ***" << endl;
        cout << "1. Enter Array" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Merge Sort" << endl;
        cout << "4. Linear Search" << endl;
        cout << "5. Binary Search" << endl;
        cout << "6. Display Arraty" << endl;
        cout << "7. Exit" << endl;

        cout<<endl;
        cout << "Enter Choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
        cout<<endl;
            cout << "Enter size of array:";
            cin >> size;
            data.resize(size);
            cout << "enter elements:"<<endl;
            for (int i = 0; i < size; i++)
            {
                cin >> data[i];
            }
            break;

        case 2:
        cout<<endl;
            sort.selectionSort(data);
            cout << "After Selection Sort:" << endl;
            printArray(data);
            break;

        case 3:
        cout<<endl;
            sort.mergeSort(data, 0, data.size() - 1);
            cout << "After Merge Sort:" << endl;
            printArray(data);
            break;

        case 4:
        cout<<endl;
            cout << "Search the value:";
            cin >> val;
            result = sort.linearSearch(data, val);
            if (result != -1)
            {
                cout << "Index is:" << result << endl;
            }
            else
            {
                cout << "Not Found" << endl;
            }
            break;

            case 5:
            cout<<endl;
            cout<<"Search the value: ";
            cin>>val;
            result = sort.binarySearch(data,val);
            if (result != -1)
            {
                cout<<"Index is:"<<result<<endl;
            }
            else{
                cout<<"Not Found!"<<endl;
            }
            break;

            case 6:
            cout<<endl;
            cout<<"Current Array:"<<endl;
            printArray(data);
            break;

            case 7:
            cout<<endl;
            cout<<"Exit Program"<<endl;
            break;

        default:
        cout<<"Invalid Choice!"<<endl;
            break;
        }
    }
    while (choice != 7);
   
    return 0;
}