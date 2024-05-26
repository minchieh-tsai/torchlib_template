#include <"lib1-pub-header.h">

namespace dodo {

DodoModel::DodoModel(const std::string& path) {
  module = torch::jit::load(modelPath.c_str());
}

DodoModel::~DodoModel() {
  
}



} // namespace lib1