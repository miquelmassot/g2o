// g2o - General Graph Optimization
// Copyright (C) 2011 R. Kuemmerle, G. Grisetti, W. Burgard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
// TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
// PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
// TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef G2O_EDGE_SE3_CALIB_H
#define G2O_EDGE_SE3_CALIB_H

#include "g2o/core/base_variable_sized_edge.h"
#include "g2o/core/eigen_types.h"
#include "g2o/types/slam3d/type_traits_isometry3.h"  // IWYU pragma: keep
#include "g2o_types_slam3d_addons_api.h"

namespace g2o {
/**
 * \brief Landmark measurement that also calibrates an offset for the landmark
 * measurement
 */
class EdgeSE3Calib
    : public BaseVariableSizedEdge<6, Isometry3>  // Avoid redefinition of
                                                  // BaseEdge in MSVC
{
 public:
  G2O_TYPES_SLAM3D_ADDONS_API
  EdgeSE3Calib();

  G2O_TYPES_SLAM3D_ADDONS_API void computeError() override;
};

}  // namespace g2o

#endif
