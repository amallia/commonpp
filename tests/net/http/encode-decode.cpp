/*
 * File: tests/net/http/encode-decode.cpp
 * Part of commonpp.
 *
 * Distributed under the 2-clause BSD licence (See LICENCE.TXT file at the
 * project root).
 *
 * Copyright (c) 2015 Thomas Sanchez.  All rights reserved.
 *
 */

#include <boost/test/unit_test.hpp>
#include <commonpp/net/http/URL.hpp>

using namespace commonpp::net::http;

// same test in httpp
BOOST_AUTO_TEST_CASE(encode_decode)
{
    const std::string ENCODED_URL =
        "Type+or+paste+in+the+text+you+want+to+HTML+encode%2c%0d%0a+then+press+"
        "the+%e2%80%98Encode%e2%80%99+button%2c+or+read+a+brief+%0d%"
        "0aexplanation+of+the+process+of+HTML+encoding.%0d%0a%0d%0a";

    const std::string ENCODED_URL_PCT =
        "Type%20or%20paste%20in%20the%20text%20you%20want%20to%20HTML%20encode%"
        "2C%0D%0A%20then%20press%20the%20%E2%80%98Encode%E2%80%99%20button%2C%"
        "20or%20read%20a%20brief%20%0D%0Aexplanation%20of%20the%20process%20of%"
        "20HTML%20encoding.%0D%0A%0D%0A";

    const std::string DECODED_URL = "Type or paste in the text you want to "
                                    "HTML encode,\r\n then press the ‘Encode’ "
                                    "button, or read a brief \r\nexplanation of "
                                    "the process of HTML encoding.\r\n\r\n";

    BOOST_CHECK_EQUAL(url_decode(ENCODED_URL), DECODED_URL);
    BOOST_CHECK_EQUAL(url_encode(DECODED_URL), ENCODED_URL_PCT);
}