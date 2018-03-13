#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    bool checked = false;
    void setChecked()
    {
        checked = true;
    }
    int value = 0;
    int x, y;
    void setCord(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

void fieldproc(Node **f, int i, int j, int n, int m)
{
    static int c = 1;
    int counts[101] = {0};

    queue<Node*> q;
    q.push(f[i]+j);

    while (!q.empty())
    {
        Node *val = q.front();
        q.pop();

        if (!val->checked)
        {
            val->setChecked();
            counts[val->value]++;
        }


        Node *t;

#define addToQ if (t->value && !t->checked) { counts[t->value]++; t->setChecked(); q.push(t); }

        if (val->x)
        {
            t = f[val->y] + val->x-1;
            addToQ
        }

        if (val->x < m-1)
        {
            t = f[val->y] + val->x+1;
            addToQ
        }

        if (val->y)
        {
            t = f[val->y-1] + val->x;
            addToQ
        }

        if (val->y < n-1)
        {
            t = f[val->y+1] + val->x;
            addToQ
        }

    }

    cout << c++ << endl;

    for (int k = 1; k < 101; k++)
        if (counts[k]) cout << k << " " << counts[k] << endl;

}

int main()
{
    int N, M;
    cin >> N >> M;

    Node **field = new Node*[N];
    for (int i = 0; i < N; i++) field[i] = new Node[M];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
//            int val = j % 2 == 0 ? 1 : 0;
//            val = i % 2 == 0 ? val : !val;
            cin >> field[i][j].value;
            field[i][j].setCord(j, i);
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (!field[i][j].checked && field[i][j].value)
                fieldproc(field, i, j, N, M);
        }

    for (int i = 0; i < N; i++) delete field[i];
    delete [] field;

    return 0;
}

/*

5 5
0 0 0 1 0
0 2 2 2 0
0 1 3 4 0
0 0 0 0 0
0 1 3 2 0


10 10
0 0 0 1 1 1 1 1 0 0
0 0 0 1 0 0 0 1 0 0
0 0 0 1 0 2 0 1 0 0
0 0 0 1 0 1 0 2 0 0
0 0 0 0 2 2 2 0 0 0
0 0 0 0 3 3 3 0 0 1
0 1 1 1 0 0 0 0 0 0
0 1 1 1 0 0 0 0 0 0
0 1 1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0


10 14
0 0 0 1 1 1 1 1 0 0 0 0 0 0
0 0 0 1 0 0 0 1 0 0 0 0 0 0
0 0 0 1 0 2 0 1 0 0 0 6 0 0
0 0 0 1 0 1 0 2 0 0 0 6 0 0
0 0 0 0 2 2 2 0 0 0 0 6 0 0
0 0 0 0 3 3 3 0 0 1 0 6 0 0
0 1 1 1 0 0 0 7 0 0 0 6 0 0
0 1 1 1 0 0 0 0 7 0 0 6 0 0
0 1 1 1 0 0 0 0 0 7 0 0 0 0
0 0 0 0 0 0 0 0 0 7 0 0 0 0

*/
