#include "Library.h"

Library::Library() : next_id_(1) {
}

void Library::addBook(const std::string& title, const std::string& author) {
    books_.emplace_back(next_id_++, title, author);
    std::cout << "本が追加されました: " << title << std::endl;
}

void Library::searchByTitle(const std::string& title) const {
    bool found = false;
    
    // vectorをforループで検索
    for (const auto& book : books_) {
        // 部分一致検索
        if (book.getTitle().find(title) != std::string::npos) {
            book.displayInfo();
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "「" << title << "」を含むタイトルの本は見つかりませんでした。" << std::endl;
    }
}

void Library::searchByAuthor(const std::string& author) const {
    bool found = false;
    
    // 従来のforループを使用
    for (size_t i = 0; i < books_.size(); ++i) {
        if (books_[i].getAuthor().find(author) != std::string::npos) {
            books_[i].displayInfo();
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "「" << author << "」の本は見つかりませんでした。" << std::endl;
    }
}

bool Library::borrowBook(int id) {
    Book* book = findBookById(id);
    
    if (book == nullptr) {
        std::cout << "ID " << id << " の本は存在しません。" << std::endl;
        return false;
    }
    
    // enumを使った条件分岐
    if (book->getStatus() == BookStatus::AVAILABLE) {
        book->setStatus(BookStatus::BORROWED);
        std::cout << "「" << book->getTitle() << "」を貸し出しました。" << std::endl;
        return true;
    } else {
        std::cout << "「" << book->getTitle() << "」は現在貸出できません。" << std::endl;
        return false;
    }
}

bool Library::returnBook(int id) {
    Book* book = findBookById(id);
    
    if (book == nullptr) {
        std::cout << "ID " << id << " の本は存在しません。" << std::endl;
        return false;
    }
    
    if (book->getStatus() == BookStatus::BORROWED) {
        book->setStatus(BookStatus::AVAILABLE);
        std::cout << "「" << book->getTitle() << "」が返却されました。" << std::endl;
        return true;
    } else {
        std::cout << "「" << book->getTitle() << "」は貸出中ではありません。" << std::endl;
        return false;
    }
}

void Library::displayAllBooks() const {
    if (books_.empty()) {
        std::cout << "図書館に本がありません。" << std::endl;
        return;
    }
    
    std::cout << "\n=== 全ての本 ===" << std::endl;
    for (const auto& book : books_) {
        book.displayInfo();
    }
    std::cout << std::endl;
}

void Library::displayAvailableBooks() const {
    std::cout << "\n=== 貸出可能な本 ===" << std::endl;
    bool has_available = false;
    
    for (const auto& book : books_) {
        if (book.getStatus() == BookStatus::AVAILABLE) {
            book.displayInfo();
            has_available = true;
        }
    }
    
    if (!has_available) {
        std::cout << "現在貸出可能な本はありません。" << std::endl;
    }
    std::cout << std::endl;
}

// プライベート関数（スコープの例）
Book* Library::findBookById(int id) {
    for (auto& book : books_) {
        if (book.getId() == id) {
            return &book;
        }
    }
    return nullptr;
}