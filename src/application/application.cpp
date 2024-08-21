#include <holoscan/holoscan.hpp>
#include <getopt.h>
#include <iostream>

class App : public holoscan::Application {
public:
    void compose() override {
        using namespace holoscan;
    }

};

/** Helper function to parse the command line arguments */
bool parse_arguments(int argc, char **argv, std::string &config_name, std::string &input_path, std::string &model_path, std::string &output_path) {
    static struct option long_options[] = {
            {"input", required_argument, nullptr, 'i'},
            {"model", required_argument, nullptr, 'm'},
            {"output", required_argument, nullptr, 'o'},
            {nullptr, 0,                nullptr, 0}};

    while (int c = getopt_long(argc, argv, "i:m:o:",
                               long_options, nullptr)) {
        if (c == -1 || c == '?')
            break;

        switch (c) {
            case 'i':
                input_path = optarg;
                break;
            case 'm':
                model_path = optarg;
                break;
            case 'o':
                output_path = optarg;
                break;

            default:
                std::cout << "Unknown arguments returned: " << c << std::endl;
                return false;
        }
    }
    if (optind < argc) {
        config_name = argv[optind++];
    }
    return true;
}

int main(int argc, char *argv[]) {
    std::cout << "Hello World!";
    return 0;
}
