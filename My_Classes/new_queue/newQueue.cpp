//
//  newQueue.cpp
//  newQueue
//
//  Created by 史家箫 on 2022/3/21.
//

#include "newQueue.hpp"
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <ctime>



// Initialize:
const std::string newQueue::Service::withdraw::service = "Withdraw" ;
const std::string newQueue::Service::save::service = "Save" ;
const std::string newQueue::Service::balance_inquire::service = "Balance Inquire" ;
const std::string newQueue::Service::print_bill::service = "Print Bill" ;
int newQueue::Customer::total = 0;



/* #1 */ newQueue::Service::Service(const newQueue::Service & temp) {
    Withdraw = temp.Withdraw;
    Save = temp.Save;
    Balance_Inquire = temp.Balance_Inquire;
    Print_Bill = temp.Print_Bill;
}


/* #2 */ newQueue::Service & newQueue::Service::operator=(const newQueue::Service &temp) {
    Withdraw = temp.Withdraw;
    Save = temp.Save;
    Balance_Inquire = temp.Balance_Inquire;
    Print_Bill = temp.Print_Bill;
    return *this;
}



/* #3 */ newQueue::Customer::Customer(const std::string &n, const std::string &i, clock_t &arr)
    : name(n), id(i), arrive(arr) { number_in_all = ++total; }


/* #4 */ newQueue::Customer::Customer(const newQueue::Customer &temp)
    : name(temp.name), id(temp.id), arrive(temp.arrive) {
    service = temp.service;
    processtime = temp.processtime;
    number_in_all = ++total;
    // already_wait = temp.already_wait;
    // need_to_wait = temp.need_to_wait;
}

/* #5 */ newQueue::Customer & newQueue::Customer::operator=(const Customer & temp) {
    name = temp.name;
    id = temp.id;
    arrive = temp.arrive;
    service = temp.service;
    processtime = temp.processtime;
    // already_wait = temp.already_wait;
    // need_to_wait = temp.need_to_wait;
    return *this;
}



/* #6 */ bool newQueue::Customer::set_sp() {
    using std::cin;
    using std::cout;
    using std::string;
    business = 0;
    processtime = 0;
    
    cout << "what service(s) do you need to deal with:\n" ;
    cout << "A.Withdraw  B.Save  C.Balance Inquiry  D.Print Bill  E.Quit \n" ;
    string answer;
    cout << "Please choose: " ;
    cin >> answer;
    int flagA = 0, flagB = 0, flagC = 0, flagD = 0;
    for (int i = 0; answer[i] != '\0'; i++)
        if (toupper(answer[i]) == 'E')
            return false;
    for (int i = 0; answer[i] != '\0'; i++) {
        char a = answer[i];
        if ( !isalpha(a) ) continue;
        else {
            a = toupper(a);
            switch (a) {
                case 'A' :
                    if ( flagA ) break;
                    cout << "Howmany seconds do you need to withdraw: " ;
                    int secsA;
                    cin >> secsA;
                    service.ser_set_w(true, secsA);
                    flagA = 1;
                    business++;
                    processtime += secsA;
                    break;
                case 'B' :
                    if ( flagB ) break;
                    cout << "Howmany seconds do you need to save: " ;
                    int secsB;
                    cin >> secsB;
                    service.ser_set_s(true, secsB);
                    flagB = 1;
                    business++;
                    processtime += secsB;
                    break;
                case 'C' :
                    if ( flagC ) break;
                    cout << "Howmany seconds do you need to inquire balance: " ;
                    int secsC;
                    cin >> secsC;
                    service.ser_set_b(true, secsC);
                    flagC = 1;
                    business++;
                    processtime += secsC;
                    break;
                case 'D' :
                    if ( flagD ) break;
                    cout << "Howmany seconds do you need to print bill: " ;
                    int secsD;
                    cin >> secsD;
                    service.ser_set_p(true, secsD);
                    flagD = 1;
                    business++;
                    processtime += secsD;
                    break;
            }
        }
        if (flagA && flagB && flagC && flagD) break;
    }
    return true;
}





/* #7 */ newQueue::Queue::Node::Node(const Node &temp) {
    item = temp.item;
    previous = temp.previous;
    next = temp.next;
    already_wait = temp.already_wait;
    need_to_wait = temp.need_to_wait;
}


/* #8 */ newQueue::Queue::Node & newQueue::Queue::Node::operator=(const newQueue::Queue::Node &temp) {
    item = temp.item;
    previous = temp.previous;
    next = temp.next;
    already_wait = temp.already_wait;
    need_to_wait = temp.need_to_wait;
    return *this;
}





/* #9 */ void newQueue::Queue::Node::set_alr(clock_t &now) {
    already_wait = (now - item.when()) / CLK_TCK;
}

/* 10 */ void newQueue::Queue::Node::set_ned(long need) {
    if ( previous == nullptr ) need_to_wait = need;
    else need_to_wait = previous->need_to_wait + previous->item.ptime();
}





// Queue methods:

void newQueue::Queue::reset(long need) {
    Node * temp = front;
    if (need <= 0) {
        long interval = front->need_to_wait - need;
        while (temp) {
            if (temp->need_to_wait - interval > 0) {
                temp->set_ned(temp->need_to_wait - interval);
                temp = temp->next;
                break;
            }
            temp->set_ned(0);
            dequeue(temp->item);
        }
    }
    while (temp) {
        temp->set_ned(need);
        temp = temp->next;
    }
    delete temp;
}


/* 11 */ newQueue::Queue::Queue(clock_t &st, int qs) : start(st), qsize(qs) {
    front = rear = nullptr;
    items = 0;
}


/* 12 */ newQueue::Queue::~Queue() {
    Node * temp;
    while (front) {
        temp = front;
        front = front->next;
        delete temp;
    }
}



// Enqueue and dequeue:
/* 13 */ bool newQueue::Queue::enqueue(const Item &item) {
    if (isfull())
        return false;
    Node * add = new Node;                                        // Memory from 'new': remember to delete!
    add->item = item;
    items++;
    add->set_ned(0);
    clock_t now = clock();
    add->set_alr(now);
    // set_serial(*add);
    add->previous = rear;
    add->next = nullptr;
    if (front == nullptr)
        front = add;
    else
        rear->next = add;
    rear = add;
    return true;
}


/* 14 */ bool newQueue::Queue::dequeue(Item &item) {
    if (isempty())
        return false;
    item = front->item;                                           // Set item to first item in queue(as a memory). item in service!
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;                                                  // Now front->previous == nullptr.
    if (items == 0)
        rear = nullptr;
    return true;
}




/* 15 */ newQueue::Served::sNode::sNode(const sNode &temp) {
    customer = temp.customer;
    sPrevious = temp.sPrevious;
    sNext = temp.sNext;
}


/* 16 */ newQueue::Served::sNode & newQueue::Served::sNode::operator=(const newQueue::Served::sNode &temp) {
    customer = temp.customer;
    sPrevious = temp.sPrevious;
    sNext = temp.sNext;
    return *this;
}



/* 17 */ newQueue::Served::Served(int fs) : fsize(fs) {
    first = last = nullptr;
    sItems = 0;
}
/* 18 */ newQueue::Served::~Served() {
    sNode * temp;
    while (first) {
        temp = first;
        first = first->sNext;
        delete temp;
    }
}



/* 19 */ bool newQueue::Served::enserved(const Item & customer) {
    if (isfull())
        return false;
    sNode * add = new sNode;                                        // Memory from 'new': remember to delete!
    add->customer = customer;
    add->sPrevious = last;
    add->sNext = nullptr;
    sItems++;
    if (first == nullptr)
        first = add;
    else
        last->sNext = add;
    last = add;
    return true;
}




/* 20 */ std::ofstream & newQueue::operator<<(std::ofstream &fout, const newQueue::Queue &line) {
    fout << "The current queue status is:\n" ;
    int i = 0;
    for (newQueue::Queue::Node * temp = line.front; temp != nullptr && i < line.queuecount(); temp = temp->next, i++){
        fout << "\nCustomer " << i+1 << ": "
             << temp->item.Name() << ' ' << temp->item.Id() << ' ' << line.when_trans(*temp) << '\n' ;
        fout << "He/she will do:\n" ;
        
        if (temp->item.serv().re()[0] == 1)
            fout << temp->item.serv().wtd().ser() << " for " << temp->item.serv().wtd().tim() << " seconds.\n";
        if (temp->item.serv().re()[1] == 1)
            fout << temp->item.serv().sav().ser() << " for " << temp->item.serv().sav().tim() << " seconds.\n";
        if (temp->item.serv().re()[2] == 1)
            fout << temp->item.serv().biq().ser() << " for " << temp->item.serv().biq().tim() << " seconds.\n";
        if (temp->item.serv().re()[3] == 1)
            fout << temp->item.serv().pbl().ser() << " for " << temp->item.serv().pbl().tim() << " seconds.\n";
        fout << "He/she has been waited for " << temp->alrtime() << " seconds. "
             << "He/she still has to wait for " << temp->nedtime() << " seconds.\n" ;
    }
    
    return fout;
}


/* 21 */ std::ofstream & newQueue::operator<<(std::ofstream &fout, const newQueue::Served &line) {
    fout << "Here is the list of served customers:\n" ;
    // int i = 0;
    for (newQueue::Served::sNode * temp = line.first; temp != nullptr /*&& i < line.servedcount()*/; temp = temp->sNext) {
        fout << "\nCustomer " << temp->customer.num() << ": "
             << temp->customer.Name() << ' ' << temp->customer.Id() << ' ' << line.when_trans(*temp) << '\n' ;
        fout << "He/she had done:\n" ;
        
        if (temp->customer.serv().re()[0] == 1)
            fout << temp->customer.serv().wtd().ser() << " for " << temp->customer.serv().wtd().tim() << " seconds.\n";
        if (temp->customer.serv().re()[1] == 1)
            fout << temp->customer.serv().sav().ser() << " for " << temp->customer.serv().sav().tim() << " seconds.\n";
        if (temp->customer.serv().re()[2] == 1)
            fout << temp->customer.serv().biq().ser() << " for " << temp->customer.serv().biq().tim() << " seconds.\n";
        if (temp->customer.serv().re()[3] == 1)
            fout << temp->customer.serv().pbl().ser() << " for " << temp->customer.serv().pbl().tim() << " seconds.\n";
    }
    
    return fout;
}
