package Graphs_JAVA;

import java.util.*;


public class dfsAlgos {
    static final int N = 10010;
    static List<Integer>[] G = new ArrayList[N];
    static boolean[] vis = new boolean[N];
    static boolean[] dfsVis = new boolean[N];
    static List<Integer> path = new ArrayList<>();
    static int[] color = new int[N];
    static Stack<Integer> st = new Stack<>();

    static {
        Arrays.fill(color, -1);
        for (int i = 0; i < N; i++) {
            G[i] = new ArrayList<>();
        }
    }

    // Simple DFS
    static void dfs(int node) {
        vis[node] = true;
        path.add(node);
        for (int it : G[node]) {
            if (!vis[it]) dfs(it);
        }
    }
    
    // Cycle detection in undirected graph
    static boolean cycleDFS1(int node, int parent) {
        vis[node] = true;
        for (int it : G[node]) {
            if (!vis[it]) {
                if (cycleDFS1(it, node)) return true;
            } else if (it != parent) {
                return true;
            }
        }
        return false;
    }

    // Cycle detection in Directed graph
    static boolean cycleDFS2(int node) {
        vis[node] = true;
        dfsVis[node] = true;
        for (int it : G[node]) {
            if (!vis[it]) {
                if (cycleDFS2(it)) return true;
            } else if (dfsVis[it]) {
                return true;
            }
        }
        dfsVis[node] = false;
        return false;
    }

    // Check if Graph is Bipartite
    static boolean isBipartite(int node, int col) {
        color[node] = col;
        for (int it : G[node]) {
            if (color[it] == -1) {
                if (!isBipartite(it, 1 - col)) return false;
            } else if (color[it] == col) {
                return false;
            }
        }
        return true;
    }

    // Topological Sort
    static void Topo(int node) {
        vis[node] = true;
        for (int it : G[node]) {
            if (!vis[it]) dfs(it);
        }
        st.push(node);
    }

    static void sol(Scanner sc) {
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            G[u].add(v);
            G[v].add(u);
        }

        System.out.println(isBipartite(0, 0));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            sol(sc);
        }
        sc.close();
    }
}


