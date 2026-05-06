//
// Created by new on 5/6/26.
//

#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

double lowestToll(vector<tuple<string, string, double>> highwayTolls, string startCity, string endCity) {
    unordered_map<string, unordered_map<string, double>> G{};
    for (tuple<string, string, double> c : highwayTolls) {
        string from = get<0>(c);
        string to = get<1>(c);
        double cost = get<2>(c);
        G[from][to] = cost;
        G[to][from] = cost;
    }

    priority_queue<tuple<double, string>, vector<tuple<double, string>>, greater<>> pq;
    pq.push(tuple<double, string>(0, startCity));
    unordered_map<string, double>dist{};
    dist[startCity] = 0;
    while (!pq.empty()) {
        tuple<double, string> t_v = pq.top();
        pq.pop();

        string v = get<1>(t_v);
        double v_cost = get<0>(t_v);
        if (dist.count(endCity) > 0 && v_cost > dist[endCity]) {
            break;
        }

        for (pair<string, double> neigh_info : G[v]) {
            string neigh_v = get<0>(neigh_info);
            double neigh_cost = get<1>(neigh_info);
            if (dist.count(neigh_v) > 0 && dist[neigh_v] < (v_cost + neigh_cost)) {
                continue;
            }
            dist[neigh_v] = v_cost + neigh_cost;
            pq.push(tuple<double, string>(dist[neigh_v], neigh_v));
        }
    }

    return dist.count(endCity) > 0 ? dist[endCity] : -1;
}

void test_00() {
    std::vector<std::tuple<std::string, std::string, double>> highwayTolls {
      { "Hampton", "Fairfax", 7.50 },
      { "Roanoake", "Alexandria", 4.20 },
      { "Alexandria", "Hampton", 14.50 },
      { "Hampton", "Roanoake", 8.90 },
      { "Alexandria", "Fairfax", 5.90 },
      { "Hampton", "Manassas", 3.50 },
      { "Fairfax", "Manassas", 2.20 }
    };
    const double res = lowestToll(highwayTolls, "Alexandria", "Hampton"); // -> 11.60
    const bool passed = (res - 11.60) < 0.0001;
    cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

void test_01() {
    std::vector<std::tuple<std::string, std::string, double>> highwayTolls {
      { "Hampton", "Fairfax", 7.50 },
      { "Roanoake", "Alexandria", 4.20 },
      { "Alexandria", "Hampton", 14.50 },
      { "Hampton", "Roanoake", 8.90 },
      { "Alexandria", "Fairfax", 5.90 },
      { "Hampton", "Manassas", 3.50 },
      { "Fairfax", "Manassas", 2.20 }
    };
    const double res = lowestToll(highwayTolls, "Alexandria", "Fairfax"); // -> 5.90
    const bool passed = (res - 5.9) < 0.0001;
    cout << "test_01: " << (passed ? "passed" : "failed") << endl;
}

void test_02() {
    std::vector<std::tuple<std::string, std::string, double>> highwayTolls {
      { "Hampton", "Fairfax", 7.50 },
      { "Roanoake", "Alexandria", 4.20 },
      { "Alexandria", "Hampton", 14.50 },
      { "Hampton", "Roanoake", 8.90 },
      { "Alexandria", "Fairfax", 5.90 },
      { "Hampton", "Manassas", 3.50 },
      { "Fairfax", "Manassas", 2.20 }
    };
    const double res = lowestToll(highwayTolls, "Hampton", "Fairfax"); // -> 5.70
    const bool passed = (res - 5.7) < 0.0001;
    cout << "test_02: " << (passed ? "passed" : "failed") << endl;
}

void test_03() {
    std::vector<std::tuple<std::string, std::string, double>> highwayTolls {
          { "Kyiv", "Lviv", 7.50 },
          { "Donetsk", "Sevastopol", 42.0 },
    };

    const double res = lowestToll(highwayTolls, "Kyiv", "Donetsk"); // -> -1
    const bool passed = (res - (-1)) < 0.0001;
    cout << "test_03: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char* argv[]) {
    test_00();
    test_01();
    test_02();
    test_03();
}
