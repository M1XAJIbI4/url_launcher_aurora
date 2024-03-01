#ifndef FLUTTER_PLUGIN_URL_LAUNCHER_AURORA_PLUGIN_H
#define FLUTTER_PLUGIN_URL_LAUNCHER_AURORA_PLUGIN_H

#include <flutter/plugin-interface.h>
#include <url_launcher_aurora/globals.h>

class PLUGIN_EXPORT UrlLauncherAuroraPlugin final : public PluginInterface
{
public:
    void RegisterWithRegistrar(PluginRegistrar &registrar) override;

private:
    void onMethodCall(const MethodCall &call);
    void onLaunchUrl(const MethodCall &call);
    void unimplemented(const MethodCall &call);
};

#endif /* FLUTTER_PLUGIN_URL_LAUNCHER_AURORA_PLUGIN_H */
