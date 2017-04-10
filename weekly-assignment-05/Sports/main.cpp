#include <iostream>
#include <map>
#include <string>

using namespace std;

using Athlete = map<int, string>;
using Sports_List = map<string, Athlete>;

void print(const Sports_List& sport_list) {
    for ( auto event : sport_list ) {
        cout << event.first << endl;
        for ( auto ranking : event.second ) {
            cout << "  " << ranking.first
                 << "  " << ranking.second
                 << endl;
        }
    }

}

void add_athlete(Sports_List& events,
                    const string& event_name,
                    int rank,
                    const string& athlete_name) {
    if ( events.find(event_name) == events.end() ) {
        events.insert( { event_name, {} } );
    }

    if ( events.at(event_name).find(rank) == events.at(event_name).end() ) {
        events.at(event_name).insert( { rank, athlete_name } );
    } else {
        events.at(event_name).at(rank) = athlete_name;
    }
}

int main() {
    Sports_List list_of_sports = {
        { "Wrestling", {{ 1, "Pedro" }, { 2, "Nelly" }, }},
        { "Freezbi", {{ 1, "Mo" }, { 2, "Nelly" }, { 3, "Pedro" }, }},
    };

    add_athlete(list_of_sports, "Swimming", 1, "Nelly");
    add_athlete(list_of_sports, "Swimming", 2, "Pedro");
    add_athlete(list_of_sports, "Boxing", 2, "Nelly");
    add_athlete(list_of_sports, "Boxing", 1, "Pedro");
    add_athlete(list_of_sports, "Runnig", 1, "Farhad");
    add_athlete(list_of_sports, "Runnig", 2, "Nelly");
    add_athlete(list_of_sports, "Runnig", 3, "Mo");
    add_athlete(list_of_sports, "Runnig", 4, "Pedro");

    print(list_of_sports);
}

