#include <bits/stdc++.h>

using namespace std;

int t, n, arr[1000005], operations;

vector<int> parents;

vector<int>::iterator idx;

struct Node {
    int info;
    struct Node *left, *right;
};

Node* newNode(int data){
    Node* temp = new Node;
    temp->info = data;
    temp->left = temp->right = NULL;
    return temp;
}

void recursion(struct Node* node, int &k);

void get_parents(struct Node* node, int &k, int parent, int& m);

int main(){
    cin >> t;

    for(int i = 1; i <= t; i++){
        parents.clear();
        cin >> n;
        vector<int> v;

        for(int j = 1; j <= n; j++)
            cin >> arr[j];

        v.push_back(arr[1]);
        for(int j = 2; j <= n; j++){
            if(v.back() < arr[j]) v.push_back(arr[j]);
            else if(v.back() > arr[j]){
                idx = lower_bound(v.begin(),v.end(), arr[j]);
                int k = idx - v.begin();
                v[k] = arr[j];
            }
        }
        operations = n - v.size();
        sort(arr + 1, arr + 1 + n);

        Node* nodes[n+1];
        for(int j = 1; j <= n; j++)
            nodes[j] = newNode(0);

        for(int j = 1; j <= n/2; j++){
            nodes[j]->left = nodes[2*j];
            if(2*j + 1 > n) break;
            nodes[j]->right = nodes[2*j + 1];
        }

        int k = 0;
        recursion(nodes[1], k);

        cout << "Case " << i << ":" << endl;
        cout << "Minimum Move: " << operations << endl;

        int a = 0;
        int b = 0;
        get_parents(nodes[1], a, -1, b);

        for(int j = 0; j < parents.size() - 1; j++)
            cout << parents[j] << " ";

        cout << parents[parents.size()-1];
        cout << endl;
    }

    return 0;
}

void recursion(struct Node* node, int &k){
    if(node == NULL){
      k++;
      return;
    }

    recursion(node->left, k);
    node->info = arr[k];

    recursion(node->right, k);
}

void get_parents(struct Node* node, int &k, int parent, int& m){
    m = k;
    if(node == NULL){
      k++;
      return;
    }

    get_parents(node->left, k, node->info, m);
    if(m != k){
        parents.push_back(parent);
        m = k;
    }

    get_parents(node->right, k, node->info, m);
}




