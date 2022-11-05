#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p[6];
    while (cin >> p[0] >> p[1] >> p[2] >> p[3] >> p[4] >> p[5], p[0] + p[1] + p[2] + p[3] + p[4] + p[5])
    {
        int r = 0;
        r += p[5]; // 6x6

        r += p[4]; // 5x5
        p[0] = max(0, p[0] - p[4] * 11);

        r += p[3]; // 4x4
        if (p[3] * 5 > p[1])
        {
            p[0] = max(0, p[0] - 4*(p[3] * 5 - p[1]));
        }
        p[1] = max(0, p[1] - p[3] * 5);
        // cout << p[0] << endl;

        int resto;
        r += p[2] / 4; // 3x3
        if(p[2] % 4){
            r++;
            p[2] %= 4;
            resto = 4 - p[2]; 
            if (resto == 3){
                if(5 > p[1]){
                    p[0] = max(0, p[0]-4*(5-p[1]));
                }
                p[1] = max(0, p[1] - 5);
                p[0] = max(0, p[0]-7);
            }
            if(resto == 2){
                if(3 > p[1]){
                    p[0] = max(0, p[0]-4*(3-p[1]));
                }
                p[1] = max(0, p[1] - 3);
                p[0] = max(0, p[0]-6);
            }
            if(resto == 1)
            {
                if(1 > p[1]){
                    p[0] = max(0, p[0]-4);
                }
                p[1] = max(0, p[1] - 1);
                p[0] = max(0, p[0]-5);
            }
        }

        r+= p[1]/9; // 2x2
        if(p[1]%9){
            r++;
            p[1] %= 9;
            resto = 9 - p[1]%9;
            p[0] = max(0, p[0]-4*resto);
        }

        r+= p[0]/36; // 1x1
        if(p[0]%36) r++;

        cout << r << "\n";
    }

    return 0;
}