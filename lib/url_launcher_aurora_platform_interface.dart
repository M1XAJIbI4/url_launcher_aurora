import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'url_launcher_aurora_method_channel.dart';

abstract class UrlLauncherAuroraPlatform extends PlatformInterface {
  /// Constructs a UrlLauncherAuroraPlatform.
  UrlLauncherAuroraPlatform() : super(token: _token);

  static final Object _token = Object();

  static UrlLauncherAuroraPlatform _instance = MethodChannelUrlLauncherAurora();

  /// The default instance of [UrlLauncherAuroraPlatform] to use.
  ///
  /// Defaults to [MethodChannelUrlLauncherAurora].
  static UrlLauncherAuroraPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [UrlLauncherAuroraPlatform] when
  /// they register themselves.
  static set instance(UrlLauncherAuroraPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> getPlatformVersion() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }
}
