### Задание
Городской школьник Лёша поехал на лето в деревню и занялся выращиванием цветов. Он посадил n цветков вдоль одной длинной прямой грядки, и они успешно выросли. Лёша посадил множество различных видов цветков, i-й от начала грядки цветок имеет вид ai, где ai "— целое число, номер соответствующего вида в «Каталоге юного агронома».

Теперь Лёша хочет сделать фотографию выращенных им цветов и выложить ее в раздел «мои грядки» в социальной сети для агрономов «ВКомпосте». На фотографии будет виден отрезок из одного или нескольких высаженных подряд цветков.

Однако он заметил, что фотография смотрится не очень интересно, если на ней много одинаковых цветков подряд. Лёша решил, что если на фотографии будут видны три цветка одного вида, высаженные подряд, то его друзья — специалисты по эстетике цветочных фотографий — поставят мало лайков.

Помогите ему выбрать для фотографирования как можно более длинный участок своей грядки, на котором нет трех цветков одного вида подряд.

### Формат ввода
В первой строке содержится целое число n (1 ≤ n ≤ 200 000) — количество цветов на грядке.

Во второй строке содержится n целых чисел ai (1 ≤ ai ≤ 109), обозначающих вид очередного цветка. Одинаковые цветки обозначаются одинаковыми числами, разные — разными.

### Формат вывода
Выведите номер первого и последнего цветка на самом длинном искомом участке. Цветки нумерются от 1 до n.
Если самых длинных участков несколько, выведите участок, который начинается раньше.

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
    // start_temp - variable that helps in that situation 
    // ( n = 5 ; a[i] = {2,2,2,2,2} ; if 5 same elements staying nearby than we need by comparing the first area (1-2) 
    // and the third area (3-4) we need to know the start of next area and thatswhy we need this variable)
    int64_t start_temp = 1 ;
    int64_t start = 1 ;
    int64_t end = 1;
     
    // variable for counting same elements nearby
    int count = 0; 
    int n;  
    
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]) ;
    
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
                // if the amount of previous area is bigger than this then 
                if (end - start < i+1 - start_temp) {
                    start = start_temp;
                    end = i+1;
                }
                start_temp = i+1;
                i--;
            }
            // if the end of garden 
            else if (i == n-2) {
                if (end - start < i+2 - start_temp){
                    start = start_temp ;
                    end = i+2;
                }
            } 
        }
    }
    printf("%" PRId64 " ", start);
    printf("%" PRId64"\n", end);
    return 0;
}
```
