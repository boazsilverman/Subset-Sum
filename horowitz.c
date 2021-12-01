/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
void printArr(int * arr, int len);
int miniSumWithIndex(int set[], int setLen, int indexes)
{
    int mask = 1;
    int i;
    int sum = 0;
    for(i=0; i<setLen; i++)
    {
        if (indexes & mask){
            sum += set[i];
        }
        mask = mask <<1;
    }
    return sum; 
}

int * makeL(int set[], int setLen)
{
    int * L = (int *) malloc((1 << setLen) * sizeof(int));
    int indexes;
    int lIndex = 0;
    for (indexes = 0; indexes < (1 << setLen); indexes ++)
    {
        L[lIndex] = miniSumWithIndex(set, setLen, indexes);
        lIndex ++;
    }
    return L;
}
int butterflyT(int * L1, int * L2, int len, int target)
{
    int index1 = 0, index2 = 0;
    for(index1 = 0; index1 < len; index1++)
    {
        index2 = 0;
        while(index2 < len)
        {
            if (L1[index1] + L2[index2] == target)
            {
                return 1;
            }
            if (L1[index1] + L2[index2] < target)
            {
                index2++;
            }
            else
            {
                break;
            }
        }
    }
    return 0;
}
int subsetSumHorowitz(int set[], int setLen, int target)
{
    int indexes;
    int * L1 = makeL(set, setLen/2);
    int * L2 = makeL(set + setLen/2, setLen/2);
    int result = butterflyT(L1, L2, setLen/2, target);
    free(L1); free(L2);
    return result;
}

int main()
{
    int set[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
    int x = subsetSumHorowitz(set, 30, -1);
    printf("%d", x);
    return 0;
}
