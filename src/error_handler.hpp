#pragma once

#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3/support/utility/error_reporting.hpp>

struct error_handler {
    template <typename Iterator, typename Exception, typename Context>
    boost::spirit::x3::error_handler_result on_error(
        Iterator& first, Iterator const& last
      , Exception const& x, Context const& context)
    {
        namespace x3 = boost::spirit::x3;

        auto& error_handler = x3::get<x3::error_handler_tag>(context).get();
        std::string message = "Error! Expecting: " + x.which() + " here:";
        error_handler(x.where(), message);
        return x3::error_handler_result::fail;
    }
};