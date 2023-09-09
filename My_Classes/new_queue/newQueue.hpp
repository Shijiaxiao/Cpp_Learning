//
//  newQueue.hpp
//  newQueue
//
//  Created by 史家箫 on 2022/3/21.
//

#ifndef newQueue_hpp
#define newQueue_hpp

#include <iostream>
#include <ctime>

// Template used to number functions to be written: /* #n */


// Define a namespace named newQueue:
namespace newQueue {






// (1) Define a business type class:
class Service {
    
private:
    
    static const int service_type = 4;
    enum { wd = 0, sa = 1, bi = 2, pb = 3};
    int record[4];
    
    
    
    
    class withdraw {
    private:
        // Informations:
        static const std::string service;
        bool whether;
        int time;
    public:
        // Constructors:
        withdraw(bool w = false, int t = 30) { whether = w; time = t; };
        withdraw(const withdraw &temp) { whether = temp.whether; time = temp.time; }
        ~withdraw() { }
        // Set private values:
        void set_all(bool w, int t) { whether = w; time = t; }
        // Return private values:
        std::string re_service() const { return service; }
        bool re_whether() const { return whether; }
        int re_time() const { return time; }
    } ;
    withdraw Withdraw;
    
    
    
    
    
    class save {
    private:
        // Informations:
        static const std::string service;
        bool whether;
        int time;
    public:
        // Constructors:
        save(bool w = false, int t = 30) { whether = w; time = t; };
        save(const save &temp) { whether = temp.whether; time = temp.time; }
        ~save() { }
        // Set private values:
        void set_all(bool w, int t) { whether = w; time = t; }
        // Return private values:
        std::string re_service() const { return service; }
        bool re_whether() const { return whether; }
        int re_time() const { return time; }
    } ;
    save Save;
    
    
    
    
    
    class balance_inquiry {
    private:
        // Informations:
        static const std::string service;
        bool whether;
        int time;
    public:
        // Constructors:
        balance_inquiry(bool w = false, int t = 30) { whether = w; time = t; };
        balance_inquiry(const balance_inquiry &temp) { whether = temp.whether; time = temp.time; }
        ~balance_inquiry() { }
        // Set private values:
        void set_all(bool w, int t) { whether = w; time = t; }
        // Return private values:
        std::string re_service() const { return service; }
        bool re_whether() const { return whether; }
        int re_time() const { return time; }
    } ;
    balance_inquiry Balance_Inquiry;
    
    
    
    
    
    
    class print_bill {
    private:
        // Informations:
        static const std::string service;
        bool whether;
        int time;
    public:
        // Constructors:
        print_bill(bool w = false, int t = 30) { whether = w; time = t; };
        print_bill(const print_bill &temp) { whether = temp.whether; time = temp.time; }
        ~print_bill() { }
        // Set private values:
        void set_all(bool w, int t) { whether = w; time = t; }
        // Return private values:
        std::string re_service() const { return service; }
        bool re_whether() const { return whether; }
        int re_time() const { return time; }
    } ;
    print_bill Print_Bill;
    

    
    
    
    
    
    
public:
    
    // Just build! Don't have to do anything!
    Service() {};
    /* #1 */ Service(const Service &temp);                                                           // #1
    /* #2 */ Service & operator=(const Service &temp);                                               // #2
    ~Service() {};
    // Initialize service class:
    void ser_set_w(bool w, int t) { Withdraw.set_w(w, t); if (w == true) record[wd] = 1; }
    void ser_set_s(bool w, int t) { Save.set_s(w, t); if (w == true) record[sa] = 1; }
    void ser_set_b(bool w, int t) { Balance_Inquire.set_b(w, t); if (w == true) record[bi] = 1; }
    void ser_set_p(bool w, int t) { Print_Bill.set_p(w, t); if (w == true) record[pb] = 1; }
    int const * re() const { return record; }
    withdraw wtd() const { return Withdraw; }
    save sav() const { return Save; }
    balance_inquire biq() const { return Balance_Inquire; }
    print_bill pbl() const { return Print_Bill; }
    
} ;













// (2) Define a Customer class:
class Customer {
private:
    static int total;
    /*const*/ std::string name;
    /*const*/ std::string id;
    /*const*/ clock_t arrive;
    Service service;
    int number_in_all;
    int business;
    int processtime;
public:
    Customer() { }; // I am not using it anyway.
    /* #3 */ Customer(const std::string &n, const std::string &i, clock_t &arr);                       // #3
    /* #4 */ Customer(const Customer & temp);                                                      // #4
    /* #5 */ Customer & operator=(const Customer & temp);                                          // #5
    ~Customer() { total--; };
    /* #6 */ bool set_sp();
    /* 22 */ void set_to_quit() { }; // total--, enqueue to quit.
    
    std::string Name() const { return name; }
    std::string Id() const { return id; }
    clock_t when() const { return arrive; }
    Service serv() const { return service; }
    int btime() const { return business; }
    int ptime() const { return processtime; }
    int num() const { return number_in_all; }
    
} ;











// (3) Typedefine Customer to Item:
typedef Customer Item;









// (4) Define a Queue class:
class Queue {
    
private:
    
    /* Class-scopse definations: */
    
    class Node {
    public:                                          // Node is a nested class defination local to this class. class but not object!
        Node() { previous = nullptr; next = nullptr; };  // Initilaize the two pointer to null, assign address later.
        /* #7 */ Node(const Node &temp);
        /* #8 */ Node & operator=(const Node &temp);
        ~Node() { };
        Item item;
        Node * previous;
        Node * next;
        long already_wait;
        long need_to_wait;
        /* #9 */ void set_alr(clock_t &now);
        /* 10 */ void set_ned(long need);
        // no need! because it's public!
        long alrtime() const { return already_wait; }
        long nedtime() const { return need_to_wait; }
    } ;
    
    enum { Q_SIZE = 10 };                           // For later use. Other ways doesn't actually biuld a object and                                                                   allocate storage for variables.
    // Private class members:
    Node * front;
    Node * rear;
    int items;
    const int qsize;                                // Const -- List initialize!
    const clock_t start;
    
    // Preemptive definations to prevent public copying:
    Queue(const Queue & q) : start(q.st()), qsize(q.qs()) { }           // Only for inilization! Because it doesn't do anything!
    Queue & operator=(const Queue & q) { return * this; }
    
public:
    
    // 2 const variables that are shared in this class for later use:
    static const int MIN_PER_HR = 60;
    static const int SECS_PER_MIN = 60;
    
    // (De)Constructors:
    /* 11 */ Queue(clock_t &st, int qs = Q_SIZE);
    /* 12 */ ~Queue();  // Releasse all the Node memory.
    
    // Class methods:
    
    /* 23 */ void reset(long need); // for loop, TRAVERSE!! change the first need! call set_alr() & set_ned(), alwait, needtowait, 
    
    // Judgements.
    bool isempty() const { return items == 0; }
    bool isfull() const { return items == qsize; }
    int queuecount() const { return items; }
    // void set_serial(Node & s) { s.serial_number = items; }
    clock_t when_trans(const Node & s) const { return (s.item.when() - start) / CLK_TCK; }
    clock_t st() const { return start; }
    Node * ft() const { return front; }
    Node * re() const { return rear; }
    long ftneed() const { return front->need_to_wait; }
    long ftalrw() const { return front->already_wait; }
    const int qs() const { return qsize; }
    // biuld / delete abstract data type.
    /* 13 */ bool enqueue(const Item & item);                // biuld / delete abstract data type.
    /* 14 */ bool dequeue(Item & item);
    
    /* 20 */ friend std::ofstream & operator<<(std::ofstream &fout, const Queue &line);
    
} ;




class Served {
private:
    class sNode {
    public:
        sNode() { sPrevious = nullptr; sNext = nullptr; };
        /* 15 */ sNode(const sNode &temp);
        /* 16 */ sNode & operator=(const sNode &temp);
        ~sNode() { };
        Item customer;
        sNode * sPrevious;
        sNode * sNext;
    } ;
    enum { upper_limit = 100 } ;
    sNode * first;
    sNode * last;
    int sItems;
    const int fsize;
    clock_t start;
    Served(const Served &q) : fsize(0) { }           // Only for inilization! Because it doesn't do anything!
    Served & operator=(const Served & q) { return * this; }
public:
    /* 17 */ Served(int qs = upper_limit);
    /* 18 */ ~Served();  // Releasse all the Node memory.

    bool isempty() const { return sItems == 0; }
    bool isfull() const { return sItems == fsize; }
    int servedcount() const { return sItems; }
    clock_t when_trans(const sNode & s) const { return (s.customer.when() - start) / CLK_TCK; }
    
    /* 19 */ bool enserved(const Item & customer);                // biuld / delete abstract data type.
   
    /* 21 */ friend std::ofstream & operator<<(std::ofstream &fout, const Served &line);
    
} ;
}









#endif /* newQueue_hpp */
