#pragma once

// @generated by torchgen/gen.py from NativeFunction.h

#include <c10/core/Scalar.h>
#include <c10/core/Storage.h>
#include <c10/core/TensorOptions.h>
#include <c10/util/Deprecated.h>
#include <c10/util/Optional.h>
#include <c10/core/QScheme.h>
#include <ATen/core/Reduction.h>
#include <ATen/core/Tensor.h>
#include <tuple>
#include <vector>
#include <ATen/ops/any_meta.h>

namespace at {
namespace native {
struct TORCH_API structured_any_out : public at::meta::structured_any_dim {
void impl(const at::Tensor & self, int64_t dim, bool keepdim, const at::Tensor & out);
};
TORCH_API at::Tensor any_dims_default(const at::Tensor & self, at::OptionalIntArrayRef dim=c10::nullopt, bool keepdim=false);
TORCH_API at::Tensor & any_dims_out_default(const at::Tensor & self, at::OptionalIntArrayRef dim, bool keepdim, at::Tensor & out);
struct TORCH_API structured_any_dims_out : public at::meta::structured_any_dims {
void impl(const at::Tensor & self, at::OptionalIntArrayRef dim, bool keepdim, const at::Tensor & out);
};
TORCH_API at::Tensor any(const at::Tensor & self, at::Dimname dim, bool keepdim=false);
TORCH_API at::Tensor & any_out(const at::Tensor & self, at::Dimname dim, bool keepdim, at::Tensor & out);
struct TORCH_API structured_any_all_out : public at::meta::structured_any {
void impl(const at::Tensor & self, const at::Tensor & out);
};
TORCH_API at::Tensor any_sparse(const at::Tensor & self);
} // namespace native
} // namespace at
