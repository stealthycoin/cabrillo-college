/*
 *  printime.cpp
 *  
 *
 *  Created by John Carlyle on 3/5/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
#include <iomanip>

using namespace std;

#include "ccc_time.cpp"

void print_time(Time t) {
    cout << t.get_hours() << ":" << setw(2) << setfill('0') << t.get_minutes() << ":" << setw(2) << t.get_seconds() << setfill(' ');
}

int main() {
    Time liftoff(7, 0, 1);
    Time now;
    cout << "Liftoff: ";
    print_time(liftoff);
    cout << endl;
    
    cout << "Now: ";
    print_time(now);
    cout << endl;
    
    return 0;
}

