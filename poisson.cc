#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


double poisson(double mu, int k) {
    double P = pow(mu, k) * pow(exp(1.0), -mu) / tgamma(k+1);
    return P;
}

int main() {
    using namespace std;
    vector<int> zaehler(11);
    ifstream fin("datensumme.txt");
    int n_i;
    int N = 234;
    for(int i = 0 ; i < N ; ++i) {
        fin >> n_i;
        zaehler[n_i] += 1;
    }
    ofstream fout("hist.txt");
    ofstream fout2("histpoi.txt");
    for(unsigned int k = 0 ; k < zaehler.size() ; ++k) {
    std::cout << k << ":" << zaehler[k] << std::endl;
    fout << k << " " << zaehler[k] << std::endl;
    fout2 << k << " " << zaehler[k] << " " << N * poisson(3.11538, k) << std::endl;
 }
    fin.close();
    fout.close();
}