#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class gnode {
    int id;
    string name;
    gnode* next;
    friend class graph;
};

class graph {
    gnode* head[20];
    int n;

public:
    graph() {
        cout << "Enter number of users (vertices): ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            head[i] = new gnode;
            head[i]->id = i;
            head[i]->next = NULL;
        }
    }

    void create() {
        char choice;
        for (int i = 0; i < n; i++) {
            gnode* temp = head[i];
            do {
                int v;
                cout << "Enter friend ID of " << i << ": ";
                cin >> v;

                if (v == i) {
                    cout << "User cannot be friend with himself!\n";
                } else {
                    gnode* curr = new gnode;
                    curr->id = v;
                    curr->next = NULL;
                    temp->next = curr;
                    temp = curr;
                }

                cout << "Add more friends for " << i << "? (y/n): ";
                cin >> choice;

            } while (choice == 'y' || choice == 'Y');
        }
    }

    void display() {
        cout << "\nFriend Network (Adjacency List):\n";
        for (int i = 0; i < n; i++) {
            cout << i << " -> ";
            gnode* temp = head[i]->next;
            while (temp != NULL) {
                cout << temp->id << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void dfsRecursiveUtil(int v, bool visited[]) {
        cout << v << " ";
        visited[v] = true;

        gnode* temp = head[v]->next;
        while (temp != NULL) {
            if (!visited[temp->id]) {
                dfsRecursiveUtil(temp->id, visited);
            }
            temp = temp->next;
        }
    }

    void dfsRecursive(int start) {
        bool visited[20] = {false};
        cout << "\nDFS (Recursive): ";
        dfsRecursiveUtil(start, visited);
    }

    void dfsNonRecursive(int start) {
        bool visited[20] = {false};
        stack<int> st;

        st.push(start);
        visited[start] = true;

        cout << "\nDFS (Non-Recursive): ";

        while (!st.empty()) {
            int v = st.top();
            st.pop();

            cout << v << " ";

            gnode* temp = head[v]->next;
            while (temp != NULL) {
                if (!visited[temp->id]) {
                    st.push(temp->id);
                    visited[temp->id] = true;
                }
                temp = temp->next;
            }
        }
    }

    void bfs(int start) {
        bool visited[20] = {false};
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "\nBFS: ";

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            cout << v << " ";

            gnode* temp = head[v]->next;
            while (temp != NULL) {
                if (!visited[temp->id]) {
                    visited[temp->id] = true;
                    q.push(temp->id);
                }
                temp = temp->next;
            }
        }
    }
};

int main() {
    graph g;
    g.create();
    g.display();

    int start;
    cout << "\nEnter starting user ID for traversal: ";
    cin >> start;

    g.dfsRecursive(start);
    g.dfsNonRecursive(start);
    g.bfs(start);

    return 0;
}