#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


double poisson(double mu, int k) {
    return pow(mu, k) * exp(-mu) / tgamma(k+1);
}

double prob(std::vector<int> daten, double mu) {
    double likelihood = 1.0;
    for(int k : daten) {
        likelihood *= poisson(mu, k);
    }
    return likelihood;
}

double prob2(std::vector<int> daten) {
    double likelihood = 1.0;
    for(int k : daten) {
        likelihood *= poisson(k, k);
    }
    return likelihood;
}

int main() {
    using namespace std;
    std::vector<int> daten;
    ifstream fin("datensumme.txt");
    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        daten.push_back(n_i);
    }
    cout << prob(daten, 3.11538) << endl;
    ofstream fout("likelihood.txt");
    ofstream fout2("nll.txt");
    ofstream fout3("deltanll.txt");
    for(double i = 0; i < 6; i= i + 0.1) {
        fout << i << " " << prob(daten, i) << endl;
        fout2 << i << " " << -2*log(prob(daten, i)) << endl;
        fout3 << i << " " << -2*log(prob(daten, i))-2*log(prob(daten, 3.11538)) << endl;
    }

    for(double i = 3.05; i < 3.15; i= i + 0.0001) {
        // uncertainty on the estimated mu value (exercise 1d)
        // cout << i << " " << -2*log(prob(daten, i)/prob(daten, 3.1)) << endl;
        
        // likelihood ratio for different mu
        cout << i << " " << -2*log(prob(daten, i) / prob2(daten)) << endl;
        
        // relative deviation of "my" likelihood ratio from the mean z:
        // cout << i << " " << (-2*log(prob(daten, i) / prob2(daten))-233)/sqrt(233) << endl;
    }

    fin.close();
    fout.close();
    fout2.close();
    fout3.close();
}