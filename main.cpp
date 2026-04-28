#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    Board board;
    int choice;

    do {
        std::cout << "\n===== A Bug's Life =====\n";
        std::cout << "1. Initialize Bug Board (load file)\n";
        std::cout << "2. Display all Bugs\n";
        std::cout << "3. Find a Bug\n";
        std::cout << "4. Tap the Bug Board\n";
        std::cout << "5. Display Life History\n";
        std::cout << "6. Display all Cells\n";
        std::cout << "7. Run Simulation (tap every second)\n";
        std::cout << "8. Exit & write history\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: board.initializeFromFile("bugs.txt"); break;
            case 2: board.displayAllBugs(); break;
            case 3: {
                int id; std::cout << "Enter bug id: "; std::cin >> id;
                Bug* b = board.findBugById(id);
                if(b) std::cout << "Bug found (display later)\n";
                else std::cout << "bug " << id << " not found\n";
                break;
            }
            case 4: board.tapBoard(); break;
            case 5: board.displayLifeHistories(); break;
            case 6: board.displayCells(); break;
            case 7: board.runSimulation(); break;
            case 8: board.writeLifeHistoriesToFile("bugs_life_history.out");
                std::cout << "Exiting.\n"; break;
            default: std::cout << "Invalid choice.\n";
        }
    } while(choice != 8);

    return 0;
}