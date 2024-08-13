#include <holoscan/holoscan.hpp>
#include <holoscan/operators/video_stream_replayer/video_stream_replayer.hpp>
#include <holoscan/operators/video_stream_recorder/video_stream_recorder.hpp>
#include <holoscan/operators/format_converter/format_converter.hpp>
#include <holoscan/operators/inference/inference.hpp>
#include <holoscan/operators/segmentation_postprocessor/segmentation_postprocessor.hpp>
#include <holoscan/operators/holoviz/holoviz.hpp>
#include <getopt.h>
#include <iostream>
#include "../operators/segmentation_color_mapper.hpp"
#include "../operators/tensor_loggger.hpp"
#include "../operators/segmentation_overlay.hpp"
#include "../operators/cv2png_recorder.hpp"

class App : public holoscan::Application {
public:
    void compose() override {
        using namespace holoscan;
    }

};

/** Helper function to parse the command line arguments */
bool parse_arguments(int argc, char **argv, std::string &config_name, std::string &data_path, std::string &output_path) {
    static struct option long_options[] = {
            {"data", required_argument, nullptr, 'd'},
            {"output", required_argument, nullptr, 'o'},
            {nullptr, 0,                nullptr, 0}};

    while (int c = getopt_long(argc, argv, "d:o:",
                               long_options, nullptr)) {
        if (c == -1 || c == '?')
            break;

        switch (c) {
            case 'd':
                data_path = optarg;
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
}
