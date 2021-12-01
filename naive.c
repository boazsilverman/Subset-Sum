#include <stdio.h>

int subsetWithIndex(int set[], int setLen, int target, int indexes)
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
    return sum == target;
}
int subsetSum(int set[], int setLen, int target)
{
    int indexes;
    for(indexes = 0; indexes < (1 << setLen); indexes ++)
    {
        if(subsetWithIndex(set, setLen, target, indexes))
        {
            return 1;
        }
        
    }
    return 0;
}

int main()
{
    
    int set[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
    int x = subsetSum(set, 30, -1);
    printf("%d", x);

    return 0;
}
