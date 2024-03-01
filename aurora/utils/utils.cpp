// SPDX-FileCopyrightText: 2023 Open Mobile Platform LLC <community@omp.ru>
// SPDX-License-Identifier: BSD-3-Clause

#include "utils.h"

using namespace RuntimeManager;

namespace Utils {

    QString errorCodeToString(const Error::Code &code) 
    {
        switch (code) {
        case Error::Code::NoError:
            return "NoError";
        case Error::Code::Failed:
            return "Failed";
        case Error::Code::HandlerNotFound:
            return "HandlerNotFound";
        case Error::Code::HandlerFailed:
            return "HandlerFailed";
        case Error::Code::InvalidParameters:
            return "InvalidParameters";
        case Error::Code::NotImplemented:
            return "NotImplemented";
        case Error::Code::PermissionDenied:
            return "PermissionDenied";
        case Error::Code::ProcessNotHandled:
            return "ProcessNotHandled";
        case Error::Code::ApplicationNotRunning:
            return "ApplicationNotRunning";
        case Error::Code::ApplicationAlreadyRunning:
            return "ApplicationAlreadyRunning";
        default:
            return "Undefined";
        }
    }
}