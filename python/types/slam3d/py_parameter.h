#pragma once

#include "g2o/types/slam3d/parameter_camera.h"
#include "g2o/types/slam3d/parameter_se3_offset.h"
#include "g2o/types/slam3d/parameter_stereo_camera.h"
#include "g2opy.h"

namespace g2o {

inline void declareSalm3dParameter(py::module& m) {
  py::class_<ParameterSE3Offset, Parameter,
             std::shared_ptr<ParameterSE3Offset>>(m, "ParameterSE3Offset")
      .def(py::init<>())

      .def("set_param", &ParameterSE3Offset::setParam)
      .def("set_param_data", &ParameterSE3Offset::setParameterData)
      .def("param", &ParameterSE3Offset::param)
      .def("inverse_offset", &ParameterSE3Offset::inverseOffset);

  // class G2O_TYPES_SLAM3D_API CacheSE3Offset: public Cache
  // class G2O_TYPES_SLAM3D_API CacheSE3OffsetDrawAction: public DrawAction

  py::class_<ParameterCamera, ParameterSE3Offset,
             std::shared_ptr<ParameterCamera>>(m, "ParameterCamera")
      .def(py::init<>())
      .def("setKcam", &ParameterCamera::setKcam)
      .def("set_param", &ParameterCamera::setParam)
      .def("Kcam", &ParameterCamera::Kcam)
      .def("invKcam", &ParameterCamera::invKcam)
      .def("Kcam_inverseOffsetR", &ParameterCamera::Kcam_inverseOffsetR);

  // class G2O_TYPES_SLAM3D_API CacheCamera: public CacheSE3Offset
  // class G2O_TYPES_SLAM3D_API CacheCameraDrawAction: public DrawAction

  py::class_<ParameterStereoCamera, ParameterCamera,
             std::shared_ptr<ParameterStereoCamera>>(m, "ParameterStereoCamera")
      .def(py::init<>())
      .def("set_baseline", &ParameterStereoCamera::setBaseline)
      .def("baseline", &ParameterStereoCamera::baseline);
}

}  // namespace g2o
