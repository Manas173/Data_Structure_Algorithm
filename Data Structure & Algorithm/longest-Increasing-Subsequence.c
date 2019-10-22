/*
This code has been written by Manas Ranjan Swain (https://github.com/Manas173/)

Description: Given an array of N elements print the size of the longest icreasing subsequence present in the array.

Input:
The first line contains an integer T, depicting total number of test cases. Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.

Output:
For each testcase, in a new line, print the Max length of the subsequence in a separate line.


Sample testcase:

INPUT:
2
8
10 9 2 5 3 7 101 18
6
5 8 3 7 9 1

OUTPUT:
4
3

EXPLANATION:
For the first testcase, 2,3,7,101 
For the second testcase, 5,7,9 and 3,7,9 are the possibilities
*/

#include <stdio.h>

int lis(int *arr,int *mem,int pos,int size)
{
    int max=1;
    if(mem[pos]!=-1)
        return mem[pos];
        
    for(int i=pos+1;i<size;i++)
    {
        if(arr[pos]<arr[i])
        {
            int temp=lis(arr,mem,i,size)+1;
            if(temp>max)
                max=temp;
        }
    }
    mem[pos]=max;
    return mem[pos];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int size;
        scanf("%d",&size);
        int arr[size];
        int mem[size];

        for(int i=0;i<size;i++)
        {
            scanf("%d",&arr[i]);
            mem[i]=-1;
        }
    
        if(size>0)
        {
            mem[size-1]=1;
            int ans=0;
            for(int i=size-1;i>=0;i--)
            {
                mem[i]=lis(arr,mem,i,size);
                if(ans<mem[i])
                    ans=mem[i];
            }
            printf("%d\n",ans);
        }
        else
            printf("0");
    }
}