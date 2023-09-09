//
//  Table.cpp
//  class successor
//
//  Created by 史家箫 on 2022/4/24.
//

#include "Table.hpp"
#include <iostream>

TableTennis::TableTennis(const string & fn, const string & ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht) {}

void TableTennis::Name() const { std::cout << lastname << ", " << firstname; }

RatedPlayer::RatedPlayer(unsigned int r, const string & fn, const string & ln, bool ht) : TableTennis(fn, ln, ht) {
    rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennis & tp) : TableTennis(tp) {
    rating = r;
}
