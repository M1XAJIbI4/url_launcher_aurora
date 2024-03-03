import 'package:flutter/material.dart';
import 'dart:async';
import 'package:url_launcher/url_launcher.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  
  static const _urlList = [
    'https://google.com',
    'https://youtube.com',
    'https://vk.com',
  ];

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'),
        ),
        body: Center(
          child: ListView.separated(
            itemCount: _urlList.length,
            separatorBuilder: (_, __) => const SizedBox(height: 10),
            itemBuilder: (ctx, index) {
              final url = _urlList[index];
              return TextButton(
                onPressed: () => _launchUrl(url),
                child: Text(url),
              );
            },
          )
        ),
      ),
    );
  }

  Future<void> _launchUrl(String link) async {
    final url = Uri.tryParse(link);
    if (url != null) launchUrl(url);
  }
}
