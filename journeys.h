#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Journeys {

public:
    Journeys() = delete;
    explicit Journeys(const vector<vector<char>> &citiesJoureyMap);
    explicit Journeys(const vector<vector<char>> &citiesJoureyMap, int numberOfCities);
    ~Journeys();

    bool isValidJourney(const char* journey);
    unsigned int getTotalNumJourneys(char start, char end);

private:
    vector<vector<char>> m_citiesJoureyMap;
    vector<vector<int>> m_citiesAdjacencyMatrix;
    int m_numberOfCities = 0;

    void init();
    int citiesToIndex(char c);
    bool traverseGraph(string &s, vector<vector<int>> &graph, int index);
};
