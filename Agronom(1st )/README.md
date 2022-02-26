n - count of flowers (1 ≤ n ≤ 200 000) 
ai - sort of this flower  ai (1 ≤ ai ≤ 109)

Need to find the place in garden where the count of same flowers is lower than 3 (<3)

1. Look at begin of garden for flowers and count the number of flowers which is fit our requirements. If we see third one then stop at this place and save the count of this good area. Then count the next area and if this areas flowers is more then previous then choose first one. 

2. Look all the garden and save the data about areas (1: 1-3; 2: 4-7; 3: 8-13). Then choose the area with big amount of flowers. (8-13 is biggest one, then this is the answer to our task).  

```c
#include <stdio.h>
#include <inttypes.h>

int main()
{
    int64_t start = 1 ;
    int64_t end = 1;

    int count = 0; 
    int n;  
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    if (n <= 2) end = n;
    else {
        for (int i = 0; i < n - 1; i++){
            // if same flowers nearby, then count them amount 
            if (a[i]==a[i+1]) {
                count++;
            }
            
            else count = 0;
            // if not good area (more than 2 same flowers)
            if (count == 2 ) {
                count = 0;
                //for first iteration fullfill the end 
                if (end == 0) end = i+1;
                // if the amount of previous area is bigger than this then 
                else if (end - start < i+2 - end) {
                    start = end;
                    end = i+1;
                }
                i--;
            }
            // if the end of garden
            if (i == n-2) {
                if (end - start < i + 2 - end) {
                    start = end ;
                    end = i+2;
                }
            } 
        }
    }
    printf("%" PRId64 " ", start);
    printf("%" PRId64, end);
    return 0;
}
```
