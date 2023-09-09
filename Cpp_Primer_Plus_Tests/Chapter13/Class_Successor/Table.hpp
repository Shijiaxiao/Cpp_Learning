//
//  Table.hpp
//  class successor
//
//  Created by 史家箫 on 2022/4/24.
//

#ifndef Table_hpp
#define Table_hpp

#include <string>
using std::string;
class TableTennis {
private:
    const string firstname;
    const string lastname;
    bool hasTable;
public:
    TableTennis(const string & fn = "none", const string & ln = "none", bool ht = false);
    virtual ~TableTennis() {}
    void Name() const; 
    bool HasTable() const { return hasTable; }
    virtual void ResetTable(bool v) { hasTable = v; }
    // void ResetTable(int a, bool v) { hasTable = v; }
};


class RatedPlayer : public TableTennis {
private:
    unsigned int rating; // Add a data member.
public:
    RatedPlayer(unsigned int r = 0, const string & fn = "none", const string & ln = "none", bool ht = false);
    RatedPlayer(unsigned int r, const TableTennis & tp);
    ~RatedPlayer() {}
    unsigned int Rating () const { return rating; }     // Add a method.
    virtual void ResetRating (unsigned int r) { rating = r; }   // Add a method.
};

#endif /* Table_hpp */
