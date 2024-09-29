#include <iostream>
#include <queue>
#include <vector>

using namespace std;

pair<int, int> source;
int n_rows, n_cols;
bool g_found = false;
pair<int, int> goal(-2,-2);

void readvalues(vector<vector<char>>& values){
            for (int i=0; i<n_rows; ++i){
                for (int j=0; j<n_cols; ++j){
                    cin >> values[i][j];
                    if (values[i][j] == 'S'){
                        source.first = i;
                        source.second = j;
                    }
                }
            }
        }

void printvalues(vector<vector<char>>& values){
            for (int i=0; i<n_rows; ++i){
                for (int j=0; j<n_cols; ++j){
                    if (j == n_cols -1){
                        cout << values[i][j];
                    }
                    else{
                        cout << values[i][j] << ' ';
                    }
                }
                cout << endl;
            }
        }
bool visited(vector<vector<pair<int, int>>>& parent, pair<int, int> location){
    for (int i=0; i<n_rows; ++i){
        for (int j=0; j<n_cols; ++j){
            if (parent[i][j] == location){
                return true;
            } 
        }
    }
    return false; 
}
void push_q(vector<vector<char>>& values, vector<vector<int>>& distance, vector<vector<pair<int, int>>>& parent, queue<pair<int, int>>& q, pair<int, int>& neighbour, pair<int, int>& curr){
    if (values[neighbour.first][neighbour.second] != 'x' && visited(parent, neighbour) == false){
            if (values[neighbour.first][neighbour.second] == 'G'){
                g_found = true;
                goal = neighbour;
            }
            distance[neighbour.first][neighbour.second] = distance[curr.first][curr.second] + 1;
            parent[neighbour.first][neighbour.second] = curr;
            q.push(neighbour);
        }
}
int main(){
    queue<pair<int, int>> q;

    cin >> n_rows >> n_cols;

    vector<vector<char>> values(n_rows, vector<char>(n_cols, 0));
    vector<vector<int>> distance(n_rows, vector<int>(n_cols, 100000));
    vector<vector<pair<int, int>>> parent(n_rows, vector<pair<int, int>>(n_cols, make_pair(-2, -2)));

    cin;

    readvalues(values);
    q.push(source);

    while (q.empty() == false && g_found == false){
        pair<int, int> curr = q.front();
        q.pop();
        pair<int, int> neighbour(curr.first,curr.second-1);
        push_q(values, distance, parent, q, neighbour, curr);

        neighbour = make_pair(curr.first-1, curr.second);
        push_q(values, distance, parent, q, neighbour, curr);

        neighbour = make_pair(curr.first, curr.second+1);
        push_q(values, distance, parent, q, neighbour, curr);

        neighbour = make_pair(curr.first+1, curr.second);
        push_q(values, distance, parent, q, neighbour, curr);

    }
    if (q.empty() == false && g_found == false){
        cout << "No Path" << endl;
    }
    else{
        vector<pair<int, int>> path;
        pair<int, int> curr = goal;
        while (curr != source){
            path.push_back(curr);
            curr = parent[curr.first][curr.second];
        }
        path.push_back(source);

        for (int i = 1; i < path.size()-1; ++i){
            values[path[i].first][path[i].second] = '*';
        }
        printvalues(values);
    }
    
    
}

