#include <ctime>
#include<iostream>  

using namespace std;

#pragma once
#pragma warning(disable: 4996)

template<class T>
class Control
{
public:
    bool operator() (T x)
    {
        T z = T();
        return x > z;
    }
};

template <class T>
bool is_contains(T* begin, T* end, T elem)
{
    for (T* i = begin; i < end; i++)
    {
        if (*i == elem)
            return true;
    }
    return false;
}

template <class T>
int or_set(T* first_1, T* second_1, T* first_2, T* second_2, T* first_3, T* second_3)
{
    int count = 0;
    T* element = first_3;
    for (T* i = first_1; i < second_1; i++)
    {
        if (!is_contains(first_3, second_3, *i))
        {
            *element++ = *i;
            count++;
        }
    }

    for (T* i = first_2; i < second_2; i++)
    {
        if (!is_contains(first_3, second_3, *i))
        {
            *element++ = *i;
            count++;
        }
    }
    return count;
}

template <class T>
int if_set(T* first_1, T* second_1, T* first_2, T* second_2, T* first_3, T* second_3, Control<T>& control)
{
    int count = 0;
    T* element = first_3;
    for (T* i = first_1; i < second_1; i++)
    {
        if (!is_contains(first_3, second_3, *i))
        {
            if (control(*i))
            {
                *element++ = *i;
                count++;
            }
        }
    }
    for (T* i = first_2; i < second_2; i++)
    {
        if (!is_contains(first_3, second_3, *i))
        {
            if (control(*i))
            {
                *element++ = *i;
                count++;
            }
        }
            
    }
    return count;
}
int main()
{

    setlocale(LC_ALL, "rus");
    srand(time(NULL));

	
    int first_array[5] = { -1,2,-3,4,-5 };
    int second_array[5] = { -1,-2,-3,4,5 };
    int third_array[10];
    Control<int>* control = new Control<int>();
    int n = if_set(&first_array[0], &first_array[5], &second_array[0], &second_array[5], &third_array[0], &third_array[10], *control);

    for (int* i = &third_array[0]; i < &third_array[0 + n]; i++)
    {
        cout << *i << " ";
    }     
    cout << endl;

    system("pause");
    return 0;
}