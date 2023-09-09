//
//  main.cpp
//  newQueue
//
//  Created by 史家箫 on 2022/3/21.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "newQueue.hpp"


void interface1(void);
void interface2(void);
bool newcustomer(double x);

int main() {
    
    interface1();
    
    return 0;
    
}

void interface1(void) {
    
    // Using-instructions:
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    using std::strlen;
    using std::strcpy;
    using std::ios_base;
    using std::ifstream;
    using std::ofstream;
    using newQueue::Customer;
    using newQueue::Item;
    using newQueue::Queue;
    using newQueue::Served;
    
    
    // File-oriented programming:
    ifstream fin;
    ofstream fout;

    // Set random initializing rand():
    std::srand((unsigned int)(time(0)));
    
    // Greeting my guest:
    cout << "Welcome to Drogba's ATM!\n" ;
    
    // The file for output:
    string fileName = "/Users/shijiaxiao/Desktop/cpp program/My class - Encapsulation/newQueue/Result of Queue.txt" ;
    fout.open(fileName);
    if (fout.is_open())
        cout << "Open file successfully!\n" ;
    
    // Initialize queue line:
    int qs;
    cout << "Please enter maximum size of queue: " ;
    cin >> qs;
    
    // Initialize served line:
    int fs;
    cout << "Please enter maximum size of served queue: " ;
    cin >> fs;
    Served finish(fs);
    
    
    // Acquiring cycle limit:
    // Total seconds:
    double hours;
    cout << "Please enter the number of simulation hours: " ;
    cin >> hours;
    long whole_secs = long(Queue::MIN_PER_HR * Queue::SECS_PER_MIN * hours);
    // How many seconds for each simulated loop:
    int cyc_secs;
    cout << "Please enter the simulated seconds for every loop: " ;
    cin >> cyc_secs;
    long cycle_limit = whole_secs / cyc_secs;
    
    // Aquiring average customers of visiting ATM per hour:
    int cus_per_hour;
    cout << "Please enter the average number of customers per hour: " ;
    cin >> cus_per_hour;
    
    // Calculate the average time interval between 2 customers:
    double secs_per_cus = double(Queue::MIN_PER_HR * Queue::SECS_PER_MIN) / cus_per_hour;
    double reciprocal_probability_per_cyc = secs_per_cus / cyc_secs;
    double &x = reciprocal_probability_per_cyc;
    
    int turnaways = 0;
    
    clock_t start = clock();
    Queue line(start, qs);
    
    
    // Running the simulation:
    for (int cycle = 0; cycle < cycle_limit; cycle++) {
        if (cycle == 0) {
            fout << "\nSimulation begins:\n" ;
            cout << "\nSimulation begins:\n" ;
        }
        else {
            fout << '\n' << cycle * cyc_secs << " seconds after the simulation has begun:\n" ;
            cout << '\n' << cycle * cyc_secs << " seconds after the simulation has begun:\n" ;
        }
        
    
        // clock_t now = clock();
        if ( line.ft() )
            line.reset(line.ft()->need_to_wait - cyc_secs);
        
        
        // Have new customer:
        if (newcustomer(x)) {
            cout << "A new customer is coming!\n" ;
            fout << "A new customer is coming!\n" ;
            
            // Won't collext personal information in this case:
            if (line.isfull()) {
                fout << "Unfortunately, the queue is full, he/she leaves. Now we have " << ++turnaways << " turnaways.\n" ;
                cout << "Unfortunately, the queue is full, he/she leaves. Now we have " << ++turnaways << " turnaways.\n" ;
            }
                
            
            
            string name;
            cout << "Please enter your name: " ;
            cin >> name;
            string id;
            cout << "Please enter your ID number: " ;
            cin >> id;
            clock_t arrive = clock();
            Item temp(name, id, arrive);
            
            if ( !temp.set_sp() ) {
                temp.set_to_quit();
                cout << "Hope to see you again!\n" ;
                continue;
            }
            else {
                fout << "There still has places available, please in queue!" ;
                cout << "There still has places available, please in queue!" ;
                line.enqueue(temp);
            }
            
            if ( !line.isempty() )  fout << line;
            else                    fout << "Empty queue!\n" ;
            if ( !finish.isempty()) fout << finish;
            else                    fout << "Nobody has been served!\n" ;
            
        }
    }
}



bool newcustomer(double x) {
    // Whether there will be new customer:
    return (std::rand() * x / RAND_MAX < 1);
}
