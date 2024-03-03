# url_launcher_aurora

The Aurora implementation of [url_launcher] (https://pub.dev/packages/url_launcher)

## Usage
This package is not an _endorsed_ implementation of 'url_launcher'.
Therefore, you have to include 'url_launcher_aurora' alongside 'url_launcher' as dependencies in your 'pubspec.yaml' file.


***.desktop**

'''desktop
Permissions=Internet
'''

***.spec

'''spec
BuildRequires: pkgconfig(runtime-manager-qt5)
'''

**pubspec.yaml**

'''yaml
dependencies:
    url_launcher: ^6.0.2
    url_launcher_aurora:
        git:
            url: <!-- Add url -->
            ref: <!-- Add ref -->
            path: <!-- Add path -->
'''