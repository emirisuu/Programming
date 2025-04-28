#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    string pavadinimas;
    vector<Node*> vaikai;

    Node(const string& pavadinimas) : pavadinimas(pavadinimas) {}

    void pridetiVaika(Node* vaikas) {
        vaikai.push_back(vaikas);
    }
};

void spausdintiMedi(Node* node, const string& prefix = "", bool paskutinis = true) {
    if (!node) return;

    cout << prefix;
    cout << (paskutinis ? "└── " : "├── ");
    cout << node->pavadinimas << endl;

    for (size_t i = 0; i < node->vaikai.size(); ++i) {
        spausdintiMedi(node->vaikai[i], prefix + (paskutinis ? "    " : "│   "), i == node->vaikai.size() - 1);
    }
}

int main() {
    Node* saknis = new Node("Žinduoliai");

    Node* placentiniai = new Node("Placentaliniai žinduoliai");
    Node* sterbliniai = new Node("Sterbliniai žinduoliai");
    Node* monotremos = new Node("Kiaušinius dedantys žinduoliai");

    saknis->pridetiVaika(placentiniai);
    saknis->pridetiVaika(sterbliniai);
    saknis->pridetiVaika(monotremos);

    Node* plesrunai = new Node("Plėšrūnai");
    Node* primatai = new Node("Primatai");
    Node* banginiai = new Node("Banginiai");

    placentiniai->pridetiVaika(plesrunai);
    placentiniai->pridetiVaika(primatai);
    placentiniai->pridetiVaika(banginiai);

    plesrunai->pridetiVaika(new Node("Liūtas"));
    plesrunai->pridetiVaika(new Node("Vilkai"));

    primatai->pridetiVaika(new Node("Žmogus"));
    primatai->pridetiVaika(new Node("Šimpanzė"));

    banginiai->pridetiVaika(new Node("Delfinai"));
    banginiai->pridetiVaika(new Node("Banginiai"));

    sterbliniai->pridetiVaika(new Node("Kengūra"));
    sterbliniai->pridetiVaika(new Node("Koala"));

    monotremos->pridetiVaika(new Node("Ančiasnapis"));
    monotremos->pridetiVaika(new Node("Echidna"));

    spausdintiMedi(saknis);

    return 0;
}
