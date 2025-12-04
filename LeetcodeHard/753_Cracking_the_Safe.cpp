class Solution {
private:
    void dfs(string node, int k) {
        for (int i = 0; i < k; i++) {

            char digit = (char)(i + '0');
            
            string edge = node + digit;

            if (visited.find(edge) == visited.end()) {
                visited.insert(edge);
                
                dfs(edge.substr(1), k);
                result += digit;
            }
        }
    }
public:
    unordered_set<string> visited;
    string result;
    string crackSafe(int n, int k) {
        if (n == 1 && k == 1) return "0";
        visited.clear();
        result = "";

        string startNode(n - 1, '0');

        dfs(startNode, k);

        return result + startNode;
    }
};