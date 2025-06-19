#pragma once

#include <iostream>
#include <string>

// 貸出状況を表すenum
enum class BookStatus {
    AVAILABLE,    // 貸出可能
    BORROWED,     // 貸出中
    RESERVED      // 予約済み
};

class Book {
public:
    // コンストラクタ
    Book(int book_id, const std::string& book_title, const std::string& book_author);
    
    // ゲッター関数
    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    BookStatus getStatus() const;
    
    // セッター関数
    void setStatus(BookStatus new_status);
    
    // 本の情報を表示する関数
    void displayInfo() const;
    
    // ステータスを文字列に変換する関数
    std::string statusToString() const;

private:
    std::string title_;
    std::string author_;
    int id_;
    BookStatus status_;
};
