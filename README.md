 # HitSoccer

`HitSoccer`はロボットサッカーを制御するためのプログラム群です。プレイヤーと監督としての2つの主要なコンポーネントから構成されています。

## ディレクトリ構造

```
hitsoccer/
├── README.md
├── control
└── player
    ├── .gitignore
    ├── include
    │   └── README
    ├── lib
    │   ├── PS2X_lib
    │   └── README
    ├── platformio.ini
    ├── src
    │   ├── attacker
    │   │   ├── attacker_main.cpp
    │   │   ├── controller.cpp
    │   │   ├── controller.h
    │   │   ├── motor.cpp
    │   │   └── motor.h
    │   ├── defender
    │   │   └── defender_main.cpp
    │   └── main.cpp
    └── test
        └── README
```

### 主なディレクトリの説明

- **player**: 攻撃ロボット、防衛ロボットの制御プログラム PlatformIOプロジェクトです。

- **control**: 全体の戦略や状態の監視を担当するコントローラのプログラム。Raspberry Pi+ .NETで制御

## 使用部品

### Robot

プログラムでの制御対象な使用部品

- Arduino UNO
- L298N
- DC Motor
- VS-C3 (controller)

## ライセンス

© 2023 HITDesignGroup.
