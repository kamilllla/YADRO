//
// Created by Камилла Балаева on 15.02.2023.
//

#ifndef YADRO_TAPE_H
#define YADRO_TAPE_H

#include <string>
#include "ITape.h"
#include <fstream>
#include <iostream>
using namespace std;
class Tape: public ITape {
public:
    string name;
    int current_position;
public:
    void filling_input_tape(int limit, int step, int *number) override {
        ofstream file_out;
        try {
            file_out.open(name);
            for (int i = 0; i < limit; i += step) {
                file_out << number[i] << ' ';
            }
            file_out.close();
        }
        catch (const exception &exception) {
            cout << exception.what();
        }
    }
    int get_count_of_tape(){
        ifstream if_stream;
        int size=-1;
        string s;
        try {
            if_stream.open(name);
            while (!if_stream.eof()) {
                if_stream >> s;
                size++;
            }
            if_stream.close();
            return size;
        }
        catch (const exception &exception) {
            cout << exception.what();
        }
    }

};





#endif //YADRO_TAPE_H
