#include "journeys.h"

int main ()
{
    vector<vector<char>> paths = {
        {'a','b'},
        {'b','c'},
        {'b','c'},
        {'c', 'b'},
        {'c','d'},
        {'d','c'},
        {'d','b'},
        {'b','d'},
        {'d','e'},
    };
    Journeys j(paths);
    auto rt = j.isValidJourney("abde");
    cout << "Is Valid: " << rt << endl;
    rt = j.isValidJourney("abcdbcdbcde");
    cout << "Is Valid: " << rt << endl;
    return 0;
}