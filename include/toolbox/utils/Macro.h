// ----------------------------------------------------------------------------
// -                        TOOLBOX: www.TOOLBOX.org                            -
// ----------------------------------------------------------------------------
// Copyright (c) 2018-2023 www.TOOLBOX.org
// SPDX-License-Identifier: MIT
// ----------------------------------------------------------------------------

#pragma once

#include <cassert>

// https://gcc.gnu.org/wiki/Visibility updated to use C++11 attribute syntax
#if defined(_WIN32) || defined(__CYGWIN__)
#define TOOLBOX_DLL_IMPORT __declspec(dllimport)
#define TOOLBOX_DLL_EXPORT __declspec(dllexport)
#define TOOLBOX_DLL_LOCAL
#else
#define TOOLBOX_DLL_IMPORT [[gnu::visibility("default")]]
#define TOOLBOX_DLL_EXPORT [[gnu::visibility("default")]]
#define TOOLBOX_DLL_LOCAL [[gnu::visibility("hidden")]]
#endif

#ifdef TOOLBOX_STATIC
#define TOOLBOX_API
#define TOOLBOX_LOCAL
#else
#define TOOLBOX_LOCAL TOOLBOX_DLL_LOCAL
#if defined(TOOLBOX_ENABLE_DLL_EXPORTS)
#define TOOLBOX_API TOOLBOX_DLL_EXPORT
#else
#define TOOLBOX_API TOOLBOX_DLL_IMPORT
#endif
#endif

// Compiler-specific function macro.
// Ref: https://stackoverflow.com/a/4384825
#ifdef _WIN32
#define TOOLBOX_FUNCTION __FUNCSIG__
#else
#define TOOLBOX_FUNCTION __PRETTY_FUNCTION__
#endif

// Assertion for CUDA device code.
// Usage:
//     TOOLBOX_ASSERT(condition);
//     TOOLBOX_ASSERT(condition && "Error message");
// For host-only code, consider using utility::LogError();
#define TOOLBOX_ASSERT(...) assert((__VA_ARGS__))
