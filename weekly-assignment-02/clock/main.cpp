#include <iostream>
#include <iomanip>

using namespace std;


class Clock {
  public:
    Clock(int hour, int minute);
    void tick_tock();
    void print() const;
    int diff(Clock);

  private:
    int hours_;
    int minutes_;
};


Clock::Clock(int hour, int minute):
    hours_(hour), minutes_(minute) {
}


int Clock::diff(Clock second) {
   int diff;
   if (second.hours_ > this->hours_)   {
       diff = (-this->hours_ + second.hours_) * 60  - this->minutes_ + second.minutes_;
   } else if (this->hours_ == second.hours_)   {
       if (second.minutes_ > this->minutes_)
           diff = - this->minutes_ + second.minutes_;
       else if (second.minutes_ < this->minutes_)
           diff = 24*60 - this->minutes_ + second.minutes_;
       else
           return 0;
   } else  {
       diff = (24 - this->hours_ + second.hours_) * 60  - this->minutes_ + second.minutes_;
   }
   return diff;
}

void Clock::tick_tock() {
    ++minutes_;
    if ( minutes_ >= 60 ) {
        minutes_ = 0;
        ++hours_;
    }

    if ( hours_ >= 24 ) {
        hours_ = 0;
    }
}


void Clock::print() const {
    cout << setw(2) << setfill('0') << hours_
         << "."
         << setw(2) << minutes_
         << endl;
}


int main() {
    int h1;
    int h2;
    int m1;
    int m2;

    cout << "Type the first time's hours please.\n";
    cin >> h1;
    cout << "Type the first time's minutes please.\n";
    cin >> m1;
    cout << "Type the second time's hours please.\n";
    cin >> h2;
    cout << "Type the second time's minutes please.\n";
    cin >> m2;

    Clock time1(h1, m1);
    Clock time2(h2, m2);
    cout << "The difference between two times is: \n";
    cout << time1.diff(time2) << endl;
//    time.print();
//    time.tick_tock();
//    time.print();
}

