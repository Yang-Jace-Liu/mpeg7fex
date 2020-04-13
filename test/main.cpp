#include <iostream>
#include <vector>
#include <fstream>
#include "FexWrite.h"

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

std::vector<char *> load_images(char *text_path) {
    std::ifstream fin(text_path);
    std::vector<char *> results;
    while (!fin.eof()) {
        char * line = new char[200];
        fin.getline(line, 200);
        if (!fin.eof()) {
            if (fin.fail()) {
                std::cout << "Each path should be less than 200 characters." << std::endl;
                exit(0);
            }
            results.push_back(line);
        }
    }
    return results;
}

Frame *load_frame(char *image_path) {
    Mat img = imread(image_path);
    Frame *frame = new Frame(img.cols, img.rows, true, true, true);
    frame->setImage(img);
    return frame;
}

int main(int argc, char **argv) {
    char CLD_help[100];
    char CSD_help[100];
    char DCD_help[100];
    char EHD_help[100];
    char HTD_help[100];
    char SCD_help[100];

    sprintf(CLD_help, "Usage: %s CLD <numYCoef> <numCCoef> <input list> <output text file>", argv[0]);
    sprintf(CSD_help, "Usage: %s CSD <deckSize> <input list> <output text file>", argv[0]);
    sprintf(DCD_help, "Usage: %s DCD <input list> <output text file>", argv[0]);
    sprintf(EHD_help, "Usage: %s EHD <input list> <output text file>", argv[0]);
    sprintf(HTD_help, "Usage: %s HTD <input list> <output text file>", argv[0]);
    sprintf(SCD_help, "Usage: %s SCD <deckSize> <input list> <output text file>", argv[0]);

    if (argc < 4) {
        std::cout << CLD_help << std::endl;
        std::cout << CSD_help << std::endl;
        std::cout << DCD_help << std::endl;
        std::cout << EHD_help << std::endl;
        std::cout << HTD_help << std::endl;
        std::cout << SCD_help << std::endl;
        return 0;
    }

    char *metric = argv[1];

    if (strcmp(metric, "CLD") == 0) {
        if (argc < 6) {
            std::cout << CLD_help << std::endl;
            return 0;
        }
        int numYCoef = std::stoi(argv[2]);
        int numCCoef = std::stoi(argv[3]);
        char *input_list = argv[4];
        std::vector<char *> images = load_images(input_list);

        // Clear the content if the output file exists
        std::ofstream fout(argv[5], std::ofstream::out);

        for (char *image_path: images) {
            std::cout << image_path << std::endl;
            Frame *frame = load_frame(image_path);
            FexWrite::computeWriteCLD(frame, fout, numYCoef, numCCoef);
        }
        fout.close();
    } else if (strcmp(metric, "CSD") == 0) {
        if (argc < 5) {
            std::cout << CSD_help << std::endl;
            return 0;
        }
        int deckSize = std::stoi(argv[2]);
        char *input_list = argv[3];

        // Clear the content if the output file exists
        std::ofstream fout(argv[4], std::ofstream::out);

        std::vector<char *> images = load_images(input_list);
        for (char *image_path: images) {
            std::cout << image_path << std::endl;
            Frame *frame = load_frame(image_path);
            FexWrite::computeWriteCSD(frame, fout, deckSize);
        }
        fout.close();
    } else if (strcmp(metric, "DCD") == 0) {
        if (argc < 4) {
            std::cout << DCD_help << std::endl;
            return 0;
        }
        char *input_list = argv[2];

        // Clear the content if the output file exists
        std::ofstream fout(argv[3], std::ofstream::out);

        std::vector<char *> images = load_images(input_list);
        for (char *image_path: images) {
            std::cout << image_path << std::endl;
            Frame *frame = load_frame(image_path);
            FexWrite::computeWriteDCD(frame, fout);
        }
        fout.close();
    } else if (strcmp(metric, "EHD") == 0) {
        if (argc < 4) {
            std::cout << EHD_help << std::endl;
            return 0;
        }
        char *input_list = argv[2];

        // Clear the content if the output file exists
        std::ofstream fout(argv[3], std::ofstream::out);

        std::vector<char *> images = load_images(input_list);
        for (char *image_path: images) {
            std::cout << image_path << std::endl;
            Frame *frame = load_frame(image_path);
            FexWrite::computeWriteEHD(frame, fout);
        }
        fout.close();
    } else if (strcmp(metric, "HTD") == 0) {
        if (argc < 4) {
            std::cout << HTD_help << std::endl;
            return 0;
        }
        char *input_list = argv[2];

        // Clear the content if the output file exists
        std::ofstream fout(argv[3], std::ofstream::out);

        std::vector<char *> images = load_images(input_list);
        for (char *image_path: images) {
            std::cout << image_path << std::endl;
            Frame *frame = load_frame(image_path);
            FexWrite::computeWriteHTD(frame, fout);
        }
        fout.close();
    } else if (strcmp(metric, "SCD") == 0) {
        if (argc < 5) {
            std::cout << SCD_help << std::endl;
            return 0;
        }
        int deckSize = std::stoi(argv[2]);
        char *input_list = argv[3];

        // Clear the content if the output file exists
        std::ofstream fout(argv[4], std::ofstream::out);

        std::vector<char *> images = load_images(input_list);
        for (char *image_path: images) {
            std::cout << image_path << std::endl;
            Frame *frame = load_frame(image_path);
            FexWrite::computeWriteSCD(frame, fout, deckSize);
        }
        fout.close();
    }
}
