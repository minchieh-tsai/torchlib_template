#include "lib1/lib1-pub-header.h"

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

// 推理方法：对输入图像进行推理
std::vector<cv::Mat> DodoModel::inference(const std::vector<cv::Mat>& imgs) {
    std::vector<cv::Mat> results;

    for (const auto& img : imgs) {
        // 将cv::Mat转换为Tensor
        auto input_tensor = torch::from_blob(img.data, {1, img.rows, img.cols, 3}, torch::kByte);
        input_tensor = input_tensor.permute({0, 3, 1, 2}); // 调整维度
        input_tensor = input_tensor.to(torch::kFloat); // 转换类型

        // 推理
        auto output = module.forward({input_tensor}).toTensor();
        
        // 将Tensor转换为cv::Mat
        auto result = cv::Mat(output.size(2), output.size(3), CV_32F, output.data_ptr<float>());
        results.push_back(result.clone()); // clone确保数据正确
    }

    return results;
}

}   // namespace dodo