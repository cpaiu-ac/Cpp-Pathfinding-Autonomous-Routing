#include <iostream>
#include <cstring>

#define NMAX 10
#define INF 1000000000

int G[NMAX][NMAX]; 
int h[NMAX];       
int g[NMAX];       
int f[NMAX];       
int prev[NMAX];   
bool openSet[NMAX];
bool closedSet[NMAX];

const char* numeOras[NMAX] = {
    "Bucuresti", "Pitesti", "Craiova", "Sibiu", "Timisoara", "Oradea"
};

int V;

void initializare(int S, int D) {
    for (int i = 0; i < V; i++) {
        g[i] = INF;
        f[i] = INF;
        prev[i] = -1;
        openSet[i] = false;
        closedSet[i] = false;
    }
    g[S] = 0;
    f[S] = h[S];
    openSet[S] = true;
}

bool A_Star(int S, int D) {
    initializare(S, D);

    while (true) {
        int current = -1;
        int min_f = INF;

        for (int i = 0; i < V; i++) {
            if (openSet[i] && f[i] < min_f) {
                min_f = f[i];
                current = i;
            }
        }

        if (current == -1) break;

        if (current == D) return true;

        openSet[current] = false;
        closedSet[current] = true;

        for (int v = 0; v < V; v++) {
            if (G[current][v] > 0 && !closedSet[v]) {
                if (!openSet[v]) {
                    openSet[v] = true;
                }

                int alt_g = g[current] + G[current][v];
                if (alt_g < g[v]) {
                    prev[v] = current;
                    g[v] = alt_g;
                    f[v] = g[v] + h[v];
                }
            }
        }
    }

    return false;
}

void reconstruieste_drum(int S, int D) {
    int ST[NMAX];
    int top = -1;

    int u = D;
    ST[++top] = u;

    while (u != S) {
        u = prev[u];
        if (u == -1) {
            std::cout << "Nu exista drum de la " << numeOras[S] << " la " << numeOras[D] << std::endl;
            return;
        }
        ST[++top] = u;
    }

    std::cout << "\nDrum A* de la " << numeOras[S] << " la " << numeOras[D] << ":\n";
    for (int i = top; i >= 0; i--) {
        std::cout << numeOras[ST[i]];
        if (i > 0) std::cout << " -> ";
    }
    std::cout << "\nCost total: " << g[D] << " km\n";
}

int main() {
    V = 6;
    int S = 0; 
    int D = 5; 
    memset(G, 0, sizeof(G));
    G[0][1] = 110;
    G[1][2] = 115;
    G[2][3] = 180; 
    G[3][4] = 270; 
    G[4][5] = 180; 
    G[2][4] = 310; 
    G[0][3] = 280; 
    h[0] = 450; 
    h[1] = 390; 
    h[2] = 310; 
    h[3] = 210; 
    h[4] = 130; 
    h[5] = 0;   
    if (A_Star(S, D)) {
        reconstruieste_drum(S, D);
    } else {
        std::cout << "Nu exista drum intre " << numeOras[S] << " si " << numeOras[D] << "." << std::endl;
    }
    return 0;
}