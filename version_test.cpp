#define BOOST_TEST_MODULE lib_test_module

#include <boost/test/unit_test.hpp>

#include "lib.h"

BOOST_AUTO_TEST_SUITE( lib_test_suite )

BOOST_AUTO_TEST_CASE( version_test )
{
    BOOST_CHECK(version() > 0);
}

BOOST_AUTO_TEST_SUITE_END()

