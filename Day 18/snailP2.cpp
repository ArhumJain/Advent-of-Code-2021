#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node *parent;
    Node(Node *parent) {
        data = -1;
        left = nullptr;
        right = nullptr;
        this->parent = parent;
    }
};

Node *topNode;
void addNearestLeft(Node *root, int depth, bool stop);
void addNearestRight(Node *root, int a, bool stop);
bool explodeAny(Node *root, int depth);
bool splitAny(Node *root);
Node* newFishNumber(string fp);
Node* addFishNumbers(Node *root1, Node *roo2);
int magnitude(Node *root);
int maxMagnitude(vector<string> &fishNumbers);
void reduce(Node* sum);
string stringify(Node* root);


void addNearestLeft(Node *root, int a, bool stop) {
    if (root->parent->left != root) {
        Node *curr = root->parent->left;
        while (curr->data == -1) {
            curr = curr->right; 
        }
        curr->data += a;
        return;
    } else {
        if (root->parent == nullptr || stop) return;
        else if (root->parent->parent == nullptr) {
            addNearestLeft(root, a, true);
        } else{
            addNearestLeft(root->parent, a, false);
        }
        return;
    }
}

void addNearestRight(Node *root, int a, bool stop) { // <--- stop is simply for not entering an infinte loop when the parent of the parent of the current root is null (meaning its the top node)
    if (root->parent->right != root)  {
        Node *curr = root->parent->right;
        while (curr->data == -1) {
            curr = curr->left; 
        }
        curr->data += a;
        return;
    } else {
        if (root->parent == nullptr || stop) return;
        else if(root->parent->parent == nullptr) {
            addNearestRight(root, a, true);
        }
        else addNearestRight(root->parent, a, false);
        return;
    }
}

bool explodeAny(Node *root, int depth) {
    bool anyExploded = false;
    if (depth > 4 || root == nullptr) {
        anyExploded = false;
    } else if (depth == 4) {
        if (root->left->data != -1 && root->right->data != -1) { // <---- if both children data are -1 then this is a pair of pure regular numbers
            addNearestLeft(root, root->left->data, false);
            addNearestRight(root, root->right->data, false);
            root->data = 0;
            delete root->left;
            delete root->right;
            root->left = nullptr; root->right = nullptr;
            anyExploded = true;
        }
    } else {
        bool explodedLeft = false;
        bool explodedRight = false;
        if (root->left->data == -1) {
            explodedLeft = explodeAny(root->left, depth + 1);
        }
        if (root->right->data == -1) {
            explodedRight = explodeAny(root->right, depth + 1);
        }
        if (explodedLeft || explodedRight) anyExploded = true;
    }
    return anyExploded;
}

bool splitAny(Node *root) {
    bool anySplitted = false;
    if (root->data >= 10) {
        root->left = new Node(root);
        root->left->data = root->data/2;

        root->right = new Node(root);
        root->right->data = (root->data+1)/2;

        root->data = -1;
        anySplitted = true;
    } else if (root->data == -1) {
        if (splitAny(root->left)) return true;
        else if (splitAny(root->right)) return true;
        else return false;
    }
    return anySplitted;
}

Node* newFishNumber(string fp) {
    Node *root = new Node(nullptr); 
    stack<Node*> s; s.push(root);
    for (char c: fp) {
        if (c != ',') {
            if (c=='[') {
                Node *n = new Node(s.top());
                if (s.top()->left == nullptr) s.top()->left = n;
                else s.top()->right = n;
                s.push(n);
            } else if (c==']') {
                s.pop();
            } else {
                Node *n = new Node(s.top());
                n->data = c-'0';
                if (s.top()->left == nullptr) {
                    s.top()->left = n;
                } else {
                    s.top()->right = n;
                }
            }
        }
    }
    return root;
}

Node* addFishNumbers(Node *root1, Node *root2) {
    Node* root = new Node(nullptr);
    root->left = root1; root->right = root2;
    root1->parent = root;
    root2->parent = root;
    return root;
}

int magnitude(Node *root) {
    int leftMag = 0;
    int rightMag = 0;
    if (root->left->data == -1) leftMag = 3 * magnitude(root->left);
    else leftMag = root->left->data * 3;
    if (root->right->data == -1) rightMag = 2 * magnitude(root->right);
    else rightMag = root->right->data * 2;
    return leftMag+rightMag;
}

int maxMagnitude(vector<string> &fishNumbers) {
    int maxMag = -999999999;
    int currMag;
    for (auto num1: fishNumbers) {
        for (auto num2: fishNumbers) {
            Node* sum;
            sum->parent = nullptr;
            sum = addFishNumbers(newFishNumber(num1), newFishNumber(num2));
            topNode = sum;
            reduce(sum);
            currMag = magnitude(sum);
            if (currMag > maxMag) maxMag = currMag;
        }
    }
    return maxMag;
}

void reduce(Node* sum) {
    bool end = false;
    while (!end) {
        if (explodeAny(sum, 0)) {
            continue;
        } else if (splitAny(sum)) {
            continue;
        } else {
            end = true;
        }
    }
}

string stringify(Node *root) {
    if (root->data == -1) {
        return "[" + stringify(root->left) + "," + stringify(root->right) + "]";
    } else {
        return to_string(root->data);
    }
}
int main() {
    ifstream fin("snail.in");
    string fp; 
    vector<string> fishNumbers;
    while (!fin.eof()) {
        fin.ignore(1);
        getline(fin, fp);
        fishNumbers.push_back(fp);
    }
    int maxMag = maxMagnitude(fishNumbers);
    cout << "Pair Magnitude with Maximum Magnitude " << maxMag << endl;
}
