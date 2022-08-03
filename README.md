# Preface

A screenshot demo application. Only for child's interested study.

In the latest Qt dev tools, some old functions have been cancelled. The following applies to the QT 5.12.x +.

## Function

1. Screenshot.

2. Support shortcut keys (HotKey): "Ctrl+Alt+S".

## How does the Qt development tool get a screenshot of the current screen?

** 1. QPixmap **

In the old version, you can see `QPixmap` and use `grabWindow()` to get the screenshot. For example:

```
QPixmap::grabWindow(QApplication::desktop()->winId());
```

** 2. QScreen **

Now, you can do with `QScreen` ! Like:

```
QScreen *myScreen = QGuiApplication::primaryScreen();
QPixmap screenPixmap = myScreen->grabWindow(0);
```

## How it works?

Hahaha... 

If you don't understand, you can get inspiration from this demo. Any child can do it!

## More

You can see Qt -> Help.