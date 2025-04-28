#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int SuskaiciuotiZingsnius(Node* root, int target) {
    int zingsniai = 0;
    Node* current = root;
    
    while (current != nullptr) {
        zingsniai++;
        if (current->data == target) {
            return zingsniai; 
        } else if (target < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    return -1;
}

Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int main() {
    Node* root = nullptr;

    int temp;
    while(true) {
        cout << "Iveskite skaiciu medziui(jeigu norite sustoti iveskite 0): " << endl;
        cin >> temp;
        if(temp == 0) break;
        root = insert(root, temp);
    }

    int N;
    cout << "Įveskite skaičių, kurio ieškote: ";
    cin >> N;
    
    int steps = SuskaiciuotiZingsnius(root, N);
    
    if (steps != -1)
        cout << "Skaičius rastas po " << steps << " žingsnių." << endl;
    else
        cout << "Skaičius nerastas." << endl;
    
    return 0;
}