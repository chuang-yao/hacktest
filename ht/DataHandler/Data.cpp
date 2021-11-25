//
// Created by Chuang Yao on 11/10/2021.
//

#include "ht/DataHandler/Data.hpp"

namespace HackTest {

Data::Data(std::string src, Type tp) : source_(std::move(src)), type_(tp) {}

} // namespace HackTest
