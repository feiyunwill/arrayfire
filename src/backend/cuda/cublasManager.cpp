/*******************************************************
 * Copyright (c) 2014, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#include <platform.hpp>
#include <err_common.hpp>
#include <cublasManager.hpp>

namespace cublas
{

const char *errorString(cublasStatus_t err)
{

    switch(err)
    {
    case    CUBLAS_STATUS_SUCCESS:              return "CUBLAS_STATUS_SUCCESS";
    case    CUBLAS_STATUS_NOT_INITIALIZED:      return "CUBLAS_STATUS_NOT_INITIALIZED";
    case    CUBLAS_STATUS_ALLOC_FAILED:         return "CUBLAS_STATUS_ALLOC_FAILED";
    case    CUBLAS_STATUS_INVALID_VALUE:        return "CUBLAS_STATUS_INVALID_VALUE";
    case    CUBLAS_STATUS_ARCH_MISMATCH:        return "CUBLAS_STATUS_ARCH_MISMATCH";
    case    CUBLAS_STATUS_MAPPING_ERROR:        return "CUBLAS_STATUS_MAPPING_ERROR";
    case    CUBLAS_STATUS_EXECUTION_FAILED:     return "CUBLAS_STATUS_EXECUTION_FAILED";
    case    CUBLAS_STATUS_INTERNAL_ERROR:       return "CUBLAS_STATUS_INTERNAL_ERROR";
#if CUDA_VERSION > 5050
    case    CUBLAS_STATUS_NOT_SUPPORTED:        return "CUBLAS_STATUS_NOT_SUPPORTED";
#endif
    default:                                    return "UNKNOWN";
    }
}

cublasHandle::cublasHandle()  : handle(0)
{
    CUBLAS_CHECK(cublasCreate(&handle));
    CUBLAS_CHECK(cublasSetStream(handle, cuda::getStream(cuda::getActiveDeviceId())));
}

cublasHandle::~cublasHandle()
{
    cublasDestroy(handle);
}

cublasHandle_t cublasHandle::get() const
{
    return handle;
}

}
