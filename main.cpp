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
        {'d','c'},
        {'d','b'},
        {'b','d'},
        {'d','e'},
    };

    Journeys j(paths);

    const char *path1 = "abde";
    auto rt = j.isValidJourney(path1);
    cout << "Is " << path1 << " Valid: " << rt << endl;

    const char *path2 = "abcdbcdbcde";
    rt = j.isValidJourney(path2);
    cout << "Is " << path2 << " Valid: " << rt << endl;

    const char *path3 = "abde";
    rt = j.isValidJourney(path3);
    cout << "Is " << path3 << " Valid: " << rt << endl;

    const char *path4 = "abdbde";
    rt = j.isValidJourney(path4);
    cout << "Is " << path4 << " Valid: " << rt << endl;


    const char *path5 = "abe";
    rt = j.isValidJourney(path5);
    cout << "Is " << path5 << " Valid: " << rt << endl;

    const char *path6 = "aba";
    rt = j.isValidJourney(path6);
    cout << "Is " << path6 << " Valid: " << rt << endl;
    
    auto count = j.getTotalNumJourneys('a', 'e');
    cout << "Total Number of Paths between ('a', 'e') " << count << endl;

    count = j.getTotalNumJourneys('a', 'b');
    cout << "Total Number of Paths between ('a', 'b') " << count << endl;

    count = j.getTotalNumJourneys('b', 'e');
    cout << "Total Number of Paths between ('b', 'e') " << count << endl;

    count = j.getTotalNumJourneys('b', 'd');
    cout << "Total Number of Paths between ('b', 'd') " << count << endl;

    count = j.getTotalNumJourneys('b', 'z');
    cout << "Total Number of Paths between ('b', 'z') " << count << endl;

    return 0;
}
