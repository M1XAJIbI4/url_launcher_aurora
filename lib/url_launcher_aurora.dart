
import 'package:flutter/services.dart';
import 'package:url_launcher_platform_interface/link.dart';
import 'package:url_launcher_platform_interface/url_launcher_platform_interface.dart';

const methodChannel = const MethodChannel('url_launcher_aurora');

class UrlLauncherAurora extends UrlLauncherPlatform {
  /// Registers this class as the default instance of [UrlLauncherPlatform].
  static void registerWith() {
    UrlLauncherPlatform.instance = UrlLauncherAurora();
  }

  @override
  final LinkDelegate? linkDelegate = null;

  @override
  Future<bool> launchUrl(String url, LaunchOptions options) async {
    return (await methodChannel.invokeMethod<bool>(
      'launchUrl',
      <String, Object>{"url": url},
    )) ?? false;
  }
}
