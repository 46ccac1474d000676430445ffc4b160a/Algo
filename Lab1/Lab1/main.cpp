#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int LC;
int BC;


int linearSearch(int *arr, int N, int val)
{
    LC = 0;
    for (int i=0; i<N; i++)
    {
        LC++;
        if (arr[i]==val) return i;
    }
    return -1;
}


int binarySearch(int *arr,int N, int val)
{
    BC = 0;
    int left = 0, right = N-1;
    while (1)
    {
        BC++;
        int midl = (left + right) / 2;
        if (val < arr[midl]) right = midl-1;
        else if (val > arr[midl]) left = midl+1;
        else return midl;
        if (left > right) return -1;
    }
}


void sortb(int *arr, int N)
{
    for (int i=0; i<N-1; i++)
        for (int j=i; j<N; j++)
            if (arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
}


int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));

    char sw;
    do
    {
        int N;
        cout << "Введите длинну массива << ";
        cin>>N;

        int arr[N];

        cout <<"1 - пользовательский ввод, 2 - заполнение случайными числами ... ";
        char s;
        cin >> s;

        switch (s)
        {
            case '1':
            {
                for (int i=0; i<N; i++)
                {
                    cout << "arr[" << i << "] << ";
                    cin >> arr[i];
                }

            } break;
            case '2':
            {
                for (int i=0; i<N; i++) arr[i] = rand() % N;
            } break;
            default:
            {
                cout << "Ошибка!" << endl;
                return 0;
            }
        }

        sortb(arr,N);
        cout << endl;
        for (int i = 0; i < N; i++) cout << arr[i] << " ";
        cout << endl << endl;

        cout << "Введите кол-во чисел для поиска << ";
        int val_n;
        cin >> val_n;

        cout << "1 - пользовательский ввод, 2 - тестирование случайными числами ... ";
        cin >> s;

        switch(s)
        {
            case '1':
            {
                for (int i = 0; i < val_n; i++)
                {
                    cout << endl << "Введите искомое число << ";
                    int val;
                    cin >> val;
                    cout << "Индекс искомого числа в массиве(лин. поиск): "
                         << linearSearch(arr, N, val) << endl << "Колличество итераций: ";
                    cout << LC << endl;
                    cout << "Индекс искомого числа в массиве(бин. поиск): "
                         << binarySearch(arr, N, val) << endl
                         << "Колличество итераций: "; cout << BC << endl;
                }

            } break;
            case '2':
            {
                for (int i = 0; i < val_n; i++)
                {
                    int val = rand() % N;
                    cout << endl << "Искомое число: " << val << endl;
                    cout << "Индекс искомого числа в массиве(лин. поиск): "
                         << linearSearch(arr, N, val) << endl << "Колличество итераций: ";
                    cout << LC << endl;
                    cout << "Индекс искомого числа в массиве(бин. поиск): "
                         << binarySearch(arr, N, val) << endl
                         << "Колличество итераций: "; cout << BC << endl;
                }
            } break;
            default:
            {
                cout << "Ошибка!" << endl;
                return 0;
            }
        }

        cout << endl << "Введите: 1 - повторить, 2 - выйти ... ";
        cin >> sw;
        cout << endl;

    } while(sw == '1');


    return 0;
}

