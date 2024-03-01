#include <url_launcher_aurora/url_launcher_aurora_plugin.h>
#include <flutter/method-channel.h>
#include <sys/utsname.h>

#include "intent/intent_default.h"
#include "invoke_manager/invoke_manager.h"

void UrlLauncherAuroraPlugin::RegisterWithRegistrar(PluginRegistrar &registrar)
{
    registrar.RegisterMethodChannel("url_launcher_aurora",
                                    MethodCodecType::Standard,
                                    [this](const MethodCall &call) { this->onMethodCall(call); });
}

void UrlLauncherAuroraPlugin::onMethodCall(const MethodCall &call)
{
    const auto &method = call.GetMethod();

    if (method == "launchUrl") {
        onLaunchUrl(call);
        return;
    }

    unimplemented(call);
}

void UrlLauncherAuroraPlugin::onLaunchUrl(const MethodCall &call)
{
    Invoker::InvokeManager::instance().init();
    Intent::IntentDefault::registerQmlType();

    auto url = call.GetArgument<Encodable::String>("url");
    QString sUrl = QString::fromStdString(url);
    Intent::IntentDefault intent;
    intent.invokeOpenURI(sUrl);

    call.SendSuccessResponse(nullptr);
}

void UrlLauncherAuroraPlugin::unimplemented(const MethodCall &call)
{
    call.SendSuccessResponse(nullptr);
}
