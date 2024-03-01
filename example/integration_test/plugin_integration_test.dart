// This is a basic Flutter integration test.
//
// Since integration tests run in a full Flutter application, they can interact
// with the host side of a plugin implementation, unlike Dart unit tests.
//
// For more information about Flutter integration tests, please see
// https://docs.flutter.dev/cookbook/testing/integration/introduction


import 'package:flutter_test/flutter_test.dart';
import 'package:integration_test/integration_test.dart';

import 'package:url_launcher_aurora/url_launcher_aurora.dart';

void main() {
  IntegrationTestWidgetsFlutterBinding.ensureInitialized();

  testWidgets('onLauncUrl test', (WidgetTester tester) async {
    final UrlLauncherAurora plugin = UrlLauncherAurora();
    final String? version = await plugin.onLaunchUrl('Test');
    expect(version?.isNotEmpty, true);
  });
}
