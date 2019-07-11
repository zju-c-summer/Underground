#ifndef PRIM_H
#define PRIM_H

struct Coordinate  //迷宫点类
{
    bool Judgment = 1;   //判断是否为墙，1为是，0为不是
    bool Judgemet_2 = 0;  //prim算法用到，深度优先算法没用
};

struct Coordinated  //prim算法用到，深度优先算法没用
{
    int adress;
};
void PrimeMap(Coordinate *map, int n);
void Sequence(Coordinated *Arry, int n, int &sum) ;
void Store(Coordinated *map_1, Coordinate *map_2, int map, int &k, int n);

#endif // PRIM_H
