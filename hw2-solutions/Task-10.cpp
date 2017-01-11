#include <iostream>
///#include <assert.h>
#include <stdio.h>
///#define INF 100

using namespace std;

const unsigned short int INF = 100;

unsigned short int maximum(unsigned short int number1, unsigned short int number2) /// could be char
{
    return (number1 > number2) ? number1 : number2;
}

unsigned short int pAdicOrder(unsigned int prime, unsigned long long int number) /// Returns Vp(number) or INF if it's infinity!
{
    if (number == 0)
    {
        return INF;
    }
    unsigned short int adicOrder = 0;
    while ((number % prime == 0) && (number != 0))
    {
        ++adicOrder;
        number /= prime;
    }
    return adicOrder;
}

unsigned short int pAdicOrderQuery(unsigned int prime1, unsigned long long int number, unsigned int prime2) /// returns max(Vp1(n), Vp2(n)).
{
    return maximum(pAdicOrder(prime1, number), pAdicOrder(prime2, number));
}

/*!
void pAdicOrderQueryTest()
{
    assert(pAdicOrderQuery(2U, 209952ULL, 3U) == 8);
    assert(pAdicOrderQuery(5U, 18ULL, 2U) == 1);
    assert(pAdicOrderQuery(13U, 0ULL, 17U) == INF);
    assert(pAdicOrderQuery(2U, 6ULL, 3U) == 1);
    assert(pAdicOrderQuery(13U, 13ULL, 2U) == 1);
    assert(pAdicOrderQuery(5U, 50ULL, 11U) == 2);
}

void pAdicOrderTest()
{
    assert(pAdicOrder(2U, 209952ULL) == 5);
    assert(pAdicOrder(3U, 209952ULL) == 8);
    assert(pAdicOrder(2U, 18ULL) == 1);
    assert(pAdicOrder(5U, 18ULL) == 0);
    assert(pAdicOrder(2U, 0ULL) == INF);
    assert(pAdicOrder(17U, 0ULL) == INF);
    assert(pAdicOrder(2U, 6ULL) == 1);
    assert(pAdicOrder(13U, 169ULL) == 2);
    assert(pAdicOrder(5U, 50ULL) == 2);
    assert(pAdicOrder(11U, 50ULL) == 0);
    assert(pAdicOrder(100000007U, 10000001400000049ULL) == 2);
    assert(pAdicOrder(2U, 10000001400000049ULL) == 0);

}

void maxTest()
{
    assert(maximum(0U, 76U) == 76U);
    assert(maximum(456U, 0U) == 456U);
    assert(maximum(0U, 0U) == 0U);
    assert(maximum(12U, 15U) == 15U);
}

void appTest()
{
    maxTest();
    pAdicOrderTest();
    pAdicOrderQueryTest();
}
*/

void outputQueryResult(unsigned short int queryResult)
{
    if (queryResult == INF)
    {
        cout << "infinity\n";
    }
    else
    {
        cout << queryResult << endl;
    }
}

void inputProcessAndOutputQuery()
{
    unsigned int prime1, prime2;
    unsigned long long int number;
    cin >> prime1 >> number >> prime2;
    outputQueryResult( pAdicOrderQuery(prime1, number, prime2) );
}

int main()
{
    ///appTest();
    unsigned int numberOfQueries;
    cin >> numberOfQueries;
    while (numberOfQueries--)
    {
        inputProcessAndOutputQuery();
    }
    return 0;
}
