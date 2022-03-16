#include <iostream>
using namespace std;

bool search(int arr[], int *size)
{
    int key;
    cout << "Enter element to search";
    cin >> key;
    for (int i = 0; i < *size; i++)
    {
        if (arr[i] == key)
        {
            return true;
        }
    }
    return false;
}
void deletion(int arr[], int *size)
{
    int key;
    cout << "Enter position to delete" << endl;
    cin >> key;
    if ((key - 1) > *size)
        cout << "\nThere is no element to delete";
    else
    {
        for (int i = (key - 1); i < *size; i++)
        {
            arr[i] = arr[i + 1];
        }
        *size = *size - 1;
        cout << "\nElement deleted succussfully!";
    }
}
void update(int arr[], int *size)
{
    int pos, num;
    cout << "\nEnter position of element ";
    cin >> pos;
    cout << "\nEnter value ";
    cin >> num;
    if ((pos - 1) > *size)
        cout << "\nOut of index";
    else if (pos < 0)
        cout << "\nChoose correct index value";
    else
        arr[pos] = num;
}
void insertAtPos(int arr[], int *size)
{
    int pos, num;
    cout << "\nEnter position of element ";
    cin >> pos;
    cout << "\nEnter value ";
    cin >> num;
    if ((pos - 1) > *size || (pos - 1) < 0)
        cout << "\nChoose valid index";
    else
    {
        *size = *size + 1;
        for (int i = (pos - 1); i < *size; i++)
        {
            arr[i + 1] = arr[i];
        }
        arr[(pos - 1)] = num;
    }
}
void display(int arr[], int *size)
{
    for (int i = 0; i < *size; i++)
    {
        cout << arr[i] << " ";
    }
}
void selectionSort(int arr[], int *size)
{
    for (int i = 0; i < *size - 1; i++)
    {
        for (int j = i + 1; j < *size; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main()
{
    int n;
    cout << "Enter size of the array";
    cin >> n;
    int arr[n];
    cout << "Enter array element";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = 0, key;
    do
    {
        cout << "\n1.insertAtPos    2.Update     3.deletion     4.Search   5.display  6.Sort   7.Exit" << endl;
        cin >> key;
        switch (key)
        {

        case 1:
            insertAtPos(arr, &n);
            break;
        case 2:
            update(arr, &n);
            break;
        case 3:
            deletion(arr, &n);
            break;
        case 4:
            if (search(arr, &n))
                cout << "\nElement found";
            else
                cout << "\nElement not found";
            break;
        case 5:
            display(arr, &n);
        case 6:
            selectionSort(arr, &n);
            display(arr, &n);
        case 7:
            return 7;
            break;
        default:
            cout << "\nChoose valid options";
        }
    } while (i != 7);

    return 0;
}