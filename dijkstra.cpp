#include <iostream>
#define nodurimax 100
#define inf 100000000000

int G[nodurimax][nodurimax];
int distanta[nodurimax];
int prev[nodurimax];
bool Q[nodurimax];

void dijkstra(int V, int S)
{
    for(int v = 0; v < V; v++)
    {
        distanta[v] = inf;
        prev[v] = -1;
        Q[v] = true;
    }
    distanta[S] = 0;

    while(true)
    {
        int u = -1;
        int distmin = inf;
        for(int i = 0; i < V; i++)
        {
            if(Q[i] && distanta[i] < distmin)
            {
                distmin = distanta[i];
                u = i;
            }
        }
        if(u == -1) break;
        Q[u] = false;
        for(int v = 0; v < V; v++)
        {
            if(Q[v] && G[u][v] > 0)
            {
                int alt = distanta[u] + G[u][v];
                if(alt < distanta[v])
                {
                    distanta[v] = alt;
                    prev[v] = u;
                }
            }
        }
    }

}

void afisare(int V, int S)
{
    for(int v = 0; v < V; v++)
        std::cout << "distanta de la " << S << " la " << v << " este " << distanta[v] << std::endl;
}

void afiseaza_drum_minim(int prev[], int distanta[], int S, int D)
{
    if(distanta[D] == inf)
    {
        std::cout << "nu exista drum de la " << S << " la " << D << std::endl;
        return;
    }
    int ST[nodurimax];
    int top = -1;
    int u = D;
    ST[++top] = D;
    while(u != S)
    {
        u = prev[u];
        if(u == -1)
        {
            std::cout << "nu exista drum complet de la " << S << " la " << D << std::endl;
            return;
        }
        ST[++top] = u;
    }
    std::cout << "drum minim de la " << S << " la " << D << " : ";
    for(int i = top; i >= 0; i--)
    {
        std::cout << ST[i];
        if(i > 0) std::cout << " -> ";
    }
    std::cout << std::endl;
    std::cout << "cost total : " << distanta[D] << std::endl;
}

int main()
{
   int V = 5;
   int S = 0;
   for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            G[i][j] = 0;
    G[0][1] = 10;
    G[0][3] = 30;
    G[0][4] = 100;
    G[1][2] = 50;
    G[2][4] = 10;
    G[3][2] = 20;
    G[3][4] = 60;        
    dijkstra(V, S);
    afisare(V, S);
    afiseaza_drum_minim(prev, distanta, S, 4);
}
