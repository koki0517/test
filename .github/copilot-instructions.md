# Copilot Instructions - NHK部隊コーディングルール

このプロジェクトでは、NHK部隊のコーディングルールに従ってコードを作成してください。

## 命名規則

### 変数名
- **ローカル変数**: スネークケース（小文字 + アンダーバー）
  ```cpp
  int can_id;
  bool is_ready;
  float motor_speed;
  ```

### 定数
- **定数名**: 大文字 + アンダーバー
  ```cpp
  #define MAX_STUDENTS 31
  const int NUM_WHEELS = 4;
  ```

### 関数名
- **関数名**: キャメルケース（最初は小文字、以降の単語は大文字開始）
- **動詞から始める**
  ```cpp
  void setTxData(uint8_t *data, uint8_t len);
  float getPosition();
  bool isReady();
  ```

### クラス
- **クラス名**: パスカルケース（各単語の最初を大文字）
  ```cpp
  class LibrarySystem {
  ```

- **メンバ変数**: スネークケース + 末尾にアンダーバー
  ```cpp
  private:
      int wheel_num_;
      std::string device_name_;
  ```

- **メンバ変数はprivateにする**: 外部アクセスにはgetter/setter関数を使用
- **初期化リストを使用**: 宣言順に並べる

### ファイル名
- **ファイル名**: キャメルケース
  ```
  main.cpp
  purePersuit.h
  motorController.cpp
  ```

## コーディング規則

### 変数のスコープ
- **スコープを最小限に**: 変数の寿命を短くする
- **グローバル変数を避ける**

### マジックナンバーを避ける
- **意味のある定数名を使用**

### 構文規則
- **中括弧{}を省略しない**
- **三項演算子は避ける**

### インデント
- **一貫したインデント**: Tab または Space（2回/4回）
- **同一プロジェクト内で統一**
- **対応する{}の位置を揃える**

### 誤解を招く命名を避ける
- **limit → max/min を使用**
- **boolean変数はis/can/hasで始める**
- **変数名は名詞句、関数名は動詞句**

## C++固有の規則

### STLコンテナ
- **適切なコンテナを選択**: vector, map, setなど
- **range-based for文を活用**

### メモリ管理
- **RAIIパターンを使用**
- **スマートポインタを活用**: unique_ptr, shared_ptr

### const の使用
- **const correctness を保つ**
- **メンバ関数でオブジェクトを変更しない場合はconst指定**

これらのルールに従って、保守性が高く、チーム開発に適したコードを作成してください。
