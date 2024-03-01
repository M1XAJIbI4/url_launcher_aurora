#include <url_launcher_aurora/url_launcher_aurora_plugin.h>
#include <flutter/method-channel.h>
#include <sys/utsname.h>

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
        std::cout <<"FOOBAR TEST SUCCESSED";
        onLaunchUrl(call);
        return;
    }

    unimplemented(call);
}

void UrlLauncherAuroraPlugin::onLaunchUrl(const MethodCall &call)
{
    utsname uname_data{};
    uname(&uname_data);

    auto url = call.GetArgument<Encodable::String>("url");
    std::cout <<url;

    std::string preamble = "Aurora (Linux): ";
    std::string version = preamble + "FOOBAR" + url;

    call.SendSuccessResponse(version);
}

void UrlLauncherAuroraPlugin::unimplemented(const MethodCall &call)
{
    call.SendSuccessResponse(nullptr);
}
