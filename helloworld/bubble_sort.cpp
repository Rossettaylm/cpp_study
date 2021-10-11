#include <iostream>
#include <vector>

using namespace std;
void display(vector<int> vec);
//引用调用函数
void swap(int &a, int &b);
void bubble_sort(vector<int> &vec);

int main()
{
    int arr[8] = {3, 5, 20, 5, 6, 20, 89, 50};
    vector<int> vec(arr, arr + 8);
    cout << "The origin vector: ";
    display(vec);
    bubble_sort(vec);
    cout << "After sorting: ";
    display(vec);

    return 0;
}

void display(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ' ';
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(vector<int> &vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = 0; j < vec.size() - 1 - i; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}
