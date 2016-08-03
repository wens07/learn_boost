#include <iostream>
#include <string>
#include <stdint.h>

#include <boost/program_options.hpp>



int main(int argc, char **argv)
{
    // create a description variable
    boost::program_options::options_description desc("All options");

    // add options to the description variable
    /**
      *  @param: the option name in commandline
      *  @param: the type of the option name
      *  @param: the description of the option
      */
    desc.add_options()
            ("help", "produce help message")
            ("name", boost::program_options::value<std::string>(), "the name of the user")
            ("age", boost::program_options::value<uint8_t>(), "the age of the user");

    // the variable to store the description variable
    boost::program_options::variables_map vm;

    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
    boost::program_options::notify(vm);

    // add messages for --help
    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return 1;
    }

}

