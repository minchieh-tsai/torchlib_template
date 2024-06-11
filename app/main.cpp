
#include <iostream>
#include <lib1/lib1-pub-header.h>
#include <torch/torch.h>
#include <torch/script.h>
#include <opencv2/opencv.hpp>

#include <filesystem>  
namespace fs = std::filesystem;


// torch::Tensor cvMatToTensorGray(const cv::Mat& image) {

//     cv::Mat imageFloat;
//     image.convertTo(imageFloat, CV_32F, 1.0 / 255.0);
//     torch::Tensor tensorImage = torch::from_blob(imageFloat.data, {1, 1, imageFloat.rows, imageFloat.cols}, torch::kFloat);

//     return tensorImage.clone(); 
// }


// cv::Mat tensorToCvMatGray(const torch::Tensor& tensorImage) {

//     torch::Tensor tensor = tensorImage.detach().clone();
//     tensor = tensor.squeeze(0);

//     tensor = tensor.mul(255).clamp(0, 255).to(torch::kU8);
//     int height = tensor.size(1);
//     int width = tensor.size(2);

//     cv::Mat image(cv::Size(width, height), CV_8UC1, tensor.data_ptr());

//     return image.clone(); 
// }


// int main(int argc, const char* argv[]) {

//     std::vector<cv::Mat> images;
//     std::string folderPath = "external_libs/testset"; 
    

//     for (const auto& entry : fs::directory_iterator(folderPath)) {
//         if (entry.is_regular_file() && entry.path().extension() == ".png") {
//             cv::Mat image = cv::imread(entry.path().string(), cv::IMREAD_COLOR);

//             if (!image.empty()) {
//                 images.push_back(image);
//                 std::cout << "Loaded image: " << entry.path() << std::endl;
//                 std::cout << "Loaded image: " << image.size() << std::endl;
//             } else {
//                 std::cerr << "Failed to load image: " << entry.path() << std::endl;
//             }
//         }
//     }

//     std::cout << "Total loaded images: " << images.size() << std::endl;



//   if (argc != 2) {
//     std::cerr << "usage: example-app <path-to-exported-script-module>\n";
//     return -1;
//   }
//   const std::string modelPath(argv[1]);

// //   std::cout << "argv[0]:" << argv[0] << std::endl;
// //   std::cout << "argv[1]:" << argv[1] << std::endl;

//   torch::jit::script::Module module;
//   try {
//     // Deserialize the ScriptModule from a file using torch::jit::load().
//     module = torch::jit::load(modelPath.c_str());
//   }
//   catch (const c10::Error& e) {
//     std::cerr << "error loading the model\n";
//     return -1;
//   }
//   std::cout << "Model "<< argv[1]<<" loaded fine\n";


//   for (auto& img : images) {
//         if (!img.empty()) {
//             torch::Tensor tensor = cvMatToTensorGray(img);
//             torch::Tensor output = module.forward({tensor}).toTensor();
//             std::cout << output.sizes() << std::endl;

//             cv::Mat mat_output  = tensorToCvMatGray(output);
//             bool isSaved = cv::imwrite("external_libs/output_dir/test.jpg", mat_output);
//         }
//     }


  

// }

int main(int argc, const char* argv[]) {

    std::vector<cv::Mat> images;
    std::string folderPath = "external_libs/testset"; 

    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".png") {
            cv::Mat image = cv::imread(entry.path().string(), cv::IMREAD_COLOR);

            if (!image.empty()) {
                images.push_back(image);
                std::cout << "Loaded image: " << entry.path() << std::endl;
                std::cout << "Loaded image: " << image.size() << std::endl;
            } else {
                std::cerr << "Failed to load image: " << entry.path() << std::endl;
            }
        }
    }

    std::cout << "Total loaded images: " << images.size() << std::endl;



    std::unique_ptr<dodo::DodoModel> dodoModel = dodo::DodoModel::create("./external_libs/model/pretrained_script.pt");
    auto output = dodoModel->inference(images);

    std::cout << "Total output images: " << output.size() << std::endl;

}