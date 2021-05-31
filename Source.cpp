/*На основі контейнера queue побудувати черги цілих чисел та символьних рядків.
Виконати операції занесення елемента у чергу, вилучення елемента з черги, виведення
усіх елементів черги на екран, визначення кількості елементів черги.*/

#include <iostream>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

template<typename T>
class queue_temp
{
private:
    queue<T> q;
public:
    void Input_queue()
    {
        T temp;
        int i = 0;
        while (i < 4)
        {
            cin >> temp;
            q.push(temp);
            i++;
        }
    }

    void Print_queue()
    {
        for (int i = 0; i < q.size(); i++)
        {
            cout << q.front() << " ";
            q.push(q.front());
            q.pop();
        }
        cout << "\nРозмір списку:\n";
        cout << q.size();
    }

    void operator+()
    {
        T pelem;
        cout << "\nВведіть елемент, який ви хочете додати:\n";
        cin >> pelem;
        q.push(pelem);
    }

    void operator-()
    {
        if (q.empty())
            return;
        cout << "\nВидалити елемент:\n";
        q.pop();
    }

    void Set_Q(T temp)
    {
        q.push(temp);
    }
};

int main() {
    system("chcp 1251");
    int choose;
    cout << "Choose the way of inputting :\n\n\t0 - file string\n\t1 - keyboard int\n\t2 - keyboard string\n";
    cin >> choose;

    if (choose == 0)
    {
        queue_temp<string> elem;
        string  temp;

        ifstream input("C:\\Users\\я\\Desktop\\lr7.txt");
        if (input.is_open())
        {
            while (getline(input, temp))
            {
                elem.Set_Q(temp);
            }
        }
        else
            printf("Файл не вдалось відкрити");

        elem.Print_queue();
        +elem;
        elem.Print_queue();
        -elem;
        elem.Print_queue();
        input.close();
    }
    if (choose == 1)
    {
        queue_temp<int> elem1;
        elem1.Input_queue();
        elem1.Print_queue();
        +elem1;
        elem1.Print_queue();
        -elem1;
        elem1.Print_queue();
    }
    if (choose == 2)
    {
        queue_temp<string> elem2;
        elem2.Input_queue();
        elem2.Print_queue();
        +elem2;
        elem2.Print_queue();
        -elem2;
        elem2.Print_queue();
    }
    return 0;
}