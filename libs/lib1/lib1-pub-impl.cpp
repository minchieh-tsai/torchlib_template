#include "lib1/lib1-pub-header.h"
#include <string>

namespace dodo {

// 构造函数：加载模型
DodoModel::DodoModel(const std::string& path) {
    try {
        module = torch::jit::load(path);
    } catch (const c10::Error& e) {
        std::cerr << "Error loading the model: " << e.what() << std::endl;
        throw;
    }
}

// 析构函数：这里我们不需要做额外的清理工作，因为智能指针会自动管理资源
DodoModel::~DodoModel() {}

// 静态工厂方法：创建DodoModel的唯一指针
std::unique_ptr<DodoModel> DodoModel::create(const std::string& path) {
    return std::make_unique<DodoModel>(path);
}

namespace {

torch::Tensor cvMatToTensorGray(const cv::Mat& image) {

    cv::Mat imageFloat;
    image.convertTo(imageFloat, CV_32F, 1.0 / 255.0);
    torch::Tensor tensorImage = torch::from_blob(imageFloat.data, {1, 1, imageFloat.rows, imageFloat.cols}, torch::kFloat);

    return tensorImage.clone(); 
}

cv::Mat tensorToCvMatGray(const torch::Tensor& tensorImage) {

    torch::Tensor tensor = tensorImage.detach().clone();
    tensor = tensor.squeeze(0);

    tensor = tensor.mul(255).clamp(0, 255).to(torch::kU8);
    int height = tensor.size(1);
    int width = tensor.size(2);

    cv::Mat image(cv::Size(width, height), CV_8UC1, tensor.data_ptr());

    return image.clone(); 
}

void saveImgs(const std::string& pathWithPrefix, const std::vector<cv::Mat>& imgs) {
    for (size_t i = 0; i < imgs.size(); ++i) {
        if (cv::imwrite(pathWithPrefix + std::to_string(i) + ".png", imgs[i])) {
            std::cout << "Saved result image " << i << " to " << pathWithPrefix << std::endl;
        } else {
            std::cerr << "Failed to save result image " << i << " to " << pathWithPrefix << std::endl;
        }
    }
}

}

// 推理方法：对输入图像进行推理
std::vector<cv::Mat> DodoModel::inference(const std::vector<cv::Mat>& imgs) {
    std::vector<cv::Mat> results;

    for (const auto& img : imgs) {

        auto input_tensor = cvMatToTensorGray(img);
        auto output = module.forward({input_tensor}).toTensor();
        
        // 将Tensor转换为cv::Mat
        auto result = tensorToCvMatGray(output);

        cv::imwrite("result/temp_imgs_result.png", result);

        results.push_back(result.clone()); // clone确保数据正确
    }

    saveImgs("result/temp_imgs_", imgs);
    saveImgs("result/temp_results_", results);

    return results;
}

}   // namespace dodo