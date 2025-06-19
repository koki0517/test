#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Book.h"

class Library {
public:
    // コンストラクタ
    Library();
    
    // 本を追加する関数
    void addBook(const std::string& title, const std::string& author);
    
    // 本を検索する関数（タイトルで検索）
    void searchByTitle(const std::string& title) const;
    
    // 本を検索する関数（著者で検索）
    void searchByAuthor(const std::string& author) const;
    
    // 本を貸し出す関数
    bool borrowBook(int id);
    
    // 本を返却する関数
    bool returnBook(int id);
    
    // 全ての本を表示する関数
    void displayAllBooks() const;
    
    // 貸出可能な本のみを表示する関数
    void displayAvailableBooks() const;
    
private:
    // IDで本を検索する関数（プライベートスコープ）
    Book* findBookById(int id);
    std::vector<Book> books_;  // vectorを使用
    int next_id_;
};
