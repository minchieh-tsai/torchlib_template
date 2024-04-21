
#include <iostream>
#include <lib1/lib1-pub-header.h>
#include <torch/torch.h>
#include <torch/script.h>

// test tempalate
// int main(int argNum, char **argValue) {
//   std::cout << "1 + 2 = " << lib1::sum(1, 2) << '\n';
//   return 0;
// }

// test libtorch
// int main()
// {
//     torch::DeviceType device_type = torch::kCPU;
//     if (torch::cuda::is_available()) {
//         std::cout << "CUDA available! Predicting on GPU." << std::endl;
//         device_type = torch::kCUDA;
//     }
//     else {
//         std::cout << "Predicting on CPU." << std::endl;
//         device_type = torch::kCPU;
//     }
//     torch::Device device(device_type);
//     torch::Tensor tensor = torch::eye(3);
//     tensor = tensor.to(device_type);
//     // std:cout<<tensor<<std::endl;
//     std::cout<<"hello torch"<<std::endl;
//     std::cout<<tensor<<std::endl;
//     return 0;
// }


int main(int argc, const char* argv[]) {
  if (argc != 2) {
    std::cerr << "usage: example-app <path-to-exported-script-module>\n";
    return -1;
  }
  const std::string modelPath(argv[1]);

//   std::cout << "argv[0]:" << argv[0] << std::endl;
//   std::cout << "argv[1]:" << argv[1] << std::endl;

  torch::jit::script::Module module;
  try {
    // Deserialize the ScriptModule from a file using torch::jit::load().
    module = torch::jit::load(modelPath.c_str());
  }
  catch (const c10::Error& e) {
    std::cerr << "error loading the model\n";
    return -1;
  }
  std::cout << "Model "<< argv[1]<<" loaded fine\n";

  // Create a vector of inputs.
  std::vector<torch::jit::IValue> inputs;
  inputs.push_back(torch::ones({1, 3, 1024, 1024}));

  // Execute the model and turn its output into a tensor.
  at::Tensor output = module.forward(inputs).toTensor();
  torch::Tensor slice = output[0][0][0].slice(0, 0, 100);
  std::cout << slice << "\n";

}
