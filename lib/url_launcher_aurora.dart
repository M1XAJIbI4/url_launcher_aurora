
import 'url_launcher_aurora_platform_interface.dart';

class UrlLauncherAurora {
  Future<String?> getPlatformVersion() {
    return UrlLauncherAuroraPlatform.instance.getPlatformVersion();
  }
}
