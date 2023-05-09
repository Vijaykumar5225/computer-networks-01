#include <stdio.h>
#include <string.h>
 
void bitStuffing(int N, int arr[])
{
    // Here we will store the stuffed array.
    int brr[30];
 
 
    int i, j, k;
    i = 0;
    j = 0;
 
    while (i < N) {
 
        if (arr[i] == 1) {
 
            //Will store the count of consecutive ones
            int count = 1;
 
 
            brr[j] = arr[i];
 
 
            for (k = i + 1;
                arr[k] == 1 && k < N && count < 5; k++) {
                j++;
                brr[j] = arr[k];
                count++;
 
                // if we found 5 consecutive ones then will insert a zero.
                if (count == 5) {
                    j++;
                    brr[j] = 0;
                }
                i = k;
            }
        }
 
    // otherwise will copy the array directly without any modification.
        else {
            brr[j] = arr[i];
        }
        i++;
        j++;
    }
 
 
    for (i = 0; i < j; i++)
        printf("%d", brr[i]);
}
 
 
int main()
{
    int N = 9;
    int arr[] = { 1, 1, 1, 0, 1, 1, 1, 1, 1 };
 
    bitStuffing(N, arr);
 
    return 0;
}
