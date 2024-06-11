

#include <bits/stdc++.h>
using namespace std;
#define firstPlayer 1
#define secondPlayer 2
int calculateMex(unordered_set<int> s)
{
    int MEX = 0;
    while (s.find(MEX) != s.end())
        MEX++;

    return MEX;
}


int findGrundyNum(int n, int Grundy[])
{
    Grundy[0] = 0;
    Grundy[1] = 1;
    Grundy[2] = 2;
    Grundy[3] = 3;

    if (Grundy[n] != -1)
        return (Grundy[n]);

    unordered_set<int> Set;

    for (int i = 1; i <= 3; i++)
        Set.insert(findGrundyNum(n - i, Grundy));

    Grundy[n] = calculateMex(Set);

    return Grundy[n];
}

void findWinner(int turn, int piles[],
                int Grundy[], int n)
{
    int xor_Val = Grundy[piles[0]];

    for (int i = 1; i <= n - 1; i++)
        xor_Val = xor_Val ^ Grundy[piles[i]];

    if (xor_Val != 0)
    {
        if (turn == firstPlayer)
            printf("First player will win.\n");
        else
            printf("Second Player will win.\n");
    }
    else
    {
        if (turn == firstPlayer)
            printf("Second Player will win\n");
        else
            printf("First player will win\n");
    }

    return;
}

int main()
{
    int n = 3;
    int piles[n] = {3, 4, 5};
    int maximum = *max_element(piles, piles + n);


    int Grundy[maximum + 1];
    memset(Grundy, -1, sizeof(Grundy));


    for (int i = 0; i <= n - 1; i++)
        findGrundyNum(piles[i], Grundy);

    findWinner(firstPlayer, piles, Grundy, n);
}
