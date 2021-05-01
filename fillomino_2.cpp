#include <bits/stdc++.h>

using namespace std;

int n;

bool is_valid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        cin >> board[i][i];
    }

    // check under, left, right, and then above (in that order)
    int dx[] = {0, -1, 1, 0};
    int dy[] = {-1, 0, 0, 1};

    //first dfs :cool_face:
    for(int i = 0; i < n; i++){
        int count = 1;
        int number = board[i][i];
        stack<pair<int, int>> stack;
        stack.push({i, i});
        while(!stack.empty() && count < number){
            pair<int, int> node = stack.top();
            stack.pop();
            for(int j = 0; j < 4; j++){
                int x = node.first + dx[j];
                int y = node.second + dy[j];
                if(is_valid(x, y) && x >= i && y <= i && board[x][y] == 0){
                    board[x][y] = number;
                    count++;
                    stack.push({x, y});
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] != 0){
                cout << board[i][j] << " ";
            }
        }
        cout << "\n";
    }
}
