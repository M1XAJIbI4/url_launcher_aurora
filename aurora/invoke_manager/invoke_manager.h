// SPDX-FileCopyrightText: 2023 Open Mobile Platform LLC <community@omp.ru>
// SPDX-License-Identifier: BSD-3-Clause

#ifndef INVOKE_MANANGER_H
#define INVOKE_MANANGER_H

#include <QObject>
#include <RuntimeManager/IntentsInvoker>

namespace Invoker {
    class InvokeManager : public QObject 
    {
        Q_OBJECT
    public: 
        static InvokeManager& instance();

        void init();

        void invoke(const QString& name, const QJsonObject& hints, const QJsonObject& param);
    
    private:
        InvokeManager(QObject* parent = nullptr);    
        ~InvokeManager() override = default;

    private:
        QScopedPointer<RuntimeManager::IntentsInvoker> m_invoker;

    private slots:
        void onHandleReply(const QJsonObject& reply, const RuntimeManager::Error& error);

    signals:
        void replyReceived(const QJsonObject&);
        void errorInfo(const QString&, const QString&);
    };
}

#endif // INVOKE_MANANGER_H
