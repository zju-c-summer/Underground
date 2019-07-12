#include "prim.h"
void Sequence(Coordinated *Arry, int n, int &sum)   //把元素从数组删除
{
    int i;
    for (i = n; i < sum; i++)
    {
        Arry[i] = Arry[i + 1];
    }
    sum--;
}

void Store(Coordinated *map_1, Coordinate *map_2, int map, int &k, int n)     //把元素储存进数组
{
    if (((map + 2) % n != 0)&&map_2[map + 1].Judgemet_2 == 0)
    {
        map_1[k].adress = map + 1;
        map_2[map_1[k].adress].Judgemet_2 = 1;
        k++;
    }
    if (((map - 1) % n != 0) && map_2[map - 1].Judgemet_2 == 0)
    {
        map_1[k].adress = map - 1;
        map_2[map_1[k].adress].Judgemet_2 = 1;
        k++;
    }
    if (((map - n) / n != 0) && map_2[map - n].Judgemet_2 == 0)
    {
        map_1[k].adress = map - n;
        map_2[map_1[k].adress].Judgemet_2 = 1;
        k++;
    }
    if (((map + n) / n != n - 1) && map_2[map + n].Judgemet_2 == 0)
    {
        map_1[k].adress = map + n;
        map_2[map_1[k].adress].Judgemet_2 = 1;
        k++;
    }
}

void PrimeMap(Coordinate *map, int n)
{
    Coordinated *map2 = new Coordinated[(n*n-3*n-2)/2];
    srand((unsigned)time(0));

    int k = 2;
    map2[0].adress = n + 2;
    map2[1].adress = 2 * n + 1;
    map[n + 2].Judgemet_2 = 1;
    map[2 * n + 1].Judgemet_2 = 1;

    int b;
    while(k!=0)
    {
        b = rand() % k;
        if ((map2[b].adress / n) % 2 == 0)
            if (map[map2[b].adress + n].Judgment + map[map2[b].adress - n].Judgment > 0)
            {
                map[map2[b].adress + n].Judgment = 0;
                map[map2[b].adress].Judgment = 0;
                map[map2[b].adress - n].Judgment = 0;
                Store(map2, map, map2[b].adress + n, k, n);
                Store(map2, map, map2[b].adress - n, k, n);
                Sequence(map2, b, k);
                continue;
            }
            else
            {
                Sequence(map2, b, k);
                continue;
            }
        if ((map2[b].adress / n) % 2 == 1)
            if (map[map2[b].adress + 1].Judgment + map[map2[b].adress - 1].Judgment > 0)
            {
                map[map2[b].adress + 1].Judgment = 0;
                map[map2[b].adress].Judgment = 0;
                map[map2[b].adress - 1].Judgment = 0;
                Store(map2, map, map2[b].adress + 1, k, n);
                Store(map2, map, map2[b].adress - 1, k, n);
                Sequence(map2, b, k);
                continue;
            }
            else
            {
                Sequence(map2, b, k);
                continue;
            }
    }
   // map[1].Judgment = 0;
   // map[n*n - 2].Judgment = 0;
    delete map2;
}
