#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

const unsigned MaxSize = 100000;
void readArray(int* data, unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
        cin >> data[i];
}

void printArray(const int* data, unsigned size)
{
    assert(size > 0);
    for (unsigned i = 0; i < size-1; ++i)
        cout << data[i] << " ";
    cout << data[size-1] << endl;
}

void insertionSort(int* data, unsigned size)
{
    for (unsigned i = 1; i < size; ++i)
    {
        int h = data[i];
        int pos;
        for (pos = i-1; pos >= 0; --pos)
        {
            if ((data[pos] % 3 + 3) % 3 > (h % 3 + 3) % 3)
                data[pos+1] = data[pos];
            else
                break;
        }
        data[pos+1] = h;
    }
}

void sortArray(int* data, unsigned size)
{
    int* tmpData = new(nothrow) int[size];
    if (!tmpData)
    {
        insertionSort(data, size);
        return;
    }
    unsigned pos = 0;
    for (unsigned mod = 0; mod < 3; ++mod)
    {
        for (unsigned i = 0; i < size; ++i)
            if ((data[i] % 3 + 3) % 3 == mod)
                tmpData[pos++] = data[i];
    }
    for (unsigned i = 0; i < size; ++i)
        data[i] = tmpData[i];

    delete[] tmpData;
}

int main()
{
    unsigned n;
    cin >> n;
    if (n == 0 || n > MaxSize)
    {
        cerr << "Bad input size" << endl;
        return 1;
    }

    int* data = new (nothrow) int[n];
    if (!data)
    {
        cerr << "No memory" << endl;
        return 1;
    }
    readArray(data, n);

    sortArray(data, n);
    printArray(data, n);

    delete[] data;
    return 0;
}
