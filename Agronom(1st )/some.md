n - count of flowers (1 ≤ n ≤ 200 000) 
ai - sort of this flower  ai (1 ≤ ai ≤ 109)

Need to find the place in garden where the count of same flowers is lower than 3 (<3)

1. Look at begin of garden for flowers and count the number of flowers which is fit our requirements. If we see third one then stop at this place and save the count of this good area. Then count the next area and if this areas flowers is more then previous then choose first one. 

2. Look all the garden and save the data about areas (1: 1-3; 2: 4-7; 3: 8-13). Then choose the area with big amount of flowers. (8-13 is biggest one, then this is the answer to our task).  