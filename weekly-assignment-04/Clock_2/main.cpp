#include <iostream>
#include <list>

using namespace std;


class Clock {
  public:
    Clock(int hour = 0, int minute = 0);
    void set(int hour = 0, int minute = 0);
    int diff(Clock);
    int get_hour();
    int get_minute();

  private:
    int hours_;
    int minutes_;
};


Clock::Clock(int hour, int minute):
    hours_(hour), minutes_(minute) {
}

void Clock::set(int hour, int minute) {
        hours_ = hour;
        minutes_ = minute;
}

int Clock::get_hour()    {
    return hours_;
}

int Clock::get_minute()    {
    return minutes_;
}


bool cmp_time( Clock& time1, Clock& time2) {
//    cout << time1.hours_;
    return (time1.get_hour() * 60 + time1.get_minute()) < (time2.get_hour() * 60 + time2.get_minute());
//    return true;
}


int main() {
    int h1;
    int m1;
    list<Clock> clock_list;
    string end;
    Clock time;

    while(end != "yes") {
        cout << "Type the time's hours please.\n";
        cin >> h1;
        cout << "Type the time's minutes please.\n";
        cin >> m1;
        cout << "Do you want to STOP entering more time? if so press \"yes\" and if not just enter antything else to continue entering more times.\n";
        cin >> end;
        time.set(h1, m1);
        clock_list.push_back(time);
    }
    clock_list.sort(cmp_time);

    cout << "mylist contains:" << endl;
      for (list<Clock>::iterator it=clock_list.begin(); it != clock_list.end(); ++it)
        cout << ' ' << (*it).get_hour() << ":" <<  (*it).get_minute() << endl;

}

