import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'url_launcher_aurora_method_channel.dart';

abstract class UrlLauncherAuroraPlatform extends PlatformInterface {
  UrlLauncherAuroraPlatform() : super(token: _token);

  static final Object _token = Object();

  static UrlLauncherAuroraPlatform _instance = MethodChannelUrlLauncherAurora();

  /// The default instance of [UrlLauncherAuroraPlatform] to use.
  ///
  /// Defaults to [MethodChannelUrlLauncherAurora].
  static UrlLauncherAuroraPlatform get instance => _instance;

  static set instance(UrlLauncherAuroraPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> launchUrl(String url) {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }
}
