#include <bits/stdc++.h>

using namespace std;


struct Tree{
    Tree *left = nullptr;
    Tree *right = nullptr;
    int node = -1;
    bool setted = false;
    bool created = false;

    bool insert(const string &path, int i, const int value){
        if(i > path.size()) return false;
        created = true;
        if(i == path.size()){
            if(!setted) node = value;
            // cout << "inserted " << path << " " << " with value " << value << endl;
            return setted = !setted;
        }

        if(path[i] == 'L'){
            if(left == nullptr) left = new Tree();
            return left->insert(path, i+1, value);
        }
        if(path[i] == 'R'){
            if(right == nullptr) right = new Tree();
            return right->insert(path, i+1, value);
        }

        return true;
    }
};

bool BFS(Tree *tree, string &r){
    deque<Tree*> trees;
    Tree *v;
    trees.push_back(tree);
    while(trees.size()){
        v = trees.front();
        trees.pop_front();
        if(v == nullptr) continue;
        if(v->created && !v->setted) return false;
        r+= to_string(v->node) + " ";
        trees.push_back(v->left);
        trees.push_back(v->right);
    }

    return true;
}

int read(int &n, string &w){
    string s, number;

    cin >> s;
    if(cin.eof()) return 3;
    
    if(s[1] == ')') return 2;
    int i = 1;
    while(s[i] != ',') number+=s[i++];
    i++;
    while(s[i] != ')') w+=s[i++];

    n = stoi(number);
    return 1;
}

int main(){

    string s, r;
    int n, stop;
    vector<pair<string, int> > pos;


    while(s= "", stop = read(n, s)){
        if(stop == 3) break;
        if(stop > 1){
            bool puede = true;
            Tree *tree = new Tree();
            r = "";
            for(int i=0; i<pos.size(); i++){
                puede &=tree->insert(pos[i].first, 0, pos[i].second);
            }
            if(puede) puede&= BFS(tree, r);

            if(puede) cout << r.substr(0,r.size()-1) << "\n";
            else cout << "not complete\n";
        }
        if(stop == 2){
            pos.resize(0);
            continue;
        }

        pos.push_back({s, n});
    }

    

    return 0;
}