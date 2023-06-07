#include "journeys.h"

Journeys::Journeys(const vector<vector<char>> &citiesJoureyMap) : Journeys(citiesJoureyMap, 26)
{
}

Journeys::Journeys(const vector<vector<char>> &citiesJoureyMap, int numberOfCities) : m_citiesJoureyMap(citiesJoureyMap), m_numberOfCities(numberOfCities)
{
    init();
}

Journeys::~Journeys()
{
    m_citiesJoureyMap.clear();
    m_citiesAdjacencyMatrix.clear();
}

void Journeys::init()
{
    if (m_numberOfCities > 26) {
        cerr << "Error :Number of Cities is Out of Range" << endl;
        return;
    }
    m_citiesAdjacencyMatrix = vector<vector<int>> (m_numberOfCities, vector<int> (m_numberOfCities, 0));

    for (auto connection : m_citiesJoureyMap) {
        int x = citiesToIndex(connection[0]);
        int y = citiesToIndex(connection[1]);
        m_citiesAdjacencyMatrix[x][y]++;
        m_citiesAdjacencyMatrix[y][x]++;
    }
}

bool Journeys::isValidJourney(const char* journey)
{
    string path(journey);
    auto graph = m_citiesAdjacencyMatrix;
    for (int i = 1; i < path.size(); i++) {
        int x = citiesToIndex(path[i - 1]);
        int y = citiesToIndex(path[i]);
        if (graph[x][y] > 0) {
            graph[x][y]--;
            graph[y][x]--;
        } else {
            return false;
        }
    }
    return true;
}

unsigned int Journeys::getTotalNumJourneys(char start, char end)
{
    int st = citiesToIndex(start);
    int en = citiesToIndex(end);
    unsigned int count = 0;
    for (int i = 0; i < m_citiesAdjacencyMatrix.size(); i++) {
        auto v = m_citiesAdjacencyMatrix[st][i];
        if (v > 0) {
            count += (traverseGraph(st, i, en) * v);
        }
    }

    return count;
}

int Journeys::citiesToIndex(char c) {
    return c >= 'a' && c <= 'z' ? c - 'a' : c -'A';
}

unsigned int Journeys::traverseGraph(int prev, int curr, int end)
{
    if (curr == end) {
        return 1;
    }

    m_citiesAdjacencyMatrix[prev][curr] -= 1;
    m_citiesAdjacencyMatrix[curr][prev] -= 1;

    unsigned int count = 0;

    for (int i = 0; i < m_citiesAdjacencyMatrix.size(); i++) {
        auto v = m_citiesAdjacencyMatrix[curr][i];
        if (v > 0) {
            count += (traverseGraph(curr, i, end) * v);
        }
    }

    m_citiesAdjacencyMatrix[prev][curr] += 1;
    m_citiesAdjacencyMatrix[curr][prev] += 1;

    return count;
}