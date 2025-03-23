import java.util.*;

public class dfsProblems {
    static final int N = 10010;
    static List<int[]> moves = Arrays.asList(
        new int[]{0, 1}, new int[]{1, 0}, new int[]{0, -1}, new int[]{-1, 0}
    );
    static List<int[]> moves8 = Arrays.asList(
        new int[]{0, 1}, new int[]{1, 0}, new int[]{0, -1}, new int[]{-1, 0},
        new int[]{1, 1}, new int[]{1, -1}, new int[]{-1, 1}, new int[]{-1, -1}
    );
    static Map<Integer, List<Integer>> G = new HashMap<>();

    static boolean isValid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    // Surrounded Regions
    static char[][] SurroundedRegions(char[][] board) {
        int n = board.length, m = board[0].length;
        boolean[][] vis = new boolean[n][m];

        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O') dfsSurrounded(board, vis, 0, j);
            if (!vis[n - 1][j] && board[n - 1][j] == 'O') dfsSurrounded(board, vis, n - 1, j);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O') dfsSurrounded(board, vis, i, 0);
            if (!vis[i][m - 1] && board[i][m - 1] == 'O') dfsSurrounded(board, vis, i, m - 1);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        return board;
    }

    static void dfsSurrounded(char[][] board, boolean[][] vis, int row, int col) {
        vis[row][col] = true;
        for (int[] move : moves) {
            int nrow = row + move[0], ncol = col + move[1];
            if (isValid(nrow, ncol, board.length, board[0].length) && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfsSurrounded(board, vis, nrow, ncol);
            }
        }
    }

    static List<Integer> safeNodes(int V) {
        int n = G.size();
        boolean[] vis = new boolean[n], path = new boolean[n];
        int[] safe = new int[n];
        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfsSafeNodes(i, vis, path, safe);
        }
        for (int i = 0; i < n; i++) {
            if (safe[i] == 1) result.add(i);
        }
        return result;
    }

    static boolean dfsSafeNodes(int node, boolean[] vis, boolean[] path, int[] safe) {
        vis[node] = true;
        path[node] = true;
        safe[node] = 0;
        for (int it : G.getOrDefault(node, new ArrayList<>())) {
            if (!vis[it]) {
                if (dfsSafeNodes(it, vis, path, safe)) return true;
            } else if (path[it]) {
                return true;
            }
        }
        path[node] = false;
        safe[node] = 1;
        return false;
    }

    static String AlienDictionary(List<String> dict, int k) {
        Map<Integer, List<Integer>> G = new HashMap<>();
        for (int i = 0; i < dict.size() - 1; i++) {
            String s1 = dict.get(i), s2 = dict.get(i + 1);
            for (int j = 0; j < Math.min(s1.length(), s2.length()); j++) {
                if (s1.charAt(j) != s2.charAt(j)) {
                    G.computeIfAbsent(s1.charAt(j) - 'a', x -> new ArrayList<>()).add(s2.charAt(j) - 'a');
                    break;
                }
            }
        }
        boolean[] vis = new boolean[k];
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < k; i++) {
            if (!vis[i]) dfsAlienDict(i, vis, G, st);
        }

        StringBuilder ans = new StringBuilder();
        while (!st.isEmpty()) ans.append((char) (st.pop() + 'a'));
        return ans.toString();
    }

    static void dfsAlienDict(int node, boolean[] vis, Map<Integer, List<Integer>> G, Stack<Integer> st) {
        vis[node] = true;
        for (int it : G.getOrDefault(node, new ArrayList<>())) {
            if (!vis[it]) dfsAlienDict(it, vis, G, st);
        }
        st.push(node);
    }

    public static void sol(Scanner sc) {
        int n = sc.nextInt();
        List<String> v = new ArrayList<>();
        for (int i = 0; i < n; i++) v.add(sc.next());
        int k = sc.nextInt();
        System.out.println(AlienDictionary(v, k));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) sol(sc);
        sc.close();
    }
}
