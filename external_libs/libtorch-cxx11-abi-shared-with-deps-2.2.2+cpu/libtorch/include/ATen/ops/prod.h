#pragma once

// @generated by torchgen/gen.py from Function.h

#include <ATen/Context.h>
#include <ATen/DeviceGuard.h>
#include <ATen/TensorUtils.h>
#include <ATen/TracerMode.h>
#include <ATen/core/Generator.h>
#include <ATen/core/Reduction.h>
#include <ATen/core/Tensor.h>
#include <c10/core/Scalar.h>
#include <c10/core/Storage.h>
#include <c10/core/TensorOptions.h>
#include <c10/util/Deprecated.h>
#include <c10/util/Optional.h>



#include <ATen/ops/prod_ops.h>

namespace at {


// aten::prod(Tensor self, *, ScalarType? dtype=None) -> Tensor
inline at::Tensor prod(const at::Tensor & self, c10::optional<at::ScalarType> dtype=c10::nullopt) {
    return at::_ops::prod::call(self, dtype);
}

// aten::prod.dim_int(Tensor self, int dim, bool keepdim=False, *, ScalarType? dtype=None) -> Tensor
inline at::Tensor prod(const at::Tensor & self, int64_t dim, bool keepdim=false, c10::optional<at::ScalarType> dtype=c10::nullopt) {
    return at::_ops::prod_dim_int::call(self, dim, keepdim, dtype);
}

// aten::prod.int_out(Tensor self, int dim, bool keepdim=False, *, ScalarType? dtype=None, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & prod_out(at::Tensor & out, const at::Tensor & self, int64_t dim, bool keepdim=false, c10::optional<at::ScalarType> dtype=c10::nullopt) {
    return at::_ops::prod_int_out::call(self, dim, keepdim, dtype, out);
}
// aten::prod.int_out(Tensor self, int dim, bool keepdim=False, *, ScalarType? dtype=None, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & prod_outf(const at::Tensor & self, int64_t dim, bool keepdim, c10::optional<at::ScalarType> dtype, at::Tensor & out) {
    return at::_ops::prod_int_out::call(self, dim, keepdim, dtype, out);
}

// aten::prod.dim_Dimname(Tensor self, Dimname dim, bool keepdim=False, *, ScalarType? dtype=None) -> Tensor
inline at::Tensor prod(const at::Tensor & self, at::Dimname dim, bool keepdim=false, c10::optional<at::ScalarType> dtype=c10::nullopt) {
    return at::_ops::prod_dim_Dimname::call(self, dim, keepdim, dtype);
}

// aten::prod.Dimname_out(Tensor self, Dimname dim, bool keepdim=False, *, ScalarType? dtype=None, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & prod_out(at::Tensor & out, const at::Tensor & self, at::Dimname dim, bool keepdim=false, c10::optional<at::ScalarType> dtype=c10::nullopt) {
    return at::_ops::prod_Dimname_out::call(self, dim, keepdim, dtype, out);
}
// aten::prod.Dimname_out(Tensor self, Dimname dim, bool keepdim=False, *, ScalarType? dtype=None, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & prod_outf(const at::Tensor & self, at::Dimname dim, bool keepdim, c10::optional<at::ScalarType> dtype, at::Tensor & out) {
    return at::_ops::prod_Dimname_out::call(self, dim, keepdim, dtype, out);
}

// aten::prod.out(Tensor self, *, ScalarType? dtype=None, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & prod_out(at::Tensor & out, const at::Tensor & self, c10::optional<at::ScalarType> dtype=c10::nullopt) {
    return at::_ops::prod_out::call(self, dtype, out);
}
// aten::prod.out(Tensor self, *, ScalarType? dtype=None, Tensor(a!) out) -> Tensor(a!)
inline at::Tensor & prod_outf(const at::Tensor & self, c10::optional<at::ScalarType> dtype, at::Tensor & out) {
    return at::_ops::prod_out::call(self, dtype, out);
}

}
