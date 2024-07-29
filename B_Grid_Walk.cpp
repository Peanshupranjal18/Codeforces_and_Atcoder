#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int H, W, Si, Sj;
    cin >> H >> W >> Si >> Sj;

    Si--;
    Sj--;

    vector<string> grid(H);
    for (int i = 0; i < H; ++i)
    {
        cin >> grid[i];
    }

    string X;
    cin >> X;

    for (char move : X)
    {
        if (move == 'L')
        {
            if (Sj > 0 && grid[Si][Sj - 1] == '.')
            {
                Sj--;
            }
        }
        else if (move == 'R')
        {
            if (Sj < W - 1 && grid[Si][Sj + 1] == '.')
            {
                Sj++;
            }
        }
        else if (move == 'U')
        {
            if (Si > 0 && grid[Si - 1][Sj] == '.')
            {
                Si--;
            }
        }
        else if (move == 'D')
        {
            if (Si < H - 1 && grid[Si + 1][Sj] == '.')
            {
                Si++;
            }
        }
    }

    cout << (Si + 1) << " " << (Sj + 1) << endl;

    return 0;
}
