import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'url_launcher_aurora_platform_interface.dart';

/// An implementation of [UrlLauncherAuroraPlatform] that uses method channels.
class MethodChannelUrlLauncherAurora extends UrlLauncherAuroraPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('url_launcher_aurora');

  @override
  Future<String?> getPlatformVersion(String url) async {
    final version = await methodChannel.invokeMethod<String>(
      'getPlatformVersion',
      <String, Object>{"url": url}
    );
    return version;
  }
}
