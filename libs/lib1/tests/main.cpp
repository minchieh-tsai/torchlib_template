#include <cstdlib>
#include <iostream>
#include <lib1/lib1-pub-header.h>

int main(int, char **) {
    std::unique_ptr<dodo::DodoModel> dodoModel = dodo::DodoModel::create("./external_libs/model/pretrained_script.pt");
    return EXIT_SUCCESS;
}
