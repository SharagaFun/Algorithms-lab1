#include <iostream>
#include <vector>


void binSearch(std::vector<int> array, int r, int t, int l = 0)
{
    while (l <= r)
    {
        int m = (l + r) / 2;
        std::cout<<array[m]<<" ";
        if (array[m] == t)
            return;
        else if (t > array[m])
            l = m + 1;
        else
            r = m - 1;
    }
}



void doublingSearch (std::vector<int> array, int n, int t) {

       int r = 1;
       int l;

       if (array.size() == 1)
       {
           std::cout<<array[0];
           return;
       }

       if (array[0] == t)
       {
           std::cout<<array[0];
           return;
       }

       while (r < n && array[r] < t)
           r *= 2;

       if (r < n && array[r] == t)
       {
           std::cout<<array[r];
           return;
       }

       if (array[1] == t)
       {
           std::cout<<array[1];
           return;
       }

       if (r == 1)
       {
           std::cout<<array[0];
           return;
       }

       l = r / 2;
       binSearch(array, std::min(r - 1, n - 1), t, l + 1);
   }

void linSearch (std::vector <int> arr, int s, int t)
{
    for (int i = 0; i < s; i++)
       {
           std::cout << arr[i] << " ";
           if (arr[i] == t)
               break;
       }
}

int main()
{
    int size, tmp;
    std::cin >> size;
    std::vector<int> arr; int num;
    std::cin >> num;

    for (int i = 0; i < size; i++)
    {
        std::cin >> tmp;
        arr.push_back(tmp);
    }

    std::cout << "Initial array:\n";

    for (auto i = arr.begin(); i != arr.end(); i++)
        std::cout << *i << " ";

    std::cout << "\nLinear search:\n";
    linSearch(arr, size, num);
    std::cout << "\nBinary search:\n";
    binSearch(arr, size - 1, num);
    std::cout << "\nDoubling search:\n";
    doublingSearch(arr, size, num);
    return 0;
}


