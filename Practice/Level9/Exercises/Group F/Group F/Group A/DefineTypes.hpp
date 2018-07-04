//
//  DefineTypes.h
//  Group A
//
//  Use BOOST_STRONG_TYPEDEF to create a new type "name", which will be
//  substitutable for the original type but still of distinct type
//
//  Created by Changheng Chen on 2/20/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef DefineTypes_hpp
#define DefineTypes_hpp

#include <boost/serialization/strong_typedef.hpp>

BOOST_STRONG_TYPEDEF(double, type_T);
BOOST_STRONG_TYPEDEF(double, type_K);
BOOST_STRONG_TYPEDEF(double, type_sig);
BOOST_STRONG_TYPEDEF(double, type_r);
BOOST_STRONG_TYPEDEF(double, type_b);
BOOST_STRONG_TYPEDEF(double, type_S);

#endif /* DefineTypes_hpp */
