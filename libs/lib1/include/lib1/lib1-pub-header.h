#ifndef LIB1_PUB_HEADER
#define LIB1_PUB_HEADER

#include <string>
#include <vector>
#include <memory>
#include <opencv2/opencv.hpp>

namespace dodo {


class DodoModel {
public:
    DodoModel(const std::string& path);
    ~DodoModel();
    static std::unique_ptr<DodoModel> create(const std::string& path);
    std::vector<cv::Mat> inference(const std::vector<cv::Mat>& imgs);

private:
    torch::jit::script::Module module;
}

}

#endif