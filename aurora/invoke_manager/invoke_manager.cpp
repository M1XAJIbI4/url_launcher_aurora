// SPDX-FileCopyrightText: 2023 Open Mobile Platform LLC <community@omp.ru>
// SPDX-License-Identifier: BSD-3-Clause

#include "invoke_manager.h"
#include "../utils/utils.h"

namespace Invoker {
    InvokeManager& InvokeManager::instance() 
    {
        static InvokeManager instance;
        return instance;
    }

    void InvokeManager::init() 
    {
        connect(
            m_invoker.data(),
            &RuntimeManager::IntentsInvoker::replyReceived,
            this,
            &InvokeManager::onHandleReply
        );
    }

    void InvokeManager::invoke(const QString& name, const QJsonObject& hints, const QJsonObject& param) 
    {
        m_invoker->invoke(name, hints, param);
    }

    InvokeManager::InvokeManager(QObject* parent)
        : QObject(parent)
        , m_invoker(new RuntimeManager::IntentsInvoker) 
    {}

    void InvokeManager::onHandleReply(const QJsonObject& reply, const RuntimeManager::Error& error) 
    {
        if (error.code() != RuntimeManager::Error::Code::NoError) {
            const auto errCodeStr = Utils::errorCodeToString(error.code());
            qWarning(
                "Error code: %s\tMessage: %s", 
                errCodeStr.toUtf8().constData(),    
                error.message().toUtf8().constData()
            );
            emit errorInfo(errCodeStr, error.message());
            return;
        }
        emit replyReceived(reply);
    }
}
