#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " input_binary_file output_text_file\n";
        return 1;
    }

    std::ifstream fin(argv[1], std::ios::binary);
    std::ofstream fout(argv[2]);

    if (!fin.is_open()) {
        std::cerr << "Error opening input binary file.\n";
        return 1;
    }

    if (!fout.is_open()) {
        std::cerr << "Error opening output text file.\n";
        return 1;
    }

    int src, dst;
    while (fin.read(reinterpret_cast<char*>(&src), sizeof(int)) &&
           fin.read(reinterpret_cast<char*>(&dst), sizeof(int))) {
        fout << src << " " << dst << "\n";
    }

    fin.close();
    fout.close();

    std::cout << "Conversion complete.\n";

    return 0;
}
