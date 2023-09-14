# HitSoccer

`HitSoccer`はロボットサッカーを制御するためのプログラム群です。攻撃ロボット、守備ロボット、そして全体の監督としての3つの主要なコンポーネントから構成されています。

## ToDo

- 具台的なディレクトリ構造を追加、プログラムを追加

## ディレクトリ構造

```
HitSoccer/
│
├── attackrobot/
│   └── ...
│
├── defenserobot/
│   └── ...
│
└── control/
    └── ...
```

## 各ディレクトリの説明

- **attackrobot**: 攻撃ロボットの動作を制御するプログラム。 arduino で制御

- **defenserobot**: 守備ロボットの動作を制御するプログラム。arduino で制御

- **control**: 全体の戦略や状態の監視を担当するコントローラのプログラム。Raspberry Pi + .NETで制御


## ライセンス

(c) 2023 HITDesign Group All Rights Reserved.

