// MIT License
//
// Copyright (c) 2020 Lennart Braun
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "tensor_op_factory.h"

#include <stdexcept>
#include "tensor/tensor_op.h"

#include <fmt/format.h>

namespace MOTION::tensor {

std::pair<ENCRYPTO::ReusableFiberPromise<IntegerValues<std::uint32_t>>, TensorCP>
TensorOpFactory::make_arithmetic_32_tensor_input_my(const TensorDimensions&) {
  throw std::logic_error(
      fmt::format("{} does not support arithmetic 32 bit inputs", get_provider_name()));
}

std::pair<ENCRYPTO::ReusableFiberPromise<IntegerValues<std::uint64_t>>, TensorCP>
TensorOpFactory::make_arithmetic_64_tensor_input_my(const TensorDimensions&) {
  throw std::logic_error(
      fmt::format("{} does not support arithmetic 64 bit inputs", get_provider_name()));
}

TensorCP TensorOpFactory::make_arithmetic_32_tensor_input_other(const TensorDimensions&) {
  throw std::logic_error(
      fmt::format("{} does not support arithmetic 32 bit inputs", get_provider_name()));
}

TensorCP TensorOpFactory::make_arithmetic_64_tensor_input_other(const TensorDimensions&) {
  throw std::logic_error(
      fmt::format("{} does not support arithmetic 64 bit inputs", get_provider_name()));
}

// share inputs
std::pair<std::vector<ENCRYPTO::ReusableFiberPromise<IntegerValues<uint32_t>>>, TensorCP >
TensorOpFactory::make_arithmetic_32_tensor_input_shares(const TensorDimensions&){
  throw std::logic_error(
      fmt::format("{} does not support arithmetic 32 bit inputs"));

}

std::pair<std::vector<ENCRYPTO::ReusableFiberPromise<IntegerValues<uint64_t>>>, TensorCP >
TensorOpFactory::make_arithmetic_64_tensor_input_shares(const TensorDimensions&) {
  throw std::logic_error(
      fmt::format("{} does not support arithmetic 64 bit inputs"));
}

ENCRYPTO::ReusableFiberFuture<IntegerValues<std::uint32_t>>
TensorOpFactory::make_arithmetic_32_tensor_output_my(const TensorCP&) {
  throw std::logic_error(
      fmt::format("{} does not support arithmetic 32 bit outputs", get_provider_name()));
}

ENCRYPTO::ReusableFiberFuture<IntegerValues<std::uint64_t>>
TensorOpFactory::make_arithmetic_64_tensor_output_my(const TensorCP&) {
  throw std::logic_error(
      fmt::format("{} does not support arithmetic 64 bit outputs", get_provider_name()));
}

void TensorOpFactory::make_arithmetic_tensor_output_other(const TensorCP&) {
  throw std::logic_error(
      fmt::format("{} does not support arithmetic outputs", get_provider_name()));
}

tensor::TensorCP TensorOpFactory::make_tensor_conversion(MPCProtocol, const tensor::TensorCP) {
  throw std::logic_error(
      fmt::format("{} does not support conversions to other protocols", get_provider_name()));
}

tensor::TensorCP TensorOpFactory::make_tensor_flatten_op(const tensor::TensorCP, std::size_t) {
  throw std::logic_error(
      fmt::format("{} does not support the Flatten operation", get_provider_name()));
}

tensor::TensorCP TensorOpFactory::make_tensor_conv2d_op(const tensor::Conv2DOp&,
                                                        const tensor::TensorCP,
                                                        const tensor::TensorCP,
                                                        const tensor::TensorCP, std::size_t) {
  throw std::logic_error(
      fmt::format("{} does not support the Conv2D operation", get_provider_name()));
}

tensor::TensorCP TensorOpFactory::make_tensor_conv2d_op(const tensor::Conv2DOp& op,
                                                        const tensor::TensorCP input,
                                                        const tensor::TensorCP kernel,
                                                        std::size_t) {
  return make_tensor_conv2d_op(op, input, kernel, nullptr);
}

tensor::TensorCP TensorOpFactory::make_tensor_gemm_op(const tensor::GemmOp&, const tensor::TensorCP,
                                                      const tensor::TensorCP, std::size_t) {
  throw std::logic_error(
      fmt::format("{} does not support the Gemm operation", get_provider_name()));
}

tensor::TensorCP TensorOpFactory::make_tensor_hamm_op(const tensor::HammOp&, const tensor::TensorCP,
                                                      const tensor::TensorCP, std::size_t) {
  throw std::logic_error(
      fmt::format("{} does not support the Hamm operation", get_provider_name()));
}

tensor::TensorCP TensorOpFactory::make_tensor_sqr_op(const tensor::TensorCP, std::size_t) {
  throw std::logic_error(fmt::format("{} does not support the Sqr operation", get_provider_name()));
}

tensor::TensorCP TensorOpFactory::make_tensor_relu_op(const tensor::TensorCP) {
  throw std::logic_error(
      fmt::format("{} does not support the ReLU operation", get_provider_name()));
}

tensor::TensorCP TensorOpFactory::make_tensor_relu_op(const tensor::TensorCP,
                                                      const tensor::TensorCP) {
  throw std::logic_error(
      fmt::format("{} does not support the ReLU (arith x Bool) operation", get_provider_name()));
}

tensor::TensorCP TensorOpFactory::make_tensor_maxpool_op(const tensor::MaxPoolOp&,
                                                         const tensor::TensorCP) {
  throw std::logic_error(
      fmt::format("{} does not support the MaxPool operation", get_provider_name()));
}

tensor::TensorCP TensorOpFactory::make_tensor_avgpool_op(const tensor::AveragePoolOp&,
                                                         const tensor::TensorCP, std::size_t) {
  throw std::logic_error(
      fmt::format("{} does not support the AveragePool operation", get_provider_name()));
}

tensor::TensorCP TensorOpFactory::make_tensor_negate(const tensor::TensorCP) {
  throw std::logic_error(
      fmt::format("{} does not support the Negate operation", get_provider_name()));
}

tensor::TensorCP TensorOpFactory::make_tensor_constMul_op(const tensor::TensorCP,const std::vector<uint64_t>) {
  throw std::logic_error(
      fmt::format("{} does not support the Const Multiplication operation", get_provider_name()));
}

// Haritha cosnt matrix mult***** (Given model in clear to both parties and data the inform of shares)
tensor::TensorCP TensorOpFactory::make_tensor_constMatrix_Mul_op(const tensor::GemmOp& gemm_op, 
                                                            const std::vector<uint64_t> W, const tensor::TensorCP X, 
                                                            const std::size_t fractional_bits){
throw std::logic_error(
      fmt::format("{} does not support the Const Matrix Multiplication operation", get_provider_name())); 
}

tensor::TensorCP TensorOpFactory::make_tensor_constAdd_op(const tensor::TensorCP,const uint64_t) {
  throw std::logic_error(
      fmt::format("{} does not support the Const Multiplication operation", get_provider_name()));
}

tensor::TensorCP TensorOpFactory::make_tensor_add_op(const tensor::TensorCP,const tensor::TensorCP) {
  throw std::logic_error(
      fmt::format("{} does not support the Tensor addition operation", get_provider_name()));
}


std::vector<tensor::TensorCP> TensorOpFactory::make_tensor_split_op(const tensor::TensorCP) {
  throw std::logic_error(
      fmt::format("{} does not support the Split operation", get_provider_name()));
}

tensor::TensorCP TensorOpFactory::make_tensor_gt_op(const tensor::MaxPoolOp&,
                                                         const tensor::TensorCP) {
  throw std::logic_error(
      fmt::format("{} does not support the GT operation", get_provider_name()));
}

tensor::TensorCP TensorOpFactory::make_tensor_join_op(const tensor::JoinOp&, const tensor::TensorCP,
                                                      const tensor::TensorCP, std::size_t) {
  throw std::logic_error(
      fmt::format("{} does not support the Join operation", get_provider_name()));
}

}  // namespace MOTION::tensor
