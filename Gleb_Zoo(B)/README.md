### Задание
Недавно Глеб открыл зоопарк. Он решил построить его в форме круга и, естественно, обнёс забором. Глеб взял вас туда начальником охраны. Казалось бы все началось так хорошо, но именно в вашу первую смену все животные разбежались. В зоопарке n животных различных видов, также под каждый из видов есть свои ловушки. К сожалению некоторые животные враждуют с друг другом в природе (они обозначены разными буквами), а зоопарк обнесён забором и имеет форму круга. С помощью камер, удалось выяснить, где находятся все животные. Умная система поддержки жизнедеятельности зоопарка уже просканировала зоопарк и вывела id всех животных и ловушек в том порядке, в котором они видны из центра зоопарка. Получилось так, что все животные и все ловушки находятся на краю зоопарка. Вы хотите понять, могут ли животные прийти в свою ловушку так, чтобы их путь не пересекался с другими. Если да, также предъявите какую-нибудь из схем поимки животных.

Формат ввода
 На вход подается строчка из 2 ⋅ n символов латинского алфавита, где маленькая буква - животное, а большая - ловушка. Размер строки не более 100000.

Формат вывода
Требуется вывести "Impossible", если решения не существует или "Possible", если можно вернуть всех животных в клетки. В случае если можно, то для каждой ловушки в порядке обхода требуется вывести индекс животного в ней.

## Решение
Решать буду используя структуру данных стек (Первый вошел, последний вышел). Пушаю элементы если элемент вершины стека не схожи со следующим (не та буква), вытаскиваю в ином случае. 
```c
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};
 
// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(int));
    return stack;
}
 
// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
 
// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 
// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
 
// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
 
// Function to return the top from stack without removing it
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}


 
// Driver program to test above functions
int main()
{
    char letters[100000];
    scanf("%s", letters);
    int n = 0;
    int push_count = 0;
    int pop_count = 0;
    int previous_push = 0;
    int result_count = 0;
    while (letters[n] != '\0'){ 
        n++;
    }
    int result[n/2];
    struct Stack* stack = createStack(n/2);
    
    for(int i = 0 ; i<n; i++){
        if (i > 0 && peek(stack) == letters[i]){
            push(stack, letters[i]);
            push_count++;
            continue;
        }
     
        if (tolower(peek(stack)) != tolower(letters[i])){
            push(stack, letters[i]);
            push_count++;
            previous_push = 1;
        } else {
            pop(stack);
            if (previous_push) result[result_count] = push_count;
            else result[result_count] = push_count - pop_count;
            pop_count ++;
            previous_push = 0;
            result_count++;
        }
        if (isEmpty(stack)) pop_count = 0;
    }
    
    if(isEmpty(stack)) {
        printf("Possible\n");
        for(int i = 0 ; i<n/2; i++){
            printf("%d ", result[i]);
        }
    }
    else printf("Impossible");
    return 0;
}
//ABCaAbBcba 45321
//cAbBabBaAC 32451
```
