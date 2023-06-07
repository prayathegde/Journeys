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
    return 0;
}

// TODO: Consider Uppercase Characters as city names. 
int Journeys::citiesToIndex(char c) {
    return  c - 'a';
}

bool Journeys::traverseGraph(string &s, vector<vector<int>> &graph, int index)
{
    return false;
}