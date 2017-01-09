#include <iostream>
using std::cin;
using std::cout;

unsigned * price;
unsigned * min;
unsigned * mb;
unsigned * sms;
unsigned N;

void readPlans()
{
    cin >> N;

    price = new unsigned[N];
    min = new unsigned[N];
    mb = new unsigned[N];
    sms = new unsigned[N];

    for (unsigned i = 0; i < N; ++i)
    {
        cin >> price[i] >> min[i] >> mb[i] >> sms[i];
    }
}

unsigned filterPlans()
{
    unsigned targetMB, targetMin, targetSms;
    cin >> targetMin >> targetMB >> targetSms;

    unsigned w = 0;
    for (unsigned r = 0; r < N; ++r)
    {
        if (min[r] >= targetMin && mb[r] >= targetMB && sms[r] >= targetSms)
        {
            price[w] = price[r];
            min[w] = min[r];
            mb[w] = mb[r];
            sms[w] = sms[r];
            ++w;
        }
    }
    return w;
}

void sortPlans()
{
    for (unsigned sorted = 1; sorted < N; ++sorted)
    {
        unsigned p = price[sorted],
                 m = min[sorted],
                 M = mb[sorted],
                 s = sms[sorted],
                 pos = sorted;
        while (pos > 0 && price[pos-1] > p)
        {
            price[pos] = price[pos-1];
            min[pos] = min[pos-1];
            mb[pos] = mb[pos-1];
            sms[pos] = sms[pos-1];
            --pos;
        }
        price[pos] = p;
        min[pos] = m;
        mb[pos] = M;
        sms[pos] = s;
    }
}

void printPlans()
{
    if (N == 0)
        cout << "No solution\n";

    for (unsigned i = 0; i < N; ++i)
    {
        cout << price[i] << " "
             << min[i] << " "
             << mb[i] << " "
             << sms[i] << "\n";
    }
}

void freeMemory()
{
    delete[] price;
    delete[] min;
    delete[] mb;
    delete[] sms;
}

int main()
{
    readPlans();
    N = filterPlans();
    sortPlans();
    printPlans();
    freeMemory();

    return 0;
}
