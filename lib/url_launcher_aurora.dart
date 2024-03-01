
import 'url_launcher_aurora_platform_interface.dart';

class UrlLauncherAurora {
  Future<String?> launchUrl(String url) {
    return UrlLauncherAuroraPlatform.instance.launchUrl(url);
  }
}
