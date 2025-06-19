#include "Book.h"

Book::Book(int book_id, const std::string& book_title, const std::string& book_author)
    : title_(book_title), author_(book_author), id_(book_id), status_(BookStatus::AVAILABLE) {
}

int Book::getId() const {
    return id_;
}

std::string Book::getTitle() const {
    return title_;
}

std::string Book::getAuthor() const {
    return author_;
}

BookStatus Book::getStatus() const {
    return status_;
}

void Book::setStatus(BookStatus new_status) {
    status_ = new_status;
}

void Book::displayInfo() const {
    std::cout << "ID: " << id_ 
              << ", タイトル: " << title_ 
              << ", 著者: " << author_ 
              << ", 状況: " << statusToString() << std::endl;
}

std::string Book::statusToString() const {
    // enumを使った制御文（switch文）
    switch (status_) {
        case BookStatus::AVAILABLE:
            return "貸出可能";
        case BookStatus::BORROWED:
            return "貸出中";
        case BookStatus::RESERVED:
            return "予約済み";
        default:
            return "不明";
    }
}