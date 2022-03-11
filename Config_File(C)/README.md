## Задание 
Вадим разрабатывает парсер конфигурационных файлов для своего проекта. Файл состоит из блоков, которые выделяются с помощью символов «{» — начало блока, и «}» — конец блока. Блоки могут вкладываться друг в друга. В один блок может быть вложено несколько других блоков.

В конфигурационном файле встречаются переменные. Каждая переменная имеет имя, которое состоит из не более чем десяти строчных букв латинского алфавита. Переменным можно присваивать числовые значения. Изначально все переменные имеют значение 0.

Присваивание нового значения записывается как <variable>=<number>, где <variable> — имя переменной, а <number> — целое число, по модулю не превосходящее 109. Парсер читает конфигурационный файл построчно. Как только он встречает выражение присваивания, он присваивает новое значение переменной. Это значение сохраняется до конца текущего блока, а затем восстанавливается старое значение переменной. Если в блок вложены другие блоки, то внутри тех из них, которые идут после присваивания, значение переменной также будет новым.

Кроме того, в конфигурационном файле можно присваивать переменной значение другой переменной. Это действие записывается как <variable1>=<variable2>. Прочитав такую строку, парсер присваивает текущее значение переменной variable2 переменной variable1. Как и в случае присваивания константного значения, новое значение сохраняется только до конца текущего блока. После окончания блока переменной возвращается значение, которое было перед началом блока.

Для отладки Вадим хочет напечатать присваиваемое значение для каждой строки вида <variable1>=<variable2>. Помогите ему отладить парсер.

## Формат ввода
Входные данные содержат хотя бы одну и не более 105 строк. Каждая строка имеет один из четырех типов:

{ — начало блока;
} — конец блока;
<variable>=<number> — присваивание переменной значения, заданного числом;
<variable1>=<variable2> — присваивание одной переменной значения другой переменной. Переменные <variable1> и <variable2> могут совпадать.
Гарантируется, что ввод является корректным и соответствует описанию из условия. Ввод не содержит пробелов.

## Формат вывода
Для каждой строки типа <variable1>=<variable2> выведите значение, которое было присвоено.

## Решения
1. Можно ли реализовать при помощи стека? При входе в новый блок новое значение записывается на вершину(push). При выходе из блока (pop) -> сл-но значение в блоке выше забывается.
2. Действительно реализовывается с помощью стека, однако используя понятие рекурсии. При нахождении открывающей скобки вхожу заново в функцию с измененными переменными, при закрывающей выхожу из этой функции (забывая значения переменных на текущем шаге). А запоминаю в мапу (Example: "a"=3)
3. Память при рекурсии: `O(n)`. На 44 тесте валится из-за превышения лимита использования памяти.
4. Что если использовать динаммический массив дополняя его новыми значениями при входе в нову
5. Вычислительная сложность: 
```
a=b			1. Map not contains the variable before and after '=' => Add two variable in map and their value is 0 and output the value
b=123			2. Map contains the variable before '=' and after '=' is value => Reset the value of this variable 
var=b			3. Map not contains the variable before '=' and after '=' is variable which is in map => Set the 1st varibale in map with value of 2nd variable and output the value 
b=-34			
{
c=b
b=1000000000
d=b
{
a=b			4. Map contains the variable before and after '=' => Reset the value of 1st variable with the value of 2nd variable and output the new value 
e=var
}
}
b=b
```

//TODO Ест много памяти
```c
#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

// to split the word by '=' 
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

// checker that the second part in line (after '=') is number
bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (c=='-') continue;
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

// the brain of my program
void func (map<string, int> m){
    vector<string> a;
    string input;
    while(cin>>input){
        if (input=="{") func(m);
        else if (input=="}") return ;
        else {
            a = split(input,"=");
            string first = a.at(0);
            auto second = a.at(1);
            if (isNumber(second)) {
                m[first]= stoi(second);
            } else {
                if (m.find(first) == m.end() && m.find(second) == m.end()){
                    m[first]=0;
                    m[second]=0;
                } else m[first]=m[second];
                cout << m[first]<<"\n";
            }
        }
    }
}

// the head of my program
int main()
{
    map<string, int> m {  };
    func(m);
    return 0;
}
```
