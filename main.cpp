#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
public:
    string name;

    User(string name) : name(name) {}
};

struct Graph {
    int V;
    vector<User> users;
    vector<vector<int>> adjMatrix;

    Graph(int versh) {
        V = versh;
        adjMatrix.resize(V, vector<int>(V, 0));
        users.resize(V, User(""));
    }

    void setUser(int index, string name) {
        if (index >= V) {
            cout << "Ошибка: индекс за пределами графа!\n";
            return;
        }
        users[index] = User(name);
    }


    void addFriendship(int index1, int index2) {
        if (index1 >= V || index2 >= V) {
            cout << "Ошибка: индекс за пределами графа!\n";
            return;
        }
        adjMatrix[index1][index2] = 1;
        adjMatrix[index2][index1] = 1;
    }

    void print() {
        cout << "   ";
        for (const auto& user : users) {
            cout << user.name << " ";
        }
        cout << endl;

        for (int i = 0; i < V; i++) {
            cout << users[i].name << " ";
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(5);

    graph.setUser(0, "Alice");
    graph.setUser(1, "Brich");
    graph.setUser(2, "Jett");
    graph.setUser(3, "Viper");
    graph.setUser(4, "Reyna");


    graph.addFriendship(0, 1);
    graph.addFriendship(1, 2);
    graph.addFriendship(3, 4);

    graph.print();

    return 0;
}













