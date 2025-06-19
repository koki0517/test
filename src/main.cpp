#include "Library.h"
#include <iostream>
#include <string>

// メニューを表示する関数
void displayMenu() {
    std::cout << "\n=== 図書館管理システム ===" << std::endl;
    std::cout << "1. 本を追加" << std::endl;
    std::cout << "2. タイトルで検索" << std::endl;
    std::cout << "3. 著者で検索" << std::endl;
    std::cout << "4. 本を貸し出す" << std::endl;
    std::cout << "5. 本を返却" << std::endl;
    std::cout << "6. 全ての本を表示" << std::endl;
    std::cout << "7. 貸出可能な本を表示" << std::endl;
    std::cout << "0. 終了" << std::endl;
    std::cout << "選択してください: ";
}

int main() {
    Library library;
    int user_choice;
    
    // サンプルデータを追加
    library.addBook("やさしいC++", "高橋麻奈");
    library.addBook("Effective C++", "Scott Meyers");
    library.addBook("苦しんで覚えるC言語", "MMGames");
    library.addBook("ROS 2ではじめよう 次世代ロボットプログラミング", "近藤豊");
    library.addBook("SLAM入門（改訂2版）", "友納 正裕");
    library.addBook("カルマンフィルタの基礎", "丸田一郎, 足立修一");
    
    // メインループ（while文による制御文）
    while (true) {
        displayMenu();
        std::cin >> user_choice;
        
        // switch文による制御文
        switch (user_choice) {
            case 1: {
                std::string title, author;
                std::cout << "タイトルを入力: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "著者を入力: ";
                std::getline(std::cin, author);
                library.addBook(title, author);
                break;
            }
            case 2: {
                std::string title;
                std::cout << "検索するタイトル（部分一致）: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                library.searchByTitle(title);
                break;
            }
            case 3: {
                std::string author;
                std::cout << "検索する著者名: ";
                std::cin.ignore();
                std::getline(std::cin, author);
                library.searchByAuthor(author);
                break;
            }
            case 4: {
                int id;
                std::cout << "貸し出す本のID: ";
                std::cin >> id;
                library.borrowBook(id);
                break;
            }
            case 5: {
                int id;
                std::cout << "返却する本のID: ";
                std::cin >> id;
                library.returnBook(id);
                break;
            }
            case 6:
                library.displayAllBooks();
                break;
            case 7:
                library.displayAvailableBooks();
                break;
            case 0:
                std::cout << "プログラムを終了します。" << std::endl;
                return 0;
            default:
                std::cout << "無効な選択です。再度入力してください。" << std::endl;
                break;
        }
    }
    
    return 0;
}